<?php

/**
 * @file
 *   Contains administration forms.
 */

/**
 * Administration form for each bundle.
 */
function auto_nodetitle_settings_form($form, $form_state, $entity_type, $bundle_arg) {
  $entity = entity_get_info($entity_type);
  $bundle_name = isset($bundle_arg->{$entity['bundle keys']['bundle']}) ? $bundle_arg->{$entity['bundle keys']['bundle']} : $bundle_arg;
  $key = $entity_type . '_' . $bundle_name;
  $default_value = auto_nodetitle_get_setting($key);
  $form['auto_nodetitle'] = array(
    '#type' => 'fieldset',
    '#title' => t('Automatic title generation'),
    '#weight' => 0,
    /*'#attached' => array( //Not needed anymore at the moment.
      'js' => array(
        'auto-nodetitle' => drupal_get_path('module', 'auto_nodetitle') . '/auto_nodetitle.js',
      ),
    ),*/
  );
  $form['auto_nodetitle']['ant_'.$key] = array(
    '#type' => 'radios',
    '#default_value' => $default_value,
    '#options' => array(
      t('Disabled'),
      t('Automatically generate the title and hide the title field'),
      t('Automatically generate the title if the title field is left empty'),
    )
  );
  $form['auto_nodetitle']['ant_pattern_'.$key] = array(
    '#type' => 'textarea',
    '#title' => t('Pattern for the title'),
    '#description' => t('Leave blank for using the per default generated title. Otherwise this string will be used as title. Use the syntax [token] if you want to insert a replacement pattern.'),
    '#default_value' => variable_get('ant_pattern_' . $key, ''),
  );
  // Don't allow editing of the pattern if PHP is used, but the users lacks
  // permission for PHP.
  if (variable_get('ant_php_' . $key, '') && !user_access('use PHP for title patterns')) {
    $form['auto_nodetitle']['ant_pattern_'.$key]['#disabled'] = TRUE;
    $form['auto_nodetitle']['ant_pattern_'.$key]['#description'] = t('You are not allow the configure the pattern for the title, as you lack the %permission permission.', array('%permission' => t('Use PHP for title patterns')));
  }
  $entity_tokens = module_invoke_all('auto_nodetitle_entity_tokens');
  // Display the list of available placeholders if token module is installed.
  if (module_exists('token')) {
    $form['auto_nodetitle']['token_help'] = array(
      '#theme' => 'token_tree',
      '#token_types' => isset($entity_tokens[$entity_type])?array($entity_tokens[$entity_type]):array($entity_type),
    );
  }


  $form['auto_nodetitle']['ant_php_'.$key] = array(
    '#access' => user_access('use PHP for title patterns'),
    '#type' => 'checkbox',
    '#title' => t('Evaluate PHP in pattern.'),
    '#description' => t('Put PHP code above that returns your string, but make sure you surround code in <code>&lt;?php</code> and <code>?&gt;</code>. Note that <code>$entity</code> and <code>$language</code> are available and can be used by your code.'),
    '#default_value' => variable_get('ant_php_' . $key, ''),
  );
  return system_settings_form($form);
}