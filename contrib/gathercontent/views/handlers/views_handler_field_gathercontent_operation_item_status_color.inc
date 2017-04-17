<?php

/**
 * Field handler to present a link to delete a mytype record.
 */
class views_handler_field_gathercontent_operation_item_status_color extends views_handler_field {

  function render($values) {
    return '<div style="width:20px; height: 20px; float: left; margin-right: 5px; background: ' .
    $values->gathercontent_operation_item_item_status_color . ';"></div>';
  }

}
