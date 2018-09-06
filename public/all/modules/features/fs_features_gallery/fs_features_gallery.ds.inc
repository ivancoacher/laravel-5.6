<?php
/**
 * @file
 * fs_features_gallery.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function fs_features_gallery_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|gallery|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'gallery';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'gallery_default' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|gallery|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function fs_features_gallery_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'gallery_default';
  $ds_field->label = 'Gallery Default';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'gallery|default';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
print fs_gallery_ds_default($entity);
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['gallery_default'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function fs_features_gallery_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|gallery|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'gallery';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'gallery_default',
      ),
    ),
    'fields' => array(
      'gallery_default' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|gallery|default'] = $ds_layout;

  return $export;
}
