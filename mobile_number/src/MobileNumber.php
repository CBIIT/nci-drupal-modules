<?php

/**
 * @file
 * Contains MobileNumber.
 */

require_once drupal_get_path('module', 'mobile_number') . '/include/mobile_number.libphonenumber.inc';

use libphonenumber\PhoneNumberUtil;
use libphonenumber\PhoneNumberFormat;

/**
 * Class MobileNumber handles mobile number validation and verification.
 *
 * @package Drupal\mobile_number
 *
 * @ingroup mobile_number
 */
class MobileNumber implements MobileNumberInterface {

  const ERROR_INVALID_NUMBER = 1;
  const ERROR_WRONG_TYPE = 2;
  const ERROR_WRONG_COUNTRY = 3;
  const ERROR_NO_NUMBER = 4;
  const VERIFY_WRONG_CODE = 5;
  const VERIFY_TOO_MANY_ATTEMPTS = 6;
  const VERIFY_SMS_FAILED = 7;
  const VERIFY_ATTEMPTS_COUNT = 5;
  const VERIFY_ATTEMPTS_INTERVAL = 3600;
  const SMS_ATTEMPTS_INTERVAL = 60;
  const SMS_ATTEMPTS_COUNT = 1;

  /**
   * The PhoneNumberUtil object.
   *
   * @var \libphonenumber\PhoneNumberUtil
   */
  public $libUtil;

  /**
   * The PhoneNumber object of the number.
   *
   * @var \libphonenumber\PhoneNumber
   */
  public $libPhoneNumber;

  /**
   * Country code.
   *
   * @var string
   */
  public $country;

  /**
   * The version of the number in the format local to the country.
   *
   * @var string
   */
  public $localNumber;

  /**
   * The international callable version of the number.
   *
   * @var string
   */
  public $callableNumber;

  /**
   * MobileNumber constructor.
   *
   * @param string $number
   *   Number.
   * @param null|string $country
   *   Country.
   * @param array $types
   *   Allowed phone number types.
   *
   * @throws \Exception
   */
  public function __construct($number, $country = NULL, $types = array(1 => 1, 2 => 2)) {

    if (!$number) {
      throw new \Exception('Empty number', $this::ERROR_NO_NUMBER);
    }

    $this->libUtil = PhoneNumberUtil::getInstance();

    try {
      $phone_number = $this->libUtil->parse($number, $country);
    }
    catch (\Exception $e) {
      throw new \Exception('Invalid number', $this::ERROR_INVALID_NUMBER);
    }

    if ($types) {
      if (!in_array($this->libUtil->getNumberType($phone_number), $types)) {
        throw new \Exception('Not a mobile number', $this::ERROR_WRONG_TYPE);
      }
    }
    
    $this->country = $this->libUtil->getRegionCodeForNumber($phone_number);
    
    $national_number = $phone_number->getNationalNumber();
    $prefix = $this->libUtil->getNddPrefixForRegion($this->country, TRUE);
    $this->localNumber = $prefix . $national_number;

    if ($country && $this->country != $country) {
      throw new \Exception('Wrong country', $this::ERROR_WRONG_COUNTRY);
    }

    $this->callableNumber = $this->libUtil->format($phone_number, PhoneNumberFormat::E164);
    $this->libPhoneNumber = $phone_number;
    $this->verificationToken = '';

  }

  /**
   * String typecasting.
   *
   * @return string
   *   Callable number.
   */
  public function __toString() {
    return $this->callableNumber;
  }

  /**
   * {@inheritdoc}
   */
  public function toArray() {
    return array(
      'callable_number' => $this->callableNumber,
      'country' => $this->country,
      'local_number' => $this->localNumber,
      'verified' => $this->isVerified(),
    );
  }

  /**
   * {@inheritdoc}
   */
  public static function getCountryCode($country) {
    $libUtil = PhoneNumberUtil::getInstance();
    return $libUtil->getCountryCodeForRegion($country);
  }

  /**
   * {@inheritdoc}
   */
  public static function getCountryOptions($filter = array(), $show_country_names = FALSE) {
    $libUtil = PhoneNumberUtil::getInstance();
    $regions = $libUtil->getSupportedRegions();
    $countries = array();

    foreach ($regions as $region => $country) {
      $code = $libUtil->getCountryCodeForRegion($country);
      if (!$filter || !empty($filter[$country])) {
        $name = MobileNumber::getCountryName($country);
        $countries[$country] = ($show_country_names && $name) ? "$name (+$code)" : "$country (+$code)";
      }
    }

    asort($countries);
    return $countries;
  }

  /**
   * {@inheritdoc}
   */
  public static function getCountryName($country) {
    include_once DRUPAL_ROOT . '/includes/locale.inc';
    $drupal_countries = country_get_list();
    return !empty($drupal_countries[$country]) ? $drupal_countries[$country] : '';
  }

  /**
   * {@inheritdoc}
   */
  public static function generateVerificationCode($length = 4) {
    return str_pad((string) rand(0, pow(10, $length)), $length, '0', STR_PAD_LEFT);
  }

  /**
   * {@inheritdoc}
   */
  public function checkFlood($type = 'verification') {
    switch ($type) {
      case 'verification':
        return flood_is_allowed('mobile_number_verification', $this::VERIFY_ATTEMPTS_COUNT, $this::VERIFY_ATTEMPTS_INTERVAL, $this->callableNumber);

      case 'sms':
        return flood_is_allowed('mobile_number_sms', $this::SMS_ATTEMPTS_COUNT, $this::SMS_ATTEMPTS_INTERVAL, $this->callableNumber) &&
        flood_is_allowed('mobile_number_sms_ip', $this::SMS_ATTEMPTS_COUNT * 5, $this::SMS_ATTEMPTS_INTERVAL * 5);

      default:
        return TRUE;
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getToken() {
    if (!empty($_SESSION['mobile_number_verification'][$this->callableNumber]['token'])) {
      return $_SESSION['mobile_number_verification'][$this->callableNumber]['token'];
    }

    return NULL;
  }

  /**
   * {@inheritdoc}
   */
  public function sendVerification($message, $code, $token_data = array()) {
    $message = t($message, array(
      '!code' => $code,
      '!site_name' => variable_get('site_name', $_SERVER['SERVER_NAME']),
    ));
    if (module_exists('token')) {
      $message = token_replace($message, $token_data);
    }

    flood_register_event('mobile_number_sms', $this::SMS_ATTEMPTS_INTERVAL, $this->callableNumber);
    flood_register_event('mobile_number_sms_ip', $this::SMS_ATTEMPTS_INTERVAL * 5);

    if (mobile_number_send_sms($this->callableNumber, $message)) {
      $token = $this->registerVerificationCode($code, $this->callableNumber);

      $_SESSION['mobile_number_verification'][$this->callableNumber] = array(
        'token' => $token,
        'verified' => FALSE,
      );

      return $token;
    }

    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public static function registerVerificationCode($code, $number) {
    $time = time();
    $token = drupal_get_token(rand(0, 999999999) . $time . 'mobile verification token' . $number);
    $hash = static::codeHash($token, $code, $number);

    db_insert('mobile_number_verification')
      ->fields(array(
        'token' => $token,
        'timestamp' => $time,
        'verification_code' => $hash,
      ))
      ->execute();

    return $token;
  }

  /**
   * {@inheritdoc}
   */
  public function verifyCode($code, $token = NULL) {
    if ($code && ($this->getToken() || $token)) {
      $token = $token ? $token : $this->getToken();
      $hash = $this->codeHash($token, $code, $this->callableNumber);
      $query = db_select('mobile_number_verification', 'm');
      $query->fields('m', array('token'))
        ->condition('token', $token)
        ->condition('timestamp', time() - (60 * 60 * 24), '>')
        ->condition('verification_code', $hash);
      $result = $query->execute()->fetchAssoc();

      if ($result) {
        $_SESSION['mobile_number_verification'][$this->callableNumber]['verified'] = TRUE;
        return TRUE;
      }

      flood_register_event('mobile_number_verification', $this::VERIFY_ATTEMPTS_INTERVAL, $this->callableNumber);

      return FALSE;
    }

    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function isVerified() {
    return !empty($_SESSION['mobile_number_verification'][$this->callableNumber]['verified']);
  }

  /**
   * {@inheritdoc}
   */
  public static function codeHash($token, $code, $number) {
    $secret = variable_get('mobile_number_secret', '');
    return sha1("$number$secret$token$code");
  }

}
