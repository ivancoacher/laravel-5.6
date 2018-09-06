<?php

/**
 * Helper function to get trending now list.
 */
function fs_get_trending_now($cid, $pager) {
  // for a quick fix for cache.
  drupal_page_is_cacheable(FALSE);

  // $query = new EntityFieldQuery();

  $start = 10 + 9 * $pager;

  /*
  $date = new DateTime();
  $date->modify('-2 week');
  $time = $date->getTimestamp();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'article')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->propertyCondition('created', $time, '>')
    ->fieldCondition('og_group_ref', 'target_id', $cid)
    ->fieldOrderBy('field_article_trending_pin', 'value', 'DESC')
    ->fieldOrderBy('field_article_trending_weight', 'value', 'DESC')
    ->range($start, 6)
    ->addMetaData('account', user_load(1)); // Run the query as user 1.

  $result = $query->execute();

  $nodes = [];
  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);
  }

  shuffle($nodes);
  */

  $query = db_select('node', 'n')
    ->fields('n', array('nid'));
  $query->leftJoin('field_data_field_article_trending_push', 'atp', 'n.nid=atp.entity_id and atp.bundle= :bundle', array(':bundle' => 'article'));
  $query->leftJoin('og_membership', 'om', 'n.nid = om.etid and om.entity_type = :entity_type', array(':entity_type' => 'node'));

  $query->leftJoin('fs_article_point', 'fap', 'n.nid = fap.nid');
  $query->condition('n.status', 1)
    ->condition('n.type', 'article')
    ->condition('om.gid', $cid);

  $query->orderBy('atp.field_article_trending_push_value', 'DESC')
    ->orderBy('fap.point', 'DESC')
    ->orderBy('n.created', 'DESC');

  $query->range($start, 9)
    ->addTag('node_access');


  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $nodes = [];
  if (!empty($result)) {
    $nids = [];
    foreach ($result as $result_item) {
      $nids[] = $result_item['nid'];
    }

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
      $field_article_main_image = $node_wrapper->field_article_main_image->value();

      $item['title'] = $title;

      if (!empty($field_article_main_image)) {
        $item['image'] = image_style_url('article_trending_now_normal', $field_article_main_image['uri']);
      }
      else {
        $item['image'] = '';
      }

      $tids_root = [];
      foreach ($node_wrapper->field_article_category->getIterator() as $delta => $taxonomy_wrapper) {
        $tid = $taxonomy_wrapper->getIdentifier();
        $parents = taxonomy_get_parents_all($tid);
        $parent = end($parents);
        if (isset($parent->tid)) {
          $tids_root[] = $parent->tid;
        }
      }

      $tids_root = array_unique($tids_root);

      $categories = [];
      if (!empty($tids_root)) {
        foreach ($tids_root as $tid) {
          $term_wrapper = entity_metadata_wrapper('taxonomy_term', $tid);
          $categories[] = $term_wrapper->name->value();
        }
      }
      $item['categories'] = $categories;
      $field_article_win = $node_wrapper->field_article_win->value();
      $item['win'] = $field_article_win;

      $field_article_sponsored = $node_wrapper->field_article_sponsored->value();
      $item['sponsored'] = $field_article_sponsored;

      $field_article_editor_pick_push = $node_wrapper->field_article_editor_pick_push->value();
      $item['editor_pick'] = $field_article_editor_pick_push;

      $items[] = $item;
    }
  }

  drupal_json_output($items);
}


/**
 * Helper function to get what's new list.
 */
function fs_get_what_new($cid, $pager) {
  // for a quick fix for cache.
  drupal_page_is_cacheable(FALSE);

  $query = new EntityFieldQuery();

  $start = 10 + 9 * $pager;

  // $date = new DateTime();
  // $date->modify('-2 week');
  // $time = $date->getTimestamp();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'article')
    ->propertyCondition('status', NODE_PUBLISHED)
    // ->propertyCondition('created', $time, '>')
    ->fieldCondition('og_group_ref', 'target_id', $cid)
    ->fieldOrderBy('field_article_what_new', 'value', 'DESC')
    // ->fieldOrderBy('field_article_trending_weight', 'value', 'DESC')
    ->propertyOrderBy('created', 'desc')
    ->range($start, 9)
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
      $item = [];
      $node_wrapper = entity_metadata_wrapper('node', $node);
      $nid = $node_wrapper->getIdentifier();
      $item['nid'] = $nid;
      $url = $node_wrapper->url->value();
      $item['url'] = $url;

      $title = $node_wrapper->title->value();
      $field_article_main_image = $node_wrapper->field_article_main_image->value();

      $item['title'] = $title;

      if (!empty($field_article_main_image)) {
        $item['image'] = image_style_url('article_trending_now_normal', $field_article_main_image['uri']);
      }
      else {
        $item['image'] = '';
      }

      $tids_root = [];
      foreach ($node_wrapper->field_article_category->getIterator() as $delta => $taxonomy_wrapper) {
        $tid = $taxonomy_wrapper->getIdentifier();
        $parents = taxonomy_get_parents_all($tid);
        $parent = end($parents);
        if (isset($parent->tid)) {
          $tids_root[] = $parent->tid;
        }
      }

      $tids_root = array_unique($tids_root);

      $categories = [];
      if (!empty($tids_root)) {
        foreach ($tids_root as $tid) {
          $term_wrapper = entity_metadata_wrapper('taxonomy_term', $tid);
          $categories[] = $term_wrapper->name->value();
        }
      }

      $item['categories'] = $categories;

      $field_article_win = $node_wrapper->field_article_win->value();
      $item['win'] = $field_article_win;

      $field_article_sponsored = $node_wrapper->field_article_sponsored->value();
      $item['sponsored'] = $field_article_sponsored;

      $field_article_editor_pick_push = $node_wrapper->field_article_editor_pick_push->value();
      $item['editor_pick'] = $field_article_editor_pick_push;

      $items[] = $item;
    }
  }

  drupal_json_output($items);
}