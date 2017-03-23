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
class views_handler_field_gathercontent_operation_item_gathercontent_link extends views_handler_field_node_link {

  /**
   * Renders the link.
   */
  function render_link($entity, $values) {
    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = 'http://' . variable_get('gathercontent_urlkey') . '.gathercontent.com/item/' . $entity->gathercontent_id;

    $text = !empty($this->options['text']) ? $this->options['text'] : t('Open');
    return $text;
  }

}
