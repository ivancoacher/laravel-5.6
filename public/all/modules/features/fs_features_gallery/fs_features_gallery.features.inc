<?php
/**
 * @file
 * fs_features_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fs_features_gallery_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function fs_features_gallery_image_default_styles() {
  $styles = array();

  // Exported image style: gallery_default_album.
  $styles['gallery_default_album'] = array(
    'label' => 'Gallery Default Album',
    'effects' => array(
      30 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 520,
          'height' => 330,
          '#imageinfo_cache_effect_callback' => 'image_scale_and_crop_effect',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: gallery_home_gallery.
  $styles['gallery_home_gallery'] = array(
    'label' => 'Gallery Home Gallery',
    'effects' => array(
      31 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 401,
          'height' => 230,
          '#imageinfo_cache_effect_callback' => 'image_scale_and_crop_effect',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: gallery_list_view.
  $styles['gallery_list_view'] = array(
    'label' => 'Gallery List View',
    'effects' => array(
      32 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 300,
          'height' => '',
          'upscale' => 0,
          '#imageinfo_cache_effect_callback' => 'image_scale_effect',
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function fs_features_gallery_node_info() {
  $items = array(
    'gallery' => array(
      'name' => t('Gallery'),
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
