<?php

module_load_include('inc', 'fs_base', 'fs_base');
module_load_include('inc', 'fs_elasticsearch', 'fs_elasticsearch');

function fs_search_directory_list_page($city) {


  drupal_add_css(drupal_get_path('theme', 'family') . '/css/components/listing.css', array('group' => CSS_THEME));

  drupal_add_js('http://webapi.amap.com/maps?v=1.3&key=265b2136b0c369e4cded2a18d7662236', 'external');
  drupal_add_js('http://cache.amap.com/lbs/static/addToolbar.js', 'external');

  drupal_add_css(drupal_get_path('theme', 'family') . '/lib/bootstrap/css/bootstrap-select.min.css', array('group' => CSS_THEME));
  drupal_add_js(drupal_get_path('theme', 'family') . '/lib/bootstrap/js/bootstrap-select.min.js', array('scope' => 'footer'));
  drupal_add_js(drupal_get_path('module', 'fs_search_directory') . '/js/fs_search_directory.js', array('scope' => 'footer'));
  drupal_add_js(variable_get("path_theme", NULL) . '/lib/amap/amap.js', array('scope' => 'footer'));

  $query_params = drupal_get_query_parameters();

  $filters = fs_search_directory_get_filters_from_query_params($query_params, $city);


  $city = strtolower(check_plain($city));
  $category = fs_search_directory_get_nested_category_tree();
  $neighbourhood = fs_search_directory_get_nested_neighbourhood_tree();
  $count = 0;
  $items = [];
  $items_source = [];
  try { 
    $elasticsearch = new FsElasticsearch();
    $query = fs_search_directory_es_query($filters);
    $result_json = $elasticsearch->es_node_list($query, 'listings');
    $result_s = drupal_json_decode($result_json);
    $count = $result_s['hits']['total'];
    $per_page = 9;
    $current_page = pager_default_initialize($count, $per_page);

    $from = $current_page * $per_page;
    $size = $per_page;
    $result_items = $result_s['hits']['hits'];
    //var_dump($result_items);
    $json_directory = "var json_directory=[";
    $i = 0;
    $default_preview_image = variable_get("default_image"); //url(drupal_get_path('module', 'fs_search') . '/images/placeholder.jpg');   
    foreach ($result_items as $result_item){
      $item = [];
      $item['nid'] = $result_item['_source']['nid'];
      $item['title'] = $result_item['_source']['title'];
      if ($result_item['_source']["field_editor_description"]) {
        $item['summary'] = $result_item['_source']['field_editor_description'];
      }
      else{
        $item['summary'] = $result_item['_source']['field_contributor_description'];
      }
      // $item['summary'] = $result_item['_source']['contributor_description'];
  
      
      if (empty($result_item['_source']['field_main_image'])) {
        $item['preview_image'] = $default_preview_image;
      }
      else {
        $url = image_style_url("event_item",$result_item['_source']['field_main_image']); 
        $item['preview_image'] = $url;
      }
  
      $item['url'] = url(drupal_get_path_alias('node/' . $item['nid']));
      $img = $item['preview_image'];
      $lat = (isset($result_item['_source']['field_map']['lat']))?$result_item['_source']['field_map']['lat']:0;
      $lon = (isset($result_item['_source']['field_map']['lon']))?$result_item['_source']['field_map']['lon']:0;
      $json_directory .= "{'lat':'" . $lat . "','long':'" . $lon . "','img':'" . $img . "','url':'" . $item['url'] . "'},";
      $item_source = $result_item['_source'];
      $items_source[] = $item_source;
      $items[] = theme('fs_search_directory_directory_list_view', ['item' => $item]);
      $i++;    
    }
    $json_directory .= "];";
    drupal_add_js($json_directory, array('type' => 'inline'));
  }
  catch (Exception $e) {
    $message = $e->getMessage();
    $message .= "<br/>" . $e->getTraceAsString();
    watchdog('fs_event', $message, [], WATCHDOG_ERROR);
  }

  $form_variables = [
    'filters' => [],
  ];
  if (isset($filters['city'])) {
    $form_variables['filters']['city'] = $filters['city'];
  }

  if (isset($filters['keyword'])) {
    $form_variables['filters']['keyword'] = $filters['keyword'];
  }
  $search_form = drupal_get_form('fs_search_directory_search_from', $form_variables);

  // Show the pager
  $pager = theme('pager', array('directory_search', $count));

  $variables = [
    'city' => $city,
    'category' => $category,
    'neighbourhood' => $neighbourhood,
    'filters' => $filters,
    'items' => $items,
    'count' => $count,
    'items_source' => $items_source,
    // 'form' => render($filters_form),
    'search_form' => render($search_form),
    'pager' => $pager,
  ];

  return theme('fs_search_directory_list_page', $variables);
}

/*
  function fs_search_directory_list_page_form($form, &$form_state, $variables) {

  if (isset($variables['filters']['keyword'])) {
  unset($variables['filters']['keyword']);
  }
  $form['variables'] = [
  '#type' => 'hidden',
  '#value' => serialize($variables['filters']),
  ];

  $form['submit'] = [
  '#type' => 'submit',
  '#value' => t('Search'),
  ];

  return $form;
  }

  function fs_search_directory_list_page_form_submit($form, &$form_state) {
  // $city = $form_state['values']['city'];

  $variables = unserialize($form_state['values']['variables']);
  // $variables['keyword'] = check_plain($form_state['values']['keyword']);

  $city = $variables['city'];

  //remove some filters.
  unset($variables['city']);
  unset($variables['keyword']);

  $option['query'] = $variables;

  drupal_goto($city . '/directory', $option);
  }
 */

function fs_search_directory_search_from($form, &$form_state, $variables) {
  $serialized_variables = serialize($variables['filters']);

  $form['keyword'] = [
    '#type' => 'textfield',
    '#autocomplete_path' => "directory/autocomplete/{$serialized_variables}",
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
    '#attributes' => array('class' => array('auto_submit')),
    '#default_value' => isset($variables['filters']['keyword']) ? $variables['filters']['keyword'] : '',
  ];

  $form['variables'] = [
    '#type' => 'hidden',
    '#value' => serialize($variables['filters']),
  ];

  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t('Search'),
  ];

  return $form;
}

function fs_search_directory_search_from_submit($form, &$form_state) {
  $variables = unserialize($form_state['values']['variables']);

  $city = $variables['city'];

  $option['query'] = array(
    'keyword' => $form_state['values']['keyword'],
  );

  drupal_goto($city . '/directory', $option);
}

function fs_search_directory_get_filters_from_query_params($query_params, $city) {
  $filters = [];
  if (isset($query_params['category'])) {
    $filters['category'] = $query_params['category'];
  }
  if (isset($query_params['neighbourhood'])) {
    $filters['neighbourhood'] = $query_params['neighbourhood'];
  }
  if (isset($query_params['keyword']) && !empty($query_params['keyword'])) {
    $filters['keyword'] = $query_params['keyword'];
  }
  if (isset($query_params['page']) && !empty($query_params['page'])) {
    $filters['page'] = $query_params['page'];
  }
  $filters['city'] = $city;

  return $filters;
}

function fs_search_directory_get_nested_category_tree() {
  return fs_base_get_vocabulary_list_term_by_name("listing_category");
}
function fs_search_directory_get_nested_neighbourhood_tree() {
  return fs_base_get_vocabulary_list_term_by_name("neighborhood");
}
function fs_search_directory_autocomplete($variables, $keyword) {
  $variables = unserialize($variables);
  $variables['keyword'] = $keyword;
  $elasticsearch = new FsElasticsearch();
  $fields = array("title");
  $elasticsearch->es_query(array());
  $elasticsearch->es_search($fields, $keyword);
  $query = $elasticsearch->es_query ;
  $result_items = drupal_json_decode($elasticsearch->es_node_list($query, 'listings'));
  $result_items = $result_items['hits']['hits'];
  
  if (!empty($result_items)) {  
    foreach ($result_items as $result_item){
      $title = $result_item['_source']['title'];
      $suggest[$title] = $title;
    }    
  }else{
    $suggest[$keyword] = t('No Result found.');
  }
  drupal_json_output($suggest);
}

function fs_search_directory_es_query($filter) {
  $elasticsearch = new FsElasticsearch();
  $elasticsearch->es_query($filter); //default query
//  if (!empty($filter['neighbourhood'])) {
//    $elasticsearch->es_query['query']['bool']['must'][] = array(
//      'match' => array(
//        'field_neighborhood.tid' => $filter['neighbourhood'][0],
//      )
//    );
//  }
  if (isset($filter['keyword'])) {
    $fields =array("title");  
    $elasticsearch->es_search($fields, $filter['keyword']);
  }else{
      $sort["title"]="asc";
      $elasticsearch->es_sort_multi($sort);
    
  }
  if (!empty($filter['category'])) {
    $elasticsearch->es_add_filter('field_listing_category.tid', $filter['category'][0]);
  }
  if (!empty($filter['neighbourhood'])) {
    $elasticsearch->es_add_filter('field_neighborhood.tid', $filter['neighbourhood'][0]);
  }

  return ($elasticsearch->es_query);
}
