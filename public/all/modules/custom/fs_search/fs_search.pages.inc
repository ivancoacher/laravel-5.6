<?php

//TODO: now this page not support school very well, should change from root to have better performance.
module_load_include('inc', 'fs_elasticsearch', 'fs_elasticsearch');

function fs_city_search_result_page($city) {
  $path_family = drupal_get_path('theme', 'family');
  drupal_add_css($path_family . '/css/components/listing.css', array('group' => CSS_THEME));
  drupal_add_css(drupal_get_path('module', 'fs_taxonomy') . '/css/article.css', array('group' => CSS_THEME));
  drupal_add_css($path_family . '/css/components/search.css', array('group' => CSS_THEME));

  $params_query = drupal_get_query_parameters();
  $params = $params_query;
  $params['city'] = $city;

  $items = [];
  $count = 0;

  try {
   
    $elasticsearch = new FsElasticsearch();
    $query_in = fs_search_es_query($params);
    if (isset($params['type']) && $params['type'] == 'all') {
      $result_json = $elasticsearch->es_node_list($query_in);
   }else{
      $result_json = $elasticsearch->es_node_list($query_in, $params['type']);
   }
  
    $result = drupal_json_decode($result_json);
    $count = $result['hits']['total'];
 

    // $list is the list of items you are paging through
    $per_page = 9;
    // Initialise the pager
    $current_page = pager_default_initialize($count, $per_page);

    $from = $current_page * $per_page;
    $size = $per_page;
    $resultItems = $result['hits']['hits'];

    foreach ($resultItems as $resultItem) {
      $source = $resultItem['_source'];
  
      switch ($resultItem['_type']) {
        case 'article':
          $item = fs_city_search_result_get_article($resultItem);
          $items[] = theme('fs_city_search_result_article', ['item' => $item]);
          break;
          case 'events' :
          $item = fs_city_search_result_get_event($resultItem);
          $variables = [
            'item' => $item,
          ];
          $items[] = theme('fs_city_search_result_event', $variables);
          break;
        case 'listings':
          $item = fs_city_search_result_get_listing($resultItem);
          $items[] = theme('fs_city_search_result_listing', ['item' => $item]);
          break;
        case 'schools':
          $item = fs_city_search_result_get_listing($resultItem);
          $items[] = theme('fs_city_search_result_listing', ['item' => $item]);
          break;
      }
    }
  }
  catch (Exception $e) {
    $message = $e->getMessage();
    $message .= "<br/>" . $e->getTraceAsString();
    watchdog('fs_search', $message, [], WATCHDOG_ERROR);
  }

  //filter
  $current_page = current_path();
  $keyword = isset($params_query['keyword']) ? $params_query['keyword'] : NULL;
  $type = isset($params_query['type']) ? $params_query['type'] : NULL;
  $filter_all_active = ($type == 'all') ? 'active' : '';

  $link_all = [
    'title' => t('All'),
    'href' => $current_page,
    'attributes' => [
      'class' => [$filter_all_active],
    ],
    'query' => [
      'type' => 'all',
    ],
  ];
  if (!is_null($keyword)) {
    $link_all['query']['keyword'] = $keyword;
  }

  $filter_links[] = $link_all;

  $filter_article_active = ($type == 'article') ? 'active' : '';
  $link_article = [
    'title' => t('Article'),
    'href' => $current_page,
    'attributes' => [
      'class' => [$filter_article_active],
    ],
    'query' => [
      'type' => 'article',
    ],
  ];
  if (!is_null($keyword)) {
    $link_article['query']['keyword'] = $keyword;
  }

  $filter_links[] = $link_article;

  $filter_listing_active = ($type == 'listings') ? 'active' : '';
  $link_listing = [
    'title' => t('Listing'),
    'href' => $current_page,
    'attributes' => [
      'class' => [$filter_listing_active],
    ],
    'query' => [
      'type' => 'listings',
    ],
  ];
  if (!is_null($keyword)) {
    $link_listing['query']['keyword'] = $keyword;
  }

  $filter_links[] = $link_listing;

  $filter_event_active = ($type == 'events') ? 'active' : '';
  $link_event = [
    'title' => t('Event'),
    'href' => $current_page,
    'attributes' => [
      'class' => [$filter_event_active],
    ],
    'query' => [
      'type' => 'events',
    ],
  ];
  if (!is_null($keyword)) {
    $link_event['query']['keyword'] = $keyword;
  }

  $filter_links[] = $link_event;

  $pager = theme('pager', array('search_global', $count));

  $variables = [
    'items' => $items,
    'pager' => $pager,
    'filter_links' => $filter_links,
    'count' => $count,
    'keyword' => $keyword,
  ];

  return theme('fs_city_search_result_page', $variables);
}

function fs_search_autocomplete($cid) {

  $elasticsearch = new FsElasticsearch();
  $fields = array("title");
  $keyword = check_plain($_GET['term']);
  $elasticsearch->es_query(array());
  $elasticsearch->es_search($fields, $keyword);
  $query = $elasticsearch->es_query;
  $result_roots = drupal_json_decode($elasticsearch->es_node_list($query));
  $result_items = $result_roots['hits']['hits'];

  $suggestions = [];
  if (!empty($result_items)) {
    foreach ($result_items as $result_item) {
      $source = $result_item['_source'];
      $suggestion['label'] = $source['title'];
      $suggestion['value'] = $source['title'];
      $suggestion['id'] = $source['nid'];
      switch ($result_item["_type"]) {
        case 'listings':
          $suggestion['url'] = url('directory/' . $source['id'], ['absolute' => TRUE]);
          break;
        case 'schools':
          $suggestion['url'] = url('school/' . $source['id'], ['absolute' => TRUE]);
          break;
        case 'events':
          $suggestion['url'] = url('event/' . $source['id'], ['absolute' => TRUE]);
          break;
        case 'article':
          $suggestion['url'] = url('node/' . $source['id'], ['absolute' => TRUE]);
          break;
      }

      $suggestions[] = $suggestion;
    }
  }
  else {
    $suggestion['label'] = t('No result found...');
    $suggestion['value'] = t('No result found...');

    $suggestions[] = $suggestion;
  }

  drupal_json_output($suggestions);
}

function fs_city_search_result_get_article($resultItem) {
  $source = $resultItem['_source'];
  $default_preview_image = url(drupal_get_path('module', 'fs_search') . '/images/placeholder.jpg');
  $item = $source;
  $item['summary'] = $source['field_article_body'];
  $item['date'] = $source['created'];
  $item['author'] = $source['author'];
  $author = user_load($source["uid"]);
  $profile = profile2_load_by_user($author, 'editor');
  global $base_url;
  $path_theme = $base_url . "/" . drupal_get_path('theme', 'family');
  if (isset($profile->field_pe_photo['und'][0]['uri'])) {
      $item['author_picture'] = image_style_url('editor_thumbnail', $profile->field_pe_photo['und'][0]['uri']);
  }
  else {
      $item['author_picture'] = $path_theme . "/images/default.jpeg";     
  }
  $item['author_url'] = "/profile-editor/" . $source['uid'];
  $item['url'] = url('node/' . $item['nid']);
    if (empty($source['field_article_main_image'])) {
        $item['preview_image'] = $default_preview_image;
    }
    else {
        //$item['preview_image'] = image_style_url("event_item",$source['field_article_main_image']);
        $item['preview_image'] = image_style_url('medium',$source['field_article_main_image']);
    }    
  return $item;
}
function fs_city_search_result_get_event($result_item){
    $default_preview_image = url(drupal_get_path('module', 'fs_search') . '/images/placeholder.jpg');
    $item = [];
    // set variables
    $item['nid'] = $result_item['_source']['nid'];
    $item['title'] = $result_item['_source']['title'];
    if ($result_item['_source']['field_editor_description']) {
        $item['summary'] = $result_item['_source']['field_editor_description'];
    }
    else {
        $item['summary'] = $result_item['_source']['field_contributor_description'];
    }

    if (empty($result_item['_source']['field_main_image'])) {
        $item['preview_image'] = $default_preview_image;
    }
    else {
        $item['preview_image'] = image_style_url("event_item",$result_item['_source']['field_main_image']);
    }
    if (isset($result_item['_source']['field_date'][0])) {
        $item['date_start_s'] = $result_item['_source']['field_date'][0]['date_start'];
        $item['date_end_s'] = $result_item['_source']['field_date'][0]['date_end'];
    }
    else {
        $item['date_start_s'] = $result_item['_source']['field_date']['date_start'];
        $item['date_end_s'] = $result_item['_source']['field_date']['date_end'];
    }
    $date_start = new DateTime($item['date_start_s'].'+00');
    $date_start->setTimezone(new DateTimeZone('Asia/Shanghai'));
    $date_end = new DateTime($item['date_end_s'].'+00');
    $date_end->setTimezone(new DateTimeZone('Asia/Shanghai'));
    $item['time_start_s'] = $date_start->format('H:i');
    $item['time_end_s'] = $date_end->format('H:i');
    $item['type'] = $result_item['_source']['field_event_type'];
    $item['247_url'] = $result_item['_source']['field_247_link'];

    $item['url'] =  $result_item['_source']['url'];
    return $item;
}

/**
 * @param $source
 *
 * @return mixed
 */
function fs_city_search_result_get_listing($resultItem) {
  $source = $resultItem['_source'];
  module_load_include('inc', 'fs_search_school', 'fs_search_school');
  $default_preview_image = url(drupal_get_path('module', 'fs_search') . '/images/placeholder.jpg');
 
    $item['summary'] = $source['field_editor_description'];
    $item['title'] = $source['title'];
    $item['url'] =  $source['url'];
    if (empty($source['field_main_image'])) {
        $item['preview_image'] = $default_preview_image;
    }
    else {
        $item['preview_image'] = image_style_url("event_item",$source['field_main_image']);
    }
  return $item;
}
function fs_search_es_query($filter){
  $elasticsearch = new FsElasticsearch();
  $elasticsearch->es_query($filter);
  if (isset($filter['keyword'])) {
    $fields =array("title");  
    $elasticsearch->es_search($fields, $filter['keyword']);
  }
 
  return $elasticsearch->es_query;
}