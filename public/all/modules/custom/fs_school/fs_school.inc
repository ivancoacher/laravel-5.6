<?php

function fs_school_add_sailthru_metatags($node) {
  $metatag_tags = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.tags',
      'content' => 'school-family',
    ],
  ];
  $sailthru_metatags['sailthru.tags'] = $metatag_tags;

  $created = date("F j, Y", $node->created) ;
  $metatag_date = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.date',
      'content' => $created,
    ],
  ];
  $sailthru_metatags['sailthru.date'] = $metatag_date; 
  $metatag_summary = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.description',
      'content' => '',
    ],
  ];
  if (!empty($node->field_contributor_description['und'])) {
    $desc = $node->field_contributor_description['und'][0]['value'];
  }
  else {
    if (!empty($node->field_editor_description['und'])) {
    $desc = $node->field_editor_description['und'][0]['value'] ;      
    }else{
     $desc=""; 
    }
  }

  if (!empty($desc)) {
    $metatag_summary['#attributes']['content'] = truncate_utf8(drupal_html_to_text($desc), 900, TRUE, TRUE);
  }
  $sailthru_metatags['sailthru.description'] = $metatag_summary;
  $metatag_image_full = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.image.full',
      'content' => '',
    ],
  ];
  if (!empty($node->field_main_image['und'])){
    $metatag_image_full['#attributes']['content'] = file_create_url($node->field_main_image['und'][0]['uri']);
  }
  $sailthru_metatags['sailthru.image.full']=$metatag_image_full;


  $metatag_image_thumb = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.image.thumb',
      'content' => '',
    ],
  ];
  if (!empty($node->field_main_image['und'])){
    $metatag_image_thumb['#attributes']['content'] = file_create_url($node->field_main_image['und'][0]['uri']);
  }
  $sailthru_metatags['sailthru.image.thumb'] = $metatag_image_thumb;


  $metatag_title = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.title',
      'content' => '',
    ],
  ];

  $title = $source['title'];
  $metatag_title['#attributes']['content'] = $title;
  $sailthru_metatags['sailthru.title'] = $metatag_title;


  foreach ($sailthru_metatags as $key => $data) {
    drupal_add_html_head($data, $key);
  }
}
