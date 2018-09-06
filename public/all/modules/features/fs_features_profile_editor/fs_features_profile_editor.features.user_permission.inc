<?php
/**
 * @file
 * fs_features_profile_editor.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function fs_features_profile_editor_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'edit any editor profile'.
  $permissions['edit any editor profile'] = array(
    'name' => 'edit any editor profile',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'edit own editor profile'.
  $permissions['edit own editor profile'] = array(
    'name' => 'edit own editor profile',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view any editor profile'.
  $permissions['view any editor profile'] = array(
    'name' => 'view any editor profile',
    'roles' => array(
      'School Manager' => 'School Manager',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view own editor profile'.
  $permissions['view own editor profile'] = array(
    'name' => 'view own editor profile',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'profile2',
  );

  return $permissions;
}
