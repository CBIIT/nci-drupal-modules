<?php

/**
 * @file
 * Flush cache functionality for the Navbar Flush Cache module.
 */

/**
 * Implements hook_navbar_flush_cache_info().
 *
 * Performed on behalf of the Panels module.
 */
function panels_navbar_flush_cache_info() {
  $caches['panels'] = array(
    'title' => t('Panels'),
    'callback' => '_navbar_flush_cache_panels',
  );
  return $caches;
}

/**
 * Implements hook_navbar_flush_cache_info().
 *
 * Performed on behalf of the System module.
 */
function system_navbar_flush_cache_info() {
  $caches = array(
    'assets' => t('CSS and JavaScript'),
    'page' => t('Page and else'),
    'menu' => t('Menu'),
    'registry' => t('Class registry'),
    'theme' => t('Theme registry'),
  );

  foreach ($caches as $name => $cache) {
    $caches[$name] = array(
      'title' => $cache,
      'callback' => '_navbar_flush_cache_' . $name,
    );
  }

  return $caches;
}

/**
 * Implements hook_navbar_flush_cache_info().
 *
 * Performed on behalf of the Update module.
 */
function update_navbar_flush_cache_info() {
  $caches['update'] = array(
    'title' => t('Update data'),
    'callback' => '_update_cache_clear',
  );
  return $caches;
}

/**
 * Flushes the "Panels" cache.
 */
function _navbar_flush_cache_panels() {
  cache_clear_all('*', 'cache_panels', TRUE);
}

/**
 * Flushes the "Assets" cache.
 */
function _navbar_flush_cache_assets() {
  // Change query-strings on CSS/JS files to enforce reload for all users.
  _drupal_flush_css_js();

  drupal_clear_css_cache();
  drupal_clear_js_cache();

  // Clear the page cache, since cached HTML pages might link to old CSS and JS
  // aggregates.
  cache_clear_all('*', 'cache_page', TRUE);
}

/**
 * Flushes the "Page and else" cache.
 */
function _navbar_flush_cache_page() {
  // Don't clear cache_form - in-progress form submissions may break. Ordered so
  // clearing the page cache will always be the last action.
  // @see drupal_flush_all_caches()
  $core = array('cache', 'cache_bootstrap', 'cache_filter', 'cache_page');
  $cache_tables = array_merge(module_invoke_all('flush_caches'), $core);

  foreach ($cache_tables as $table) {
    cache_clear_all('*', $table, TRUE);
  }
}

/**
 * Flushes the "Menu" cache.
 */
function _navbar_flush_cache_menu() {
  menu_rebuild();
}

/**
 * Flushes the "Class registry" cache.
 */
function _navbar_flush_cache_registry() {
  registry_rebuild();

  // Also clear cache tables, since registry information is usually the base for
  // other data that is cached (e.g. SimpleTests).
  _navbar_flush_cache_page();
}

/**
 * Flushes the "Theme" cache.
 */
function _navbar_flush_cache_theme() {
  system_rebuild_theme_data();
  drupal_theme_rebuild();
}
