<?php

/**
 * @file
 * Multistep mapping form.
 */

/**
 * DELETE MAPPING.
 */

/**
 * Delete mapping form.
 *
 * @inheritdoc
 */
function gathercontent_mapping_delete_form($form, &$form_state, $id) {
  $form = array();
  $form['id'] = array(
    '#type' => 'value',
    '#value' => $id,
  );

  return confirm_form(
    $form,
    t('Are you sure you want to delete this item?'),
    'admin/config/gathercontent/mapping',
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Submit callback for delete mapping form.
 *
 * @inheritdoc
 */
function gathercontent_mapping_delete_form_submit($form, &$form_state) {
  // @TODO: remove mapping from nodes, if used.
  entity_delete('gathercontent_mapping', $form_state['values']['id']);
  drupal_set_message(t('You removed mapping'));
  $form_state['redirect'] = 'admin/config/gathercontent/mapping';
}
