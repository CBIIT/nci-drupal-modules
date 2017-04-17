<?php

/**
 * @file
 * Definition of views_handler_field_node_link_edit.
 */

/**
 * Field handler to present a link node edit.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_mapping_link_edit extends views_handler_field_node_link {

  /**
   * Renders the link.
   */
  function render_link($entity, $values) {

    if ($this->view->field['gathercontent_updated']->original_value !== 'Not accessible') {
      $this->options['alter']['make_link'] = TRUE;

      $this->options['alter']['path'] = "admin/config/gathercontent/mapping/$entity->id/edit";
      $this->options['alter']['query'] = drupal_get_destination();

      $text = !empty($this->options['text']) ? $this->options['text'] : (empty($entity->data) ? t('create') : t('edit'));
    }
    else {
      $text = '';
    }
    return $text;
  }
}