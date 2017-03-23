<?php

/**
 * @file
 * Definition of views_handler_field_mapping_link_edit.
 */

/**
 * Field handler to present a link node edit.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_mapping_link_delete extends views_handler_field_node_link {

  /**
   * Renders the link.
   */
  function render_link($entity, $values) {
    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = "admin/config/gathercontent/mapping/$entity->id/delete";
    $this->options['alter']['query'] = drupal_get_destination();

    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    return $text;
  }

}
