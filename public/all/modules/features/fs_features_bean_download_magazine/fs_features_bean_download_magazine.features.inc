<?php
/**
 * @file
 * fs_features_bean_download_magazine.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fs_features_bean_download_magazine_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function fs_features_bean_download_magazine_image_default_styles() {
  $styles = array();

  // Exported image style: bean_download_magazine_default.
  $styles['bean_download_magazine_default'] = array(
    'label' => 'Bean download magazine default',
    'effects' => array(
      19 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 150,
          'height' => 200,
          '#imageinfo_cache_effect_callback' => 'image_scale_and_crop_effect',
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
