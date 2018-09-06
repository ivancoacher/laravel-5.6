<?php
/**
 * @file
 * fs_features_city.features.inc
 */

/**
 * Implements hook_node_info().
 */
function fs_features_city_node_info() {
  $items = array(
    'city' => array(
      'name' => t('City'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
