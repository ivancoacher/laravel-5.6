<?php

//Base field exclude for elastic search mapping
function base_field_exclude() {
  return array(
    "vid", "log", "comment", "sticky", "language", "tnid", "translate", "revision_timestamp",
    "revision_uid", "og_group_ref", "path", "rdf_mapping", "cid", "last_comment_timestamp",
    "last_comment_name", "last_comment_uid", "comment_count", "data", "picture", "type"
  );
}
// Field check if empty
function field($node, $string) {

  if (isset($node->{$string}) && !empty($node->{$string})) {
    // var_dump($node->{$string}['und']);
    return $node->{$string}['und'];
  }
  else {
    return null;
  }
}
// Get one item node  
function node_last($type) {
  $r = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('n.type', trim($type), '=')
      ->orderBy('nid', 'DESC')
      ->range(0, 1)
      ->execute()
      ->fetchObject();
  if (is_object($r)) {
    return node_load($r->nid);
  }
  else {
    return null;
  }
}

//Get field type
function type_fields_default() {
  return array(
    "name" => "property",
    "promote" => "property",
    "sticky" => "property",
    "status" => "property"
  );
}
function field_type($name) {
  $type_fields_default = type_fields_default();
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

function image_storage($nid,$field_name){
  $entity = entity_load('node', array($nid));
  $node_fix = reset($entity);
  $node_wrapper = entity_metadata_wrapper('node', $node_fix);
  $image = $node_wrapper->{$field_name}->value();

  return $image["uri"]; 
}

include_once 'base_mapping.php';
include_once 'base_indexing.php';


/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

