<?php

include_once 'base.php';

function article_field_exclude() {
  $field_exclude = base_field_exclude();
  $field_exclude[] = 'field_article_related_articles';
  $field_exclude[] = 'field_article_slide_images';
 // $field_exclude[] = 'field_article_related_articles';

  return $field_exclude;
}

function article_mapping() {
  $article_mapping = [];
  $field_exclude = article_field_exclude();
  $node = node_last('article');
  if(is_object($node)){
  foreach ($node as $key => $value) {
    if (!in_array($key, $field_exclude)) {
      $article_mapping[$key] = array(
        'type' => 'string',
        "include_in_all" => true
      );
      /// custom type field structure  
      if (field_type($key)) {
        $type_fun = "base_" . field_type($key) . "_format_mapping";
        if (function_exists($type_fun)) {
          $article_mapping[$key] = $type_fun();
        }
      }
      // custom field structure
      $field_fun = "fs_article_{$key}_format_mapping";
      if (function_exists($field_fun)) {
        $article_mapping[$key] = $field_fun();
      }
    }
  }
  }else{
    $article_mapping = mapping_base();
  }
  return $article_mapping;
}
// custom mapping category
function  fs_article_field_article_category_format_mapping(){
   return array(
    "type" => "nested",
    "properties" => array(
      "tid" => array(
        "type" => "integer",
        "include_in_all" => true
      ),
      "name" => array(
        "type" => "string",
        "include_in_all" => true
      ),
    )
  );
}


/// change node Object to elastic search fields mapping
function article_load($node) {
  $enode = array();
  $field_base = fields_base($node);
  $field_exclude = article_field_exclude();
  $node->field_article_main_image['und'][0]['uri'] = image_storage($node->nid,'field_article_main_image');
 
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
      $field_fun = "fs_article_{$field}_custom";
      if (function_exists($field_fun)) {
        $enode[$field] = $field_fun($node,$field);
      }
   
    }
  }
  $enode['url'] = url(drupal_get_path_alias('node/' . $node->nid));
  return (array_merge($field_base, $enode));
}

//hook custom main image article
function fs_article_field_article_category_custom($node,$field) {
  $field = $node->{$field};
  if (empty($field['und']) || count($field['und']) < 1) {
    return array();
  }
  $terms = array();
  foreach ($field['und'] as $ntid) {
    $tid = $ntid['target_id'];
    $term = taxonomy_term_load($tid);
    if (!$term) {
      continue;
    }
    $terms[] = array(
      'tid' => $term->tid,
      'name' => $term->name,
    );
  }
  if (count($terms) == 1) {
    return array_shift($terms);
  }
  return $terms;
}
