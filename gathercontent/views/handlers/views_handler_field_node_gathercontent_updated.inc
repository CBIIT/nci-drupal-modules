<?php

/**
 * Field handler to present a link to delete a mytype record.
 */
class views_handler_field_node_gathercontent_updated extends views_handler_field_date {

  function construct() {
    parent::construct();
    $this->additional_fields['gathercontent_id'] = 'gathercontent_id';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    // Load last updated time from remote server.
    $content = $this->view->field['gathercontent_status']->contents;
    $gathercontent_id = $values->{$this->aliases['gathercontent_id']};
    if (isset($content[$gathercontent_id]['gathercontent_updated'])) {
      $value = strtotime($content[$gathercontent_id]['gathercontent_updated']->date);

      $format = $this->options['date_format'];
      if (in_array($format, array(
        'custom',
        'raw time ago',
        'time ago',
        'today time ago',
        'raw time hence',
        'time hence',
        'raw time span',
        'time span',
        'raw time span',
        'inverse time span',
        'time span'
      ))) {
        $custom_format = $this->options['custom_date_format'];
      }

      if ($value) {
        $timezone = !empty($this->options['timezone']) ? $this->options['timezone'] : NULL;
        $time_diff = REQUEST_TIME - $value; // will be positive for a datetime in the past (ago), and negative for a datetime in the future (hence)
        switch ($format) {
          case 'raw time ago':
            return format_interval($time_diff, is_numeric($custom_format) ? $custom_format : 2);
          case 'time ago':
            return t('%time ago', array('%time' => format_interval($time_diff, is_numeric($custom_format) ? $custom_format : 2)));
          case 'today time ago':
            $second_format = $this->options['second_date_format'];
            $second_custom_format = $this->options['second_date_format_custom'];
            if (format_date(REQUEST_TIME, 'custom', 'Y-m-d', $timezone) == format_date($value, 'custom', 'Y-m-d', $timezone)) {
              return t('%time ago', array('%time' => format_interval($time_diff, is_numeric($custom_format) ? $custom_format : 2)));
            }
            elseif ($second_format == 'custom') {
              if ($second_custom_format == 'r') {
                return format_date($value, $second_format, $second_custom_format, $timezone, 'en');
              }
              return format_date($value, $second_format, $second_custom_format, $timezone);
            }
            else {
              return format_date($value, $this->options['second_date_format'], '', $timezone);
            }
          case 'raw time hence':
            return format_interval(-$time_diff, is_numeric($custom_format) ? $custom_format : 2);
          case 'time hence':
            return t('%time hence', array('%time' => format_interval(-$time_diff, is_numeric($custom_format) ? $custom_format : 2)));
          case 'raw time span':
            return ($time_diff < 0 ? '-' : '') . format_interval(abs($time_diff), is_numeric($custom_format) ? $custom_format : 2);
          case 'inverse time span':
            return ($time_diff > 0 ? '-' : '') . format_interval(abs($time_diff), is_numeric($custom_format) ? $custom_format : 2);
          case 'time span':
            return t(($time_diff < 0 ? '%time hence' : '%time ago'), array('%time' => format_interval(abs($time_diff), is_numeric($custom_format) ? $custom_format : 2)));
          case 'custom':
            if ($custom_format == 'r') {
              return format_date($value, $format, $custom_format, $timezone, 'en');
            }
            return format_date($value, $format, $custom_format, $timezone);
          default:
            return format_date($value, $format, '', $timezone);
        }
      }
    }
    else {
      return t('Not accessible');
    }
  }

}
