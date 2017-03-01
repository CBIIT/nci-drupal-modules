<?php
/**
 * @file
 * multisite_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function multisite_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'category_importer';
  $feeds_importer->config = array(
    'name' => 'Category Importer',
    'description' => 'An importer for all services',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => 0,
        'direct' => 1,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'sys_id',
            'target' => 'field_imported_cat_system_id',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 1,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'unpublish',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'imported_service_category',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['category_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'demo_service_importer';
  $feeds_importer->config = array(
    'name' => 'Demo Service Importer',
    'description' => 'Service Importer for demo',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => 0,
        'direct' => 1,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsExXml',
      'config' => array(
        'context' => array(
          'value' => '/xml/*',
        ),
        'sources' => array(
          'name' => array(
            'name' => 'name',
            'value' => 'name',
            'raw' => 0,
            'inner' => 0,
            'debug' => 1,
            'weight' => '1',
          ),
          'description' => array(
            'name' => 'description',
            'value' => 'description',
            'raw' => 0,
            'inner' => 0,
            'debug' => 1,
            'weight' => '2',
          ),
        ),
        'display_errors' => 1,
        'debug_mode' => 1,
        'source_encoding' => array(
          0 => 'auto',
        ),
        'use_tidy' => FALSE,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'name',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'description',
            'target' => 'field_body',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '0',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
        'bundle' => 'service',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['demo_service_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'service_importer';
  $feeds_importer->config = array(
    'name' => 'Service Importer',
    'description' => 'An importer for all services',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => 0,
        'direct' => 1,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsExXml',
      'config' => array(
        'context' => array(
          'value' => '/xml/*',
        ),
        'sources' => array(
          'sys_id' => array(
            'name' => 'sys_id',
            'value' => 'sys_id',
            'raw' => 0,
            'inner' => 0,
            'debug' => 1,
            'weight' => '0',
          ),
          'name' => array(
            'name' => 'name',
            'value' => 'name',
            'raw' => 0,
            'inner' => 0,
            'debug' => 1,
            'weight' => '1',
          ),
          'description' => array(
            'name' => 'description',
            'value' => 'description',
            'raw' => 0,
            'inner' => 0,
            'debug' => 1,
            'weight' => '2',
          ),
          'category' => array(
            'name' => 'category',
            'value' => 'category',
            'raw' => 0,
            'inner' => 0,
            'debug' => 1,
            'weight' => '3',
          ),
          'sys_updated_on' => array(
            'name' => 'sys_updated_on',
            'value' => 'sys_updated_on',
            'raw' => 0,
            'inner' => 0,
            'debug' => 1,
            'weight' => '4',
          ),
          'sys_created_on' => array(
            'name' => 'sys_created_on',
            'value' => 'sys_created_on',
            'raw' => 0,
            'inner' => 0,
            'debug' => 1,
            'weight' => '5',
          ),
        ),
        'display_errors' => 1,
        'debug_mode' => 1,
        'source_encoding' => array(
          0 => 'auto',
        ),
        'use_tidy' => FALSE,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'sys_id',
            'target' => 'field_imported_system_id',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'name',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'description',
            'target' => 'field_imported_description',
            'format' => 'filtered_html',
            'language' => 'und',
          ),
          3 => array(
            'source' => 'sys_created_on',
            'target' => 'field_imported_created_date',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'sys_updated_on',
            'target' => 'field_imported_updated_date',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'category',
            'target' => 'field_imported_category_id',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'unpublish',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
        'bundle' => 'imported_service',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['service_importer'] = $feeds_importer;

  return $export;
}
