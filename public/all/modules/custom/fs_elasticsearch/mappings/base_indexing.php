<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//Base fields list indexing
function fields_base($node) {
  return array(
    'nid' => $node->nid,
    'title' => $node->title,
    'uid' => $node->uid,
    'author' =>  (isset($node->name))?$node->name:'',
    'status' => $node->status,
    'created' => $node->created,
    'changed' => $node->changed,
  );
}
function base_entityreference_custom($node,$field) {
  $field = $node->{$field};
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

function base_taxonomy_term_reference_custom($node,$field) {
  $field = $node->{$field};
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
  if (count($terms) == 1) {
    return array_shift($terms);
  }
  return $terms;
}
function base_image_custom($node,$field) {
    
  return image_storage($node->nid,$field); 
}



function base_property_custom($node,$field) {
   $field = $node->{$field};
  return $field;
}

function base_text_custom($node,$field) {
   $field = $node->{$field};
  if (!empty($field['und'])) {
    return $field['und'][0]["value"];
  }
  else {
    return null;
  }
}
function base_email_custom($node,$field){
   $field = $node->{$field};
    if (!empty($field['und'])) {
    return $field['und'][0]["email"];
  }
  else {
    return null;
  }
}
function base_link_field_custom($node,$field){
  $field = $node->{$field};
   if (!empty($field['und'])) {
    return $field['und'][0]["url"];
  }
  else {
    return null;
  }
}
function base_field_amap_custom($node,$field) {
  $field = $node->{$field};
  if (isset($field['und'][0])) {
    if (!isset($field['und'][0]['lat']) || !isset($field['und'][0]['lng'])) {
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
function base_date_custom($node,$field){
   $field = $node->{$field};
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
function base_text_with_summary_custom($node,$field){
   $field = $node->{$field};
  if (!empty($field['und'])) {
    return $field['und'][0]["value"];
  }else{
    return null;
  }
}
function base_text_long_custom($node,$field){
  
   return base_text_custom($node,$field);
}
function base_telephone_custom($node,$field){
  return base_text_custom($node,$field);
}
function base_list_boolean_custom($node,$field){
  return base_text_custom($node,$field);
}
function base_datetime_custom($node,$field){
   return base_date_custom($node,$field);
}
function base_number_float_custom($node,$field){
  return floatval(base_text_custom($node,$field));
}

function base_list_text_custom($node,$field){
 return base_text_custom($node,$field);
}