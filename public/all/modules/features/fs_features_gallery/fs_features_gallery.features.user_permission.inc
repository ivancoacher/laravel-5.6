<?php
/**
 * @file
 * fs_features_gallery.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function fs_features_gallery_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_gallery_summary'.
  $permissions['create field_gallery_summary'] = array(
    'name' => 'create field_gallery_summary',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_gallery_tags'.
  $permissions['create field_gallery_tags'] = array(
    'name' => 'create field_gallery_tags',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_gallery_summary'.
  $permissions['edit field_gallery_summary'] = array(
    'name' => 'edit field_gallery_summary',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_gallery_tags'.
  $permissions['edit field_gallery_tags'] = array(
    'name' => 'edit field_gallery_tags',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_gallery_summary'.
  $permissions['edit own field_gallery_summary'] = array(
    'name' => 'edit own field_gallery_summary',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_gallery_tags'.
  $permissions['edit own field_gallery_tags'] = array(
    'name' => 'edit own field_gallery_tags',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_gallery_summary'.
  $permissions['view field_gallery_summary'] = array(
    'name' => 'view field_gallery_summary',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_gallery_tags'.
  $permissions['view field_gallery_tags'] = array(
    'name' => 'view field_gallery_tags',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_gallery_summary'.
  $permissions['view own field_gallery_summary'] = array(
    'name' => 'view own field_gallery_summary',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_gallery_tags'.
  $permissions['view own field_gallery_tags'] = array(
    'name' => 'view own field_gallery_tags',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
