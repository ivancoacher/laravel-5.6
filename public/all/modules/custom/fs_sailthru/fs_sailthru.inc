<?php

function fs_sailthru_meta_tags($entity) {
  $sailthru_metatags = [];
  $node_wrapper = entity_metadata_wrapper('node', $entity);

  $metatag_tags = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.tags',
      'content' => '',
    ],
  ];
  $tags = [];
  $type = $node_wrapper->getBundle();

  // dpm($node_wrapper->getPropertyInfo());
//  
//  $tags[] = $type;
//
//  $og_group_ref = $node_wrapper->og_group_ref->value();
//  if (!empty($og_group_ref)) {
//    foreach ($og_group_ref as $og_item) {
//      $tags[] = strtolower($og_item->title);
//    }
//  }
//  $field_article_category = $node_wrapper->field_article_category->value();
//
//  if (!empty($field_article_category)) {
//    foreach ($field_article_category as $category_item) {
//      if (is_object($category_item)) {
//        $category_item_wrapper = entity_metadata_wrapper('taxonomy_term', $category_item);
//        $field_term_sailthru_tag = $category_item_wrapper->field_term_sailthru_tag->value();
//        $field_term_sailthru_tag = trim($field_term_sailthru_tag);
//        if($field_term_sailthru_tag) {
//          $temp = explode(',', $field_term_sailthru_tag);
//          if(is_array($temp) && !empty($temp)) {
//            foreach($temp as $temp_item) {
//              $tags[] = $temp_item;
//            }
//          }
//        }
//      }
//    }
//  }
//
//  array_unique($tags);

  $tags[] = $type . '-family';
  $metatag_tags['#attributes']['content'] = implode(',', $tags);
  $sailthru_metatags['sailthru.tags'] = $metatag_tags;

  //Meta Author
  $metatag_author = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.author',
      'content' => '',
    ],
  ];
  $name = $node_wrapper->author->name->value();
  $metatag_author['#attributes']['content'] = $name;
  $sailthru_metatags['sailthru.author'] = $metatag_author;

  //Meta Created Date
  $created = $node_wrapper->created->value();
  $metatag_date = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.date',
      'content' => format_date($created, 'custom', 'Y-m-d H:i:s'),
    ],
  ];
  $sailthru_metatags['sailthru.date'] = $metatag_date;


  //Meta image
  $metatag_image_full = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.image.full',
      'content' => '',
    ],
  ];
  $field_main_image = $node_wrapper->field_main_image->value();
  if (!empty($field_main_image)) {
    $metatag_image_full['#attributes']['content'] = file_create_url($field_main_image['uri']);
  }
  $sailthru_metatags['sailthru.image.full'] = $metatag_image_full;
  $metatag_image_thumb = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.image.thumb',
      'content' => '',
    ],
  ];
  if (!empty($field_main_image)) {
    $metatag_image_thumb['#attributes']['content'] = image_style_url('article_taxonomy_normal', $field_main_image['uri']);
  }
  $sailthru_metatags['sailthru.image.thumb'] = $metatag_image_thumb;
  $metatag_title = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.title',
      'content' => '',
    ],
  ];

  //Meta Title
  $title = $node_wrapper->title->value();
  $metatag_title['#attributes']['content'] = $title;
  $sailthru_metatags['sailthru.title'] = $metatag_title;


  // Meta Location
  $metatag_location = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.location',
      'content' => '',
    ],
  ];
  $metatag_location['#attributes']['content'] = 'shanghai';
  $sailthru_metatags['sailthru.location'] = $metatag_location;
  
  //Meta Description
  $metatag_summary = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.description',
      'content' => '',
    ],
  ];
  
  if($node_wrapper->field_contributor_description->value()){
    $field_body = $node_wrapper->field_contributor_description->value();
  }else{
    $field_body = $node_wrapper->field_editor_description->value();
  }
  //if (!empty($field_body['value'])) {
  $metatag_summary['#attributes']['content'] = substr(drupal_html_to_text($field_body), 0, 900);
  //}
  $sailthru_metatags['sailthru.description'] = $metatag_summary;
  //Build
  foreach ($sailthru_metatags as $key => $data) {
    drupal_add_html_head($data, $key);
  }
}

?>