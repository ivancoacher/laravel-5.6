<?php
/**
 * @file
 * fs_features_article.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function fs_features_article_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'win_articles';
  $view->description = 'This view shows all the Win Articles';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Win Articles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Win Articles';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['field_article_body']['id'] = 'field_article_body';
  $handler->display->display_options['fields']['field_article_body']['table'] = 'field_data_field_article_body';
  $handler->display->display_options['fields']['field_article_body']['field'] = 'field_article_body';
  $handler->display->display_options['fields']['field_article_body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['field_article_body']['settings'] = array(
    'trim_length' => '400',
  );
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_article_main_image']['id'] = 'field_article_main_image';
  $handler->display->display_options['fields']['field_article_main_image']['table'] = 'field_data_field_article_main_image';
  $handler->display->display_options['fields']['field_article_main_image']['field'] = 'field_article_main_image';
  $handler->display->display_options['fields']['field_article_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_article_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_article_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_article_main_image']['settings'] = array(
    'image_style' => 'article_trending_now_normal',
    'image_link' => 'content',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'specific_article_win_page');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  /* Filter criterion: Content: Win (field_article_win) */
  $handler->display->display_options['filters']['field_article_win_value']['id'] = 'field_article_win_value';
  $handler->display->display_options['filters']['field_article_win_value']['table'] = 'field_data_field_article_win';
  $handler->display->display_options['filters']['field_article_win_value']['field'] = 'field_article_win_value';
  $handler->display->display_options['filters']['field_article_win_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'shanghai/articles/win';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'specific_article_quick_read_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Quick Reads';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  /* Filter criterion: Content: Quick Read (field_article_quick_read) */
  $handler->display->display_options['filters']['field_article_quick_read_value']['id'] = 'field_article_quick_read_value';
  $handler->display->display_options['filters']['field_article_quick_read_value']['table'] = 'field_data_field_article_quick_read';
  $handler->display->display_options['filters']['field_article_quick_read_value']['field'] = 'field_article_quick_read_value';
  $handler->display->display_options['filters']['field_article_quick_read_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'shanghai/articles/quick-reads';
  $export['win_articles'] = $view;

  return $export;
}
