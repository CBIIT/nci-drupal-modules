<?php

/**
 * @file
 * Functions which process the menu.
 */

/**
 * Build a menu tree based.
 */
function responsive_menu_tree_build($tree, $menu_name) {
  $data = array();
  $data['subject'] = '';
  $data['content']['#content'] = responsive_menu_tree_output($tree, $menu_name);

  if (!empty($data['content']['#content'])) {
    $data['content']['#theme'] = array(
      'responsive_menu_block_wrapper'
    );
    $data['content']['#menu_name'] = $menu_name;
  }
  else {
    $data['content'] = '';
  }

  return $data;
}

/**
 * Returns a renderable menu tree.
 *
 * This is a copy of menu_tree_output() with parts stripped away.
 *
 * @param array $tree
 *   A data structure representing the tree as returned from menu_tree_data.
 * @param string $menu_name
 *   The menu name of the menu being rendered.
 * @return string
 *   The rendered HTML of that data structure.
 */
function responsive_menu_tree_output(&$tree, $menu_name) {
  $build = array();
  $items = array();

  // Create context if no config was provided.
  $config['delta'] = 0;
  $config['menu_name'] = $menu_name;

  // Pull out just the menu links we are going to render so that we
  // get an accurate count for the first/last classes.
  foreach ($tree as $key => &$value) {
    if ($tree[$key]['link']['access'] && !$tree[$key]['link']['hidden']) {
      $items[] = $tree[$key];
    }
  }

  $router_item = menu_get_item();
  $num_items = count($items);
  foreach ($items as $i => &$data) {
    $class = array();
    if ($i == 0) {
      $class[] = 'first';
    }
    if ($i == $num_items - 1) {
      $class[] = 'last';
    }
    // Set a class for the <li>-tag. Since $data['below'] may contain local
    // tasks, only set 'expanded' class if the link also has children within
    // the current menu.
    if ($data['link']['has_children'] && $data['below']) {
      $class[] = 'expanded';
    }
    elseif ($data['link']['has_children']) {
      $class[] = 'collapsed';
    }
    else {
      $class[] = 'leaf';
    }
    if (!empty($data['link']['leaf_has_children'])) {
      $class[] = 'has-children';
    }

    // Set a class if the link is in the active trail.
    if ($data['link']['in_active_trail']) {
      $class[] = 'active-trail';
      $data['link']['localized_options']['attributes']['class'][] = 'active-trail';
    }

    // Determine whether this item should be shown as a fly-left flyout.
    if ($data['below']) {
      // Try to load the variable for this menu item to see whether to add the class.
      if (variable_get('responsive_menu_flyleft_mlid:' . $data['link']['mlid'], FALSE)) {
        $class[] = 'fly-left';
      }
    }

    if ($data['link']['href'] == $_GET['q'] || ($data['link']['href'] == '<front>' && drupal_is_front_page())) {
      $class[] = 'active';
    }
    // Set a menu link ID class.
    $class[] = 'menu-mlid-' . $data['link']['mlid'];
    // Normally, l() compares the href of every link with $_GET['q'] and sets
    // the active class accordingly. But local tasks do not appear in menu
    // trees, so if the current path is a local task, and this link is its
    // tab root, then we have to set the class manually.
    if ($data['link']['href'] == $router_item['tab_root_href'] && $data['link']['href'] != $_GET['q']) {
      $data['link']['localized_options']['attributes']['class'][] = 'active';
    }

    // Define the theme function for the menu link element.
    $element['#theme'] = array(
      'responsive_menu_link',
    );
    $element['#attributes']['class'] = $class;
    $element['#title'] = $data['link']['title'];
    $element['#href'] = $data['link']['href'];
    $element['#localized_options'] = !empty($data['link']['localized_options']) ? $data['link']['localized_options'] : array();
    $element['#below'] = $data['below'] ? responsive_menu_tree_output($data['below'], $config) : $data['below'];
    $element['#original_link'] = $data['link'];
    $element['#bid'] = array('module' => 'responsive_menu', 'delta' => $config['delta']);
    // Index using the link's unique mlid.
    $build[$data['link']['mlid']] = $element;
  }
  if ($build) {
    // Make sure drupal_render() does not re-order the links.
    $build['#sorted'] = TRUE;
    // Add the theme wrapper for outer markup.
    // Allow menu-specific theme overrides.
    $build['#theme_wrappers'][] = array(
      'responsive_menu_tree',
    );
  }

  return $build;
}

/**
 * Gets the data structure representing a menu tree for the given configuration.
 *
 * @param $config
 *   See the $config param of menu_tree_build().
 */
function responsive_menu_tree_block_data($menu_name, $max_depth = NULL) {

  $tree = menu_tree_all_data($menu_name, NULL, $max_depth);
  // And add the active trail data back to the full tree.
  $menu_item = current($tree);
  $tree_with_trail = menu_tree_page_data($menu_item['link']['menu_name'], $max_depth);

  // To traverse the original tree down the active trail, we use a pointer.
  $subtree_pointer = &$tree;

  // Find each key in the active trail.
  while ($tree_with_trail) {
    foreach ($tree_with_trail as $key => &$value) {
      if ($tree_with_trail[$key]['link']['in_active_trail'] && isset($subtree_pointer[$key])) {
        // Set the active trail info in the original tree.
        $subtree_pointer[$key]['link']['in_active_trail'] = TRUE;
        // Continue in the subtree, if it exists.
        $tree_with_trail = &$tree_with_trail[$key]['below'];
        $subtree_pointer = &$subtree_pointer[$key]['below'];
        break;
      }
      else {
        unset($tree_with_trail[$key]);
      }
    }
  }

  // Allow alteration of the tree and config before we begin operations on it.
  drupal_alter('responsive_menu_tree', $tree, $menu_name);

  // Localize the tree.
  if (module_exists('i18n_menu')) {
    $tree = i18n_menu_localize_tree($tree);
  }

  // Trim the branches that extend beyond the specified depth.
  responsive_menu_tree_depth_trim($tree, $max_depth);

  return $tree;
}

/**
 * Prune a tree so it does not extend beyond the specified depth limit.
 *
 * @param $tree
 *   array The menu tree to prune.
 * @param $depth_limit
 *   int The maximum depth of the returned tree; must be a positive integer.
 * @return
 *   void
 */
function responsive_menu_tree_depth_trim(&$tree, $depth_limit) {
  // Prevent invalid input from returning a trimmed tree.
  if ($depth_limit < 1) {
    return;
  }

  // Examine each element at this level to find any possible children.
  foreach ($tree as $key => &$value) {
    if ($tree[$key]['below']) {
      if ($depth_limit > 1) {
        responsive_menu_tree_depth_trim($tree[$key]['below'], $depth_limit - 1);
      }
      else {
        // Remove the children items.
        $tree[$key]['below'] = FALSE;
      }
    }
    if ($depth_limit == 1 && $tree[$key]['link']['has_children']) {
      // Turn off the menu styling that shows there were children.
      $tree[$key]['link']['has_children'] = FALSE;
      $tree[$key]['link']['leaf_has_children'] = TRUE;
    }
  }
}