<?php
/**
 * @file
 * fs_features_bean_dfp.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function fs_features_bean_dfp_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|dfp|default';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'dfp';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'bean_dfp_default' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['bean|dfp|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function fs_features_bean_dfp_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'bean_dfp_default';
  $ds_field->label = 'Bean dfp default';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'bean' => 'bean',
  );
  $ds_field->ui_limit = 'dfp|default';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
print fs_dfp_ds_default($entity);
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['bean_dfp_default'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function fs_features_bean_dfp_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|dfp|default';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'dfp';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'bean_dfp_default',
      ),
    ),
    'fields' => array(
      'bean_dfp_default' => 'ds_content',
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
  $export['bean|dfp|default'] = $ds_layout;

  return $export;
}
