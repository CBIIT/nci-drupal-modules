<?php

/**
 * @file
 * Mobile_number.libphonenumber.inc.
 */

use mobile_number\ClassLoader;

require __DIR__ . '/ClassLoader.php';

/**
 * Mobile number autoload.
 */
class MobileNumberAutoload {

  /**
   * Load.
   */
  public static function load() {
    module_load_include('module', 'libraries');
    
    $classLoader = new ClassLoader();
    $classLoader->set('libphonenumber', array(libraries_get_path('libphonenumber') . '/src'));
    $classLoader->setPsr4('libphonenumber\\', array(libraries_get_path('libphonenumber') . '/src'));
    $classLoader->register(TRUE);

    return $classLoader;
  }

}

return MobileNumberAutoload::load();
