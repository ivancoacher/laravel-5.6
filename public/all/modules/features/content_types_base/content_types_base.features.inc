<?php
/**
 * @file
 * content_types_base.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function content_types_base_image_default_styles() {
  $styles = array();

  // Exported image style: event_item.
  $styles['event_item'] = array(
    'label' => 'Event Item',
    'effects' => array(
      34 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 220,
          '#imageinfo_cache_effect_callback' => 'image_scale_and_crop_effect',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: fs_home_slider_image.
  $styles['fs_home_slider_image'] = array(
    'label' => 'fs home slider image 596x366',
    'effects' => array(
      26 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 596,
          'height' => 366,
          '#imageinfo_cache_effect_callback' => 'image_scale_and_crop_effect',
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
