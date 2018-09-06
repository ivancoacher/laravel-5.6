<?php
/**
 * @file
 * fs_features_bean_dfp.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fs_features_bean_dfp_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}
