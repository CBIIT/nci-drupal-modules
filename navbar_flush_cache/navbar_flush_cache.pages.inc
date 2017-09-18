<?php

/**
 * @file
 * Page callbacks for the Navbar Flush Cache module.
 */

/**
 * Page callback: Flushes cache.
 *
 * @param string $name
 *   (optional) The name of cache to flush.
 *
 * @return int|null
 *   Returns a menu status code if either the token in the URL doesn't validate
 *   or the given cache name can't be found, NULL otherwise.
 */
function navbar_flush_cache_page($name = NULL) {
  if (!isset($_GET['token']) || !drupal_valid_token($_GET['token'], current_path())) {
    return MENU_ACCESS_DENIED;
  }
  if (isset($name)) {
    $caches = module_invoke_all('navbar_flush_cache_info');
    if (!isset($caches[$name])) {
      return MENU_NOT_FOUND;
    }
  }
  else {
    $caches[$name] = array(
      'title' => t('Every'),
      'callback' => 'drupal_flush_all_caches',
    );
  }

  // Pass the cache to flush forward to the callback.
  $function = $caches[$name]['callback'];
  $function($name);

  drupal_set_message(t('!title cache cleared.', array('!title' => $caches[$name]['title'])));

  // The URL contains a destination request parameter pointing to the
  // originating page, so the user is redirected back to that page. Without
  // destination parameter, the redirect ends on the front page.
  drupal_goto();
}
