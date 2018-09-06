<?php

module_load_include('inc', 'fs_search', 'fs_search');


function fs_search_settings_form($form, &$form_state) {
  $str= "<h4>NOTICE FOR ELASTICSEARCH :</h4>";
  $str=$str."<p>Current Elasticsearch is only for the following nodes :article,events,schools,listings   </p>";
  $str=$str."<b>Drush Command-1( general ) : </b> <span style='color:#0074BD'> drush elas-mapping-create </span>  ( create mapping following nodes : 'article,events,schools,listings')<br/>" ;
  $str=$str."<b>Drush Command-2( general ) : </b> <span style='color:#0074BD'> drush elas-mapping-delete </span>  ( delete mapping following nodes : 'article,events,schools,listings')<br/>" ;
  $str=$str."<b>Drush Command-3( general ) : </b> <span style='color:#0074BD'> drush elas-indexing </span>  ( create indexing following nodes : 'article,events,schools,listings')<br/>" ;
 
  $str=$str."<b>Drush Command-4( by node ) : </b> <span style='color:#0074BD'>  drush elas-mapping-create  node_type </span> Example :'drush elas-mapping-create  schools' ( create mapping by node )<br/>" ;
  $str=$str."<b>Drush Command-5( by node ) : </b> <span style='color:#0074BD'>  drush elas-indexing node_type </span> Example :'drush elas-indexing  schools' ( create indexing by node )<br/>" ;
  $str=$str."<b>Drush Command-5( by node ) : </b> <span style='color:#0074BD'>  drush elas-indexing-delete node_type </span> Example :'drush elas-indexing-delete  schools' ( delete indexing by node )<br/>" ;
  
  $str=$str.'<br/>Please enter elastic server url for example <span style="color:#0074BD"> http://192.168.1.3:9200 </span>';

  $form['notes'] = array(
    '#markup' => t($str),
  );

//  $form['fs_search_hosts_online'] = array(
//    '#type' => 'textfield',
//    '#title' => t('Hosts for Online'),
//    '#default_value' => variable_get('fs_search_hosts_online', ''),
//  );

//  $form['fs_search_hosts_test'] = array(
//    '#type' => 'textfield',
//    '#title' => t('Hosts for Test'),
//    '#default_value' => variable_get('fs_search_hosts_test', ''),
//  );

  $form['fs_search_hosts_localhost'] = array(
    '#type' => 'textfield',
    '#title' => t('Hosts for Localhost'),
    '#default_value' => variable_get('fs_search_hosts_localhost', 'localhost:9200'),
  );

  $form = system_settings_form($form);

  return $form;
}

function fs_search_index_set_form($form, &$form_state) {

  $markup = '<p>If you want to change the mapping, Please change the mapping settings in code, then click <em>Change mapping</em> button.';
  $form['notes'] = array(
    '#markup' => $markup,
  );

  $form['actions'] = array('#type' => 'actions');

  $form['actions']['index_create'] = array(
    '#type' => 'button',
    '#value' => t('Create index'),
    '#submit' => array('fs_search_index_create'),
    '#executes_submit_callback' => TRUE,
  );

  $form['actions']['index_delete'] = array(
    '#type' => 'button',
    '#value' => t('Delete index'),
    '#submit' => array('fs_search_index_delete'),
    '#executes_submit_callback' => TRUE,
  );

  return $form;
}


