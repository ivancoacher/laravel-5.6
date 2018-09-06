<?php

module_load_include('inc', 'fs_taxonomy', 'fs_taxonomy');

//module_load_include('inc', 'fs_elasticsearch', 'fs_elasticsearch');
/**
 * @param $term
 *
 * @return string
 */
function fs_taxonomy_article_term_page($term) {

 //$elasticsearch = new FsElasticsearch();

// // $elasticsearch->create_index_mapping();
 // $nid=268; //schools
 // $nid =35 ;// article; 
  //$node = node_load($nid);
 
//$query = '{ "match_all": {} }';
//$query['query']['match_all']["nid"] = 177000;
//$query= drupal_json_encode($query);
//$r = $elasticsearch->es_node_list($query,'events');  
//  $r= $elasticsearch->es_node_save($node);
// // $r= $elasticsearch->es_node_delete($node);
//var_dump( $elasticsearch->es_node_get($node));die();
 //$r =   $elasticsearch->create_index_mapping('article');
 //$r =   $elasticsearch->create_index_mapping();
 //$r = $elasticsearch->update_index_mapping('events');  
 //$r=$elasticsearch->delete_index_mapping();  
 //print $r;
 // die();
  
  $path = drupal_get_path('module', 'fs_taxonomy');
  $path_them = variable_get("path_theme", NULL);
  drupal_add_css($path . '/css/article.css', array('group' => CSS_THEME));
  drupal_add_css(drupal_get_path('theme', 'family') . '/lib/salvattore/salvattore.css', array('group' => CSS_THEME));
  drupal_add_js($path_them . '/lib/salvattore/salvattore.min.js', array('scope' => 'footer'));
  drupal_add_js($path . '/js/fs_taxonomy_article_term_page.js', array('scope' => 'footer'));

  // If there is a menu link to this term, the link becomes the last part of
  // the active trail, and the link name becomes the page title. Thus, we must
  // explicitly set the page title to be the term title.
  drupal_set_title($term->name);

  // Set the term path as the canonical URL to prevent duplicate content.
  $uri = entity_uri('taxonomy_term', $term);
  drupal_add_html_head_link(array('rel' => 'canonical', 'href' => url($uri['path'], $uri['options'])), TRUE);
  // Set the non-aliased path as a default shortlink.
  drupal_add_html_head_link(array('rel' => 'shortlink', 'href' => url($uri['path'], array_merge($uri['options'], array('alias' => TRUE)))), TRUE);

  // Generate metatags output.
  if ($output = metatag_generate_entity_metatags($term, 'taxonomy_term')) {
    $instance = metatag_get_entity_metatags_instance($term, 'taxonomy_term', $term->vocabulary_machine_name);
    // We need to register the term's metatags, so we can later fetch them.
    // @see metatag_page_build().
    metatag_page_set_metatags($instance, $output);
  }

  $tid = $term->tid;

  drupal_add_js(array('fs_taxonomy' => ['tid' => $tid]), ['type' => 'setting']);

  $name = $term->name;
  drupal_add_js('var tid="' . $tid . '";', array('type' => 'inline'));

  $length = 9;
  
  $nodes = fs_taxonomy_get_articles_by_tid($tid, 0, $length);
  $items = [];

  if ($nodes) {
    $index = 0;
    foreach ($nodes as $node) {
      if ($index == 0) {
        $items[] = fs_taxonomy_get_top_article($node);
      }
      else {
        $items[] = fs_taxonomy_get_normal_article($node);
      }
      $index++;
    }
  }
  $variables = [
    'name' => $name,
    'items' => $items,
  ];

  return theme('fs_taxonomy_article_term_page', $variables);
}

function fs_taxonomy_get_article_callback($tid, $pager, $length = 9) {
  drupal_page_is_cacheable(FALSE);
  $nodes = fs_taxonomy_get_articles_by_tid($tid, $pager, $length);
  if ($nodes) {
    foreach ($nodes as $node) {
      $items[] = fs_taxonomy_get_normal_article($node);
    }
  }
  else {
    $items = array(0);
  }

  drupal_json_output($items);
}