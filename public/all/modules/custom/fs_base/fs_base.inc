<?php

/**
 * Fn   To get the client IP address
 * return   IP Address
 */
function fs_base_get_visitor_ip_address() {

  $ipaddress = '';
  if (isset($_SERVER['HTTP_X_FORWARDED_IP'])) {
    $ipaddress = $_SERVER['HTTP_X_FORWARDED_IP'];
  }
  else {
    if (isset($_SERVER['HTTP_X_FORWARDED_FOR'])) {
      $ipaddress = $_SERVER['HTTP_X_FORWARDED_FOR'];
    }
    else {
      if (isset($_SERVER['HTTP_X_FORWARDED'])) {
        $ipaddress = $_SERVER['HTTP_X_FORWARDED'];
      }
      else {
        if (isset($_SERVER['HTTP_FORWARDED_FOR'])) {
          $ipaddress = $_SERVER['HTTP_FORWARDED_FOR'];
        }
        else {
          if (isset($_SERVER['HTTP_FORWARDED'])) {
            $ipaddress = $_SERVER['HTTP_FORWARDED'];
          }
          else {
            if (isset($_SERVER['REMOTE_ADDR'])) {
              $ipaddress = $_SERVER['REMOTE_ADDR'];
            }
            else {
              $ipaddress = 'UNKNOWN';
            }
          }
        }
      }
    }
  }

  return $ipaddress;
}

/**
 * Fn   To get the client IP address
 * return  Country Name of Visitor
 */
function fs_base_get_visitor_name_country() {
  $ipaddress = fs_base_get_visitor_ip_address();
  //$vistor_info = unserialize(file_get_contents('http://www.geoplugin.net/php.gp?ip=182.18.17.209')); // US : 76.109.14.196 Ch: 182.18.17.209
  $vistor_info = unserialize(file_get_contents('http://www.geoplugin.net/php.gp?ip=' . $ipaddress));
  if (isset($vistor_info['geoplugin_countryName']) && $vistor_info['geoplugin_countryName'] != NULL) {
    return $vistor_info['geoplugin_countryName'];
  }
  else {
    return NULL;
  }
}

function fs_base_taxonomy_get_nested_tree($terms = array(), $max_depth = NULL, $parent = 0, $parents_index = array(), $depth = 0) {
  if (is_int($terms)) {
    $terms = taxonomy_get_tree($terms);
  }

  foreach ($terms as $term) {
    foreach ($term->parents as $term_parent) {
      if ($term_parent == $parent) {
        $return[$term->tid] = $term;
      }
      else {
        $parents_index[$term_parent][$term->tid] = $term;
      }
    }
  }

  foreach ($return as &$term) {
    if (isset($parents_index[$term->tid]) && (is_null($max_depth) || $depth < $max_depth)) {
      $term->children = fs_base_taxonomy_get_nested_tree($parents_index[$term->tid], $max_depth, $term->tid, $parents_index, $depth + 1);
    }
  }


  return $return;
}

function fs_base_output_taxonomy_nested_tree($tree) {
  if (count($tree)) {
    $output = '<ul class="taxonomy-tree">';
    foreach ($tree as $term) {
      $output .= '<li class="taxonomy-term">';
      $output .= $term->name;
      if ($term->children) {
        $output .= fs_base_output_taxonomy_nested_tree($term->children);
      }
      $output .= '</li>';
    }
    $output .= '</ul>';
  }

  return $output;
}

function fs_base_get_taxonomy_terms_by_api($tids) {

  foreach ($tids as $key => $tid) {

    $tx = $tid["taxonomy_term"];
    $item[] = array("name" => $tx->name, "tid" => $tx->tid);
  }
  return $item;
}

function fs_base_image_rebuild_style($styleName, $uri) {
  $styleFileName = (image_style_url($styleName, $uri));
  if (!file_exists($styleFileName)) {
    $styleDef = image_style_load($styleName);
    if (count($styleDef)) {
      image_style_create_derivative($styleDef, $uri, image_style_path($styleName, $uri));
    }
    else {
      $styleFileName = file_create_url($uri);
    }
  }
  if (!file_exists($styleFileName)) {
    $styleFileName = file_create_url($uri);
  }

  return $styleFileName;
}

function fs_base_video_player($video, $size = array()) {
  $width = "100%";
  $heigth = "300";

  if ($size["width"]) {
    $width = $size["width"];
  }


  if ($size["height"]) {
    $heigth = $size["height"];
  }

  $output = "";
  if (strpos($video, "youtube")) {
    $video_id = explode("?v=", $video)[1];
    $output = '<iframe class="embed-responsive-item" width="' . $width . '" height="' . $heigth . '" frameborder="0" src="https://www.youtube.com/embed/' . $video_id . '?autoplay=0&showinfo=1&autohide=1&output=embed&html5=1" allowfullscreen></iframe>';
  }
  if (strpos($video, "v.youku")) {
    $video_id = explode("id_", $video)[1];
    $video_id = explode(".html", $video_id)[0];
    $output = "<embed src='http://player.youku.com/player.php/sid/" . $video_id . "==/v.swf' allowFullScreen='true' quality='high' width='" . $width . "' height='" . $heigth . "' align='middle' allowScriptAccess='always' type='application/x-shockwave-flash'></embed>";
  }
  if (strpos($video, "v.qq")) {
    $video_id = explode(".html", $video)[0];
    $video_id = explode("/", $video_id);
    $video_id = $video_id[sizeof($video_id) - 1];
    $output = '<iframe frameborder="0" width="' . $width . '" height="' . $heigth . '"  src="https://v.qq.com/iframe/player.html?vid=' . $video_id . '&tiny=0&auto=0" allowfullscreen></iframe>';
  }

  return $output;
}

//taxonomy get list by vocabulary 
function fs_base_get_vocabulary_list_term_by_name($name) {
  $vid = taxonomy_vocabulary_machine_name_load($name)->vid;
  $data = taxonomy_get_tree($vid);
  $term = [];
  foreach ($data as $key => $value) {
    if ($value->depth == 0) {
      $term[$key] = fs_base_taxonomy_format($value);
    }
  }
  return $term;
}

//taxonomy format item
function fs_base_taxonomy_format($term) {
  $item["tid"] = $term->tid;
  $item["name"] = $term->name;
  return $item;
}

function fs_base_list_text_custom($field) {
  return fs_base_text_custom($field);
}

function taxonomy_get_children_all($tid, $vid = 0, $key = 'tid') {
  $c = taxonomy_get_children($tid, $vid, $key);
  $parent = taxonomy_term_load($tid);
  $result = array();
  $result[$tid] = $parent;
  foreach ($c as $t => $d) {
    $result[$t] = $d;
    $below = taxonomy_get_children_all($t, $vid, $key);
    if (!empty($below)) {
      foreach ($below as $nt => $nd) {
        $result[$nt] = $nd;
      }
    }
  }
  return $result;
}

// Field check if empty
function fs_base_field($node, $string) {

  if (isset($node->{$string}) && !empty($node->{$string})) {
    // var_dump($node->{$string}['und']);
    return $node->{$string}['und'];
  }
  else {
    return null;
  }
}

function fs_base_entityreference_custom($field) {
  if (!isset($field['und']) || count($field['und']) < 1) {
    return array();
  }
  $nodes = array();
  $nsql = 'select nid, title from node where nid = ? limit 1';
  foreach ($field['und'] as $nnid) {
    if (!isset($nnid['target_id']) || !$nnid['target_id']) {
      continue;
    }
    $nid = $nnid['target_id'];
    $nr = db_query($nsql, array($nid));
    $node = $nr->fetchAssoc();
    if (!$node) {
      continue;
    }
    $nodes[] = array(
      'nid' => $node['nid'],
      'title' => $node['title'],
    );
  }
  return $nodes;
}

function fs_base_taxonomy_term_reference_custom($field) {

  if (empty($field['und']) || count($field['und']) < 1) {
    return array();
  }
  $terms = array();
  foreach ($field['und'] as $ntid) {

    $tid = $ntid['tid'];
    $term = taxonomy_term_load($tid);
    if (!$term) {
      continue;
    }
    $terms[] = array(
      'tid' => $term->tid,
      'name' => $term->name,
    );
  }
//  if (count($terms) == 1) {
//    return array_shift($terms);
//  }
  return $terms;
}

function fs_base_image_custom($field) {

  if (!empty($field['und'])) {
    return $field['und'][0]['uri'];
  }
  else {
    return null;
  }
}

function fs_base_property_custom($field) {
  return $field;
}

function fs_base_text_custom($field) {
  if (!empty($field['und'])) {
    return $field['und'][0]["value"];
  }
  else {
    return null;
  }
}

function fs_base_email_custom($field) {
  if (!empty($field['und'])) {
    return $field['und'][0]["email"];
  }
  else {
    return null;
  }
}

function fs_base_link_field_custom($field) {
  if (!empty($field['und'])) {
    return $field['und'][0]["url"];
  }
  else {
    return null;
  }
}

function fs_base_field_amap_custom($field) {
  if (isset($field['und'][0])) {
    if (!isset($field['und'][0]['lat']) && !isset($field['und'][0]['lng'])) {
      return array();
    }
    $map = array(
      'lat' => $field['und'][0]['lat'],
      'lon' => $field['und'][0]['lng'],
    );
  }
  else {
    $map = array();
  }
  return $map;
}

function fs_base_text_long_custom($field) {
  return fs_base_text_custom($field);
}

function fs_base_telephone_custom($field) {
  return fs_base_text_custom($field);
}

function fs_base_list_boolean_custom($field) {
  return fs_base_text_custom($field);
}

function fs_base_datetime_custom($field) {
  if (!isset($field['und']) || count($field['und']) < 1) {
    return array();
  }
  $dates = array();
  foreach ($field['und'] as $key => $value) {
    $dates[] = array(
      'date_start' => $value["value"],
      'date_end' => $value["value2"],
    );
  }
  if (count($dates) == 1) {
    return array_shift($dates);
  }
  return $dates;
}

function fs_base_number_float_custom($field) {
  return floatval(fs_base_text_custom($field));
}

function fs_base_text_with_summary_custom($field) {
  if (!empty($field['und'])) {
    return $field['und'][0]["value"];
  }
  else {
    return null;
  }
}

//Get field type
function fs_base_type_fields_default() {
  return array(
    "name" => "property",
    "promote" => "property",
    "sticky" => "property",
    "status" => "property",
    "title" => "property",
    "nid" => "property",
  );
}

function fs_base_field_type($name) {
  $type_fields_default = fs_base_type_fields_default();
  if (in_array($name, array_keys($type_fields_default))) {
    return $type_fields_default[$name];
  }
  else {
    $type_result = db_select('field_config', 'n')
        ->fields('n', array('type'))
        ->condition('field_name', $name, '=')
        ->range(0, 1)
        ->execute()
        ->fetchObject();
    if (is_object($type_result)) {
      return $type_result->type;
    }
    else {
      return null;
    }
  }
}

/// change node Object to elastic search fields mapping
function fs_base_load($node, $type, $field_names = array()) {
  $enode = array();

  if (is_object($node)) {
    $enode['url'] = url(drupal_get_path_alias('node/' . $node->nid));
    foreach ($node as $field => $value) {
      //check if field is exclude or in field base indexing
      if (fs_base_field_type($field)) {
        $type_fun = "fs_base_" . fs_base_field_type($field) . "_custom";
        if (function_exists($type_fun)) {
          if (isset($field_names[$field])) {
            $enode[$field_names[$field]] = $type_fun($node->{$field});
          }
          else {
            $enode[$field] = $type_fun($node->{$field});
          }
          unset($node->{$field});
        }
      }
      // custom field structure
      $field_fun = "fs_{$type}_{$field}_custom";
      if (function_exists($field_fun)) {
        if (isset($field_names[$field])) {
          $enode[$field_names[$field]] = $field_fun($node->{$field});
        }
        else {
          $enode[$field] = $field_fun($node->{$field});
        }
        unset($node->{$field});
      }
    }

    $enode["node"] = ($node);
  }
  return $enode;
}

function timeAgo($time_ago) {
  $time_ago = strtotime($time_ago) ? strtotime($time_ago) : $time_ago;
  $time = time() - $time_ago;

  switch ($time):
// seconds
    case $time <= 60;
      return ' a minute ';
// minutes
    case $time >= 60 && $time < 3600;
      return (round($time / 60) == 1) ? 'a minute' : round($time / 60) . ' minutes ago';
// hours
    case $time >= 3600 && $time < 86400;
      return (round($time / 3600) == 1) ? 'a hour ago' : round($time / 3600) . ' hours ago';
// days
    case $time >= 86400 && $time < 604800;
      return (round($time / 86400) == 1) ? 'a day ago' : round($time / 86400) . ' days ago';
// weeks
    case $time >= 604800 && $time < 2600640;
      return (round($time / 604800) == 1) ? 'a week ago' : round($time / 604800) . ' weeks ago';
// months
    case $time >= 2600640 && $time < 31207680;
      return (round($time / 2600640) == 1) ? 'a month ago' : round($time / 2600640) . ' months ago';
// years
    case $time >= 31207680;
      return (round($time / 31207680) == 1) ? 'a year ago' : round($time / 31207680) . ' years ago';

  endswitch;
}
function fs_base_image_storage($nid,$field_name){
  $entity = entity_load('node', array($nid));
  $node_fix = reset($entity);
  $node_wrapper = entity_metadata_wrapper('node', $node_fix);
  $image = $node_wrapper->{$field_name}->value();

  return $image["uri"]; 
}
function fs_base_generate_image($style_name,$uri){
    $style = image_style_load($style_name);
    //image_style_flush($style); 
   
    $r = image_style_create_derivative($style, $uri, image_style_path($style_name, $uri));
    if($r==1 ) {       
        watchdog('fs_base', '!style success image generate', [
        '!style' => $style_name,
        ]);
    }else{       
        watchdog('fs_base', "error image generate ".$style_name, [], WATCHDOG_ERROR);
    }
  
  
}

function fs_base_count_node($type){
    $data = db_select('node', 'n')
          ->fields('n', array('nid'))
          ->orderBy('nid', 'DESC')
          ->condition('type', $type, '=')
          ->condition('status',1, '=')
          ->execute()
          ->fetchAll();  
    return sizeof($data);
}