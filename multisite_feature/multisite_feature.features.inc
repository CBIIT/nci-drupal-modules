<?php
/**
 * @file
 * multisite_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function multisite_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_views_api().
 */
function multisite_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function multisite_feature_node_info() {
  $items = array(
    'imported_service' => array(
      'name' => t('Imported Service'),
      'base' => 'node_content',
      'description' => t('A content type for all ServiceNow Services'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'imported_service_category' => array(
      'name' => t('Imported Service Category'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'service' => array(
      'name' => t('Service'),
      'base' => 'node_content',
      'description' => t('A content type for all services'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
