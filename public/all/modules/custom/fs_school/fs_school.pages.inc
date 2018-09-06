<?php

function fs_school_compare_page($city) {

  module_load_include('inc', 'fs_base', 'fs_base');
  module_load_include('inc', 'fs_elasticsearch', 'fs_elasticsearch');

  $path_family = drupal_get_path('theme', 'family');
  $path_school = drupal_get_path('module', 'fs_school');
  drupal_add_css($path_family . '/css/components/listing.css', array('group' => CSS_THEME));
  drupal_add_css($path_family . '/lib/fancybox/jquery.fancybox.min.css', array('group' => CSS_THEME));
  drupal_add_css($path_family . '/css/components/compare_school.css', array('group' => CSS_THEME));

  drupal_add_css($path_family . '/lib/bootstrap/css/bootstrap-select.min.css', array('group' => CSS_THEME));

  drupal_add_js($path_family . '/lib/cookie.js/cookie.min.js', array('scope' => 'header'));

  drupal_add_js($path_family . '/lib/bootstrap/js/bootstrap-select.min.js', array('scope' => 'header'));
  drupal_add_js($path_family . '/lib/fancybox/jquery.fancybox.min.js', array('scope' => 'header'));
   drupal_add_js($path_family . '/lib/handlebars/handlebars.js', array('scope' => 'footer'));

  drupal_add_js($path_family . '/lib/bootstrap-typeahead/bootstrap-typeahead.js', array('scope' => 'footer'));

  drupal_add_js($path_school . '/js/fs_school.js', array('scope' => 'footer'));

  global $base_url;

  $query_params = drupal_get_query_parameters();
  if (isset($query_params['ids'])) {
    $ids = $query_params['ids'];
  }
  else {
    $ids = [];
  }

  $items = [];

  try {
    //  $country = fs_base_get_visitor_name_country();
    //  $client = new FsSearchSchool();
    //  $result_schools = $client->getByIds($city, $ids);
    $elasticsearch = new FsElasticsearch();
    $elasticsearch->es_add_filter_multi_value("nid", $ids);
    $query_in = $elasticsearch->es_query;
    $result_school_json = $elasticsearch->es_node_list($query_in, 'schools');
    $result_schools = drupal_json_decode($result_school_json);
    $hits = $result_schools['hits']['hits'];
    $i=1;
    $temp_key=1;
      $default_preview_image = url(drupal_get_path('module', 'fs_search') . '/images/placeholder.jpg');
    foreach ($hits as $hit) {
      $nid = $hit['_source']['nid'];
      $item = fs_base_load(node_load($nid), "school");
      $item["field_school_maximum_tuition"] = $item["field_school_minimum_tuition"].' - '.$item["field_school_maximum_tuition"].' rmb';
        if (empty($hit['_source']['field_school_logo'])) {
            $item['field_school_logo'] = $default_preview_image;
        }
        else {
            $url = image_style_url("medium",$hit['_source']['field_school_logo']);
            $item['field_school_logo'] = $url;
        }
      if($i%2==0){  
      $items[$temp_key][] = $item;
      $temp_key++;
      }else{
      $items[$temp_key][] = $item;   
      }
      
    
      $i++;
    }
   // var_dump(array_keys($items[2]));die();
  }
  catch (Exception $e) {
    $message = $e->getMessage();
    $message .= "<br/>" . $e->getTraceAsString();
    watchdog('fs_school', $message, [], WATCHDOG_ERROR);
  }

  $form = drupal_get_form('fs_school_compare_add_school_form');

  $id_city = 2;
  if ($city == "shanghai") {
    $id_city = 1;
  }
  $fields_compare =array(
    "field_school_type" =>"Type",
    "field_neighborhood" =>"Neighborhood",
//     "field_neighborhood" =>"Neighborhood",
    "field_school_strengths" => "School Strengths",
    "field_school_academic_program" => "Academic Program",
    "field_school_taught_languages" => "Languages",
    "field_school_curriculum" => "Curriculum",
    "field_school_foundation_date" => "Founded",
    "field_school_maximum_tuition" => "Tuition");
  
  drupal_add_js(array('fields_compare' => array_keys($fields_compare)), 'setting');
  
  $variables = [
    'url_search' => $base_url . "/index.php?q=school_compare/autocomplete/",

    'items' => $items,
    'form' => render($form),
    'fields_compare' => $fields_compare,
//    'has_brochure' => $has_brochure,
//    'has_video' => $has_video,
  ];

  return theme('fs_school_compare_page', $variables);
}
function fs_school_compare_autocomplete_default(){
       module_load_include('inc', 'fs_search_school', 'fs_search_school.pages');
//  $cities = _fs_city_get_cities();
//  if (is_numeric($cid)) {
//    $city = $cities[$cid];
//  }
//  else {
    $city = 'shanghai';
 // }

  $params = [
    'city' => $city,
    'keyword' => $keyword,
    'search_type'=>'fuzzy'
  ];

  $suggest = [];

  try {
    $elasticsearch = new FsElasticsearch();
    $elasticsearch->es_query(array()); 
    $elasticsearch->es_sort_random();
    $query_in = $elasticsearch->es_query;
     //var_dump($query_in);
    $result_school_json = $elasticsearch->es_node_list($query_in, 'schools');
    $result_items = drupal_json_decode($result_school_json);
    $result_items = $result_items['hits']['hits'];
   
    if (!empty($result_items)) {
      foreach ($result_items as $result_item) {
//        $title = $result_item['_source']['title'];
        $suggest[$result_item['_source']['nid']]  = fs_search_school_item($result_item);
        $suggest[$result_item['_source']['nid']]['id']= $result_item['_source']['title'].'<input type="hidden" value="'.$result_item['_source']['nid'].'"/>';
        
//          $id = $result_item['_source']['nid'];
//          $key = $id;
        //var_dump($result_item);
//        $result_item['_source']["image"] = $result_item['_source']["field_school_logo"];
//        $suggest[] = $result_item['_source'];
      }
      //$suggest = $result_item['_source'] ;
    }
    else {
      $suggest = [];
    }
  }
  catch (Exception $e) {
    $message = $e->getMessage();
    $message .= "<br/>" . $e->getTraceAsString();
    watchdog('fs_school', $message, [], WATCHDOG_ERROR);
  }
  drupal_json_output($suggest);
}
function fs_school_compare_autocomplete($keyword) {
  module_load_include('inc', 'fs_search_school', 'fs_search_school.pages');
//  $cities = _fs_city_get_cities();
//  if (is_numeric($cid)) {
//    $city = $cities[$cid];
//  }
//  else {
    $city = 'shanghai';
 // }

  $params = [
    'city' => $city,
    'keyword' => $keyword,
    'search_type'=>'fuzzy'
  ];

  $suggest = [];

  try {
    $elasticsearch = new FsElasticsearch();
    $elasticsearch->es_query(array());
    $fields = array("title"); 
    $elasticsearch->es_search($fields, $keyword);
    $query_in = $elasticsearch->es_query;
     //var_dump($query_in);
    $result_school_json = $elasticsearch->es_node_list($query_in, 'schools');
    $result_items = drupal_json_decode($result_school_json);
    $result_items = $result_items['hits']['hits'];
   
    if (!empty($result_items)) {
      foreach ($result_items as $result_item) {
//        $title = $result_item['_source']['title'];
        $suggest[$result_item['_source']['nid']]  = fs_search_school_item($result_item);
        $suggest[$result_item['_source']['nid']]['id']= $result_item['_source']['title'].'<input type="hidden" value="'.$result_item['_source']['nid'].'"/>';
        
//          $id = $result_item['_source']['nid'];
//          $key = $id;
        //var_dump($result_item);
//        $result_item['_source']["image"] = $result_item['_source']["field_school_logo"];
//        $suggest[] = $result_item['_source'];
      }
      //$suggest = $result_item['_source'] ;
    }
    else {
      $suggest = [];
    }
  }
  catch (Exception $e) {
    $message = $e->getMessage();
    $message .= "<br/>" . $e->getTraceAsString();
    watchdog('fs_school', $message, [], WATCHDOG_ERROR);
  }
  drupal_json_output($suggest);
}

function fs_school_get_by_id($id) {
  module_load_include('inc', 'fs_base', 'fs_base');
  $item = [];
  try {
    $node = node_load($id);
    if (is_object($node)) {
      $item['nid'] = $node->nid;
      $item['title'] = $node->title;
      $item['address_in_english'] = fs_base_field($node, "field_address_in_english")[0]['value'];
      $item['address_in_chinese'] = fs_base_field($node, "field_address_in_chinese")[0]['value'];
      //$item['phone'] = fs_base_field($node,"field_telephone")[0]['value'];
      $item['website'] = fs_base_field($node, "field_website")[0]['url'];
      $item['email'] = fs_base_field($node, "field_email")[0]['email'];
      $item['tuition_min'] = fs_base_field($node, "field_school_minimum_tuition ")[0]['value'];
      $item['tuition_max'] = fs_base_field($node, "field_school_maximum_tuition ")[0]['value'];
      $item['main_image'] = image_style_url("main_image_school", fs_base_field($node, "field_main_image")[0]['uri']);
      //   $item['gallery_image'] = $source['gallery_image'];
      //   $item['addresses'] = $source['addresses'];
      $item['other_payments'] = fs_base_field($node, "field_school_other_payments")[0]['value'];
      $item['foundation_date'] = fs_base_field($node, "field_school_foundation_date")[0]['value'];
      $item['contributor_description'] = fs_base_field($node, "field_contributor_description")[0]['value'];
      $item['editor_description'] = fs_base_field($node, "field_editor_description ")[0]['value'];
      $item['admission_inquiry'] = fs_base_field($node, "field_school_admission_inquiry ")[0]['value'];
      $item['premium'] = fs_base_field($node, "field_school_premium")[0]['value'];
      $item['contact_email'] = fs_base_field($node, "field_email")[0]['email'];
      $item['contact_name'] = fs_base_field($node, "field_school_contact_name")[0]['value'];

      $item['url'] = url(drupal_get_path_alias('node/' . $node->nid));




//      $data['tuition_min'] = $source['tuition_min'];
//      $data['tuition_max'] = $source['tuition_max'];
//      $data['website'] = $source['website'];
//      $data['email'] = $source['email'];
//      $data['phone'] = $source['phone'];
      $school_type = $node->field_school_strengths["und"];
      $academic_program = $node->field_school_academic_program["und"];
      $languages = $node->field_school_academic_program["und"];
      $school_neighborhood = $node->field_neighborhood["und"];
      $curriculum = $node->field_school_curriculum["und"];
      if (!empty($school_type)) {
        $item['school_type'] = fs_base_get_taxonomy_terms_by_api($school_type);
      }
      if (!empty($academic_program)) {
        $item['academic_program'] = fs_base_get_taxonomy_terms_by_api($academic_program);
      }
      if (!empty($languages)) {
        $item['language'] = fs_base_get_taxonomy_terms_by_api($languages);
      }

      if (!empty($school_neighborhood)) {
        $item['school_neighborhood'] = fs_base_get_taxonomy_terms_by_api($school_neighborhood);
      }
    }
  }
  catch (Exception $e) {
    $message = $e->getMessage();
    $message .= "<br/>" . $e->getTraceAsString();
    watchdog('fs_school', $message, [], WATCHDOG_ERROR);
  }

  drupal_json_output($item);
}

function fs_school_contact_school_callback() {
  $data = [
    'name' => check_plain($_POST['name']),
    'email' => check_plain($_POST['email']),
    'subject' => check_plain($_POST['subject']),
    'message' => check_plain($_POST['message']),
    'contact_email' => check_plain($_POST['contact_email']),
    'contact_telephone' => check_plain($_POST['contact_telephone']),
    'contact_name' => check_plain($_POST['contact_name']),
  ];

  $message = [];

  $validate_error = _fs_school_contact_school_variables_validate($data);

  $success = 0;

  if (empty($validate_error)) {
    $result = _fs_school_contact_school_send_mail_by_sailthru($data);
    if ($result['success']) {
      $success = 1;
    }
    else {
      $message[] = 'Get errors when sending email';
    }
  }
  else {
    $message = $validate_error;
  }

  $response = [
    'success' => $success,
    'message' => $message,
  ];

  drupal_json_output($response);
}

function _fs_school_contact_school_variables_validate($data) {
  $error = [];

  foreach ($data as $key => $value) {
    switch ($key) {
      case 'name':
      case 'subject':
      case 'contact_name':
        if (empty($value)) {
          $error[] = $key . ' is empty.';
        }
        break;
      case 'email':
      case 'contact_email' :
        if (empty($value)) {
          $error[] = $key . ' is empty';
        }

        if (!valid_email_address($value)) {
          $error[] = $key . ' is not a valid email address';
        }
        break;
    }
  }

  return $error;
}

function _fs_school_contact_school_send_mail_by_sailthru($data) {
  module_load_include('module', 'fs_sailthru', 'fs_sailthru');

   $data = [
     'name' => check_plain($_POST['name']),
     'email' => check_plain($_POST['email']),
     'subject' => check_plain($_POST['subject']),
     'message' => check_plain($_POST['message']),
     'contact_email' => check_plain($_POST['contact_email']),
     'contact_email' => check_plain($_POST['contact_email']),
   ];
   $email = $data['contact_email'];
   if($_POST['send_me']==1){
        $email = array($email,$data["email"]);      
   }

  //contact_name, message, subject, contact_email, school_contact

  $template = 'contact school family';
 
  $vars = [
    'contact_name' => $data['name'],
    'contact_email' => $data['contact_email'],
    'contact_telephone' => $data['contact_telephone'],
    'message' => $data['message'],
    'subject' => $data['subject'],
    'school_contact' => $data['contact_name'],
  ];


  $options = [
    'behalf_email' => $data['email'],
  ];


  $result = fs_sailthru_send_notification($template, $email, $vars, $options);

  return $result;
}
