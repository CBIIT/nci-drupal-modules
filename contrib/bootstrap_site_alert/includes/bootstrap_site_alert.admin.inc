<?php

/**
 * @file
 * The bootstrap_site_alert Admin Settings file.
 */

/**
 * Configuration Form for the site alerts.
 */
function bootstrap_site_alert_admin() {
  $form = array();

  $form['description'] = array(
    '#markup' => t('<h3>Use this form to setup the bootstrap site alert.</h3>
                  <p>Make sure you select the checkbox if you want to turn the alerts on</p>'),
  );

  $form['bootstrap_site_alert_active'] = array(
    '#type' => 'checkbox',
    '#title' => t('If Checked, Bootstrap Site Alert is Active.'),
    '#default_value' => variable_get('bootstrap_site_alert_active', FALSE),
  );

  $form['bootstrap_site_alert_severity'] = array(
    '#type' => 'select',
    '#title' => t('Severity'),
    '#options' => array(
      'alert-success' => t('Success'),
      'alert-info' => t('Info'),
      'alert-warning' => t('Warning'),
      'alert-danger' => t('Danger'),
    ),
    '#empty_option' => t('- SELECT -'),
    '#default_value' => variable_get('bootstrap_site_alert_severity', NULL),
    '#required' => TRUE,
  );

  $form['bootstrap_site_alert_dismiss'] = array(
    '#type' => 'checkbox',
    '#title' => t('Make this alert dismissable?'),
    '#default_value' => variable_get('bootstrap_site_alert_dismiss', FALSE),
  );

  // Need to load the text_format default a little differently.
  $message = variable_get('bootstrap_site_alert_message', array('value' => '', 'format' => NULL));

  $form['bootstrap_site_alert_message'] = array(
    '#type' => 'text_format',
    '#title' => t('Alert Message'),
    '#default_value' => $message['value'],
    '#required' => TRUE,
  );

  $form['#submit'][] = 'bootstrap_site_alert_custom_submit';

  return system_settings_form($form);
}

/**
 * Additional Submit callback for settings form.
 */
function bootstrap_site_alert_custom_submit() {
  // Clear the page cache to make sure the message is seen.
  cache_clear_all('*', 'cache_page', TRUE);

  // Save a random key so that we can use it to track a 'dismiss' action for
  // this particular alert.
  variable_set('bootstrap_site_alert_key', drupal_random_key());
}
