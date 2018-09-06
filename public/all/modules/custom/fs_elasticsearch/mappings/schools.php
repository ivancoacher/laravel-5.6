<?php

include_once 'base.php';

function schools_field_exclude() {
  $field_exclude = base_field_exclude();
  $field_exclude[] = 'field_email';
  $field_exclude[] = 'field_school_contact_name';
  $field_exclude[] = 'field_website';
  $field_exclude[] = 'field_school_other_payments';
  $field_exclude[] = 'field_address_in_english';
  $field_exclude[] = 'field_address_in_chinese';
  $field_exclude[] = 'field_school_admission_inquiry';
  $field_exclude[] = 'name';
  $field_exclude[] = 'promote';
  $field_exclude[] = 'author';
  $field_exclude[] = 'field_school_strengths';
  $field_exclude[] = 'field_school_manager';
 // $field_exclude[] = 'field_school_taught_languages';
 // $field_exclude[] = 'field_school_curriculum';
  return $field_exclude;
}

function fs_schools_field_school_maximum_tuition_format_mapping() {
  return array(
    'type' => 'float',
  );
}

function schools_mapping() {
  $schools_mapping = [];
  $field_exclude = schools_field_exclude();
  $node = node_last('schools');
  if (is_object($node)) {
    foreach ($node as $key => $value) {
      if (!in_array($key, $field_exclude)) {
        $schools_mapping[$key] = array(
          'type' => 'string',
          "include_in_all" => true
        );
        /// custom type field structure  
        if (field_type($key)) {
          $type_fun = "base_" . field_type($key) . "_format_mapping";
          if (function_exists($type_fun)) {
            $schools_mapping[$key] = $type_fun();
          }
        }
        // custom field structure
        $field_fun = "fs_schools_{$key}_format_mapping";
        if (function_exists($field_fun)) {
          $schools_mapping[$key] = $field_fun();
        }
      }
    }
    $schools_mapping["title_first"] = array(
      'type' => 'string',
    );
  }
  else {
    $schools_mapping = mapping_base();
  }
  return $schools_mapping;
}

/// change node Object to elastic search fields mapping
function schools_load($node) {
  $enode = array();
  $field_base = fields_base($node);
  $field_exclude = schools_field_exclude();
  //$node->field_main_image['und'][0]['uri'] = image_storage($node->nid,'field_main_image');
 
  foreach ($node as $field => $value) {
    //check if field is exclude or in field base indexing
    if (!in_array($field, $field_exclude) && !in_array($field, array_keys($field_base))) {
      if (field_type($field)) {
        $type_fun = "base_" . field_type($field) . "_custom";
        //var_dump($type_fun);
        //var_dump($field);
        
        if(function_exists($type_fun)){      
          $enode[$field] = $type_fun($node,$field);
        }
      }
      // custom field structure
      $field_fun = "fs_schools_{$field}_custom";
      if (function_exists($field_fun)) {
        $enode[$field] = $field_fun($node,$field);
      }
    }
  }
  $enode['url'] = url(drupal_get_path_alias('node/' . $node->nid));
  $enode['title_first'] = explode(' ', trim($node->title))[0];
  return (array_merge($field_base, $enode));
}


