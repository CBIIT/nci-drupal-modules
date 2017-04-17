<?php

/**
 * @file
 * Multistep mapping form.
 */

use GatherContent\Project;
use GatherContent\Template;

/**
 * GatherContent template import.
 *
 * In this form, we load templates from Gather Content and create empty Mappings
 * for them.
 *
 * @inheritdoc
 */
function gathercontent_mapping_form_templates($form, &$form_state) {
  $pr_obj = new Project();
  $projects = $pr_obj->getProjects();

  $template_obj = new Template();

  $form = array();

  $form['description'] = array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#value' => t("Please select the GatherContent Templates you'd like to map. Only Templates you've not selected will be listed."),
    '#attributes' => array(
      'class' => array('description'),
    ),
  );

  $form['projects'] = array(
    '#type' => 'vertical_tabs',
  );

  foreach ($projects as $project_id => $project) {
    $remote_templates = $template_obj->getTemplates($project_id);
    $query = db_select('gathercontent_mapping', 'm')
      ->distinct()
      ->fields('m', array('gathercontent_template', 'gathercontent_template_id'))
      ->execute();
    $local_templates = $query->fetchAllKeyed(1, 0);

    $templates = array_diff_assoc($remote_templates, $local_templates);

    if (empty($templates)) {
      continue;
    }

    $form['p' . $project_id] = array(
      '#type' => 'fieldset',
      '#title' => $project,
      '#group' => 'projects',
      '#tree' => TRUE,
    );
    $form['p' . $project_id]['templates'] = array(
      '#type' => 'checkboxes',
      '#title' => $project,
      '#options' => $templates,
    );
  }

  $form['selected_templates_message'] = array(
    '#type' => 'gathercontent_checkboxcounter',
    '#counter_message_js_template' => array(
      '1 template selected',
      '@count templates selected',
    ),
    '#counter_message_default' => format_plural(0, '1 template selected', '@count templates selected'),
  );

  $form['actions'] = array(
    '#type' => 'actions',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Select'),
  );
  $form['actions']['close'] = array(
    '#type' => 'submit',
    '#value' => t('Close'),
  );

  return $form;
}

/**
 * Submit callback for Gather Content template import.
 *
 * @inheritdoc
 */
function gathercontent_mapping_form_templates_submit($form, &$form_state) {
  if ($form_state['triggering_element']['#id'] == 'edit-submit') {
    // Load all projects.
    $pr_obj = new Project();
    $projects = $pr_obj->getProjects();
    foreach ($form_state['values'] as $k => $tree) {
      if (!is_array($tree)) {
        continue;
      }
      $templates = array_filter($form_state['values'][$k]['templates']);
      foreach ($templates as $template_id => $selected) {
        $tmp_obj = new Template();
        $template = $tmp_obj->getTemplate($template_id);
        $mapping_values = array(
          'gathercontent_project_id' => $template->project_id,
          'gathercontent_project' => $projects[$template->project_id],
          'gathercontent_template_id' => $template_id,
          'gathercontent_template' => $template->name,
          'created' => time(),
          'updated_gathercontent' => $template->updated_at,
          'template' => serialize($template),
        );
        $mapping = entity_create('gathercontent_mapping', $mapping_values);
        if (is_object($mapping)) {
          $mapping->save();
        }
      }
    }
  }

  drupal_goto('admin/config/gathercontent/mapping');
}
