<?php

namespace GatherContent;

use GuzzleHttp\Client;

/**
 * Class Template.
 *
 * @package GatherContent
 */
class Template {
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
   * Fetch projects from GatherContent.
   *
   * @return array
   *   Associative array of projects.
   */
  public function getTemplates($project_id) {
    $templates = array();

    try {
      $response = $this->client->get('/templates?project_id=' . $project_id);
      if ($response->getStatusCode() === 200) {
        $data = json_decode($response->getBody());
        foreach ($data->data as $template) {
          $templates[$template->id] = $template->name;
        }
      }
    }
    catch (\Exception $e) {
      drupal_set_message($e->getMessage(), 'error');
      watchdog('gathercontent', $e->getMessage(), array(), WATCHDOG_ERROR);
    }

    return $templates;
  }

  /**
   * Fetch projects from GatherContent.
   *
   * @return array
   *   Associative array of projects.
   */
  public function getTemplatesObject($project_id) {
    $templates = array();

    try {
      $response = $this->client->get('/templates?project_id=' . $project_id);
      if ($response->getStatusCode() === 200) {
        $data = json_decode($response->getBody());
        foreach ($data->data as $template) {
          $templates[$template->id] = $template;
        }
      }
    }
    catch (\Exception $e) {
      drupal_set_message($e->getMessage(), 'error');
      watchdog('gathercontent', $e->getMessage(), array(), WATCHDOG_ERROR);
    }

    return $templates;
  }

  /**
   * TBD.
   *
   * @param int $template_id
   *   ID of template.
   *
   * @return object
   *   Object of template
   */
  public function getTemplate($template_id) {
    $template = NULL;
    try {
      $response = $this->client->get('/templates/' . $template_id);
      if ($response->getStatusCode() === 200) {
        $data = json_decode($response->getBody());
        $template = $data->data;
      }
    }
    catch (\Exception $e) {
      drupal_set_message($e->getMessage(), 'error');
      watchdog('gathercontent', $e->getMessage(), array(), WATCHDOG_ERROR);
    }

    return $template;
  }

}
