<?php
/**
 * @file
 * content_types_base.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function content_types_base_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_editor_description'.
  $permissions['create field_editor_description'] = array(
    'name' => 'create field_editor_description',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_editor_description'.
  $permissions['edit field_editor_description'] = array(
    'name' => 'edit field_editor_description',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_editor_description'.
  $permissions['edit own field_editor_description'] = array(
    'name' => 'edit own field_editor_description',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_editor_description'.
  $permissions['view field_editor_description'] = array(
    'name' => 'view field_editor_description',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_editor_description'.
  $permissions['view own field_editor_description'] = array(
    'name' => 'view own field_editor_description',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
