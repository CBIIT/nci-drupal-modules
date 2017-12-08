<?php

/**
 * Detaches an instance of a repeating date by cloning the node.
 */
function date_repeat_instance_edit($original_node, $field, $langcode, $delta) {
  global $user;

  // Clone the node and reset certain values.
  $node = clone $original_node;
  $node->nid = NULL;
  $node->vid = NULL;
  $node->created = NULL;
  $node->name = $user->name;
  $node->uid = $user->uid;
  $node->path = NULL;

  // Set page title.
  drupal_set_title(t('Detach: ') . $node->title);

  // Save the parameters for use in hook_form_alter().
  $node->date_repeat_instance = array(
    'original_nid' => $original_node->nid,
    'field' => $field,
    'langcode' => $langcode,
    'delta' => $delta,
  );

  // Unset all other dates.
  foreach (array_keys($node->{$field}[$langcode]) as $field_delta) {
    if ($field_delta != $delta) {
      unset($node->{$field}[$langcode][$field_delta]);
    }
  }

  // Move the instance of the detached date into position 0.
  $node->{$field}[$langcode][0] = $node->{$field}[$langcode][$delta];
  unset($node->{$field}[$langcode][$delta]);

  // Unset its repeating rule.
  $node->{$field}[$langcode][0]['rrule'] = NULL;

  // Render node form.
  module_load_include('inc', 'node', 'node.pages');
  return drupal_get_form($node->type .'_node_form', $node);
}

/**
 * Confirmation that instance of repeating date should be deleted.
 */
function date_repeat_instance_delete_confirm($form, $form_state, $node, $field, $langcode, $delta) {
  $form['node'] = array('#type' => 'value', '#value' => $node);
  $form['field'] = array('#type' => 'value', '#value' => $field);
  $form['langcode'] = array('#type' => 'value', '#value' => $langcode);
  $form['delta'] = array('#type' => 'value', '#value' => $delta);
  $date = new DateObject($node->{$field}[$langcode][$delta]['value']);
  $question = t('Are you sure you want to delete !date from the repeating date series?', array(
    '!date' => $date->format(DATE_FORMAT_DATE),
  ));
  $path = isset($_GET['destination']) ? $_GET['destination'] : "node/$node->nid";
  $form_state['redirect'] = $path;
  return confirm_form($form, $question, $path, NULL, t('Delete'), t('Cancel'));
}

/**
 * Confirmation submit handler which deletes the instance of a repeating date.
 */
function date_repeat_instance_delete_confirm_submit($form, &$form_state) {
  extract($form_state['values']);
  if ($confirm) {
    date_repeat_instance_set_exception($node, $field, $langcode, $delta);
  }
  $form_state['redirect'] = "node/$node->nid";
}
