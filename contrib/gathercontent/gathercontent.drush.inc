<?php

/**
 * @file
 *   Drush command to cli config import.
 */

use GatherContent\Content;
use GatherContent\Project;

/**
 * Implements hook_drush_command().
 */
function gathercontent_drush_command() {
  $commands = [];

  $commands['gathercontent-list-mappings'] = [
    'aliases' => ['gc-lm'],
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'description' => dt('Lists the available mapping definitions.'),
    'engines' => [
      'outputformat' => [
        'default' => 'table',
        'pipe-format' => 'json',
        'output-data-type' => 'format-table',
        'field-labels' => [
          'mapping_id' => dt('Mapping ID'),
          'project_id' => dt('Project ID'),
          'project_label' => dt('Project label'),
          'template_id' => dt('Template ID'),
          'template_label' => dt('Template label'),
          'content_type' => dt('Content type'),
        ],
      ],
    ],
  ];

  $commands['gathercontent-list-status'] = [
    'aliases' => ['gc-ls'],
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'description' => dt('Lists the node status definitions.'),
    'required-arguments' => FALSE,
    'arguments' => [
      'project_id' => dt('GatherContent project ID. Use: gathercontent-list-mappings'),
    ],
    'engines' => [
      'outputformat' => [
        'default' => 'table',
        'pipe-format' => 'json',
        'output-data-type' => 'format-table',
        'field-labels' => [
          'status_id' => dt('Status ID'),
          'status_label' => dt('Status label'),
        ],
      ],
    ],
  ];

  $commands['gathercontent-import'] = [
    'aliases' => ['gc-i'],
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'description' => dt('Import content from GatherContent site.'),
    'required-arguments' => FALSE,
    'arguments' => [
      'mapping_id' => dt('The drupal side content mapping ID. Use: gathercontent-list-mappings'),
      'node_update_method' => dt("Three choices: always_create, update_if_not_changed, always_update (this is the default)"),
      'parent_menu_item' => dt("Parent menu item. E.g.: Create under 'My account' menu, use: 'account:user.page'"),
      'status_id' => dt('Change the document status on GC side. Use: gathercontent-list-status'),
    ],
    'options' => [
      'publish' => array(
        'description' => dt('Use --publish or --no-publish.'),
        'required' => FALSE,
        'hidden' => FALSE,
      ),
    ],
    'engines' => [
      'outputformat' => [
        'default' => 'table',
        'pipe-format' => 'json',
        'output-data-type' => 'format-table',
        'field-labels' => [
          'id' => dt('ID'),
          'item_name' => dt('Item name'),
          'node_status' => dt('Node status'),
          'import_status' => dt('Import status'),
        ],
      ],
    ],
  ];

  return $commands;
}

/**
 * Implements drush_COMMAND().
 */
function drush_gathercontent_list_mappings() {
  /** @var stdClass $gc_mappings */
  $gc_mappings = entity_load('gathercontent_mapping');

  $mappings = [];
  foreach ($gc_mappings as $gc_mapping) {
    $mappings[$gc_mapping->id] = [
      'mapping_id' => $gc_mapping->id,
      'project_id' => $gc_mapping->gathercontent_project_id,
      'project_label' => $gc_mapping->gathercontent_project,
      'template_id' => $gc_mapping->gathercontent_template_id,
      'template_label' => $gc_mapping->gathercontent_template,
      'content_type' => $gc_mapping->content_type,
    ];
  }

  return $mappings;
}

/**
 * Implements drush_COMMAND().
 */
function drush_gathercontent_list_status($project_id = NULL) {
  $project_obj = new Project();
  if ($project_id === NULL) {
    $projects = $project_obj->getProjects();

    $options = [];
    foreach ($projects as $id => $label) {
      $options[$id] = $id . ' | ' . $label;
    }
    $project_id = drush_choice($options, dt('Select a project ID: '));
  }

  if (!$project_id) {
    return drush_set_error('gathercontent_unknown_mapping_id', dt('Unknown mapping ID.'));
  }
  $statuses = $project_obj->getStatuses($project_id);
  $mappings = [];
  foreach ($statuses as $status) {
    $mappings[$status->id] = [
      'status_id' => $status->id,
      'status_label' => $status->name,
    ];
  }

  return $mappings;
}

/**
 * Implements drush_COMMAND_validate().
 */
function drush_gathercontent_import_validate($mapping_id = NULL) {
  $publish = drush_get_option('publish');
  if ($publish !== NULL && !is_bool($publish)) {
    drush_set_error('gathercontent_invalid_option', dt("The --publish option doesn't accept value."));
  }

  if ($mapping_id !== NULL) {
    $mapping = entity_load('gathercontent_mapping', [$mapping_id]);
    if (!$mapping) {
      drush_set_error('gathercontent_invalid_argument', dt('Invalid mapping ID: @mapping_id', ['@mapping_id' => $mapping_id]));
    }
  }
}

/**
 * Implements drush_COMMAND().
 */
function drush_gathercontent_import($mapping_id = NULL, $node_update_method = 'always_update', $status_id = '', $parent_menu_item = NULL) {
  if ($mapping_id === NULL) {
    /** @var stdClass $gc_mappings */
    $gc_mappings = entity_load('gathercontent_mapping');

    $options = [];
    foreach ($gc_mappings as $gc_mapping) {
      $options[$gc_mapping->id] = $gc_mapping->id . ' | ' . $gc_mapping->gathercontent_project . ' | ' . $gc_mapping->gathercontent_template;
    }
    $mapping_id = drush_choice($options, dt('Select a mapping ID: '));
  }

  if (!$mapping_id) {
    return drush_set_error('gathercontent_unknown_mapping_id', dt('Unknown mapping ID.'));
  }

  $uuid = _gathercontent_uuid_generate();
  $operation = entity_create('gathercontent_operation', [
    'uuid' => $uuid,
    'type' => 'import',
  ]);
  entity_save('gathercontent_operation', $operation);

  $mapping = entity_load('gathercontent_mapping', [$mapping_id]);
  $project_id = $mapping[$mapping_id]->gathercontent_project_id;
  $template_id = $mapping[$mapping_id]->gathercontent_template_id;

  $content_obj = new Content();
  $content = $content_obj->getContents($project_id);

  $publish = drush_get_option('publish', variable_get('node_default_status'));
  $publish = $publish ? '1' : '0';

  $operations = [];

  foreach ($content as $item) {
    if ($item->template_id == $template_id) {
      $operations[] = [
        'gathercontent_import_process',
        [
          $item->id,
          $status_id,
          $operation->uuid,
          $publish,
          $parent_menu_item,
          $node_update_method,
        ],
      ];
    }
  }

  $batch = [
    'title' => dt('Importing'),
    'init_message' => dt('Starting import'),
    'error_message' => dt('An unrecoverable error has occurred. You can find the error message below. It is advised to copy it to the clipboard for reference.'),
    'operations' => $operations,
    'file' => drupal_get_path('module', 'gathercontent') . '/gathercontent.import.inc',
    'finished' => 'gathercontent_drush_import_process_finished',
  ];
  batch_set($batch);
  drush_backend_batch_process();

  $mappings = [];

  $query = new EntityFieldQuery();
  $query
    ->entityCondition('entity_type', 'gathercontent_operation_item')
    ->propertyCondition('operation_uuid', $operation->uuid);
  $result = $query->execute();
  if (!empty($result['gathercontent_operation_item'])) {
    $imported_items = entity_load('gathercontent_operation_item', array_keys($result['gathercontent_operation_item']));
    foreach ($imported_items as $imported_item) {
      $mappings[$imported_item->id] = [
        'id' => $imported_item->id,
        'item_name' => $imported_item->item_name,
        'node_status' => $imported_item->item_status,
        'import_status' => $imported_item->status,
      ];
    }
  }

  return $mappings;
}

function gathercontent_drush_import_process_finished($success, $results, $operations) {
  if ($success) {
    drush_log(dt('Import finished'), 'ok');
  }
  else {
    drush_set_error('gathercontent_import_failed', dt('Import failed'));
  }
}
