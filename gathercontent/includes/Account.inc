<?php

/**
 * @file
 * Contains GatherContent\Accont class.
 */

namespace GatherContent;


use GuzzleHttp\Client;

/**
 * Class Account.
 *
 * @package GatherContent
 */
class Account {

  private $client;

  /**
   * Account constructor.
   *
   * @param string $username
   *   API username.
   * @param string $api_key
   *   API key.
   */
  public function __construct($username = NULL, $api_key = NULL) {
    if (is_null($username)) {
      $username = variable_get('gathercontent_username', '');
    }

    if (is_null($api_key)) {
      $api_key = variable_get('gathercontent_api_key', '');
    }

    if (empty($username || $api_key)) {
      watchdog('gathercontent', "Trying to call API without credentials.", array(), WATCHDOG_ERROR);
    }

    $this->client = new Client(
      array(
        'base_url' => 'https://api.gathercontent.com',
        'defaults' => array(
          'auth' => array(
            $username,
            $api_key,
          ),
          'headers' => array(
            'Accept' => 'application/vnd.gathercontent.v0.5+json',
          ),
        ),
      )
    );

  }

  /**
   * Get list of accounts.
   *
   * @return array
   *   Array with accounts.
   */
  public function getAccounts() {
    $accounts = array();

    try {
      $response = $this->client->get('/accounts');

      if ($response->getStatusCode() === 200) {
        $data = json_decode($response->getBody());
        $accounts = $data->data;
      }
      else {
        drupal_set_message(t("User with provided credentials wasn't found."), 'error');
        $accounts = NULL;
      }
    }
    catch (\Exception $e) {
      watchdog('gathercontent', $e->getMessage(), array(), WATCHDOG_ERROR);
      drupal_set_message(t("User with provided credentials wasn't found."), 'error');
      $accounts = NULL;
    }

    return $accounts;
  }

  /**
   * Test connection with current credentials.
   *
   * @return bool
   *   Return TRUE on success connection otherwise FALSE.
   */
  public function testConnection() {
    try {
      $response = $this->client->get('/me');

      if ($response->getStatusCode() === 200) {
        return TRUE;
      }
      else {
        return FALSE;
      }
    }
    catch (\Exception $e) {
      return FALSE;
    }
  }

}
