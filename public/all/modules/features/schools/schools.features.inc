<?php
/**
 * @file
 * schools.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function schools_image_default_styles() {
  $styles = array();

  // Exported image style: fs_school_main_image.
  $styles['fs_school_main_image'] = array(
    'label' => 'fs school main image 612x362',
    'effects' => array(
      25 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 612,
          'height' => 362,
          '#imageinfo_cache_effect_callback' => 'image_scale_and_crop_effect',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: fs_school_video_gallery.
  $styles['fs_school_video_gallery'] = array(
    'label' => 'fs_school_video_gallery_500x326',
    'effects' => array(
      27 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 500,
          'height' => 326,
          '#imageinfo_cache_effect_callback' => 'image_scale_and_crop_effect',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: fs_school_video_gallery_220x150.
  $styles['fs_school_video_gallery_220x150'] = array(
    'label' => 'fs_school_video_gallery_220x150',
    'effects' => array(
      26 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 500,
          'height' => 326,
          '#imageinfo_cache_effect_callback' => 'image_scale_and_crop_effect',
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
function schools_node_info() {
  $items = array(
    'schools' => array(
      'name' => t('School'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('School Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
