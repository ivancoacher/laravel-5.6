<?php
/**
 * @file
 * fs_features_bean_download_magazine.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function fs_features_bean_download_magazine_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'download_magazine';
  $bean_type->label = 'Download magazine';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['download_magazine'] = $bean_type;

  return $export;
}
