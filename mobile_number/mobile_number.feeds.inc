<?php

/**
 * @file
 * Implementation of Feeds mapping API for mobile_number.module.
 */

/**
 * Implements hook_feeds_processor_targets().
 */
function mobile_number_feeds_processor_targets($entity_type, $bundle_name) {
  $targets = array();

  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    $info = field_info_field($name);

    if ($info['type'] == 'mobile_number') {
      $targets[$name . ':value'] = array(
        'name' => t('@label: International Number', array('@label' => $instance['label'])),
        'callback' => 'mobile_number_feeds_set_target',
        'description' => t('International (E.164) number of @label field.', array('@label' => $instance['label'])),
        'real_target' => $name,
      );
      $targets[$name . ':country'] = array(
        'name' => t('@label: Country', array('@label' => $instance['label'])),
        'callback' => 'mobile_number_feeds_set_target',
        'description' => t('Country of @label field.', array('@label' => $instance['label'])),
        'real_target' => $name,
      );
      $targets[$name . ':local_number'] = array(
        'name' => t('@label: Local Number', array('@label' => $instance['label'])),
        'callback' => 'mobile_number_feeds_set_target',
        'description' => t('Local number of @label field.', array('@label' => $instance['label'])),
        'real_target' => $name,
      );
      $targets[$name . ':verified'] = array(
        'name' => t('@label: Verified', array('@label' => $instance['label'])),
        'callback' => 'mobile_number_feeds_set_target',
        'description' => t('Verification status of @label field.', array('@label' => $instance['label'])),
        'real_target' => $name,
      );
      $targets[$name . ':tfa'] = array(
        'name' => t('@label: TFA', array('@label' => $instance['label'])),
        'callback' => 'mobile_number_feeds_set_target',
        'description' => t('TFA status of @label field.', array('@label' => $instance['label'])),
        'real_target' => $name,
      );
    }
  }

  return $targets;
}

/**
 * Callback for mapping file fields.
 */
function mobile_number_feeds_set_target(FeedsSource $source, $entity, $target, array $values, array $mapping) {
  $language = $mapping['language'];

  list($field_name, $sub_field) = explode(':', $target);
  $info = field_info_field($field_name);

  // Populate entity.
  $field = isset($entity->$field_name) ? $entity->$field_name : array($language => array());
  $delta = 0;
  foreach ($values as $v) {
    if ($info['cardinality'] == $delta) {
      break;
    }

    if (!isset($field[$language][$delta])) {
      $field[$language][$delta] = array(
        'tfa' => 0,
        'verified' => 0,
      );
    }

    $field[$language][$delta][$sub_field] = $v;

    switch ($sub_field) {
      case 'value':
        try {
          $mobile_number = new MobileNumber($v);
          $field[$language][$delta]['value'] = $mobile_number->callableNumber;
        }
        catch (Exception $e) {

        }
        break;

      case 'country':
        if (!empty($field[$language][$delta]['local_number'])) {
          try {
            $mobile_number = new MobileNumber($field[$language][$delta]['local_number'], $v);
            $field[$language][$delta]['value'] = $mobile_number->callableNumber;
          }
          catch (Exception $e) {

          }
        }
        break;

      case 'local_number':
        if (!empty($field[$language][$delta]['country'])) {
          try {
            $mobile_number = new MobileNumber($v, $field[$language][$delta]['country']);
            $field[$language][$delta]['value'] = $mobile_number->callableNumber;
          }
          catch (Exception $e) {

          }
        }
        break;
    }

    $delta++;
  }

  $entity->$field_name = $field;
}
