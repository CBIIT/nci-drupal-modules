<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'icon' => 'icon_node_form.png',
  'title' => t('Search API exclude information'),
  'description' => t('Search API exclude information on the Node form.'),
  'required context' => new ctools_context_required(t('Form'), 'node_form'),
  'category' => t('Form'),
);

function search_api_exclude_node_form_search_api_exclude_content_type_render($subtype, $conf, $panel_args, &$context) {
  $block = new stdClass();
  $block->module = t('node_form');

  $block->title = t('Search API exclude information');
  $block->delta = 'search_api_exclude-options';

  if (isset($context->form)) {
    if (!empty($context->form['search_api_exclude'])) {
      $block->content['search_api_exclude'] = $context->form['search_api_exclude'];
      if (isset($block->content['search_api_exclude']['#group'])) {
        unset($block->content['search_api_exclude']['#pre_render']);
        unset($block->content['search_api_exclude']['#theme_wrappers']);
      }

      // Set access to false on the original rather than removing so that
      // vertical tabs doesn't clone it. I think this is due to references.
      $context->form['search_api_exclude']['#access'] = FALSE;
    }
  }
  else {
    $block->content = t('Search API exclude information.');
  }
  return $block;
}

function search_api_exclude_node_form_search_api_exclude_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s" Search API exclude information', array('@s' => $context->identifier));
}

function search_api_exclude_node_form_search_api_exclude_content_type_edit_form($form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
  return $form;
}
