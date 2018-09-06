<?php

// todo : need optimize the code to reduce the loop.
module_load_include('inc', 'fs_base', 'fs_base');
module_load_include('inc', 'fs_elasticsearch', 'fs_elasticsearch');
function fs_search_event_list_page($city) {
  $path_family = drupal_get_path('theme', 'family');
  drupal_add_css($path_family . '/css/components/listing.css', array('group' => CSS_THEME));
  drupal_add_css($path_family . '/lib/bootstrap/css/bootstrap-select.min.css', array('group' => CSS_THEME));
  drupal_add_js($path_family . '/lib/bootstrap/js/bootstrap-select.min.js', array('scope' => 'header'));
  drupal_add_js(drupal_get_path('module', 'fs_search_event') . '/js/fs_search_event.js', array('scope' => 'footer'));

  $query_params = drupal_get_query_parameters();

  $city = strtolower(check_plain($city));
  $filters = fs_search_event_get_filters_from_query_params($query_params, $city);

  $timezone = new DateTimeZone('Asia/Shanghai');
  $default_preview_image = url(drupal_get_path('module', 'fs_search') . '/images/placeholder.jpg');

  // get category filters
  $category = fs_search_event_get_nested_category_tree();
  $count = 0;

  // $items_by_month = $temp['format'];
  $items = [];
  $items_data = [];
  // $timestamps_compare = $temp['timestamp'];

  $dates_filters = [];

  try {
    $elasticsearch = new FsElasticsearch();
    if (!isset($filters["date_start"])) {
      // events today is below 
      $query_in = fs_search_events_es_query_in_between($filters);
      $result_event_json_in_between = $elasticsearch->es_node_list($query_in, 'events');
      $result_event_in_between = drupal_json_decode($result_event_json_in_between);
      $result_events_in_list = $result_event_in_between['hits']['hits'];

      // events future
      $query = fs_search_events_es_query_future($filters);
      $result_event_json_future = $elasticsearch->es_node_list($query, 'events');
      $result_event_future = drupal_json_decode($result_event_json_future);
      $result_event_fu_list = $result_event_future['hits']['hits'];
      $result_items = array_merge($result_events_in_list, $result_event_fu_list);
      
    }
    else {
       //
      $query = fs_search_events_es_query_date($filters);
      $result_event_json = $elasticsearch->es_node_list($query, 'events');
      $result_event = drupal_json_decode($result_event_json);
      $result_items = $result_event['hits']['hits'];
    }
    // $list is the list of items you are paging through

    if (!empty($result_items)) {
      $count = sizeof($result_items);

      $per_page = 9;
      // Initialise the pager
      $current_page = pager_default_initialize($count, $per_page);
      $chunks = array_chunk($result_items, $per_page, TRUE);
      $items_unformat = $chunks[$current_page];
      foreach ($items_unformat as $result_item) {
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
        
        $item['url'] =  $result_item['_source']['url'];
        $item['type'] = $result_item['_source']['field_event_type'];
        $item['247_url'] = $result_item['_source']['field_247_link'];
        //reformat the items for frontend
        if (!empty($items_unformat)) {
          $items[] = theme('fs_search_event_event_list_view', ['item' => $item]);
        }
      }
    }
  }
  catch (Exception $e) {
    $message = $e->getMessage();
    $message .= "<br/>" . $e->getTraceAsString();
    watchdog('fs_search_event', $message, [], WATCHDOG_ERROR);
  }
  
  // Show the pager
  $pager = theme('pager', array('search_event', $count));
  //date filter bar
  $dates_filter_dates = [];

  $date = new DateTime('now', $timezone);

  $dates_filter_dates[] = $date->getTimestamp();
  $days = 6;
  for ($i = 1; $i <= $days; $i++) {
    $date->modify('+1 day');
    $dates_filter_dates[] = $date->getTimestamp();
  }

  $current_path = current_path();
  foreach ($dates_filter_dates as $dates_filter_date) {
    $dates_filter_item = [];
    $dates_filter_date_ob = new DateTime();
    $dates_filter_date_ob->setTimestamp($dates_filter_date);
    $dates_filter_item['count'] = 0;
    if (isset($items[$dates_filter_date])) {
      $dates_filter_item['count'] = count($items[$dates_filter_date]['items']);
    }

    $dates_filter_item['year'] = $dates_filter_date_ob->format('Y');
    $dates_filter_item['month'] = $dates_filter_date_ob->format('M');
    $dates_filter_item['day'] = $dates_filter_date_ob->format('d');
    $dates_filter_item['DAY'] = $dates_filter_date_ob->format('D');
    $dates_filter_filters = $filters;
    unset($dates_filter_filters['city']);
    $dates_filter_filters['date_start'] = $dates_filter_date_ob->format('Y-m-d') . ' 00:00:00';
    // $dates_filter_filters['date_end'] = $dates_filter_date_ob->format('Y-m-d') . ' 23:59:59';
    $dates_filter_item['url'] = url($current_path, ['query' => $dates_filter_filters]);
    $dates_filters[] = $dates_filter_item;
  }

  $form_variables = [];
  $form_variables['filters'] = $filters;

  $search_form = drupal_get_form('fs_search_event_list_page_form', $form_variables);

  $variables = [
    'city' => $city,
    'category' => $category,
    'dates_filters' => $dates_filters,
    'filters' => $filters,
    'items' => $items,
    'form' => render($search_form),
    'pager' => $pager,
    'count' => $count,
  ];
  // var_dump($items);die();
  return theme('fs_search_event_list_page', $variables);
}

function fs_search_event_list_page_form($form, &$form_state, $variables) {

  // $cid = fs_city_get_selected_city_id();
  $serialized_variables = serialize($variables['filters']);
  // $form['keyword'] = [
  //   '#type' => 'textfield',
  //   '#autocomplete_path' => "event/autocomplete/{$serialized_variables}",
  //   '#size' => 60,
  //   '#maxlength' => 128,
  //   '#required' => TRUE,
  //   '#default_value' => isset($variables['filters']['keyword']) ? $variables['filters']['keyword'] : '',
  // ];
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

function fs_search_event_list_page_form_submit($form, &$form_state) {
  // $city = $form_state['values']['city'];
  $variables = unserialize($form_state['values']['variables']);
  $options = [];
  if(!empty($form_state['values']['keyword'])) {
    $options['keyword'] = check_plain($form_state['values']['keyword']);
  }
  if(isset($variables['date_start']) && !empty($variables['date_start'])) {
    $options['date_start'] = check_plain($variables['date_start']);
  }
  if(isset($variables['date_end']) && !empty($variables['date_end'])) {
    $options['date_end'] = check_plain($variables['date_end']);
  }
  if(isset($variables['category']) && !empty($variables['category'])) {
    $options['category'] = check_plain($variables['category']);
  }
  $city = $variables['city'];
  $option['query'] = $options;
  drupal_goto($city . '/event', $option);
}
function fs_search_event_get_filters_from_query_params($query_params, $city) {
  $filters = [];
  if (isset($query_params['date_start'])) {
    $filters['date_start'] = $query_params['date_start'];
  }
  if (isset($query_params['date_end'])) {
    $filters['date_end'] = $query_params['date_end'];
  }
  if (isset($query_params['keyword'])) {
    $filters['keyword'] = $query_params['keyword'];
  }
  if (isset($query_params['category'])) {
    $filters['category'] = $query_params['category'];
  }
  if (isset($query_params['page'])) {
    $filters['page'] = $query_params['page'];
  }
  else {
    $filters['page'] = 0;
  }
  $filters['city'] = $city;
  return $filters;
}

function fs_search_event_get_nested_category_tree() {
    return fs_base_get_vocabulary_list_term_by_name("event_category");
}

function fs_search_events_es_query_in_between($filters) {
  $timezone = new DateTimeZone('Asia/Shanghai');
  $date_filter = new DateTime('now', $timezone);
  $elasticsearch = new FsElasticsearch();
  $elasticsearch->es_size_default();
  if (isset($filters["category"])) {
    // select all subcategory  
    $terms = taxonomy_get_children_all($filters["category"]);
    $elasticsearch->es_add_filter_multi_value("field_event_category.tid", array_keys($terms));
  }
  $elasticsearch->es_query["query"]["bool"]["must"][] = array(
    "range" => array("date_s_time" => array("lte" => $date_filter->getTimestamp())
    )
  );
  $elasticsearch->es_query["query"]["bool"]["must"][] = array(
    "range" => array("date_e_time" => array("gte" => $date_filter->getTimestamp())
    )
  );
 
  return $elasticsearch->es_query;
}

function fs_search_events_es_query_future($filters) {
  $timezone = new DateTimeZone('Asia/Shanghai');
  $date_filter = new DateTime('now', $timezone);
  $elasticsearch = new FsElasticsearch();
  $elasticsearch->es_size_default();
  if (isset($filters["category"])) {
    // select all subcategory  
    $terms = taxonomy_get_children_all($filters["category"]);
    $elasticsearch->es_add_filter_multi_value("field_event_category.tid", array_keys($terms));
  }
  $elasticsearch->es_query["query"]["bool"]["must"][] = array(
    "range" => array("date_s_time" => array("gte" => $date_filter->getTimestamp())
    )
  );
  $sort_array["date_s_time"] = "asc";
  $elasticsearch->es_sort_multi($sort_array);
  return $elasticsearch->es_query;
}

function fs_search_events_es_query_date($filters) {
  
  $elasticsearch = new FsElasticsearch();
  $elasticsearch->es_size_default();
  if (isset($filters["category"])) {
    // select all subcategory  
    $terms = taxonomy_get_children_all($filters["category"]);
    $elasticsearch->es_add_filter_multi_value("field_event_category.tid", array_keys($terms));
  }
  if (isset($filters["date_start"])) {
    $date_s = new DateTime($filters["date_start"]);

    $elasticsearch->es_query["query"]["bool"]["must"][] = array(
      "range" => array("date_s_time" => array("lte" => $date_s->getTimestamp())
      )
    );
    $elasticsearch->es_query["query"]["bool"]["must"][] = array(
      "range" => array("date_e_time" => array("gte" => $date_s->getTimestamp())
      )
    );
  }
 
  return $elasticsearch->es_query;
}
