<?php

/**
 * @file
 * Facebook Instant Articles theme hooks.
 */

/**
 * Implements hook_theme().
 */
function fb_instant_articles_views_theme($existing, $type, $theme, $path) {
  return array(
    'views_view_row_fia' => array(
      'variables' => array(
        'view' => NULL,
        'options' => array(),
        'row' => NULL,
      ),
      'path' => $path . '/theme',
      'template' => 'views-view-row-fia',
    ),
  );
}

/**
 * Templete preprocessor for FBIA views row theme hook.
 */
function template_preprocess_views_view_row_fia(&$vars) {
  $view = &$vars['view'];
  $options = &$vars['options'];
  $item = &$vars['row'];
  $vars['title'] = check_plain($item->title);
  $vars['subTitle'] = isset($item->node->field_article_sub_headline)?$item->node->field_article_sub_headline['und'][0]['value']:'';
  $vars['author'] = $item->elements['author'];
  $vars['link'] = check_url($item->link);
  $body = preg_replace("/(.*?)<p>\s*(<img[^<]+?)\s*<\/p>(.*)/", "$1$2$3", $item->node->field_article_body['und'][0]['value']);
  $vars['content'] = $body;
  $vars['date'] = $item->elements['pubDate'];
  $vars['main_image'] = file_create_url($item->node->field_article_main_image['und'][0]['uri']);
  $item->elements['guid'] = $item->node->nid;
  $vars['item_elements'] = empty($item->elements) ? '' : format_xml_elements($item->elements);
}
