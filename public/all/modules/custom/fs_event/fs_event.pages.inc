<?php

function fs_event_detail_page($id) {



  try {
    $client = new FsSearchEvent();
    $result_event = $client->getById($id);

    if ($result_event['hits']['total'] != 0) {
      $source = $result_event['hits']['hits'][0]['_source'];
      fs_events_add_sailthru_metatags($source);
      $item = $source;

      $venue_name_temp = $item['venue_name'];
      $venue_name = [];
      if(!empty($venue_name_temp)) {
        foreach($venue_name_temp as $item_temp) {
          if($item_temp['status']) {
            $venue_name_item = [];
            $venue_name_item['url'] = url('directory/' . $item_temp['nid'], ['absolute' => false]);
            $venue_name_item['title'] = $item_temp['title'];
            $venue_name[] = $venue_name_item;
          }

        }
      }
      $item['venue_name'] = $venue_name;


      if(!empty($source['tags'])){
      $item['tags'] = fs_base_get_taxonomy_terms_by_api($source['tags']);

      }else{
      $item['tags'] = null;
      }

      //url('directory/' . $nid, )
      $category_temp = $item['category'];
      $category = fs_base_get_taxonomy_terms_by_api($category_temp);
      $item['category'] = $category;

      $variables = [
        'item' => $item,
      ];
      $lat = $item["location"]["lat"];
      $lon = $item["location"]["lon"];
      $img = variable_get("default_image");  //$item["preview_image"]
      $json_directory = "var json_directory=[";
      $json_directory .= "{'lat':'" . $lat . "','long':'" . $lon . "','img':'" . $img . "'},";

      $json_directory .= "];";
      drupal_add_js($json_directory, array('type' => 'inline'));

      return theme('fs_event_detail_page', $variables);
    }
    else {
      drupal_access_denied();
    }
  }
  catch (Exception $e) {
    $message = $e->getMessage();
    $message .= "<br/>" . $e->getTraceAsString();
    watchdog('fs_event', $message, [], WATCHDOG_ERROR);
  }
}
