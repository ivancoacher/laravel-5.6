<?php

function fs_events_add_sailthru_metatags($source) {
  $metatag_tags = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.tags',
      'content' => 'event-family',
    ],
  ];
  $sailthru_metatags['sailthru.tags'] = $metatag_tags;

  $created = $source['created'];
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
  if (!empty($source['contributor_description'])) {
    $desc = $source['contributor_description'];
  }
  else {
    $desc = $source['editor_description'];
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

  if (!empty($source['preview_detail_image'])) {
    $metatag_image_full['#attributes']['content'] = $source['preview_detail_image'];
  }
  $sailthru_metatags['sailthru.image.full'] = $metatag_image_full;


  $metatag_image_thumb = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.image.thumb',
      'content' => '',
    ],
  ];
  if (!empty($source['preview_image'])) {
    $metatag_image_thumb['#attributes']['content'] = $source['preview_image'];
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

function fs_events_es_query_date_in_between($date_filter) {

  $elasticsearch = new FsElasticsearch();
  $elasticsearch->es_query["query"]["bool"]["must"][] = array(
    "range" => array("date_s_time" => array("lte" => $date_filter->getTimestamp())
    )
  );
  $elasticsearch->es_query["query"]["bool"]["must"][] = array(
    "range" => array("date_e_time" => array("gte" => $date_filter->getTimestamp())
    )
  );
  $elasticsearch->es_sort_random();
  $elasticsearch->es_query["size"]=3;

  return $elasticsearch->es_query;
}

function fs_events_es_query_best_of() {

  $elasticsearch = new FsElasticsearch();
  $elasticsearch->es_add_filter("field_event_best_of", "1");
  $elasticsearch->es_sort_random();
  $elasticsearch->es_query["size"]=3;

  return $elasticsearch->es_query;
}
