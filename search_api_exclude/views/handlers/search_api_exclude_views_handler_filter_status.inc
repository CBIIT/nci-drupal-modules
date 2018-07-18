<?php

/**
 * @file
 * Definition of search_api_exclude_views_handler_filter_status.
 */

/**
 * Filter by Search API exclude status.
 *
 * @ingroup views_filter_handlers
 */
class search_api_exclude_views_handler_filter_status extends views_handler_filter_boolean_operator {
  /**
   *
   */
  function query() {
    $table = $this->ensure_my_table();
    if ($this->value == 1) {
      $this->query->add_where_expression($this->options['group'], "$table.nid IS NOT NULL");
    }
    elseif ($this->value == 0) {
      $this->query->add_where_expression($this->options['group'], "$table.nid IS NULL");
    }
  }

}
