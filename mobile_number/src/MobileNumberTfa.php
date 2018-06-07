<?php

/**
 * @file
 * Contains MobileNumberTfa.
 */

/**
 * Class MobileNumberTfa is a validation and sending plugin for TFA.
 *
 * @package Drupal\mobile_number
 *
 * @ingroup mobile_number
 */
class MobileNumberTfa extends TfaBasePlugin implements TfaValidationPluginInterface, TfaSendPluginInterface {

  protected $mobileNumber;

  /**
   * MobileNumberTfa constructor.
   *
   * @param array $context
   *   Context array.
   *
   * @throws Exception
   */
  public function __construct(array $context) {
    parent::__construct($context);

    if (!empty($context['validate_context']) && !empty($context['validate_context']['code'])) {
      $this->code = $context['validate_context']['code'];
    }

    if (!empty($context['validate_context']) && !empty($context['validate_context']['verification_token'])) {
      $this->verificationToken = $context['validate_context']['verification_token'];
    }

    $this->codeLength = 4;

    if ($m = mobile_number_tfa_account_number($context['uid'])) {
      try {
        $this->mobileNumber = new MobileNumber($m);
      }
      catch (Exception $e) {
        throw new Exception("Two factor authentication failed: \n" . $e->getMessage(), $e->getCode());
      }
    }
  }

  /**
   * Determines whether TFA is applicable to the account.
   *
   * @return bool
   *   Is applicable.
   */
  public function ready() {
    return mobile_number_tfa_account_number($this->context['uid']) ? TRUE : FALSE;
  }

  /**
   * Begin TFA process.
   */
  public function begin() {
    if (!$this->code) {
      if (!$this->sendCode()) {
        drupal_set_message(t('Unable to deliver the code. Please contact support.'), 'error');
      }
    }
  }

  /**
   * Form callback.
   */
  public function getForm(array $form, array &$form_state) {

    $numberClue = str_pad(
      substr($this->mobileNumber->localNumber, -3, 3),
      strlen($this->mobileNumber->localNumber),
      'X',
      STR_PAD_LEFT);
    $numberClue = substr_replace($numberClue, '-', 3, 0);

    $form['code'] = array(
      '#type' => 'textfield',
      '#title' => t('Verification Code'),
      '#required' => TRUE,
      '#description' => t('A verification code was sent to %clue. Enter the @length-character code sent to your device.', array('@length' => $this->codeLength, '%clue' => $numberClue)),
    );
    $form['actions']['#type'] = 'actions';
    // @todo optionally report on when code was sent/delivered.
    $form['actions']['login'] = array(
      '#type' => 'submit',
      '#value' => t('Verify'),
    );
    $form['actions']['resend'] = array(
      '#type' => 'submit',
      '#value' => t('Resend'),
      '#submit' => array('tfa_form_submit'),
      '#limit_validation_errors' => array(),
    );

    return $form;
  }

  /**
   * Validate form callback.
   */
  public function validateForm(array $form, array &$form_state) {
    // If operation is resend then do not attempt to validate code.
    if ($form_state['values']['op'] === $form_state['values']['resend']) {
      return TRUE;
    }
    elseif (!$this->verifyCode($form_state['values']['code'])) {
      $this->errorMessages['code'] = t('Invalid code.');
      return FALSE;
    }
    else {
      return TRUE;
    }
  }

  /**
   * Submit form callback.
   */
  public function submitForm(array $form, array &$form_state) {
    // Resend code if pushed.
    if ($form_state['values']['op'] === $form_state['values']['resend']) {
      if (!$this->mobileNumber->checkFlood('sms')) {
        drupal_set_message(t('Too many verification code requests, please try again shortly.'), 'error');
      }
      elseif (!$this->sendCode()) {
        drupal_set_message(t('Unable to deliver the code. Please contact support.'), 'error');
      }
      else {
        drupal_set_message(t('Code resent'));
      }

      return FALSE;
    }
    else {
      return parent::submitForm($form, $form_state);
    }
  }

  /**
   * Return context for this plugin.
   */
  public function getPluginContext() {
    return array(
      'code' => $this->code,
      'verification_token' => !empty($this->verificationToken) ? $this->verificationToken : '',
    );
  }

  /**
   * Send the code via the client.
   *
   * @return bool
   *   Where sending sms was successful.
   */
  protected function sendCode() {
    $this->code = $this->mobileNumber->generateVerificationCode($this->codeLength);
    try {
      $message = variable_get('mobile_number_tfa_message', MOBILE_NUMBER_DEFAULT_SMS_MESSAGE);
      if (!($this->verificationToken = $this->mobileNumber->sendVerification($message, $this->code, array('user' => user_load($this->context['uid']))))) {
        return FALSE;
      }

      // @todo Consider storing date_sent or date_updated to inform user.
      watchdog('mobile_number_tfa', 'TFA validation code sent to user !uid', array(
        '!uid' => $this->context['uid'],
      ), WATCHDOG_INFO);
      return TRUE;

    }
    catch (Exception $e) {
      watchdog('mobile_number_tfa', 'Send message error to user !uid. Status code: @code, message: @message', array(
        '!uid' => $this->context['uid'],
        '@code' => $e->getCode(),
        '@message' => $e->getMessage(),
      ), WATCHDOG_ERROR);
      return FALSE;
    }
  }

  /**
   * Verifies the given code with this session's verification token.
   *
   * @param string $code
   *   Code.
   *
   * @return bool
   *   Verification status.
   */
  public function verifyCode($code) {
    return $this->isValid = $this->mobileNumber->verifyCode($code, $this->verificationToken);
  }

}
