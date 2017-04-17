<?php

/**
 * Import configuration form.
 *
 * {@inheritdoc}
 */
function gathercontent_import_config_form($form, &$form_state) {
  $form['node_default_status'] = array(
    '#type' => 'radios',
    '#required' => TRUE,
    '#title' => t('Node default status'),
    '#default_value' => variable_get('node_default_status', 1),
    '#options' => array(
      0 => t('Unpublished'),
      1 => t('Published'),
    ),
  );

  $form['gathercontent_node_update_method'] = array(
    '#type' => 'radios',
    '#required' => TRUE,
    '#title' => t('Content update method'),
    '#default_value' => variable_get('gathercontent_node_update_method', 'always_update'),
    '#options' => array(
      'always_create' => t('Always create new Content'),
      'update_if_not_changed' => t('Create new Content if it has changed since the last import'),
      'always_update' => t('Always update existing Content'),
    ),
  );
  return system_settings_form($form);
}