<?php

/**
 * @file
 * Drush integration for Mobile Number module.
 */

/**
 * Implements hook_drush_command().
 */
function mobile_number_drush_command() {
  $items['libphonenumber-download'] = array(
    'description' => dt('Downloads the libphonenumber library from https://github.com/giggsey/libphonenumber-for-php.'),
    'arguments' => array(
      'path' => dt('Path to the download folder. This path is relative to the Drupal root. If omitted Drush will use the default location (sites/all/libraries/libphonenumber).'),
    ),
  );
  return $items;
}

/**
 * A command callback.
 */
function drush_mobile_number_libphonenumber_download($path = NULL) {
  // If no path is provided by the user, set our default path.
  if (is_null($path)) {
    // We use devel folder for legacy reason.
    $path = 'sites/all/libraries/libphonenumber';
  }
  if (is_dir($path)) {
    drush_log(dt('libphonenumber already present at @path. No download required.', array('@path' => $path)), 'ok');
  }
  elseif (drush_shell_exec('wget https://github.com/giggsey/libphonenumber-for-php/archive/8.0.tar.gz && tar xvzf 8.0.tar.gz && rm 8.0.tar.gz && mv libphonenumber-for-php-8.0 %s', $path)) {
    drush_log(dt('libphonenumber has been downloaded via wget to @path.', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to export libphonenumber to @path.', array('@path' => $path)), 'warning');
  }
}
