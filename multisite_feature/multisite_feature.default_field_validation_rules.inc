<?php
/**
 * @file
 * multisite_feature.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function multisite_feature_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Service sys_id';
  $rule->name = 'Service sys_id';
  $rule->field_name = 'field_imported_system_id';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'imported_service';
  $rule->validator = 'field_validation_unique_validator';
  $rule->settings = array(
    'data' => 'bundle',
    'per_user' => 0,
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      3 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'ID is required';
  $export['Service sys_id'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'sys_id';
  $rule->name = 'sys_id';
  $rule->field_name = 'field_imported_cat_system_id';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'imported_service_category';
  $rule->validator = 'field_validation_unique_validator';
  $rule->settings = array(
    'data' => 'bundle',
    'per_user' => 0,
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      3 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'ID is required';
  $export['sys_id'] = $rule;

  return $export;
}
