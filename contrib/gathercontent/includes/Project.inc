<?php

namespace GatherContent;

use GuzzleHttp\Client;


class Project {
  private $client;

  private $local;

  /**
   * Account constructor.
   *
   * @param string $username
   *   API username.
   * @param string $api_key
   *   API key.
   * @param bool $local
   *   Indicates, if we will need to have client object.
   */
  public function __construct($username = NULL, $api_key = NULL, $local = FALSE) {
    $this->local = $local;
    if (!$local) {
      if (is_null($username)) {
        $username = variable_get('gathercontent_username', '');
      }

      if (is_null($api_key)) {
        $api_key = variable_get('gathercontent_api_key', '');
      }

      if (empty($username) || empty($api_key)) {
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
  }

  /**
   * Fetch projects from GatherContent.
   *
   * @return array
   *   Associative array of projects.
   */
  public function getProjects() {
    if (!$this->local) {
      $account = variable_get('gathercontent_account', array());
      $projects = array();

      reset($account);
      $account_id = key($account);

      try {
        $response = $this->client->get('/projects?account_id=' . $account_id);
        if ($response->getStatusCode() === 200) {
          $data = json_decode($response->getBody());
          foreach ($data->data as $project) {
            if ($project->active) {
              $projects[$project->id] = $project->name;
            }
          }
        }
      }
      catch (\Exception $e) {
        drupal_set_message($e->getMessage(), 'error');
        watchdog('gathercontent', $e->getMessage(), array(), WATCHDOG_ERROR);
      }

      return $projects;
    }
    else {
      drupal_set_message(t('Error occured, please contact your system administrator'), 'error');
      watchdog('gathercontent', 'Object Project created as local, but trying to reach remote data.', NULL, WATCHDOG_ALERT);
    }
  }

  /**
   * Fetch projects from GatherContent.
   *
   * @return array
   *   Associative array of projects.
   */
  public function getProjectObjects() {
    if (!$this->local) {
      $account = variable_get('gathercontent_account', array());
      $projects = array();

      reset($account);
      $account_id = key($account);

      try {
        $response = $this->client->get('/projects?account_id=' . $account_id);
        if ($response->getStatusCode() === 200) {
          $data = json_decode($response->getBody());
          foreach ($data->data as $project) {
            if ($project->active) {
              $projects[$project->id] = $project;
            }
          }
        }
      }
      catch (\Exception $e) {
        drupal_set_message($e->getMessage(), 'error');
        watchdog('gathercontent', $e->getMessage(), array(), WATCHDOG_ERROR);
      }

      return $projects;
    }
    else {
      drupal_set_message(t('Error occured, please contact your system administrator'), 'error');
      watchdog('gathercontent', 'Object Project created as local, but trying to reach remote data.', NULL, WATCHDOG_ALERT);
    }
  }

  /**
   * Description.
   *
   * @param int $project_id
   *   Project ID.
   *
   * @return array
   *   Description.
   */
  public function getStatuses($project_id) {
    if (!$this->local) {
      try {
        $response = $this->client->get('/projects/' . $project_id . '/statuses');
        if ($response->getStatusCode() === 200) {
          $data = json_decode($response->getBody());
          return $data->data;
        }
      }
      catch (\Exception $e) {
        drupal_set_message($e->getMessage(), 'error');
        watchdog('gathercontent', $e->getMessage(), array(), WATCHDOG_ERROR);
      }
    }
    else {
      drupal_set_message(t('Error occured, please contact your system administrator'), 'error');
      watchdog('gathercontent', 'Object Project created as local, but trying to reach remote data.', NULL, WATCHDOG_ALERT);
    }
  }

  /**
   * Description.
   *
   * @param int $project_id
   *   Project ID.
   *
   * @param int $status_id
   *   Status ID.
   *
   * @return array
   *   Description.
   */
  public function getStatus($project_id, $status_id) {
    if (!$this->local) {
      try {
        $response = $this->client->get('/projects/' . $project_id . '/statuses/' . $status_id);
        if ($response->getStatusCode() === 200) {
          $data = json_decode($response->getBody());
          return $data->data;
        }
      }
      catch (\Exception $e) {
        drupal_set_message($e->getMessage(), 'error');
        watchdog('gathercontent', $e->getMessage(), array(), WATCHDOG_ERROR);
      }
    }
    else {
      drupal_set_message(t('Error occured, please contact your system administrator'), 'error');
      watchdog('gathercontent', 'Object Project created as local, but trying to reach remote data.', NULL, WATCHDOG_ALERT);
    }
  }
}
