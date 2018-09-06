<?php

module_load_include('inc', 'fs_base', 'fs_base');
module_load_include('inc', 'fs_elasticsearch', 'fs_elasticsearch');
module_load_include('inc', 'fs_search_school', 'fs_search_school.pages');

function fs_search_school_list_page_json($city = 'shanghai') {
  $path_family = drupal_get_path('theme', 'family');
  $path_school = drupal_get_path('module', 'fs_search_school');
  drupal_add_css($path_family . '/css/components/listing.css', array('group' => CSS_THEME));
  drupal_add_css($path_family . '/css/components/compare_school.css', array('group' => CSS_THEME));

  drupal_add_css($path_family . '/lib/bootstrap/css/bootstrap-select.min.css', array('group' => CSS_THEME));

  drupal_add_css($path_family . '/lib/bootstrap/css/bootstrap-slider.min.css', array('group' => CSS_THEME));
  drupal_add_js($path_family . '/lib/cookie.js/cookie.min.js', array('scope' => 'header'));

  drupal_add_js($path_family . '/lib/bootstrap/js/bootstrap-slider.min.js', array('scope' => 'header'));
  drupal_add_js($path_family . '/lib/bootstrap/js/bootstrap-select.min.js', array('scope' => 'header'));
  drupal_add_js($path_school . '/js/fs_search_school.js', array('scope' => 'footer'));

  $query_params = drupal_get_query_parameters();
  if (!isset($query_params['search_type'])) {
    $query_params['search_type'] = 'fuzzy';
  }
  $filters = fs_search_school_get_filters_from_query_params($query_params, $city);

  $count = 0;
  $items = [];

  //$sections = fs_search_school_get_sections($city);

  try {
    $elasticsearch = new FsElasticsearch();
    $query_in = fs_search_school_es_query($filters);
    $result_school_json = $elasticsearch->es_node_list($query_in, 'schools');
    $result_school = drupal_json_decode($result_school_json);
    $count = $result_school['hits']['total'];
    // var_dump(drupal_json_encode($query_in));
    //var_dump($result_school_json);die();
    // $list is the list of items you are paging through
    $per_page = 4;
    // Initialise the pager
    $current_page = pager_default_initialize($count, $per_page);

    $from = $current_page * $per_page;
    $size = $per_page;


    $result_items = $result_school['hits']['hits'];
    $default_preview_image = url(drupal_get_path('module', 'fs_search') . '/images/placeholder.jpg');


    foreach ($result_items as $result_item) {
      $item = [];
      $item = fs_search_school_item($result_item);
      $items[] = $item;
    }
  }
  catch (Exception $e) {
    $message = $e->getMessage();
    $message .= "<br/>" . $e->getTraceAsString();
    watchdog('fs_search_school', $message, [], WATCHDOG_ERROR);
  }
  drupal_json_output(array('items' => $items, 'filters' => $filters));
}


function fs_search_school_list_page($city) {
  $path_family = drupal_get_path('theme', 'family');
  $path_school = drupal_get_path('module', 'fs_search_school');
  drupal_add_css($path_family . '/css/components/listing.css', array('group' => CSS_THEME));
  drupal_add_css($path_family . '/css/components/compare_school.css', array('group' => CSS_THEME));

  drupal_add_css($path_family . '/lib/bootstrap/css/bootstrap-select.min.css', array('group' => CSS_THEME));

  drupal_add_css($path_family . '/lib/bootstrap/css/bootstrap-slider.min.css', array('group' => CSS_THEME));
  drupal_add_js($path_family . '/lib/cookie.js/cookie.min.js', array('scope' => 'header'));

  drupal_add_js($path_family . '/lib/bootstrap/js/bootstrap-slider.min.js', array('scope' => 'header'));
  drupal_add_js($path_family . '/lib/bootstrap/js/bootstrap-select.min.js', array('scope' => 'header'));
  drupal_add_js($path_school . '/js/fs_search_school.js', array('scope' => 'footer'));

  $query_params = drupal_get_query_parameters();
  if (!isset($query_params['search_type'])) {
    $query_params['search_type'] = 'fuzzy';
  }

  $filters = fs_search_school_get_filters_from_query_params($query_params, $city);

  $city = strtolower(check_plain($city));
  $school_type = fs_search_school_get_nested_school_type_tree();
  $academic_program = fs_search_school_get_nested_academic_program_tree();
  $languages = fs_search_school_get_nested_languages_tree();
  $school_neighborhood = fs_search_school_get_nested_school_neighborhood_tree();
  $curriculum = fs_search_school_get_nested_curriculum_tree();

  $count = 0;
  $items = [];

  $sections = fs_search_school_get_sections($city);

  try {
    $elasticsearch = new FsElasticsearch();
    $query_in = fs_search_school_es_query($filters);
    $result_school_json = $elasticsearch->es_node_list($query_in, 'schools');
    $result_school = drupal_json_decode($result_school_json);
    $count = floatval($result_school['hits']['total']);
    $per_page = 9;
    // Initialise the pager
    $current_page = pager_default_initialize($count, $per_page);
    $from = $current_page * $per_page;
    $size = $per_page;
    $result_items = $result_school['hits']['hits'];
    foreach ($result_items as $result_item) {
      $item = [];
      $item = fs_search_school_item($result_item);
      $items[] = theme('fs_search_school_school_list_view', ['item' => $item]);
    }
  }
  catch (Exception $e) {
    $message = $e->getMessage();
    $message .= "<br/>" . $e->getTraceAsString();
    watchdog('fs_search_school', $message, [], WATCHDOG_ERROR);
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

  $search_form = drupal_get_form('fs_search_school_search_form', $form_variables);
  // Show the pager
  $pager = theme('pager', array('school_search', $count));
  $no_result_message = t('Sorry, no results matched your criteria, but these were pretty close.');

  $variables = [
    'sections' => $sections,
    'city' => $city,
    'school_type' => $school_type,
    'academic_program' => $academic_program,
    'languages' => $languages,
    'school_neighborhood' => $school_neighborhood,
    'curriculum' => $curriculum,
    'filters' => $filters,
    'items' => $items,
    'count' => $count,
    'search_form' => render($search_form),
    'pager' => $pager,
    'no_result_message' => $no_result_message,
  ];

  return theme('fs_search_school_list_page', $variables);
}

function fs_school_search_premiun($city) {

  $path_family = drupal_get_path('theme', 'family');
  $path_school = drupal_get_path('module', 'fs_search_school');
  drupal_add_css($path_family . '/css/components/listing.css', array('group' => CSS_THEME));
  drupal_add_css($path_family . '/css/components/compare_school.css', array('group' => CSS_THEME));

  drupal_add_css($path_family . '/lib/bootstrap/css/bootstrap-select.min.css', array('group' => CSS_THEME));

  drupal_add_css($path_family . '/lib/bootstrap/css/bootstrap-slider.min.css', array('group' => CSS_THEME));
  drupal_add_js($path_family . '/lib/cookie.js/cookie.min.js', array('scope' => 'header'));

  drupal_add_js($path_family . '/lib/bootstrap/js/bootstrap-slider.min.js', array('scope' => 'header'));
  drupal_add_js($path_family . '/lib/bootstrap/js/bootstrap-select.min.js', array('scope' => 'header'));
  drupal_add_js($path_school . '/js/fs_search_school.js', array('scope' => 'footer'));

  $query_params = drupal_get_query_parameters();
  if (!isset($query_params['search_type'])) {
    $query_params['search_type'] = 'fuzzy';
  }

  $filters = fs_search_school_get_filters_from_query_params($query_params, $city);

  $city = strtolower(check_plain($city));
  $school_type = fs_search_school_get_nested_school_type_tree();
  $academic_program = fs_search_school_get_nested_academic_program_tree();
  $languages = fs_search_school_get_nested_languages_tree();
  $school_neighborhood = fs_search_school_get_nested_school_neighborhood_tree();
  $curriculum = fs_search_school_get_nested_curriculum_tree();

  $count = 0;
  $items = [];

  $sections = fs_search_school_get_sections($city);

  try {
    $elasticsearch = new FsElasticsearch();
    $filters["premium"] = 1;
    $query_in = fs_search_school_es_query($filters);
    $result_school_json = $elasticsearch->es_node_list($query_in, 'schools');
    $result_school = drupal_json_decode($result_school_json);
    $count = $result_school['hits']['total'];
    // var_dump(drupal_json_encode($query_in));
    // var_dump($result_school);die();
    // $list is the list of items you are paging through
    $per_page = 9;
    // Initialise the pager
    $current_page = pager_default_initialize($count, $per_page);

    $from = $current_page * $per_page;
    $size = $per_page;


    $result_items = $result_school['hits']['hits'];
    $default_preview_image = url(drupal_get_path('module', 'fs_search') . '/images/placeholder.jpg');


    foreach ($result_items as $result_item) {

      $item = [];

      $item['nid'] = $result_item['_source']['nid'];
      $item['title'] = $result_item['_source']['title'];
      $item['summary'] = $result_item['_source']['field_contributor_description'];
      $item['premium'] = $result_item['_source']['field_school_premium'];

      if (empty($result_item['_source']['field_school_logo'])) {
        $item['preview_image'] = $default_preview_image;
      }
      else {
        $url = $result_item['_source']['field_school_logo'];
        $item['preview_image'] = $url;
      }

      $item['annual_tuition'] = $result_item['_source']['field_school_minimum_tuition'];
      if (!empty($result_item['_source']['field_school_maximum_tuition'])) {
        $item['annual_tuition'] .= '~' . $result_item['_source']['field_school_maximum_tuition'] . ' rmb';
      }

      $item['url'] = $result_item['_source']['url'];
      $item['city'] = $city;
      $item['foundation_date'] = $result_item['_source']['field_school_foundation_date'];

      $item['academic_program'] = '';
      $academic_program_ids = $result_item['_source']['field_school_academic_program'];

      if (!empty($academic_program_ids)) {
        if (!empty($academic_program_ids[0])) {
          $i = 1;
          foreach ($academic_program_ids as $academic_program_id) {
            if ($i == 1) {
              $item['academic_program'] .= $academic_program_id['name'];
            }
            else {
              $item['academic_program'] .= ',' . $academic_program_id['name'];
            }
            $i++;
          }
        }
        else {
          $item['academic_program'] = $academic_program_ids['name'];
        }
      }

      $item['neighborhood'] = '';
      $school_neighborhoods = $result_item['_source']['field_neighborhood'];
      if (!empty($school_neighborhoods)) {

        $item['neighborhood'] = $school_neighborhoods["name"];
      }
      //  $item['neighborhood'] = trim($item['neighborhood']);

      $items[] = theme('fs_search_school_school_list_view', ['item' => $item]);
    }
  }
  catch (Exception $e) {
    $message = $e->getMessage();
    $message .= "<br/>" . $e->getTraceAsString();
    watchdog('fs_search_school', $message, [], WATCHDOG_ERROR);
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

  $search_form = drupal_get_form('fs_search_school_search_form', $form_variables);
  // Show the pager
  $pager = theme('pager', array('school_search', $count));
  $no_result_message = t('Sorry, no results matched your criteria, but these were pretty close.');

  $variables = [
    'sections' => $sections,
    'city' => $city,
    'school_type' => $school_type,
    'academic_program' => $academic_program,
    'languages' => $languages,
    'school_neighborhood' => $school_neighborhood,
    'curriculum' => $curriculum,
    'filters' => $filters,
    'items' => $items,
    'count' => $count,
    'search_form' => render($search_form),
    'pager' => $pager,
    'no_result_message' => $no_result_message,
  ];

  return theme('fs_search_school_list_page', $variables);
}

function fs_search_school_search_form($form, &$form_state, $variables) {
  // $serialized_variables = serialize($variables['filters']);
  $filters = $variables['filters'];
  $city = $filters['city'];

  $file_path = drupal_get_path('module', 'fs_search_school');
  $form['#attached']['library'] = array(
    array('system', 'ui.autocomplete'),
  );

  $form['#attached']['js'] = array(
    array(
      'data' => array(
        'fs_search_school_search_form' => [
          'query_url' => url('school/autocomplete/' . $city, ['absolute' => TRUE]),
        ], // 2. add data
      ),
      'type' => 'setting',
    ),
    $file_path . '/js/fs_search_school_search_form.js',
  );

  $form['#attached']['css'] = array(
    $file_path . '/css/fs_search_school_search_form.css',
  );


  $form['keyword'] = [
    '#type' => 'textfield',
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
    '#attributes' => array('id' => array('keyword-school'),
      'placeholder' => array('Search by school name (optional)')),
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

function fs_search_school_search_form_submit($form, &$form_state) {
  $variables = unserialize($form_state['values']['variables']);
  // $variables['keyword'] = check_plain($form_state['values']['keyword']);
  $city = $variables['city'];

  $option['query'] = array(
    'keyword' => $form_state['values']['keyword'],
  );

  drupal_goto($city . '/school', $option);
}

function fs_search_school_get_filters_from_query_params($query_params, $city) {
  $filters = [];
  switch ($query_params['search_type']) {
    case 'fuzzy' :
      if (isset($query_params['school_type'])) {
        $filters['school_type'] = $query_params['school_type'];
      }
      if (isset($query_params['academic_program'])) {
        $filters['academic_program'] = $query_params['academic_program'];
      }
      if (isset($query_params['school_neighborhood'])) {
        $filters['school_neighborhood'] = $query_params['school_neighborhood'];
      }
      if (isset($query_params['languages'])) {
        $filters['languages'] = $query_params['languages'];
      }
      if (isset($query_params['curriculum'])) {
        $filters['curriculum'] = $query_params['curriculum'];
      }
      if (isset($query_params['keyword'])) {
        $filters['keyword'] = $query_params['keyword'];
      }
      if (isset($query_params['tuition_min'])) {
        $filters['tuition_min'] = $query_params['tuition_min'];
      }
      if (isset($query_params['tuition_max'])) {
        $filters['tuition_max'] = $query_params['tuition_max'];
      }
      break;
    case 'exact' :
      if (isset($query_params['id'])) {
        $filters['id'] = $query_params['id'];
      }
      break;
  }

  if (isset($query_params['search_type'])) {
    $filters['search_type'] = $query_params['search_type'];
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

function fs_search_school_get_nested_school_type_tree() {
  return fs_base_get_vocabulary_list_term_by_name("school_type");
}

function fs_search_school_get_nested_academic_program_tree() {
  return fs_base_get_vocabulary_list_term_by_name("academic_program");
}

function fs_search_school_get_nested_languages_tree() {
  return fs_base_get_vocabulary_list_term_by_name("taught_language");
}

/**
 * @return mixed
 */
function fs_search_school_get_nested_school_neighborhood_tree() {
  return fs_base_get_vocabulary_list_term_by_name("neighborhood");
}

function fs_search_school_get_nested_curriculum_tree() {
  return fs_base_get_vocabulary_list_term_by_name("curriculum");
}

function fs_school_search_autocomplete($city) {


  $suggestions = [];

  try {

    $keyword = check_plain($_GET['term']);
    $elasticsearch = new FsElasticsearch();
    $elasticsearch->es_query(array());
    $fields = array("title");
    $elasticsearch->es_search($fields, $keyword);
    $query = $elasticsearch->es_query;
    $result_items = drupal_json_decode($elasticsearch->es_node_list($query, 'schools'));
    $result_items = $result_items['hits']['hits'];
    if (!empty($result_items)) {
      foreach ($result_items as $result_item) {
        $source = $result_item['_source'];
        $suggestion['label'] = $source['title'];
        $suggestion['value'] = $source['title'];
        $suggestion['id'] = $source['nid'];
        $suggestion['url'] = url($city . '/school', [
          'absolute' => TRUE,
          'query' => [
            'id' => check_plain($source['nid']),
            'search_type' => 'exact',
          ],
        ]);

        $suggestions[] = $suggestion;
      }
    }
    else {
      $suggestion['label'] = t('No result found...');
      $suggestion['value'] = t('No result found...');

      $suggestions[] = $suggestion;
    }
  }
  catch (Exception $e) {
    $message = $e->getMessage();
    $message .= "<br/>" . $e->getTraceAsString();
    watchdog('fs_event', $message, [], WATCHDOG_ERROR);
  }

  drupal_json_output($suggestions);
}

function fs_search_school_get_sections($city) {
  switch ($city) {
    case 'shanghai':
      $city_key = 'sh';
      break;
    default:
      $city_key = 'sh';
      break;
  }

  $types = [
    'title',
    'button',
    'button_url',
    'img_bg',
    'desc',
  ];

  $sections = [
    'one' => [],
    'two' => [],
    'three' => [],
    'four' => [],
  ];

  foreach ($sections as $key => &$section) {
    foreach ($types as $type) {
      $variable_name = 'fs_search_school_sect_' . $key . '_' . $type . '_' . $city_key;
      switch ($type) {
        case 'title':
        case 'button':
        case 'desc':
          $section[$type] = variable_get($variable_name);
          break;
        case 'button_url':
          $url = variable_get($variable_name);
          $url_info = explode('?', $url);
          $url_path = $url_info[0];
          $url_query_array = [];
          if (isset($url_info[1])) {
            $url_query_string = $url_info[1];
            parse_str($url_query_string, $url_query_array);
          }
          if (url_is_external($url)) {
            $section[$type] = url($url_path, [
              'external' => TRUE,
              'query' => $url_query_array,
            ]);
          }
          else {
            $section[$type] = url($url_path, ['query' => $url_query_array]);
          }
          break;
        case 'img_bg':
          $img_bg = variable_get($variable_name);
          $file = file_load($img_bg);
          if (is_object($file)) {
            $uri = $file->uri;
            if ($key == 'one') {
              $section[$type] = fs_base_image_rebuild_style('search_school_section_top', $uri);
            }
            else {
              $section[$type] = fs_base_image_rebuild_style('search_school_section_normal', $uri);
            }
          }
          break;
      }
    }
  }

  return $sections;
}

function fs_search_school_es_query_premium($filter) {
  $elasticsearch = new FsElasticsearch();
  $filter["premium"] = 1;
  if (isset($filter["academic_program"])) {
    $elasticsearch->es_add_filter_multi_value("field_school_academic_program.tid", $filter['academic_program']);
  }
  if (isset($filter["languages"])) {
    $elasticsearch->es_add_filter("field_school_taught_languages.tid", $filter['languages'][0]);
  }
  if (isset($filter["school_type"])) {
    $elasticsearch->es_add_filter("field_school_type.tid", $filter['school_type'][0]);
  }
  if (!empty($filter['school_neighborhood'])) {
    $elasticsearch->es_add_filter("field_neighborhood.tid", $filter['school_neighborhood'][0]);
  }
  if (isset($filter['premium'])) {
    $elasticsearch->es_add_filter("field_school_premium", $filter['premium']);
  }
  if (isset($filter["tuition_min"]) && isset($filter["tuition_max"])) {
    if ($filter["tuition_min"] == 0 && $filter["tuition_max"] == 300000) {
      
    }
    else {
      $script = ("(doc['field_school_maximum_tuition'].value < {$filter['tuition_max']})&&(doc['field_school_minimum_tuition'].value >  {$filter['tuition_min']})");
      $elasticsearch->es_query["filter"]["script"] = array(
        "script" => $script, "lang" => "groovy"
      );
    }
  }
  if (isset($filter['keyword'])) {
    $fields = array("title");
    $elasticsearch->es_search($fields, $filter['keyword']);
  }
  else {

    $sort_array["field_school_premium"] = "desc";
    // $sort_array["title"]="asc";
    $elasticsearch->es_sort_multi($sort_array);
    $elasticsearch->es_sort_random();
  }
  //var_dump( $elasticsearch->_json_encode_string(drupal_json_encode(($elasticsearch->es_query))));

  return $elasticsearch->es_query;
}

function fs_search_school_es_query($filter) {
  $elasticsearch = new FsElasticsearch();
  $elasticsearch->es_query($filter);
  if (isset($filter["academic_program"])) {
    $elasticsearch->es_add_filter_multi_value("field_school_academic_program.tid", $filter['academic_program']);
  }
  if (isset($filter["languages"])) {
    $elasticsearch->es_add_filter("field_school_taught_languages.tid", $filter['languages'][0]);
  }
  if (isset($filter["school_type"])) {
    $elasticsearch->es_add_filter("field_school_type.tid", $filter['school_type'][0]);
  }
  if (!empty($filter['school_neighborhood'])) {
    $elasticsearch->es_add_filter("field_neighborhood.tid", $filter['school_neighborhood'][0]);
  }
  if (isset($filter['premium'])) {
    $elasticsearch->es_add_filter("field_school_premium", $filter['premium']);
  }
  if (isset($filter["tuition_min"]) && isset($filter["tuition_max"])) {
    if ($filter["tuition_min"] == 0 && $filter["tuition_max"] == 300000) {
      
    }
    else {
      $script = ("(doc['field_school_maximum_tuition'].value < {$filter['tuition_max']})&&(doc['field_school_minimum_tuition'].value >  {$filter['tuition_min']})");
      $elasticsearch->es_query["filter"]["script"] = array(
        "script" => $script, "lang" => "groovy"
      );
    }
  }
  if (isset($filter['keyword'])) {
    $fields = array("title");
    $elasticsearch->es_search($fields, $filter['keyword']);
  }
  else {

//    $sort_array["field_school_premium"] = "desc";
//
//    $sort_array["title"] = "asc";
//    $elasticsearch->es_sort_multi($sort_array);
//    $elasticsearch->es_sort_random();
    $elasticsearch->es_query["sort"]["field_school_premium"] = array('order' => "desc");

    $elasticsearch->es_query["sort"]["_script"] = array(
      'order' => 'asc',
      'script' => "if(doc['field_school_premium'].value == '1'){ return Math.random() }else{ return doc['title_first'].value }",
      'type' => 'string',
    );
    //$elasticsearch->es_query["sort"]["title_first"]= array('order'=>"asc");   
  }

  //var_dump( $elasticsearch->_json_encode_string(drupal_json_encode(($elasticsearch->es_query))));

  return $elasticsearch->es_query;
}

function fs_search_school_item($result_item) {
  $default_preview_image = url(drupal_get_path('module', 'fs_search') . '/images/placeholder.jpg');

  $item = [];
  $item['nid'] = $result_item['_source']['nid'];
  $item['title'] = $result_item['_source']['title'];
  $item['summary'] = $result_item['_source']['field_contributor_description'];
  $item['premium'] = $result_item['_source']['field_school_premium'];
  if (empty($result_item['_source']['field_school_logo'])) {
    $item['preview_image'] = $default_preview_image;
  }
  else {
    $url = image_style_url("school_list_item", $result_item['_source']['field_school_logo']);
    $item['preview_image'] = $url;
  }

  $item['annual_tuition'] = $result_item['_source']['field_school_minimum_tuition'];
  if (!empty($result_item['_source']['field_school_maximum_tuition'])) {
    $item['annual_tuition'] .= '~' . $result_item['_source']['field_school_maximum_tuition'] . ' rmb';
  }

  $item['url'] = $result_item['_source']['url'];
  $item['city'] = "shanghai";
  $item['foundation_date'] = $result_item['_source']['field_school_foundation_date'];
  $item['language'] = '';
  if (!empty($result_item['_source']['field_school_taught_languages'])) {
    $language = $result_item['_source']['field_school_taught_languages'];
    if (!empty($language[0])) {
      $i = 1;
      foreach ($language as $r) {
        if ($i == 1) {
          $item['language'] .= '<span>' . $r['name'] . '</span>';
        }
        else {
          $item['language'] .= '<span>,' . $r['name'] . '</span>';
        }
        $i++;
      }
    }
    else {
      $item['language'] = $language['name'];
    }
  }
  $item['neighborhood'] = '';

  if (!empty($result_item['_source']['field_neighborhood'])) {
    $school_neighborhoods = $result_item['_source']['field_neighborhood'];
    $item['neighborhood'] = $school_neighborhoods["name"];
  }
  $item['school_type'] = '';
  $school_types = $result_item['_source']['field_school_type'];
  if (!empty($school_types)) {
    $item['school_type'] = $school_types["name"];
  }
  $item['curriculum'] = '';
  ;
  if (!empty($result_item['_source']['field_school_curriculum'])) {
    $curriculum = $result_item['_source']['field_school_curriculum'];
    if (!empty($curriculum[0])) {
      $i = 1;
      foreach ($curriculum as $r) {
        if ($i == 1) {
          $item['curriculum'] .= '<span>' . $r['name'] . '</span>';
        }
        else {
          $item['curriculum'] .= '<span>,' . $r['name'] . '</span>';
        }
        $i++;
      }
    }
    else {
      $item['curriculum'] = $curriculum['name'];
    }
  }
  return $item;
}

function fs_search_school_details_redirect($name) {

  if(is_numeric($name)) { 
    drupal_goto(url(drupal_get_path_alias('node/' . $name)));
  }else {
    drupal_goto('/shanghai-schools/' . $name);
  }
}
