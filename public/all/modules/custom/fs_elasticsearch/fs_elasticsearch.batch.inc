<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//Bacth Function for deleting a node
function indexing_execute_batch($info, $context) {
module_load_include('inc', 'fs_elasticsearch', 'fs_elasticsearch');
  // check if numeric
  if (is_numeric($info)) {   
    try {   
             $elasticsearch = new FsElasticsearch(); 
             $node = node_load($info);
            $rs =  $elasticsearch->es_node_save($node);
            drush_print("success indexing for nid {$info} ") ;
    }
    catch (\Exception $e) {
      $error_message = $e->getMessage();
      drush_print("item nid  " . $info . " Error :" . $error_message);
    }
  }
  else {
    drush_print("item nid  " . $info . " is not numeric ");
  }
}
