<?php

/**
 * Implements hook_views_default_views().
 */
function gathercontent_views_default_views() {
  $view = new view();
  $view->name = 'import_result_page';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'gathercontent_operation_item';
  $view->human_name = 'Result page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Import result page';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'item_status_color' => 'item_status',
    'item_status' => 'item_status',
    'item_name' => 'item_name',
    'status' => 'status',
    'template_name' => 'template_name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'item_status_color' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'item_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'item_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'template_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['label'] = 'Table description';
  $handler->display->display_options['footer']['area']['content'] = 'Template not mapped: Please check template mapping.
Template fields mismatch: This could be because the template in GatherContent has changed and the changed template has not been updated in Drupal.';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_gathercontent_html';
  /* Field: gathercontent Operation Item: gathercontent Status Color */
  $handler->display->display_options['fields']['item_status_color']['id'] = 'item_status_color';
  $handler->display->display_options['fields']['item_status_color']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['item_status_color']['field'] = 'item_status_color';
  /* Field: gathercontent Operation Item: Operation Item Status */
  $handler->display->display_options['fields']['item_status']['id'] = 'item_status';
  $handler->display->display_options['fields']['item_status']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['item_status']['field'] = 'item_status';
  $handler->display->display_options['fields']['item_status']['label'] = 'Status';
  /* Field: gathercontent Operation Item: Operation Item Name */
  $handler->display->display_options['fields']['item_name']['id'] = 'item_name';
  $handler->display->display_options['fields']['item_name']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['item_name']['field'] = 'item_name';
  $handler->display->display_options['fields']['item_name']['label'] = 'Item Name';
  /* Field: gathercontent Operation Item: Operation Item Operation Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Import Status';
  /* Field: gathercontent Operation Item: Operation Item Template Name */
  $handler->display->display_options['fields']['template_name']['id'] = 'template_name';
  $handler->display->display_options['fields']['template_name']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['template_name']['field'] = 'template_name';
  $handler->display->display_options['fields']['template_name']['label'] = 'GatherContent Template Name';
  /* Field: gathercontent Operation Item: gathercontent Link */
  $handler->display->display_options['fields']['gathercontent_link']['id'] = 'gathercontent_link';
  $handler->display->display_options['fields']['gathercontent_link']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['gathercontent_link']['field'] = 'gathercontent_link';
  $handler->display->display_options['fields']['gathercontent_link']['label'] = 'Open in GatherContent';
  /* Field: gathercontent Operation Item: gathercontent Node Link */
  $handler->display->display_options['fields']['gathercontent_node_link']['id'] = 'gathercontent_node_link';
  $handler->display->display_options['fields']['gathercontent_node_link']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['gathercontent_node_link']['field'] = 'gathercontent_node_link';
  $handler->display->display_options['fields']['gathercontent_node_link']['label'] = 'Open in Drupal';
  $handler->display->display_options['fields']['gathercontent_node_link']['empty'] = 'N/A';
  $handler->display->display_options['fields']['gathercontent_node_link']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['gathercontent_node_link']['hide_alter_empty'] = FALSE;
  /* Contextual filter: gathercontent Operation Item: Operation UUID */
  $handler->display->display_options['arguments']['operation_uuid']['id'] = 'operation_uuid';
  $handler->display->display_options['arguments']['operation_uuid']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['arguments']['operation_uuid']['field'] = 'operation_uuid';
  $handler->display->display_options['arguments']['operation_uuid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['operation_uuid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['operation_uuid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['operation_uuid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['operation_uuid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['operation_uuid']['limit'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/config/gathercontent/import/result/%';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Update result page';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: gathercontent Operation Item: gathercontent Status Color */
  $handler->display->display_options['fields']['item_status_color']['id'] = 'item_status_color';
  $handler->display->display_options['fields']['item_status_color']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['item_status_color']['field'] = 'item_status_color';
  /* Field: gathercontent Operation Item: Operation Item Status */
  $handler->display->display_options['fields']['item_status']['id'] = 'item_status';
  $handler->display->display_options['fields']['item_status']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['item_status']['field'] = 'item_status';
  $handler->display->display_options['fields']['item_status']['label'] = 'Status';
  /* Field: gathercontent Operation Item: Operation Item Name */
  $handler->display->display_options['fields']['item_name']['id'] = 'item_name';
  $handler->display->display_options['fields']['item_name']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['item_name']['field'] = 'item_name';
  $handler->display->display_options['fields']['item_name']['label'] = 'Item Name';
  /* Field: gathercontent Operation Item: Operation Item Operation Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Update Status';
  /* Field: gathercontent Operation Item: Operation Item Template Name */
  $handler->display->display_options['fields']['template_name']['id'] = 'template_name';
  $handler->display->display_options['fields']['template_name']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['template_name']['field'] = 'template_name';
  $handler->display->display_options['fields']['template_name']['label'] = 'GatherContent Template Name';
  /* Field: gathercontent Operation Item: gathercontent Link */
  $handler->display->display_options['fields']['gathercontent_link']['id'] = 'gathercontent_link';
  $handler->display->display_options['fields']['gathercontent_link']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['gathercontent_link']['field'] = 'gathercontent_link';
  $handler->display->display_options['fields']['gathercontent_link']['label'] = 'Open in GatherContent';
  /* Field: gathercontent Operation Item: gathercontent Node Link */
  $handler->display->display_options['fields']['gathercontent_node_link']['id'] = 'gathercontent_node_link';
  $handler->display->display_options['fields']['gathercontent_node_link']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['gathercontent_node_link']['field'] = 'gathercontent_node_link';
  $handler->display->display_options['fields']['gathercontent_node_link']['label'] = 'Open in Drupal';
  $handler->display->display_options['fields']['gathercontent_node_link']['empty'] = 'N/A';
  $handler->display->display_options['fields']['gathercontent_node_link']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['gathercontent_node_link']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['path'] = 'admin/content/update/result/%';

  /* Display: Page 2 */
  $handler = $view->new_display('page', 'Page 2', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upload result page';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: gathercontent Operation Item: gathercontent Status Color */
  $handler->display->display_options['fields']['item_status_color']['id'] = 'item_status_color';
  $handler->display->display_options['fields']['item_status_color']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['item_status_color']['field'] = 'item_status_color';
  /* Field: gathercontent Operation Item: Operation Item Status */
  $handler->display->display_options['fields']['item_status']['id'] = 'item_status';
  $handler->display->display_options['fields']['item_status']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['item_status']['field'] = 'item_status';
  $handler->display->display_options['fields']['item_status']['label'] = 'Status';
  /* Field: gathercontent Operation Item: Operation Item Name */
  $handler->display->display_options['fields']['item_name']['id'] = 'item_name';
  $handler->display->display_options['fields']['item_name']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['item_name']['field'] = 'item_name';
  $handler->display->display_options['fields']['item_name']['label'] = 'Item Name';
  /* Field: gathercontent Operation Item: Operation Item Operation Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Upload Status';
  /* Field: gathercontent Operation Item: Operation Item Template Name */
  $handler->display->display_options['fields']['template_name']['id'] = 'template_name';
  $handler->display->display_options['fields']['template_name']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['template_name']['field'] = 'template_name';
  $handler->display->display_options['fields']['template_name']['label'] = 'GatherContent Template Name';
  /* Field: gathercontent Operation Item: gathercontent Link */
  $handler->display->display_options['fields']['gathercontent_link']['id'] = 'gathercontent_link';
  $handler->display->display_options['fields']['gathercontent_link']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['gathercontent_link']['field'] = 'gathercontent_link';
  $handler->display->display_options['fields']['gathercontent_link']['label'] = 'Open in GatherContent';
  /* Field: gathercontent Operation Item: gathercontent Node Link */
  $handler->display->display_options['fields']['gathercontent_node_link']['id'] = 'gathercontent_node_link';
  $handler->display->display_options['fields']['gathercontent_node_link']['table'] = 'gathercontent_operation_item';
  $handler->display->display_options['fields']['gathercontent_node_link']['field'] = 'gathercontent_node_link';
  $handler->display->display_options['fields']['gathercontent_node_link']['label'] = 'Open in Drupal';
  $handler->display->display_options['fields']['gathercontent_node_link']['empty'] = 'N/A';
  $handler->display->display_options['fields']['gathercontent_node_link']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['gathercontent_node_link']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['path'] = 'admin/content/upload/result/%';
  $translatables['import_result_page'] = array(
    t('Master'),
    t('Import result page'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Table description'),
    t('Template not mapped: Please check template mapping.
Template fields mismatch: This could be because the template in GatherContent has changed and the changed template has not been updated in Drupal.'),
    t('GC Status Color'),
    t('Status'),
    t('Item Name'),
    t('Import Status'),
    t('GatherContent Template Name'),
    t('Open in GatherContent'),
    t('Open in Drupal'),
    t('N/A'),
    t('All'),
    t('Page'),
    t('Update result page'),
    t('Update Status'),
    t('Page 2'),
    t('Upload result page'),
    t('Upload Status'),
  );

  $views[$view->name] = $view;

  $view = new view();
  $view->name = 'mapping';
  $view->description = '';
  $view->tag = 'gathercontent';
  $view->base_table = 'gathercontent_mapping';
  $view->human_name = 'Manage Mappings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage Mappings';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'gathercontent_project' => 'gathercontent_project',
    'gathercontent_template' => 'gathercontent_template',
    'content_type_name' => 'content_type_name',
    'gathercontent_updated' => 'gathercontent_updated',
    'updated_drupal' => 'updated_drupal',
    'edit_mapping' => 'edit_mapping',
    'delete_mapping' => 'edit_mapping',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'gathercontent_project' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'gathercontent_template' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'content_type_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'gathercontent_updated' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'updated_drupal' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_mapping' => array(
      'align' => '',
      'separator' => '&emsp;',
      'empty_column' => 0,
    ),
    'delete_mapping' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No mappings were created.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Field: Mapping: gathercontent Project */
  $handler->display->display_options['fields']['gathercontent_project']['id'] = 'gathercontent_project';
  $handler->display->display_options['fields']['gathercontent_project']['table'] = 'gathercontent_mapping';
  $handler->display->display_options['fields']['gathercontent_project']['field'] = 'gathercontent_project';
  $handler->display->display_options['fields']['gathercontent_project']['label'] = 'Project';
  /* Field: Mapping: gathercontent Template */
  $handler->display->display_options['fields']['gathercontent_template']['id'] = 'gathercontent_template';
  $handler->display->display_options['fields']['gathercontent_template']['table'] = 'gathercontent_mapping';
  $handler->display->display_options['fields']['gathercontent_template']['field'] = 'gathercontent_template';
  $handler->display->display_options['fields']['gathercontent_template']['label'] = 'GatherContent Template';
  /* Field: Mapping: Content type name */
  $handler->display->display_options['fields']['content_type_name']['id'] = 'content_type_name';
  $handler->display->display_options['fields']['content_type_name']['table'] = 'gathercontent_mapping';
  $handler->display->display_options['fields']['content_type_name']['field'] = 'content_type_name';
  $handler->display->display_options['fields']['content_type_name']['label'] = 'Content type';
  $handler->display->display_options['fields']['content_type_name']['empty'] = 'None';
  /* Field: Mapping: Last updated in GatherContent */
  $handler->display->display_options['fields']['gathercontent_updated']['id'] = 'gathercontent_updated';
  $handler->display->display_options['fields']['gathercontent_updated']['table'] = 'gathercontent_mapping';
  $handler->display->display_options['fields']['gathercontent_updated']['field'] = 'gathercontent_updated';
  $handler->display->display_options['fields']['gathercontent_updated']['date_format'] = 'custom';
  $handler->display->display_options['fields']['gathercontent_updated']['custom_date_format'] = 'F d, Y - H:i';
  $handler->display->display_options['fields']['gathercontent_updated']['second_date_format'] = 'long';
  /* Field: Mapping: Updated (Drupal) */
  $handler->display->display_options['fields']['updated_drupal']['id'] = 'updated_drupal';
  $handler->display->display_options['fields']['updated_drupal']['table'] = 'gathercontent_mapping';
  $handler->display->display_options['fields']['updated_drupal']['field'] = 'updated_drupal';
  $handler->display->display_options['fields']['updated_drupal']['empty'] = 'Never';
  $handler->display->display_options['fields']['updated_drupal']['date_format'] = 'custom';
  $handler->display->display_options['fields']['updated_drupal']['custom_date_format'] = 'F d, Y - H:i';
  $handler->display->display_options['fields']['updated_drupal']['second_date_format'] = 'long';
  /* Field: Mapping: Edit link */
  $handler->display->display_options['fields']['edit_mapping']['id'] = 'edit_mapping';
  $handler->display->display_options['fields']['edit_mapping']['table'] = 'gathercontent_mapping';
  $handler->display->display_options['fields']['edit_mapping']['field'] = 'edit_mapping';
  $handler->display->display_options['fields']['edit_mapping']['label'] = 'Operations';
  /* Field: Mapping: Delete link */
  $handler->display->display_options['fields']['delete_mapping']['id'] = 'delete_mapping';
  $handler->display->display_options['fields']['delete_mapping']['table'] = 'gathercontent_mapping';
  $handler->display->display_options['fields']['delete_mapping']['field'] = 'delete_mapping';
  $handler->display->display_options['fields']['delete_mapping']['label'] = '';
  $handler->display->display_options['fields']['delete_mapping']['element_label_colon'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/config/gathercontent/mapping';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Manage Mappings';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['mapping'] = array(
    t('Master'),
    t('Manage Mappings'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('No mappings were created.'),
    t('Project'),
    t('GatherContent Template'),
    t('Content type'),
    t('None'),
    t('Last updated in GatherContent'),
    t('Updated (Drupal)'),
    t('Never'),
    t('Operations'),
    t('Page'),
  );


  $views[$view->name] = $view;

  $view = new view();
  $view->name = 'update';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Update';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Upload';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer gathercontent';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Content: Mapping used for GatherContent. */
  $handler->display->display_options['relationships']['gathercontent_mapping_id']['id'] = 'gathercontent_mapping_id';
  $handler->display->display_options['relationships']['gathercontent_mapping_id']['table'] = 'node';
  $handler->display->display_options['relationships']['gathercontent_mapping_id']['field'] = 'gathercontent_mapping_id';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::gathercontent_update' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: gathercontent Status */
  $handler->display->display_options['fields']['gathercontent_status']['id'] = 'gathercontent_status';
  $handler->display->display_options['fields']['gathercontent_status']['table'] = 'node';
  $handler->display->display_options['fields']['gathercontent_status']['field'] = 'gathercontent_status';
  $handler->display->display_options['fields']['gathercontent_status']['label'] = 'Status';
  /* Field: Mapping: gathercontent Project */
  $handler->display->display_options['fields']['gathercontent_project']['id'] = 'gathercontent_project';
  $handler->display->display_options['fields']['gathercontent_project']['table'] = 'gathercontent_mapping';
  $handler->display->display_options['fields']['gathercontent_project']['field'] = 'gathercontent_project';
  $handler->display->display_options['fields']['gathercontent_project']['relationship'] = 'gathercontent_mapping_id';
  $handler->display->display_options['fields']['gathercontent_project']['label'] = 'GatherContent Project';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Drupal Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: gathercontent Title */
  $handler->display->display_options['fields']['gathercontent_title']['id'] = 'gathercontent_title';
  $handler->display->display_options['fields']['gathercontent_title']['table'] = 'node';
  $handler->display->display_options['fields']['gathercontent_title']['field'] = 'gathercontent_title';
  $handler->display->display_options['fields']['gathercontent_title']['label'] = 'GatherContent Item name';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last updated in Drupal';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'F d, Y - H:i';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Last updated in GatherContent */
  $handler->display->display_options['fields']['gathercontent_updated1']['id'] = 'gathercontent_updated1';
  $handler->display->display_options['fields']['gathercontent_updated1']['table'] = 'node';
  $handler->display->display_options['fields']['gathercontent_updated1']['field'] = 'gathercontent_updated1';
  $handler->display->display_options['fields']['gathercontent_updated1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['gathercontent_updated1']['custom_date_format'] = 'F d, Y - H:i';
  $handler->display->display_options['fields']['gathercontent_updated1']['second_date_format'] = 'long';
  /* Field: Mapping: Content type name */
  $handler->display->display_options['fields']['content_type_name']['id'] = 'content_type_name';
  $handler->display->display_options['fields']['content_type_name']['table'] = 'gathercontent_mapping';
  $handler->display->display_options['fields']['content_type_name']['field'] = 'content_type_name';
  $handler->display->display_options['fields']['content_type_name']['relationship'] = 'gathercontent_mapping_id';
  /* Field: Mapping: gathercontent Template */
  $handler->display->display_options['fields']['gathercontent_template']['id'] = 'gathercontent_template';
  $handler->display->display_options['fields']['gathercontent_template']['table'] = 'gathercontent_mapping';
  $handler->display->display_options['fields']['gathercontent_template']['field'] = 'gathercontent_template';
  $handler->display->display_options['fields']['gathercontent_template']['relationship'] = 'gathercontent_mapping_id';
  $handler->display->display_options['fields']['gathercontent_template']['label'] = 'GatherContent Template';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Open in Drupal';
  $handler->display->display_options['fields']['view_node']['text'] = 'Open';
  /* Field: Content: gathercontent Link */
  $handler->display->display_options['fields']['gathercontent_link']['id'] = 'gathercontent_link';
  $handler->display->display_options['fields']['gathercontent_link']['table'] = 'node';
  $handler->display->display_options['fields']['gathercontent_link']['field'] = 'gathercontent_link';
  $handler->display->display_options['fields']['gathercontent_link']['label'] = 'Open in GatherContent';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Mapping: gathercontent Project */
  $handler->display->display_options['filters']['gathercontent_project']['id'] = 'gathercontent_project';
  $handler->display->display_options['filters']['gathercontent_project']['table'] = 'gathercontent_mapping';
  $handler->display->display_options['filters']['gathercontent_project']['field'] = 'gathercontent_project';
  $handler->display->display_options['filters']['gathercontent_project']['relationship'] = 'gathercontent_mapping_id';
  $handler->display->display_options['filters']['gathercontent_project']['exposed'] = TRUE;
  $handler->display->display_options['filters']['gathercontent_project']['expose']['operator_id'] = 'gathercontent_project_op';
  $handler->display->display_options['filters']['gathercontent_project']['expose']['label'] = 'GatherContent Project';
  $handler->display->display_options['filters']['gathercontent_project']['expose']['operator'] = 'gathercontent_project_op';
  $handler->display->display_options['filters']['gathercontent_project']['expose']['identifier'] = 'gathercontent_project';
  $handler->display->display_options['filters']['gathercontent_project']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Mapping: gathercontent Template */
  $handler->display->display_options['filters']['gathercontent_template']['id'] = 'gathercontent_template';
  $handler->display->display_options['filters']['gathercontent_template']['table'] = 'gathercontent_mapping';
  $handler->display->display_options['filters']['gathercontent_template']['field'] = 'gathercontent_template';
  $handler->display->display_options['filters']['gathercontent_template']['relationship'] = 'gathercontent_mapping_id';
  $handler->display->display_options['filters']['gathercontent_template']['exposed'] = TRUE;
  $handler->display->display_options['filters']['gathercontent_template']['expose']['operator_id'] = 'gathercontent_template_op';
  $handler->display->display_options['filters']['gathercontent_template']['expose']['label'] = 'GatherContent Template';
  $handler->display->display_options['filters']['gathercontent_template']['expose']['operator'] = 'gathercontent_template_op';
  $handler->display->display_options['filters']['gathercontent_template']['expose']['identifier'] = 'gathercontent_template';
  $handler->display->display_options['filters']['gathercontent_template']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Filter by item name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Mapping: Mapping ID */
  $handler->display->display_options['filters']['id']['id'] = 'id';
  $handler->display->display_options['filters']['id']['table'] = 'gathercontent_mapping';
  $handler->display->display_options['filters']['id']['field'] = 'id';
  $handler->display->display_options['filters']['id']['relationship'] = 'gathercontent_mapping_id';
  $handler->display->display_options['filters']['id']['operator'] = 'not empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Update';
  $handler->display->display_options['path'] = 'admin/content/update';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Update from GatherContent';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: gathercontent Status */
  $handler->display->display_options['fields']['gathercontent_status']['id'] = 'gathercontent_status';
  $handler->display->display_options['fields']['gathercontent_status']['table'] = 'node';
  $handler->display->display_options['fields']['gathercontent_status']['field'] = 'gathercontent_status';
  $handler->display->display_options['fields']['gathercontent_status']['label'] = 'Status';
  /* Field: Mapping: gathercontent Project */
  $handler->display->display_options['fields']['gathercontent_project']['id'] = 'gathercontent_project';
  $handler->display->display_options['fields']['gathercontent_project']['table'] = 'gathercontent_mapping';
  $handler->display->display_options['fields']['gathercontent_project']['field'] = 'gathercontent_project';
  $handler->display->display_options['fields']['gathercontent_project']['relationship'] = 'gathercontent_mapping_id';
  $handler->display->display_options['fields']['gathercontent_project']['label'] = 'GatherContent Project';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Drupal Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: gathercontent Title */
  $handler->display->display_options['fields']['gathercontent_title']['id'] = 'gathercontent_title';
  $handler->display->display_options['fields']['gathercontent_title']['table'] = 'node';
  $handler->display->display_options['fields']['gathercontent_title']['field'] = 'gathercontent_title';
  $handler->display->display_options['fields']['gathercontent_title']['label'] = 'GatherContent Item name';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last updated in Drupal';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'F d, Y - H:i';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Last updated in GatherContent */
  $handler->display->display_options['fields']['gathercontent_updated1']['id'] = 'gathercontent_updated1';
  $handler->display->display_options['fields']['gathercontent_updated1']['table'] = 'node';
  $handler->display->display_options['fields']['gathercontent_updated1']['field'] = 'gathercontent_updated1';
  $handler->display->display_options['fields']['gathercontent_updated1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['gathercontent_updated1']['custom_date_format'] = 'F d, Y - H:i';
  $handler->display->display_options['fields']['gathercontent_updated1']['second_date_format'] = 'long';
  /* Field: Mapping: Content type name */
  $handler->display->display_options['fields']['content_type_name']['id'] = 'content_type_name';
  $handler->display->display_options['fields']['content_type_name']['table'] = 'gathercontent_mapping';
  $handler->display->display_options['fields']['content_type_name']['field'] = 'content_type_name';
  $handler->display->display_options['fields']['content_type_name']['relationship'] = 'gathercontent_mapping_id';
  /* Field: Mapping: gathercontent Template */
  $handler->display->display_options['fields']['gathercontent_template']['id'] = 'gathercontent_template';
  $handler->display->display_options['fields']['gathercontent_template']['table'] = 'gathercontent_mapping';
  $handler->display->display_options['fields']['gathercontent_template']['field'] = 'gathercontent_template';
  $handler->display->display_options['fields']['gathercontent_template']['relationship'] = 'gathercontent_mapping_id';
  $handler->display->display_options['fields']['gathercontent_template']['label'] = 'GatherContent Template';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Open in Drupal';
  $handler->display->display_options['fields']['view_node']['text'] = 'Open';
  /* Field: Content: gathercontent Link */
  $handler->display->display_options['fields']['gathercontent_link']['id'] = 'gathercontent_link';
  $handler->display->display_options['fields']['gathercontent_link']['table'] = 'node';
  $handler->display->display_options['fields']['gathercontent_link']['field'] = 'gathercontent_link';
  $handler->display->display_options['fields']['gathercontent_link']['label'] = 'Open in GatherContent';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['nid_type'] = 'nids';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Choose the content you\'d like to update. This will update the content in GatherContent with the latest version in Drupal. Please note this feature currently only supports the update of written content (text fields).';
  $handler->display->display_options['header']['area']['format'] = 'filtered_gathercontent_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::gathercontent_upload' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: gathercontent Status */
  $handler->display->display_options['fields']['gathercontent_status']['id'] = 'gathercontent_status';
  $handler->display->display_options['fields']['gathercontent_status']['table'] = 'node';
  $handler->display->display_options['fields']['gathercontent_status']['field'] = 'gathercontent_status';
  $handler->display->display_options['fields']['gathercontent_status']['label'] = 'Status';
  /* Field: Mapping: gathercontent Project */
  $handler->display->display_options['fields']['gathercontent_project']['id'] = 'gathercontent_project';
  $handler->display->display_options['fields']['gathercontent_project']['table'] = 'gathercontent_mapping';
  $handler->display->display_options['fields']['gathercontent_project']['field'] = 'gathercontent_project';
  $handler->display->display_options['fields']['gathercontent_project']['relationship'] = 'gathercontent_mapping_id';
  $handler->display->display_options['fields']['gathercontent_project']['label'] = 'GatherContent Project';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Drupal Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: gathercontent Title */
  $handler->display->display_options['fields']['gathercontent_title']['id'] = 'gathercontent_title';
  $handler->display->display_options['fields']['gathercontent_title']['table'] = 'node';
  $handler->display->display_options['fields']['gathercontent_title']['field'] = 'gathercontent_title';
  $handler->display->display_options['fields']['gathercontent_title']['label'] = 'GatherContent Item name';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last updated in Drupal';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'F d, Y - H:i';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Last updated in GatherContent */
  $handler->display->display_options['fields']['gathercontent_updated1']['id'] = 'gathercontent_updated1';
  $handler->display->display_options['fields']['gathercontent_updated1']['table'] = 'node';
  $handler->display->display_options['fields']['gathercontent_updated1']['field'] = 'gathercontent_updated1';
  $handler->display->display_options['fields']['gathercontent_updated1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['gathercontent_updated1']['custom_date_format'] = 'F d, Y - H:i';
  $handler->display->display_options['fields']['gathercontent_updated1']['second_date_format'] = 'long';
  /* Field: Mapping: Content type name */
  $handler->display->display_options['fields']['content_type_name']['id'] = 'content_type_name';
  $handler->display->display_options['fields']['content_type_name']['table'] = 'gathercontent_mapping';
  $handler->display->display_options['fields']['content_type_name']['field'] = 'content_type_name';
  $handler->display->display_options['fields']['content_type_name']['relationship'] = 'gathercontent_mapping_id';
  /* Field: Mapping: gathercontent Template */
  $handler->display->display_options['fields']['gathercontent_template']['id'] = 'gathercontent_template';
  $handler->display->display_options['fields']['gathercontent_template']['table'] = 'gathercontent_mapping';
  $handler->display->display_options['fields']['gathercontent_template']['field'] = 'gathercontent_template';
  $handler->display->display_options['fields']['gathercontent_template']['relationship'] = 'gathercontent_mapping_id';
  $handler->display->display_options['fields']['gathercontent_template']['label'] = 'GatherContent Template';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Open in Drupal';
  $handler->display->display_options['fields']['view_node']['text'] = 'Open';
  /* Field: Content: gathercontent Link */
  $handler->display->display_options['fields']['gathercontent_link']['id'] = 'gathercontent_link';
  $handler->display->display_options['fields']['gathercontent_link']['table'] = 'node';
  $handler->display->display_options['fields']['gathercontent_link']['field'] = 'gathercontent_link';
  $handler->display->display_options['fields']['gathercontent_link']['label'] = 'Open in GatherContent';
  $handler->display->display_options['path'] = 'admin/content/upload';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Upload to GatherContent';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['update'] = array(
    t('Master'),
    t('Upload'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Mapping used for GatherContent.'),
    t('Content'),
    t('- Choose an operation -'),
    t('Status'),
    t('GatherContent Project'),
    t('Drupal Title'),
    t('GatherContent Item name'),
    t('Last updated in Drupal'),
    t('Last updated in GatherContent'),
    t('Content type name'),
    t('GatherContent Template'),
    t('Open in Drupal'),
    t('Open'),
    t('Open in GatherContent'),
    t('Filter by item name'),
    t('Page'),
    t('Update'),
    t('Block'),
    t('All'),
    t("Choose the content you'd like to update. This will update the content in 
    GatherContent with the latest version in Drupal. Please note this feature 
    currently only supports the update of written content (text fields)."),
  );

  $views[$view->name] = $view;

  return $views;
}

/**
 * Implements hook_views_default_views_alter().
 */
function gathercontent_views_default_views_alter(&$views) {
  $handler = &$views['mapping']->display['default']->handler;
  $handler->display->display_options['style_options']['default'] = 'gathercontent_project';
}