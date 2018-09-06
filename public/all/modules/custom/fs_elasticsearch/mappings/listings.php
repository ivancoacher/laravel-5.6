<?php

include_once 'base.php';

function listings_field_exclude() {
  $field_exclude = base_field_exclude();
  $field_exclude[] = 'field_related_venue';
  $field_exclude[] = 'field_email';
  $field_exclude[] = 'field_website';
  $field_exclude[] = 'field_operating_hours';
  $field_exclude[] = 'field_address_in_english';
  $field_exclude[] = 'field_address_in_chinese';
  $field_exclude[] = 'field_nearest_metro_station';
  $field_exclude[] = 'name';
  $field_exclude[] = 'promote';
  $field_exclude[] = 'author';
  $field_exclude[] = 'field_closed';
  $field_exclude[] = 'field_gallery';
  $field_exclude[] = 'uid';
  return $field_exclude;
}
function listings_mapping() {
  $listings_mapping = [];
  $field_exclude = listings_field_exclude();
  $node = node_last('listings');
  if(is_object($node)){
  foreach ($node as $key => $value) {
    if (!in_array($key, $field_exclude)) {
      $listings_mapping[$key] = array(
        'type' => 'string',
        "include_in_all" => true
      );
      /// custom type field structure  
      if (field_type($key)) {
        $type_fun = "base_" . field_type($key) . "_format_mapping";
        if (function_exists($type_fun)) {
          $listings_mapping[$key] = $type_fun();
        }
      }
      // custom field structure
      $field_fun = "fs_listings_{$key}_format_mapping";
      if (function_exists($field_fun)) {
        $listings_mapping[$key] = $field_fun();
      }
    }
  }
  }else{
    $listings_mapping = mapping_base();
  }
  return $listings_mapping;
}


/// change node Object to elastic search fields mapping
function listings_load($node) {
  $enode = array();
  $field_base = fields_base($node);
  $field_exclude = listings_field_exclude();
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
      $field_fun = "fs_listings_{$field}_custom";
      if (function_exists($field_fun)) {
        $enode[$field] = $field_fun($node,$field);
      }
   
    }
  }

  $enode['url'] = url(drupal_get_path_alias('node/' . $node->nid));
  unset($node);
  return (array_merge($field_base, $enode));
}

