<?php
/**
 * @file
 * multisite_feature.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function multisite_feature_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-external-menu.
  $menus['menu-external-menu'] = array(
    'menu_name' => 'menu-external-menu',
    'title' => 'External menu',
    'description' => '',
  );
  // Exported menu: menu-quick-support.
  $menus['menu-quick-support'] = array(
    'menu_name' => 'menu-quick-support',
    'title' => 'Quick Support',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('External menu');
  t('Main menu');
  t('Quick Support');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');

  return $menus;
}
