<?php

function fs_gallery_list_page($city) {
  $cities = _fs_city_get_cities();
  $cities_flip = array_flip($cities);
  $cid = $cities_flip[$city];
  drupal_add_css(drupal_get_path('theme', 'family') . '/css/components/gallery.css', array('group' => CSS_THEME));  
   

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'gallery')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('og_group_ref', 'target_id', $cid)
    ->addTag('is_related_school_null')    
    ->propertyOrderBy('created', 'desc')    
    ->pager(9)
    ->addMetaData('account', user_load(1));

  $result = $query->execute();

  $nodes = [];
  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);
  }

  $items = [];

  if (!empty($nodes)) {
    foreach ($nodes as $node) {
      $item = [];
      $node_wrapper = entity_metadata_wrapper('node', $node);

      $nid = $node_wrapper->getIdentifier();
      $item['nid'] = $nid;

      $url = $node_wrapper->url->value();
      $item['url'] = $url;
      $title = $node_wrapper->title->value();
      $item['title'] = $title;

      $field_gallery_main_image = $node_wrapper->field_gallery_main_image->value();
      if (!empty($field_gallery_main_image)) {
        $item['image'] = image_style_url('gallery_list_view', $field_gallery_main_image['uri']);
      }
      else {
        $item['image'] = '';
      }

      $field_gallery_date = $node_wrapper->field_gallery_date->value();
      $item['date'] = format_date($field_gallery_date, 'custom', 'Y-m');

      $field_gallery_summary = $node_wrapper->field_gallery_summary->value();
      $item['summary'] = $field_gallery_summary;
      $items[] = $item;
    }
  }


  $pager = theme('pager', array('gallery_list'));

  $variables = [
    'items' => $items,
    'pager' => $pager,
  ];


  return theme('fs_gallery_list_page', $variables);
}