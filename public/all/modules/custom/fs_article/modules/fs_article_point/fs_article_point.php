<?php

/**
 * @file
 * Handles counts of node views via Ajax with minimal bootstrap.
 */

/**
 * Root directory of Drupal installation.
 */
define('DRUPAL_ROOT', substr($_SERVER['SCRIPT_FILENAME'], 0, strpos($_SERVER['SCRIPT_FILENAME'], '/sites/all/modules/custom/fs_article/modules/fs_article_point/fs_article_point.php')));
// Change the directory to the Drupal root.
chdir(DRUPAL_ROOT);

include_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_VARIABLES);

if (isset($_POST['nid'])) {
  $nid = $_POST['nid'];
  if (is_numeric($nid)) {
    db_merge('fs_article_point')
      ->key(array('nid' => $nid))
      ->fields(array(
        'point' => 3,
        'timestamp' => REQUEST_TIME,
      ))
      ->expression('point', 'point + 3')
      ->execute();
  }
}