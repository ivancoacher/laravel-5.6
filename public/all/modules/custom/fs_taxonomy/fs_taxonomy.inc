<?php

module_load_include('inc', 'fs_elasticsearch', 'fs_elasticsearch');
module_load_include('inc', 'fs_elasticsearch', 'fs_elasticsearch');

function  fs_taxonomy_get_articles_by_tid_mapping($tid, $pager, $length){
   //$elasticsearch = new FsElasticsearch();

   
}
function fs_taxonomy_get_articles_by_tid($tid, $pager, $length) {
 
  $term = taxonomy_term_load($tid);
  $vid = $term->vid;

  $tids = [$tid];
  $children = taxonomy_get_children($tid, $vid);
  if (!empty($children)) {
    foreach ($children as $item) {
      $tids[] = $item->tid;
    }
  }

  $start = $pager * $length;
  // $start = $pager;

  $query = db_select('node', 'n')
    ->fields('n', ['nid']);
  $query->condition('n.status', '1', '=')
    ->condition('n.type', 'article', '=');

  $query->leftJoin('field_data_field_article_category', 'fac', 'n.nid = fac.entity_id');
  $query->condition('fac.entity_type', 'node', '=')
    ->condition('fac.bundle', 'article', '=')
    ->condition('fac.field_article_category_target_id', $tids, 'IN');

  $query->distinct('n.nid');
  $query->orderBy('n.created', 'DESC');

  $query->range($start, $length);

  $result = $query->execute();

  // dpq($query);
  $nids = [];
  while ($record = $result->fetchAssoc()) {
    $nids[] = $record['nid'];
  }
  if (!empty($nids)) {
    $nodes = entity_load('node', $nids);
  }

  if (isset($nodes)) {
    return $nodes;
  }
  else {
    return NULL;
  }
}

function fs_taxonomy_get_top_article($node) {
  $item = [];

  $node_wrapper = entity_metadata_wrapper('node', $node);

  $nid = $node_wrapper->getIdentifier();
  $item['nid'] = $nid;

  $url = $node_wrapper->url->value();
  $item['url'] = $url;

  $title = $node_wrapper->title->value();

  // $field_article_summary = $node_wrapper->field_article_summary->value();
  $field_article_body = $node_wrapper->field_article_body->value();
  $field_article_main_image = $node_wrapper->field_article_main_image->value();
  // $field_article_win = $node_wrapper->field_article_win->value();
  // $field_article_sponsored = $node_wrapper->field_article_sponsored->value();
  // $field_article_editor_pick_push = $node_wrapper->field_article_editor_pick_push->value();

  $item['title'] = $title;
  if (!empty($field_article_body['value'])) {
    $item['summary'] = truncate_utf8(drupal_html_to_text($field_article_body['value']), 450, TRUE, TRUE);
  }
  else {
    $item['summary'] = '';
  }


  if (!empty($field_article_main_image)) {
    $item['image'] = image_style_url('article_taxonomy_top', $field_article_main_image['uri']);
  }
  else {
    $item['image'] = '';
  }
  // $items[$nid]['win'] = $field_article_win;
  // $items[$nid]['sponsored'] = $field_article_sponsored;
  // $items[$nid]['editor_pick'] = $field_article_editor_pick_push;

  return $item;
}

function fs_taxonomy_get_normal_article($node) {
  $item = [];
  $node_wrapper = entity_metadata_wrapper('node', $node);

  $nid = $node_wrapper->getIdentifier();
  $item['nid'] = $nid;

  $url = $node_wrapper->url->value();
  $item['url'] = $url;

  $title = $node_wrapper->title->value();
  // $field_article_summary = $node_wrapper->field_article_summary->value();
  $field_article_body = $node_wrapper->field_article_body->value();
  $field_article_main_image = $node_wrapper->field_article_main_image->value();
  // $field_article_win = $node_wrapper->field_article_win->value();
  // $field_article_sponsored = $node_wrapper->field_article_sponsored->value();
  // $field_article_editor_pick_push = $node_wrapper->field_article_editor_pick_push->value();

  $item['title'] = $title;
  $rand = array(100,300,200,400,500,50);                                             
  if (!empty($field_article_body['value'])) {
    $item['summary'] = explode("---",substr(drupal_html_to_text($field_article_body['value']),0, $rand[mt_rand(0,5)]))[0]."...";
    
    
  }
  else {
    $item['summary'] = '';
  }

  if (!empty($field_article_main_image)) {
    $item['image'] = image_style_url('article_taxonomy_normal', $field_article_main_image['uri']);
  }
  else {
    $item['image'] = '';
  }
  // $items[$nid]['win'] = $field_article_win;
  // $items[$nid]['sponsored'] = $field_article_sponsored;
  // $items[$nid]['editor_pick'] = $field_article_editor_pick_push;
  return $item;
}