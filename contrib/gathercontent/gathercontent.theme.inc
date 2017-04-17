<?php
/**
 * @file
 * Form elements and theme functions for GatherContent module.
 */

/**
 * Implements hook_element_info().
 */
function gathercontent_element_info() {
  return array(
    //
    // Custom tableselect form element.
    //
    'gathercontent_tableselect' => array(
      '#input' => TRUE,
      '#js_select' => TRUE,
      '#multiple' => TRUE,
      '#process' => array('form_process_tableselect'),
      '#options' => array(),
      '#empty' => '',
      '#theme' => 'gathercontent_tableselect',
      '#type' => 'tableselect',
      //
      // Additional options compared to tableselect form element.
      //
      // Whether to add tablesorter plugin or not (if it's available).
      '#tablesorter' => TRUE,
      // DIV elements which have to be added to the table as prefix, array of
      // class arrays keyed by an (internal) element name.
      // These elements will be wrapped into a DIV with class
      // gathercontent-table--header.
      //
      // Example:
      // @code
      // $element['#filterwrapper'] = array(
      //   'element_one' => array('class1', 'class2'),
      //   'element_two' => array('class3', 'class4'),
      // );
      // @endcode
      //
      // Sample output in the case above:
      // @code
      // <div class="gathercontent-table-header">
      //   <div class="class1 class2"></div>
      //   <div class="class3 class4"></div>
      // </div>
      // @endcode
      '#filterwrapper' => array(),
      '#filterdescription' => '',
    ),
    //
    // Checkbox counter form element.
    //
    // Sample usage:
    // @code
    // $form['counter'] = array(
    //   '#type' => 'gathercontent_checkboxcounter',
    //   '#checkboxes_selector' => '.custom-wrapper [type="checkbox"]',
    //   '#counter_message_template' => array(
    //     '1 node selected',
    //     '@count nodes selected',
    //   ),
    //   '#counter_message_default' => format_plural(0,
    //     '1 node selected',
    //     '@count nodes selected'
    //   ),
    // );
    // @endcode
    'gathercontent_checkboxcounter' => array(
      '#input' => FALSE,
      '#theme' => 'gathercontent_checkboxcounter',
      '#process' => array('form_process_container'),
      '#checkboxes_selector' => '',
      '#counter_message_js_template' => array(),
      '#counter_message_default' => '',
    ),
  );
}

/**
 * Implements hook_theme().
 */
function gathercontent_theme() {
  return array(
    'gathercontent_tableselect' => array(
      'render element' => 'element',
    ),
    'gathercontent_checkboxcounter' => array(
      'render element' => 'element',
    ),
  );
}

/**
 * Returns HTML markup for a checkbox counter.
 *
 * @param array $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties and children of
 *     the checkboxcounter element. Properties used (every one is optional):
 *     #checkboxes_selector, #counter_message_js_template,
 *     #counter_message_default.
 *
 * @return string
 *   The rendered markup.
 *
 * @ingroup themeable
 */
function theme_gathercontent_checkboxcounter(array $variables) {
  $output = '';
  $element = $variables['element'];
  $gathercontent_module_path = drupal_get_path('module', 'gathercontent');
  $gathercontent_counter_id = drupal_html_id('gathercontent-checkbox-counter');
  $gathercontent_counter_id_js = lcfirst(implode('', array_map('ucfirst', explode('-', $gathercontent_counter_id))));
  $element['#attributes']['class'][] = 'gathercontent-checkboxcounter';
  $element['#attributes']['data-gathercontent-counter-id'] = $gathercontent_counter_id_js;
  $element['#children'] .= !empty($element['#counter_message_default']) ? format_plural(0, '1 item selected', '@count item selected') : $element['#counter_message_default'];
  $js_settings = array();

  if (!empty($element['#checkboxes_selector'])) {
    $js_settings['checkboxesSelector'] = $element['#checkboxes_selector'];
  }
  if (!empty($element['#counter_message_js_template']) && is_array($element['#counter_message_js_template'])) {
    $js_settings['counterMessage'] = $element['#counter_message_js_template'];
  }

  drupal_add_js($gathercontent_module_path . '/js/gathercontent-checkboxcounter.js', 'file');
  drupal_add_js(array($gathercontent_counter_id_js => $js_settings), 'setting');

  $output .= theme('container', array(
    'element' => $element,
  ));

  return $output;
}

/**
 * Returns HTML for a table with radio buttons or checkboxes.
 *
 * See Drupal core's theme_tableselect() as reference.
 *
 * @param array $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties and children of
 *     the tableselect element. Properties used: #header, #options, #empty,
 *     and #js_select. The #options property is an array of selection options;
 *     each array element of #options is an array of properties. These
 *     properties can include #attributes, which is added to the
 *     table row's HTML attributes; see theme_table().
 *
 * @return string
 *   The rendered markup.
 *
 * @ingroup themeable
 */
function theme_gathercontent_tableselect(array $variables) {
  $output = '';
  $element = $variables['element'];
  $gathercontent_module_path = drupal_get_path('module', 'gathercontent');

  // Libraries module and tablesorter plugin are optional.
  // If tablesorter available, add it to the scope.
  if (module_exists('libraries')) {
    $library = libraries_detect('tablesorter-mottie');
    if ($library['installed'] && isset($element['#tablesorter'])) {
      $element['#attributes']['class'][] = 'tablesorter-enabled';
      drupal_add_js($gathercontent_module_path . '/js/gathercontent-tablesorter.js');
      libraries_load('tablesorter-mottie');
    }
  }

  $table = array(
    'header' => $element['#header'],
    'rows' => [],
    'empty' => $element['#empty'],
    'attributes' => $element['#attributes'],
  );

  // Generate a table row for each selectable item in #options.
  foreach (element_children($element) as $key) {
    $row = array();

    foreach ($element['#header'] as $column => $column_title) {
      $row[$column] = array('data' => drupal_render($element[$key][$column]));
      if (isset($element[$key][$column]['#attributes'])) {
        $row[$column] += $element[$key][$column]['#attributes'];
      }
    }

    $table['rows'][$key] = $row;
  }

  // Add an empty header or a "Select all" checkbox to provide room for the
  // checkboxes/radios in the first table column.
  if (isset($element['#js_select'])) {
    // Add a "Select all" checkbox.
    drupal_add_js($gathercontent_module_path . '/js/gathercontent-tableselect.js');
    array_unshift($element['#header'], array(
      'class' => array('select-all'),
      'data-sorter' => 'false',
    ));
  }
  else {
    // Add an empty header when radio buttons are displayed or a "Select all"
    // checkbox is not desired.
    array_unshift($element['#header'], '');
  }

  if (!empty($element['#filterwrapper']) && is_array($element['#filterwrapper'])) {
    $filterwrapper = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('gathercontent-table--header'),
      ),
    );

    foreach ($element['#filterwrapper'] as $key => $classes) {
      $filterwrapper[$key] = array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => is_array($classes) ? $classes : array($classes),
        ),
      );
    }
    $output .= drupal_render($filterwrapper);
  }

  if (!empty($element['#filterdescription'])) {
    $filterdescription = array(
      '#type' => 'html_tag',
      '#tag' => 'div',
      '#value' => $element['#filterdescription'],
      '#attributes' => array(
        'class' => array('description'),
      ),
    );
    $output .= drupal_render($filterdescription);
  }

  $output .= theme('table', $table);

  return $output;
}

/**
 * Creates checkbox or radio elements to populate a tableselect table.
 *
 * See Drupal's form_process_tableselect() as reference.
 *
 * @param array $element
 *   An associative array containing the properties and children of the
 *   tableselect element.
 *
 * @return array
 *   The processed element.
 */
function gathercontent_process_gathercontent_tableselect(array $element) {
  if (isset($element['#multiple']) && $element['#multiple']) {
    $value = is_array($element['#value']) ? $element['#value'] : array();
  }
  else {
    // Advanced selection behavior makes no sense for radios.
    $element['#js_select'] = FALSE;
  }

  $element['#tree'] = TRUE;

  if (isset($element['#options']) && (count($element['#options']) > 0)) {
    if (!isset($element['#default_value']) || $element['#default_value'] === 0) {
      $element['#default_value'] = array();
    }

    // Create a checkbox or radio for each item in #options in such a way that
    // the value of the tableselect element behaves as if it had been of type
    // checkboxes or radios.
    foreach ($element['#options'] as $key => $choice) {
      // Do not overwrite manually created children.
      if (!isset($element[$key])) {
        if ($element['#multiple']) {
          $title = '';
          if (!empty($element['#options'][$key]['title']['data']['#title'])) {
            $title = t('Update @title', array(
              '@title' => $element['#options'][$key]['title']['data']['#title'],
            ));
          }
          $element[$key] = array(
            '#type' => 'checkbox',
            '#title' => $title,
            '#title_display' => 'invisible',
            '#return_value' => $key,
            '#default_value' => isset($value[$key]) ? $key : NULL,
            '#attributes' => $element['#attributes'],
          );
        }
        else {
          // Generate the parents as the autogenerator does, so we will have a
          // unique id for each radio button.
          $parents_for_id = array_merge($element['#parents'], array($key));
          $element[$key] = array(
            '#type' => 'radio',
            '#title' => '',
            '#return_value' => $key,
            '#default_value' => ($element['#default_value'] == $key) ? $key : NULL,
            '#attributes' => $element['#attributes'],
            '#parents' => $element['#parents'],
            '#id' => drupal_html_id('edit-' . implode('-', $parents_for_id)),
            '#ajax' => isset($element['#ajax']) ? $element['#ajax'] : NULL,
          );
        }
        if (isset($element['#options'][$key]['#weight'])) {
          $element[$key]['#weight'] = $element['#options'][$key]['#weight'];
        }
      }
    }
  }
  else {
    $element['#value'] = array();
  }
  return $element;
}
