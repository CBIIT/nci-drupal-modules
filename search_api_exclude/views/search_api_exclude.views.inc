<?php

/**
 * @file
 * Views hooks implemented for the Search API Exclude module.
 */

/**
 * Implements hook_views_data().
 */
function search_api_exclude_views_data() {
  $data = array();

  $data['search_api_exclude']['table']['group'] = t('Search API Exclude');
  $data['search_api_exclude']['table']['base'] = array(
    'field' => 'nid', // This is the identifier field for the view.
    'title' => t('Search API Exclude'),
  );
  $data['search_api_exclude']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
      'type' => 'LEFT',
    ),
  );
  $data['search_api_exclude']['nid'] = array(
    'title' => t('Exclude status'),
    'help' => t('Whether or not the content is excluded from Search API.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
      'output formats' => array(
        'excluded-notexcluded' => array(t('Excluded'), t('Not excluded')),
      ),
    ),
    'filter' => array(
      'handler' => 'search_api_exclude_views_handler_filter_status',
      'label' => t('Excluded'),
      'type' => 'yes-no',
      'use equal' => TRUE, // Use status = 1 instead of status <> 0 in WHERE statment
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}