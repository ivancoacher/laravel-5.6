<?php

/**
 * Helper function to get most read article.
 */
function fs_article_get_most_read_list() {
  $cid = fs_city_get_selected_city_id();

  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'article')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_article_most_read_push', 'value', '1', '=')
    ->fieldCondition('og_group_ref', 'target_id', $cid)
    ->fieldOrderBy('field_article_most_read_pin', 'value', 'DESC')
    ->fieldOrderBy('field_article_most_read_weight', 'value', 'DESC')
    ->range(0, 6)
    ->addMetaData('account', user_load(1)); // Run the query as user 1.

  $result = $query->execute();

  $nodes = [];
  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);
  }

  return $nodes;
}
/**
 * Item slide home.
 */
function fs_article_item_icon($item) {
  if ($item['editor_pick']) {
    $stick = "<div class=\"img-icon\"><img class=\"img-icon-content\" src=\"" . variable_get("path_theme", NULL) . "/images/icon/editor_pick.png\" alter=\"\" /></div>";
  }
  else {
    if ($item['sponsored']) {
      $stick = "<div class=\"sponsored img-icon \"><img class=\"img-icon-content\" src=\"" . variable_get("path_theme", NULL) . "/images/icon/sponsored.png\" alter=\"\" /></div>";

    }
    elseif ($item['win']) {
      $stick = "<div class=\"img-icon\"><img class=\"img-icon-content\" src=\"" . variable_get("path_theme", NULL) . "/images/icon/win.png\" alter=\"\" /></div>";

    }
    else {
      $stick = "";

    }
  }
  return $stick;

}
/**
 * Item slide home.
 */
function fs_article_item_slide($item) {
//  if ($item['editor_pick']) {
//    $stick = "<div class=\"img-icon\"><img class=\"img-icon-content\" src=\"" . variable_get("path_theme", NULL) . "/images/icon/editor_pick.png\" alter=\"\" /></div>";
//  }
//  else {
//    if ($item['sponsored']) {
//      $stick = "<div class=\"sponsored img-icon \"><img class=\"img-icon-content\" src=\"" . variable_get("path_theme", NULL) . "/images/icon/sponsored.png\" alter=\"\" /></div>";
//
//    }
//    elseif ($item['win']) {
//      $stick = "<div class=\"img-icon\"><img class=\"img-icon-content\" src=\"" . variable_get("path_theme", NULL) . "/images/icon/win.png\" alter=\"\" /></div>";
//
//    }
//    else {
//      $stick = "";
//
//    }
//  }
  $stick = fs_article_item_icon($item);
  echo " <div class=\"item\"><div id=\"effect-1\" class=\"effects clearfix\">   <div class=\"img\">\n";
  echo   $stick . "\n";
  echo "                                    <a href=\"" . $item['url'] . "\" ><img  src=\"" . $item['image'] . "\" class=\"img-responsive img-slide-show\" /></a>\n";
  echo "                                    <div class=\"slide-title\">\n";
  echo "                                        <p>" . $item['title'] . "</p>   \n";
  echo "</div>\n";
  echo "</div></div></div>\n";

}

/**
 * Helper function to get most pop article.
 */
function fs_article_get_most_pop_list() {
  $cid = fs_city_get_selected_city_id();

  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'article')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_article_most_pop_push', 'value', '1', '=')
    ->fieldCondition('og_group_ref', 'target_id', $cid)
    ->fieldOrderBy('field_article_most_pop_pin', 'value', 'DESC')
    ->fieldOrderBy('field_article_most_pop_weight', 'value', 'DESC')
    ->range(0, 6)
    ->addMetaData('account', user_load(1)); // Run the query as user 1.

  $result = $query->execute();

  $nodes = [];
  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);
  }

  return $nodes;
}

/**
 * Helper function to get editor's pick term .
 */
function fs_article_get_editor_pick_term_list() {
  $cid = fs_city_get_selected_city_id();
  //TODO: now is hard-coding.
  if ($cid == 1) {
    $bundle = 'article_category_sh';
  }
  else {
    $bundle = 'article_category_bj';
  }
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'taxonomy_term')
    ->entityCondition('bundle', $bundle)
    ->fieldCondition('field_term_editor_pick', 'value', '1', '=')
    ->propertyOrderBy('weight')
    ->addMetaData('account', user_load(1));

  $result = $query->execute();

  $terms = [];
  if (isset($result['taxonomy_term'])) {
    $tids = array_keys($result['taxonomy_term']);
    $terms = entity_load('taxonomy_term', $tids);
  }

  return $terms;
}


function fs_article_newsletter_get_related_articles() {
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'article')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->propertyOrderBy('created', 'desc')
    ->range(0, 3)
    ->addMetaData('account', user_load(1)); // Run the query as user 1.

  $result = $query->execute();

  $nodes = [];
  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);
  }

  $items = [];

  if (!empty($nodes)) {
    foreach ($nodes as $node) {
      $item = new stdClass();
      $node_wrapper = entity_metadata_wrapper('node', $node);
      // $nid = $node_wrapper->getIdentifier();
      $title = $node_wrapper->title->value();
      $url = $node_wrapper->url->value();
      $field_article_main_image = $node_wrapper->field_article_main_image->value();

      $item->title = $title;
      $item->url = $url;

      if (!empty($field_article_main_image)) {
        $item->image = image_style_url('article_newsletter_style', $field_article_main_image['uri']);
      }
      else {
        $item->image = '';
      }

      $items[] = $item;

    }
  }

  return $items;
}

/**
 * Add sailthru metatags inside html head section
 * @param $entity
 */
function fs_article_add_sailthru_metatags($entity) {
  module_load_include('inc', 'fs_sailthru', 'fs_sailthru');
  //this is done on the header manually
  // fs_sailthru_add_tags_js();

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

  // dpm($node_wrapper->getPropertyInfo());

  $type = $node_wrapper->getBundle();
  $tags[] = $type;

  $og_group_ref = $node_wrapper->og_group_ref->value();
  if (!empty($og_group_ref)) {
    foreach ($og_group_ref as $og_item) {
      $tags[] = strtolower($og_item->title);
    }
  }

  $field_article_category = $node_wrapper->field_article_category->value();

  if (!empty($field_article_category)) {
    foreach ($field_article_category as $category_item) {
      if (is_object($category_item)) {
        $category_item_wrapper = entity_metadata_wrapper('taxonomy_term', $category_item);
        $field_term_sailthru_tag = $category_item_wrapper->field_term_sailthru_tag->value();
        $field_term_sailthru_tag = trim($field_term_sailthru_tag);
        if($field_term_sailthru_tag) {
          $temp = explode(',', $field_term_sailthru_tag);
          if(is_array($temp) && !empty($temp)) {
            foreach($temp as $temp_item) {
              $tags[] = $temp_item;
            }
          }
        }
      }
    }
  }

  array_unique($tags);
  $tags[]='article-family';
  $metatag_tags['#attributes']['content'] = implode(',', $tags);
  $sailthru_metatags['sailthru.tags'] = $metatag_tags;


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


  $created = $node_wrapper->created->value();
  $metatag_date = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.date',
      'content' => format_date($created, 'custom', 'Y-m-d H:i:s'),
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
  $field_article_body = $node_wrapper->field_article_body->value();
  if (!empty($field_article_body['value'])) {
    $metatag_summary['#attributes']['content'] = substr(drupal_html_to_text($field_article_body['value']), 0, 900);
  }
  $sailthru_metatags['sailthru.description'] = $metatag_summary;

  $metatag_image_full = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.image.full',
      'content' => '',
    ],
  ];
  $field_article_main_image = $node_wrapper->field_article_main_image->value();
  if(!empty($field_article_main_image)) {
    $metatag_image_full['#attributes']['content'] = file_create_url($field_article_main_image['uri']);
  }
  $sailthru_metatags['sailthru.image.full'] = $metatag_image_full;


  $metatag_image_thumb = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.image.thumb',
      'content' => '',
    ],
  ];
  if(!empty($field_article_main_image)) {
    $metatag_image_thumb['#attributes']['content'] = image_style_url('article_taxonomy_normal', $field_article_main_image['uri']);
  }
  $sailthru_metatags['sailthru.image.thumb'] = $metatag_image_thumb;


  $metatag_title = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.title',
      'content' => '',
    ],
  ];

  $title = $node_wrapper->title->value();
  $metatag_title['#attributes']['content'] = $title;
  $sailthru_metatags['sailthru.title'] = $metatag_title;


  $metatag_location = [
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'sailthru.location',
      'content' => '',
    ],
  ];

  $location = [];

  if (isset($og_group_ref) && !empty($og_group_ref)) {
    foreach ($og_group_ref as $og_item) {
      $location[] = strtolower($og_item->title);
    }
  }
  $metatag_location['#attributes']['content'] = implode(',', $location);
  $sailthru_metatags['sailthru.location'] = $metatag_location;


  foreach ($sailthru_metatags as $key => $data) {
    drupal_add_html_head($data, $key);
  }

}
