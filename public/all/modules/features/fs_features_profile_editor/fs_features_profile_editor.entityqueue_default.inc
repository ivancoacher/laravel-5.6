<?php
/**
 * @file
 * fs_features_profile_editor.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function fs_features_profile_editor_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'meet_the_editors';
  $queue->label = 'Meet the editors';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'user';
  $queue->settings = array(
    'target_bundles' => array(
      'user' => 'user',
    ),
    'min_size' => '0',
    'max_size' => '0',
    'act_as_queue' => 1,
  );
  $export['meet_the_editors'] = $queue;

  return $export;
}
