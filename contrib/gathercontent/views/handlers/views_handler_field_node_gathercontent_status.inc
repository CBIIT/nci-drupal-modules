<?php

/**
 * Field handler to present a link to delete a mytype record.
 */
class views_handler_field_node_gathercontent_status extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['gathercontent_id'] = 'gathercontent_id';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $gathercontent_id = isset($values->{$this->aliases['gathercontent_id']}) ? $values->{$this->aliases['gathercontent_id']} : NULL;
    if (isset($this->contents[$gathercontent_id]['status'])) {
      return '<div style="width:20px; height: 20px; float: left; margin-right: 5px; background: ' .
      $this->contents[$gathercontent_id]['status']->data->color . ';"></div>' .
      $this->contents[$gathercontent_id]['status']->data->name;
    }
    else {
      return t('Not accessible');
    }
  }

}
