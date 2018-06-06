<?php

/**
 * @file
 * Integration with Migrate.
 */

/**
 * Implements hook_migrate_api().
 */
function mobile_number_migrate_api() {
  $api = array(
    'api' => 2,
    'field handlers' => array('MigrateMobileNumberFieldHandler'),
  );
  return $api;
}

/**
 * Migration class for migrating field content to mobile_number fields.
 */
class MigrateMobileNumberFieldHandler extends MigrateFieldHandler {
  /**
   * {@inheritdoc}
   */
  public function __construct() {
    $this->registerTypes(array('mobile_number'));
  }

  /**
   * {@inheritdoc}
   */
  public function prepare($entity, array $field_info, array $instance, array $values) {
    $arguments = array();
    if (isset($values['arguments'])) {
      $arguments = array_filter($values['arguments']);
      unset($values['arguments']);
    }
    $language = $this->getFieldLanguage($entity, $field_info, $arguments);

    // Setup the standard Field API array for saving.
    $delta = 0;
    foreach ($values as $value) {
      try {
        $mobile_number = new MobileNumber($value);
        $return[$language][$delta]['value'] = $mobile_number->callableNumber;
        $return[$language][$delta]['country'] = $mobile_number->country;
        $return[$language][$delta]['local_number'] = $mobile_number->localNumber;
        $return[$language][$delta]['verified'] = 0;
        $delta++;
      }
      catch (Exception $e) {
      }
    }
    return isset($return) ? $return : NULL;
  }
}
