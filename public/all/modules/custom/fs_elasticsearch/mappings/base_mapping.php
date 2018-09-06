<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//entityreference mapping support mutli fields
function base_entityreference_format_mapping() {
  return array(
    "type" => "nested",
    "properties" => array(
      "nid" => array(
        "type" => "integer",
        "include_in_all" => true
      ),
      "title" => array(
        "type" => "string",
      )
    )
  );
}

//taxonomy_term_reference mapping support mutli fields
function base_taxonomy_term_reference_format_mapping() {
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

function base_field_collection_format_mapping() {
  return null;
}
function base_number_float_format_mapping(){
  return array(
    'type' => 'integer',
  );
}
function base_text_with_summary_format_mapping(){
  return array(
    'type' => 'string',
  );
}
function base_list_text_format_mapping(){
  return array(
    'type' => 'string',
  );
}
function base_number_integer_format_mapping() {
  return array(
    'type' => 'integer',
  );
}
function base_datetime_format_mapping(){
  return array(
    "type" => "object",
    "properties" => array(
      "date_start" => array(
        "type" => "date",
        "format" => "yyyy-MM-dd HH:mm:ss",
      ),
      "date_end" => array(
        "type" => "date",
        "format" => "yyyy-MM-dd HH:mm:ss",
      ),
    )
  );
}
function base_field_amap_format_mapping() {
  return array(
          "type" => "geo_point",
  );
}
// Base fields list for elastic search mapping 
function mapping_base() {
  return array(
    'nid' => array(
      'type' => 'integer',
     
    ),
    'title' => array(
      'type' => 'string',
      
    ),
    'uid' => array(
      'type' => 'integer',
     
    ),
    'author' => array(
      'type' => 'string',
     
    ),
    'status' => array(
      'type' => 'boolean',
     
    ),
    'created' => array(
      'type' => 'date',
      //     "format" => "yyyy-MM-dd HH:mm:ss",
     
    ),
    'changed' => array(
      'type' => 'date',
//      "format" => "yyyy-MM-dd HH:mm:ss",
    
    ),
  );
}
