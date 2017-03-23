<?php

/**
 * @file
 * Administration code.
 */

include_once "includes/Account.inc";

use GatherContent\Account;

/**
 * Callback function for gathercontent administration.
 *
 * @param array $form
 *   Array with form elements.
 * @param array $form_state
 *   Array with form values and state.
 *
 * @return array
 *   Array with form elements.
 */
function gathercontent_authentication_form($form, &$form_state) {
  $form = array();
  $form['gathercontent_username'] = array(
    '#type' => 'textfield',
    '#title' => t('GatherContent User Email Address'),
    '#required' => TRUE,
    '#default_value' => variable_get('gathercontent_username', ''),
    '#description' => t('This is the email address you use to login to 
    GatherContent. Your permissions will determine what accounts, 
    projects and content is available.'),
  );
  $form['gathercontent_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('GatherContent API key'),
    '#required' => TRUE,
    '#default_value' => variable_get('gathercontent_api_key', ''),
    '#description' => l(t('Click to find out where you can generate your API Key'),
      'https://gathercontent.com/developers/authentication/'),
  );

  if (!$form_state['submitted']) {
    $account = variable_get('gathercontent_account', array());
    if (!empty($account)) {
      $account = array_pop($account);
      $form['current_account'] = array(
        '#prefix' => '<div>',
        '#markup' => t('Current account is <strong>@account</strong>.', array('@account' => $account)),
        '#suffix' => '</div>',
      );
    }
  }

  if ($form_state['submitted']) {
    $account_obj = new Account();
    $data = $account_obj->getAccounts();
    $accounts = array();
    if (!is_null($data)) {
      foreach ($data as $account) {
        $accounts[$account->id] = $account->name;
      }

      $form['account'] = array(
        '#type' => 'select',
        '#options' => $accounts,
        '#title' => t('Select GatherContent Account'),
        '#required' => TRUE,
        '#description' => t('Multiple accounts will be listed if the GatherContent
       user has more than one account. Please select the account you want to
       import and update content from.'),
      );
    }
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => (is_null($data)) ? t('Verify') : t('Save'),
    );
  }
  else {
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => (!empty($account) ? t('Change GatherContent Account') : t('Verify')),
    );
  }

  if (!empty($account)) {
    $form['reset'] = array(
      '#type' => 'submit',
      '#value' => t('Reset credentials'),
    );
  }

  return $form;
}

/**
 * Submit callback for `gathercontent_authentication_form`.
 *
 * @param array $form
 *   Array with form elements.
 * @param array $form_state
 *   Array with form values and state.
 */
function gathercontent_authentication_form_submit($form, &$form_state) {
  if ($form_state['triggering_element']['#id'] === 'edit-submit') {
    if (!isset($form_state['values']['account'])) {
      variable_set('gathercontent_username', $form_state['values']['gathercontent_username']);
      variable_set('gathercontent_api_key', $form_state['values']['gathercontent_api_key']);
      $form_state['submitted'] = TRUE;
      $form_state['rebuild'] = TRUE;
    }
    else {
      $account_obj = new Account();
      $data = $account_obj->getAccounts();
      foreach ($data as $account) {
        if ($account->id === $form_state['values']['account']) {
          $account_name = $account->name;
          variable_set('gathercontent_urlkey', $account->slug);
          break;
        }
      }
      variable_set('gathercontent_account', array($form_state['values']['account'] => $account_name));
      drupal_set_message(t("Credentials and project were saved."));
    }
  }
  elseif ($form_state['triggering_element']['#id'] === 'edit-reset') {
    variable_del('gathercontent_username');
    variable_del('gathercontent_api_key');
    variable_del('gathercontent_account');
    variable_del('gathercontent_urlkey');
  }
}

/**
 * Page callback for connection testing page.
 *
 * @return string
 *   Content of the page.
 */
function gathercontent_authentication_test_page() {
  $acc_obj = new Account();
  $success = $acc_obj->testConnection();

  if ($success === TRUE) {
    return t('Connection successful');
  }
  else {
    return t("Connection wasn't successful");
  }
}
