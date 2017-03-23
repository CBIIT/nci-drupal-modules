<?php

/**
 * Field handler to present a link to delete a mytype record.
 */
class views_handler_field_node_gathercontent_title extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['gathercontent_id'] = 'gathercontent_id';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $gathercontent_id = $values->{$this->aliases['gathercontent_id']};
    return isset($this->view->field['gathercontent_status']->contents[$gathercontent_id]['name']) ? $this->view->field['gathercontent_status']->contents[$gathercontent_id]['name'] : t('Not accessible');
  }

}
