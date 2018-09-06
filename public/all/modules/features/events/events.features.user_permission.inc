<?php
/**
 * @file
 * events.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function events_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_247_link'.
  $permissions['create field_247_link'] = array(
    'name' => 'create field_247_link',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_best_of'.
  $permissions['create field_event_best_of'] = array(
    'name' => 'create field_event_best_of',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_type'.
  $permissions['create field_event_type'] = array(
    'name' => 'create field_event_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_247_link'.
  $permissions['edit field_247_link'] = array(
    'name' => 'edit field_247_link',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_best_of'.
  $permissions['edit field_event_best_of'] = array(
    'name' => 'edit field_event_best_of',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_type'.
  $permissions['edit field_event_type'] = array(
    'name' => 'edit field_event_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_247_link'.
  $permissions['edit own field_247_link'] = array(
    'name' => 'edit own field_247_link',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_best_of'.
  $permissions['edit own field_event_best_of'] = array(
    'name' => 'edit own field_event_best_of',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_type'.
  $permissions['edit own field_event_type'] = array(
    'name' => 'edit own field_event_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_247_link'.
  $permissions['view field_247_link'] = array(
    'name' => 'view field_247_link',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_best_of'.
  $permissions['view field_event_best_of'] = array(
    'name' => 'view field_event_best_of',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_type'.
  $permissions['view field_event_type'] = array(
    'name' => 'view field_event_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_247_link'.
  $permissions['view own field_247_link'] = array(
    'name' => 'view own field_247_link',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_best_of'.
  $permissions['view own field_event_best_of'] = array(
    'name' => 'view own field_event_best_of',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_type'.
  $permissions['view own field_event_type'] = array(
    'name' => 'view own field_event_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
