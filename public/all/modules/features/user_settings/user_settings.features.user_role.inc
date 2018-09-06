<?php
/**
 * @file
 * user_settings.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function user_settings_user_default_roles() {
  $roles = array();

  // Exported role: School Manager.
  $roles['School Manager'] = array(
    'name' => 'School Manager',
    'weight' => 2,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 4,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 3,
  );

  return $roles;
}
