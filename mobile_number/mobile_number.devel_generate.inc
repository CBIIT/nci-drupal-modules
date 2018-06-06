<?php
/**
 * @file
 * Provides devel generate integration.
 */

use libphonenumber\PhoneNumberUtil;

require_once drupal_get_path('module', 'mobile_number') . '/include/mobile_number.libphonenumber.inc';

/**
 * Implements hook_devel_generate().
 */
function mobile_number_devel_generate($object, $field, $instance, $bundle) {
  if (field_behaviors_widget('multiple values', $instance) == FIELD_BEHAVIOR_CUSTOM) {
    return devel_generate_multiple('_mobile_number_devel_generate', $object, $field, $instance, $bundle);
  }
  else {
    return _mobile_number_devel_generate($object, $field, $instance, $bundle);
  }
}

/**
 * Devel generate callback for phone field types.
 */
function _mobile_number_devel_generate($object, $field, $instance, $bundle) {

  static $last_numbers = array();

  $util = PhoneNumberUtil::getInstance();

  $settings = array(
    'verify' => MOBILE_NUMBER_VERIFY_NONE,
    'countries' => array(),
  );
  if ($instance['widget']['type'] == 'mobile_number_default') {
    $settings = $instance['widget']['settings'];
  }
  $country = array_rand(MobileNumber::getCountryOptions($settings['countries']));
  $last = !empty($last_numbers[$country]) ? $last_numbers[$country] : array();
  $mobile_number = NULL;
  if (!$last) {
    $last['count'] = 0;
    $last['example'] = ($number = $util->getExampleNumberForType($country, 1)) ? $number->getNationalNumber() : NULL;
  }
  $example = $last['example'];
  $count = $last['count'];

  if ($example) {
    while (strlen($count) <= strlen($example) && !$mobile_number) {
      $number_length = strlen($example);
      $number = substr($example, 0, $number_length - strlen($count)) . $count;
      if (substr($count, 0, 1) != substr($example, strlen($count) - 1, 1)) {
        try {
          $mobile_number = new MobileNumber($number, $country);
          break;
        }
        catch (Exception $e) {

        }
      }
      $count++;
    };
  }

  $value = array();
  if ($mobile_number) {
    $value = array(
      'value' => $mobile_number->callableNumber,
    );
    switch ($settings['verify']) {
      case MOBILE_NUMBER_VERIFY_NONE:
        $value['verified'] = 0;
        break;

      case MOBILE_NUMBER_VERIFY_OPTIONAL:
        $value['verified'] = rand(0, 1);
        break;

      case MOBILE_NUMBER_VERIFY_REQUIRED:
        $value['verified'] = 1;
        break;
    }
  }

  $last_numbers[$country] = $last;
  return $value;
}
