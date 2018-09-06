<?php
/**
 * @file
 * listings.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function listings_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_closed'.
  $permissions['create field_closed'] = array(
    'name' => 'create field_closed',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_closed'.
  $permissions['edit field_closed'] = array(
    'name' => 'edit field_closed',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_closed'.
  $permissions['edit own field_closed'] = array(
    'name' => 'edit own field_closed',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_closed'.
  $permissions['view field_closed'] = array(
    'name' => 'view field_closed',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_closed'.
  $permissions['view own field_closed'] = array(
    'name' => 'view own field_closed',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
