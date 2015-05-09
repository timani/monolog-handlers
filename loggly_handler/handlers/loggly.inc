<?php


/**
 * @file
 * Handler include for LogglyHandler.
 */

use Monolog\Handler\LogglyHandler;

/**
 * Monolog loader callback; Loads a LogglyHandler handler.
 *
 * @return HandlerInterface
 */
function monolog_loggly_handler_loader($options) {
  return new LogglyHandler($options['token'], $options['level'], $options['bubble']);
}

/**
 * Monolog settings form; Settings for the LogglyHandler handler.
 */
function monolog_loggly_handler_settings(&$form, &$form_state, $profile, array $handler) {
  $form['token'] = array(
    '#title' => t('API token'),
    '#type' => 'textfield',
    '#default_value' => $handler['token'],
    '#description' => t('The Loggly token for the application.'),
  );
}