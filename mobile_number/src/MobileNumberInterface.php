<?php

/**
 * @file
 * MobileNumberInterface.
 */

/**
 * Provides an interface for defining mobile numbers.
 *
 * @ingroup mobile_number
 */
interface MobileNumberInterface {

  /**
   * Gets the country phone number prefix given a country code.
   *
   * @param string $country
   *   Country code (Eg. IL).
   *
   * @return int
   *   Country phone number prefix (Eg. 972).
   */
  public static function getCountryCode($country);

  /**
   * Gets the country name a country code.
   *
   * @param string $country
   *   Country code (Eg. IL).
   *
   * @return int
   *   Country display name.
   */
  public static function getCountryName($country);

  /**
   * Checks whether there were too many verifications attempted with the current number.
   *
   * @param string $type
   *   Type of flood check, can be either 'sms' or 'verification'.
   *
   * @return bool
   *   FALSE for too many attempts on this mobile number, TRUE otherwise.
   */
  public function checkFlood($type = 'verification');

  /**
   * Gets token generated if verification code was sent.
   *
   * @return string|NULL
   *   A drupal token (43 characters).
   */
  public function getToken();

  /**
   * Generates a random numeric string.
   *
   * @param int $length
   *   Number of digits.
   *
   * @return string
   *   Code in length of $length.
   */
  public static function generateVerificationCode($length = 4);

  /**
   * Registers code for mobile number and returns it's token.
   *
   * @param string $code
   *   Access code.
   * @param string $number
   *   Phone number string.
   *
   * @return string
   *   43 character token.
   */
  public static function registerVerificationCode($code, $number);

  /**
   * Get all supported countries.
   *
   * @param array $filter
   *   Limit options to the ones in the filter. (Eg. ['IL' => 'IL', 'US' => 'US'].
   * @param bool $show_country_names
   *   Whether to show full country name instead of country codes.
   *
   * @return array
   *   Array of options, with country code as keys. (Eg. ['IL' => 'IL (+972)'])
   */
  public static function getCountryOptions($filter = array(), $show_country_names = FALSE);

  /**
   * Verifies input code matches code sent to user.
   *
   * @param string $code
   *   Input code.
   * @param string|NULL $token
   *   Verification token, if verification code was not sent in this session.
   *
   * @return bool
   *   TRUE if matches
   */
  public function verifyCode($code, $token = NULL);

  /**
   * Send verification code to mobile number.
   *
   * @param string $message
   *   Drupal translatable string.
   * @param string $code
   *   Code to send.
   * @param array $token_data
   *   Token variables to be used with token_replace().
   *
   * @return bool
   *   Success flag.
   */
  public function sendVerification($message, $code, $token_data = array());

  /**
   * Is the number already verified.
   *
   * @return bool`
   *   TRUE if verified.
   */
  public function isVerified();

  /**
   * Generate hash given token and code.
   *
   * @param string $token
   *   Token.
   * @param string $code
   *   Verification code.
   * @param string $number
   *   Phone number.
   *
   * @return string
   *   Hash string.
   */
  public static function codeHash($token, $code, $number);

  /**
   * Converts object to an array.
   *
   * @return array
   *   Array with the following elements:
   *   - callable_number
   *   - country
   *   - local_number
   *   - verified.
   */
  public function toArray();

}
