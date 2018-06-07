<?php

/**
 * @file
 * Mobile_number.resources.inc.
 */

require_once drupal_get_path('module', 'mobile_number') . '/include/mobile_number.libphonenumber.inc';

/**
 * Request mobile number verification code services resource callback.
 */
function _mobile_number_request_code($number, $country = NULL) {

  if (!mobile_number_sms_sending_is_enabled()) {
    return services_error(t('SMS functionality not enabled.'), MobileNumber::VERIFY_SMS_FAILED);
  }

  try {
    $mobile_number = new MobileNumber($number, $country);
    if (!$mobile_number->checkFlood('sms')) {
      return services_error(t('Too many attempts, try again later.'), 406);
    }
    if ($token = $mobile_number->sendVerification(MOBILE_NUMBER_DEFAULT_SMS_MESSAGE, $mobile_number->generateVerificationCode())) {
      return array('verification_token' => $token);
    }

    return services_error(t('Could not send verification code.'), 406);
  }
  catch (Exception $e) {
    return services_error(t($e->getMessage()), 406);
  }

}

/**
 * Verifies a mobile number.
 *
 * @param string $number
 *   The phone number to verify.
 * @param string $country
 *   (optional) The two-letter country code of the mobile number.  Can be NULL
 *   if the country is implied in the number.
 * @param string $code
 *   The code that was sent to the mobile number.
 * @param string $verification_token
 *   The token generated to go with the code.
 *
 * @return boolean
 *   TRUE on success, FALSE on failure.
 */
function mobile_number_resource_verify_number($number, $country = NULL, $code, $verification_token = NULL) {
  try {
    $mobile_number = new MobileNumber($number, $country);
    if (!$mobile_number->checkFlood()) {
      return services_error(t('Too many attempts, try again later.'), 406);
    }
    else {
      return $mobile_number->verifyCode($code, $verification_token);
    }
  }
  catch (Exception $e) {
    return services_error($e->getMessage(), 406);
  }
}
