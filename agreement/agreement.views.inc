<?php

/**
 * @file
 * Agreement views info.
 */

/**
 * Implements hook_views_data().
 */
function agreement_views_data() {
  $data = array();
  $data['agreement']['table']['group'] = t('User');

  $data['agreement']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
      'type' => 'left',
    ),
  );

  $data['agreement']['agreed_date'] = array(
    'title'   => t('Agreement date'),
    'help'    => t('The date the agreement was submitted.'),
    'field'   => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter'  => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort'    => array(
      'handler' => 'views_handler_sort_date',
    ),
  );

  $data['agreement_type']['table']['group'] = t('Agreement');
  $data['agreement_type']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Agreement type'),
    'help' => t('Agreement type information.'),
    'weight' => 0,
  );

  $data['agreement_type']['table']['join'] = array(
    'agreement' => array(
      'left_field' => 'type',
      'field' => 'name',
      'type' => 'left',
    ),
  );

  $data['agreement_type']['name'] = array(
    'title' => t('Name'),
    'help' => t('The agreement type machine name.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click_sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'view_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['agreement_type']['title'] = array(
    'title' => t('Label'),
    'help' => t('The agreement type label'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click_sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'view_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['agreement_type']['path'] = array(
    'title' => t('Path'),
    'help' => t('The path that the agreement uses.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click_sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'view_handler_sort',
    ),
  );

  return $data;
}
