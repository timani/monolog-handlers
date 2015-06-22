<?php


/**
 * @file
 * Handler include for NewRelicHandler.
 */

use Monolog\Handler\NewRelicHandler;

/**
 * Monolog loader callback; Loads a NewRelicHandler handler.
 *
 * @return HandlerInterface
 */
function monolog_newrelic_handler_loader($options) {
  return new NewRelicHandler($options['level'], $options['bubble'], $options['app_name']);
}

/**
 * Monolog settings form; Settings for the NewRelicHandler handler.
 */
function monolog_newrelic_handler_settings(&$form, &$form_state, $profile, array $handler) {
  $form['app_name'] = array(
    '#title' => t('app_name to monitor'),
    '#type' => 'textfield',
    '#default_value' => $handler['app_name'],
    '#description' => t('The app_name for New Relic to monitor.'),
    '#required' => TRUE,
  );
}
