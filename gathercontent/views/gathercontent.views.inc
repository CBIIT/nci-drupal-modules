<?php

/**
 * Implements hook_views_data().
 */
function gathercontent_views_data() {
  $data['gathercontent_mapping']['edit_mapping'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the mapping.'),
      'handler' => 'views_handler_field_mapping_link_edit',
      'click sortable' => FALSE,
    ),
  );

  $data['gathercontent_mapping']['delete_mapping'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the mapping.'),
      'handler' => 'views_handler_field_mapping_link_delete',
      'click sortable' => FALSE,
    ),
  );
  return $data;
}

/**
 * Implements hook_views_data_alter().
 */
function gathercontent_views_data_alter(&$data) {
  $data['node']['gathercontent_id'] = array(
    'title' => t('GC ID'),
    'help' => t('The ID of content in GatherContent'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
  );
  $data['node']['gathercontent_mapping_id'] = array(
    'title' => t('gathercontent Mapping ID'),
    'help' => t('The ID of GatherContent mapping'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'relationship' => array(
      'base' => 'gathercontent_mapping',
      'base field' => 'id',
      'field' => 'gathercontent_mapping_id',
      'handler' => 'views_handler_relationship',
      'label' => t('Mapping used for GatherContent.'),
      'title' => t('Mapping used for GatherContent.'),
      'help' => t('Mapping used for GatherContent.'),
    ),
  );
  $data['node']['gathercontent_import_status'] = array(
    'title' => t('GC Import status'),
    'help' => t('Status of import from GatherContent'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
  );
  $data['node']['gathercontent_status'] = array(
    'title' => t('GC Status'),
    'help' => t('Status of content in GatherContent'),
    'field' => array(
      'handler' => 'views_handler_field_node_gathercontent_status',
    ),
  );
  $data['node']['gathercontent_title'] = array(
    'title' => t('GC Title'),
    'help' => t('Title of content in GatherContent'),
    'field' => array(
      'handler' => 'views_handler_field_node_gathercontent_title',
    ),
  );
  $data['node']['gathercontent_link'] = array(
    'title' => t('GC Link'),
    'help' => t('Link to content in GatherContent'),
    'field' => array(
      'handler' => 'views_handler_field_node_gathercontent_link',
      'click sortable' => FALSE,
    ),
  );
  $data['node']['gathercontent_updated1'] = array(
    'title' => t('Last updated in GatherContent'),
    'help' => t('Last updated in GatherContent'),
    'field' => array(
      'handler' => 'views_handler_field_node_gathercontent_updated',
      'click sortable' => TRUE,
    ),
  );
  $data['gathercontent_mapping']['gathercontent_updated'] = array(
    'title' => t('Last updated in GatherContent'),
    'help' => t('Last updated in GatherContent'),
    'field' => array(
      'handler' => 'views_handler_field_mapping_gathercontent_updated',
      'click sortable' => TRUE,
    ),
  );

  $data['gathercontent_operation_item']['gathercontent_link'] = array(
    'title' => t('GC Link'),
    'help' => t('Link to content in GatherContent'),
    'field' => array(
      'handler' => 'views_handler_field_gathercontent_operation_item_gathercontent_link',
      'click sortable' => FALSE,
    ),
  );
  $data['gathercontent_operation_item']['gathercontent_node_link'] = array(
    'title' => t('GC Node Link'),
    'help' => t('Link to content in Drupal'),
    'field' => array(
      'handler' => 'views_handler_field_gathercontent_operation_item_gathercontent_node_link',
      'click sortable' => FALSE,
    ),
  );
  $data['gathercontent_operation_item']['item_status_color'] = array(
    'title' => t('GC Status Color'),
    'help' => t('Status of content in GatherContent'),
    'field' => array(
      'handler' => 'views_handler_field_gathercontent_operation_item_status_color',
      'click sortable' => FALSE,
    ),
  );
}
