<?php
/**
 * @file
 * listings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function listings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function listings_node_info() {
  $items = array(
    'listings' => array(
      'name' => t('Listing'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Venue Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
