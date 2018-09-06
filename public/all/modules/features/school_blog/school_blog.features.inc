<?php
/**
 * @file
 * school_blog.features.inc
 */

/**
 * Implements hook_node_info().
 */
function school_blog_node_info() {
  $items = array(
    'school_blog' => array(
      'name' => t('School Blog'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
