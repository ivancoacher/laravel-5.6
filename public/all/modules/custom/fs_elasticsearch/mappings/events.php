<?php

include_once 'base.php';

function events_field_exclude() {
  $field_exclude = base_field_exclude();
  $field_exclude[] = 'field_event_venue_name';
  $field_exclude[] = 'field_price';
  $field_exclude[] = 'field_website';
  $field_exclude[] = 'field_address_in_english';
  $field_exclude[] = 'field_address_in_chinese';
  $field_exclude[] = 'field_nearest_metro_station';
  $field_exclude[] = 'name';
  $field_exclude[] = 'promote';
  $field_exclude[] = 'author';
  $field_exclude[] = 'field_related_venue';
  $field_exclude[] = 'field_wechat';
  $field_exclude[] = 'field_telephone';
  $field_exclude[] = 'uid';
  return $field_exclude;
}

function events_mapping() {
  $_mapping = [];
  $field_exclude = events_field_exclude();
  $node = node_last('events');
  if (is_object($node)) {
    foreach ($node as $key => $value) {
      if (!in_array($key, $field_exclude)) {
        $_mapping[$key] = array(
          'type' => 'string',
          "include_in_all" => true
        );
        /// custom type field structure  
        if (field_type($key)) {
          $type_fun = "base_" . field_type($key) . "_format_mapping";
          
          if (function_exists($type_fun)) {
            $_mapping[$key] = $type_fun();
          }
        }
        // custom field structure
        $field_fun = "fs_{$node->type}_{$key}_format_mapping";
        if (function_exists($field_fun)) {
          $_mapping[$key] = $field_fun();
        }
      }
    }
  }
  else {
    $_mapping = mapping_base();
  }

//  $_mapping["nearest_date"]= array(
//    'type' => 'integer',
//    "include_in_all" => true
//  );
  $_mapping["date_s_time"]= array(
    'type' => 'integer',
    "include_in_all" => true
  );
  $_mapping["date_e_time"]= array(
    'type' => 'integer',
    "include_in_all" => true
  ); 
  return $_mapping;
}

/// change node Object to elastic search fields mapping
function events_load($node) {
  $enode = array();
  $field_base = fields_base($node);
  $field_exclude = events_field_exclude();
  
  $node->field_main_image['und'][0]['uri'] = image_storage($node->nid,'field_main_image');
 
  
  foreach ($node as $field => $value) {
    //check if field is exclude or in field base indexing
    if (!in_array($field, $field_exclude) && !in_array($field, array_keys($field_base))) {

      if (field_type($field)) {
        $type_fun = "base_" . field_type($field) . "_custom";
        if (function_exists($type_fun)) {
          $enode[$field] = $type_fun($node,$field);
        }
      }
      // custom field structure
      $field_fun = "fs_{$node->type}_{$field}_custom";
      if (function_exists($field_fun)) {
        $enode[$field] = $field_fun($node,$field);
      }
    }
  }
 
  $date_s =  new DateTime($node->field_date["und"][0]['value']);
  $date_e =  new DateTime($node->field_date["und"][0]['value2']);
  $enode["date_s_time"]= ($date_s->getTimestamp()); 
  $enode["date_e_time"]= ($date_e->getTimestamp());  
    
 
  $enode['url'] = url(drupal_get_path_alias('node/' . $node->nid));
  unset($node);

  return (array_merge($field_base, $enode));
}



