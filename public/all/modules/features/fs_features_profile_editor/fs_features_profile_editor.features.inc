<?php
/**
 * @file
 * fs_features_profile_editor.features.inc
 */

/**
 * Implements hook_entityqueue_api().
 */
function fs_features_profile_editor_entityqueue_api($module = NULL, $api = NULL) {
  if ($module == "entityqueue" && $api == "entityqueue_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function fs_features_profile_editor_image_default_styles() {
  $styles = array();

  // Exported image style: editor_thumbnail.
  $styles['editor_thumbnail'] = array(
    'label' => 'Editor thumbnail',
    'effects' => array(
      16 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 200,
          '#imageinfo_cache_effect_callback' => 'image_scale_and_crop_effect',
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_default_profile2_type().
 */
function fs_features_profile_editor_default_profile2_type() {
  $items = array();
  $items['editor'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "editor",
    "label" : "Editor",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 1 },
    "rdf_mapping" : []
  }');
  return $items;
}
