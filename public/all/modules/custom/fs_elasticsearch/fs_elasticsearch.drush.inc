<?php


function fs_elasticsearch_drush_command() {
  $items['elas-mapping-create'] = array(
    'description' => 'Elasticsearch, to create index mapping',
    'callback' => 'create_index_mapping',
    'arguments' => array(
      'type' => 'node type of mapping',
    ),
  );
  $items['elas-mapping-delete'] = array(
    'description' => 'Waringing !!! It will delete  indexed date in Elasticsearch. To delete index mapping',
    'callback' => 'delete_index_mapping',
    'arguments' => array(
      'type' => 'node type of mapping',
    ),
  );
  $items['elas-indexing-delete'] = array(
    'description' => 'Waringing !!! It will delete all indexed date in Elasticsearch. To delete index mapping',
    'callback' => 'delete_index_mapping_type',
    'arguments' => array(
      'type' => 'node type of mapping',
    ),
  );
  $items['elas-mapping-update'] = array(
    'description' => 'Waringing !!! It wiil delete all indexed date in Elasticsearch. To delete index mapping',
    'callback' => 'update_index_mapping',
    'arguments' => array(
      'type' => 'node type of mapping',
    ),
  );
  
  $items['elas-indexing'] = array(
    'description' => 'Elasticsearch, to create index mapping',
    'callback' => 'process_indexing',
    'arguments' => array(
      'type' => 'node type of mapping',
    ),
  );


  return $items;
}

function delete_index_mapping_type($type = null){
  module_load_include('inc', 'fs_elasticsearch', 'fs_elasticsearch');

  $elasticsearch = new FsElasticsearch();
  if (drush_confirm(dt('Are you sure to continue the process ?'))) {
    $index_mapping = $elasticsearch->index_mapping();
    $index_types = $index_mapping['node']; 
    if($type!=null&& in_array($type, $index_types)){  
      $elasticsearch->es_node_delete_by_type($type);
      drush_print("");       
    }else{
        drush_print('Node type is null'); 
    }
  }
}


function process_indexing($type = null) {
  module_load_include('inc', 'fs_elasticsearch', 'fs_elasticsearch');

  $elasticsearch = new FsElasticsearch();
  if ($type != null) {
    $nids = db_query("SELECT nid FROM {node} where status=1 AND type='{$type}'")->fetchCol();
  }
  else {
    $index_mapping = $elasticsearch->index_mapping();
    $index_types = $index_mapping['node']; 
    $where =" type='".$index_types[0]."'";
    foreach ($index_types as $k => $value) { 
       if($k!=0)
       $where = $where." OR type = '".$value."'" ;          
    }
    $nids = db_query("SELECT nid FROM {node} where status=1 AND {$where} ")->fetchCol();
  }
  $count = 0;
  $indexed = 0;
  foreach ($nids as $key => $value) {
    if (!is_object($elasticsearch->load_by('nid', $value))) {
      $count++;
    }
    else {
      unset($nids[$key]);
      $indexed++;
    }
  }
  drush_print("There are " . $count . " node to indexing and " . $indexed . " indexed");
  drush_print('Data is Ready !! ');
  indexing_execute_pre_batch($nids, 'indexing_execute_batch', $count);
}

function indexing_execute_pre_batch($data, $function, $total) {
  if (drush_confirm(dt('Are you sure to continue the process ?'))) {
    if (!empty($data)) {
      $i = 1;
      foreach ($data as $item) {
        $info = [
          'nid' => intval($item),
          'current' => $i,
          'total_ready' => $total,
        ];
        $operations[] = array(
          $function, // The function to run on each row
          $info, // The row in the csv
        );
        $i++;
      }
      // Set up the batch job.
      $batch = array(
        'operations' => $operations,
        'title' => t('Indexing Data'),
        'init_message' => t('Starting...'),
        'progress_message' => t('Completed @current of @total.'),
        'error_message' => t('An error occurred'),
        'finished' => 'fs_elasticsearch_batch_finish',
        'file' => drupal_get_path('module', 'fs_elasticsearch') . '/fs_elasticsearch.batch.inc',
      );
      // Start the batch job.
      batch_set($batch);
      drush_backend_batch_process();
    }
    else {
      drush_print('Data is Empty !! ');
    }
  }
}

function create_index_mapping($type = null) {
module_load_include('inc', 'fs_elasticsearch', 'fs_elasticsearch');

  $elasticsearch = new FsElasticsearch();
  if ($type == null) {
    print $elasticsearch->create_index_mapping();
  }
  else {
    print $elasticsearch->create_index_mapping($type);
  }
}

function delete_index_mapping() { 
  module_load_include('inc', 'fs_elasticsearch', 'fs_elasticsearch');

  $elasticsearch = new FsElasticsearch();
  if (drush_confirm(dt('Are you sure to continue the process ?'))) {
    $elasticsearch->delete_index_mapping_all();
  }
  
}

function update_index_mapping($type = null) {
  module_load_include('inc', 'fs_elasticsearch', 'fs_elasticsearch');

  $elasticsearch = new FsElasticsearch();
  if (drush_confirm(dt('Are you sure to continue the process ?'))) {
    if ($type == null) {
      print "please add param node type";
    }
    else{
      $elasticsearch->update_index_mapping($type);
    }
  }
}
