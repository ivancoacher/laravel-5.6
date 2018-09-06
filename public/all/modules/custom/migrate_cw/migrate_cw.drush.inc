<?php

function migrate_cw_drush_command()
{
    $items = [];
  // Name of the drush command.
  $items['migrate_cw_content'] = [
    'description' => 'Migrate listings from CW DB',
    'callback' => 'migrate_cw_content',
  ];

    return $items;
}

function connectToLegacyDB(){
  Database::addConnectionInfo('cw_db', 'default','CW DB');
}

function returnQuery(){
    return "SELECT DISTINCT
                node.nid AS 'nid',
                node.title AS 'title',
                pr.`field_price_range_value` AS `price Range`,
                oh.`field_operating_hours_value` AS `operating hours`,
                CASE
                WHEN trd.tid IN (405,1382,420,784,432,438,447,454,458,1402,463,479,494,499,507) THEN trd.name
                ELSE trd3.name END
                 AS `category`,
                trd4.name as `neighborhood`,
                fnms.`field_nearest_metro_station_value` as `metro`,
                ed.`field_editor_description_value`  AS `editor description`,
                b.`body_value` AS `contributor description`,
                liie.`field_location_information_in_en_value` AS `address en`,
                liic.`field_location_information_in_ch_value` AS `address cn`,
                et.`field_event_telephone_value` AS `telephone`,
                vec.`field_venue_email_contact_email` AS `email`,
                ew.`field_event_website_value` AS `website`,
                wi.`field_wechat_id_value` AS `wechat`,
                fm.uri AS `main image`,
                lc.`field_listing_closed_value` AS `closed`,
                fmi.`field_map_information_lat` AS `lat`,
                fmi.`field_map_information_lon` AS `lon`,
                ltmin.`field_listing_tuition_min_value` AS `min tuition`,
                ltmax.`field_listing_tuition_max_value` AS `max tuition`,
                ltop.`field_listing_other_payments_value` AS `other payments`,
                ltfd.`field_listing_foundation_date_value` AS `foundation date`,
                trd5.name AS `school type`,
                ltai.`field_listing_admission_inquiry_url` AS `inquiry link`
                FROM
                node node
                LEFT JOIN field_data_field_city field_data_field_city ON node.nid = field_data_field_city.entity_id AND (field_data_field_city.entity_type = 'node' AND field_data_field_city.deleted = '0')
                LEFT JOIN field_data_field_price_range pr ON node.nid = pr.entity_id AND (pr.entity_type = 'node' AND pr.deleted = '0')
                LEFT JOIN field_data_field_operating_hours oh ON node.nid = oh.entity_id AND (oh.entity_type = 'node' AND oh.deleted = '0')
                LEFT JOIN field_data_field_features f ON node.nid = f.entity_id AND (f.entity_type = 'node' AND f.deleted = '0')
                LEFT JOIN field_data_field_editor_description ed ON node.nid = ed.entity_id AND (ed.entity_type = 'node' AND ed.deleted = '0')
                LEFT JOIN field_data_body b ON node.nid = b.entity_id AND (b.entity_type = 'node' AND b.deleted = '0')
                LEFT JOIN field_data_field_location_information_in_en liie ON node.nid = liie.entity_id AND (liie.entity_type = 'node' AND liie.deleted = '0')
                LEFT JOIN field_data_field_location_information_in_ch liic ON node.nid = liic.entity_id AND (liic.entity_type = 'node' AND liic.deleted = '0')
                LEFT JOIN field_data_field_event_telephone et ON node.nid = et.entity_id AND (et.entity_type = 'node' AND et.deleted = '0')
                LEFT JOIN field_data_field_venue_email_contact vec ON node.nid = vec.entity_id AND (vec.entity_type = 'node' AND vec.deleted = '0')
                LEFT JOIN field_data_field_event_website ew ON node.nid = ew.entity_id AND (ew.entity_type = 'node' AND ew.deleted = '0')
                LEFT JOIN field_data_field_wechat_id wi ON node.nid = wi.entity_id AND (wi.entity_type = 'node' AND wi.deleted = '0')
                LEFT JOIN field_data_field_listing_closed lc ON node.nid = lc.entity_id AND (lc.entity_type = 'node' AND lc.deleted = '0')
                LEFT JOIN field_data_field_listing_tuition_min ltmin ON node.nid = ltmin.entity_id AND (ltmin.entity_type = 'node' AND ltmin.deleted = '0')
                LEFT JOIN field_data_field_listing_tuition_max ltmax ON node.nid = ltmax.entity_id AND (ltmax.entity_type = 'node' AND ltmax.deleted = '0')
                LEFT JOIN field_data_field_listing_other_payments ltop ON node.nid = ltop.entity_id AND (ltop.entity_type = 'node' AND ltop.deleted = '0')
                LEFT JOIN field_data_field_listing_foundation_date ltfd ON node.nid = ltfd.entity_id AND (ltfd.entity_type = 'node' AND ltfd.deleted = '0')
                LEFT JOIN field_data_field_listing_school_type ltst ON node.nid = ltst.entity_id AND (ltst.entity_type = 'node' AND ltst.deleted = '0')
                LEFT JOIN field_data_field_listing_admission_inquiry ltai ON node.nid = ltai.entity_id AND (ltai.entity_type = 'node' AND ltai.deleted = '0')
                LEFT JOIN field_data_field_neighborhoods fn ON fn.`entity_id` = node.`nid`
                LEFT JOIN field_data_field_nearest_metro_station fnms ON fnms.`entity_id` = node.`nid`
                LEFT JOIN taxonomy_index ti ON ti.nid = node.nid
                LEFT JOIN taxonomy_term_hierarchy th ON th.tid = f.`field_features_tid`
                LEFT JOIN taxonomy_term_data trd ON trd.tid = f.`field_features_tid`
                LEFT JOIN taxonomy_term_data trd4 ON fn.`field_neighborhoods_tid` = trd4.`tid`
                LEFT JOIN taxonomy_term_data trd5 ON ltst.`field_listing_school_type_tid` = trd5.`tid`
                LEFT JOIN taxonomy_term_data trd3 ON trd3.tid = th.`parent`
                LEFT JOIN `field_data_field_listing_avail_for_fs` laff ON node.nid = laff.entity_id AND (laff.entity_type = 'node' AND laff.deleted = '0')
                LEFT JOIN field_data_field_logo_visual_upload_feature lvuf ON node.nid = lvuf.entity_id AND (lvuf.entity_type = 'node' AND lvuf.deleted = '0')
                LEFT JOIN file_managed fm ON fm.fid = lvuf.field_logo_visual_upload_feature_fid
                LEFT JOIN `field_data_field_map_information` fmi ON fmi.`entity_id` = node.nid


                WHERE node.type IN  ('cw_listing') AND field_data_field_city.field_city_tid = '2' AND node.status = '1' AND laff.`field_listing_avail_for_fs_value` =1
                GROUP BY node.nid
                ORDER BY node.title ASC";
}

function getNodesToMigrate(){
  $nodes = array();
  connectToLegacyDB();
  try {
      db_set_active('cw_db');
      $sql = returnQuery();
      $results = db_query($sql);
      if ($results) {
          while ($row = $results->fetchAssoc()) {
              $nodes[] = $row;
          }
      }
      drush_print('Total:' . count($nodes));
      db_set_active();
  } catch (Exception $e) {
      $msg = $e->getMessage();
      drush_print('error', $msg);
      db_set_active();
  } finally{
    Database::closeConnection('cw_db', 'default');
    return $nodes;
  }
}

function getImageFromStorage($node_id){
  $image = '';
  connectToLegacyDB();
  try {
      db_set_active('cw_db');

      $sql = "SELECT DISTINCT
                si.reference as `reference`
                FROM
                node node
                LEFT JOIN `field_data_field_listing_avail_for_fs` laff ON node.nid = laff.entity_id AND (laff.entity_type = 'node' AND laff.deleted = '0')
                LEFT JOIN field_data_field_logo_visual_upload_feature lvuf ON node.nid = lvuf.entity_id AND (lvuf.entity_type = 'node' AND lvuf.deleted = '0')
                LEFT JOIN file_managed fm ON fm.fid = lvuf.field_logo_visual_upload_feature_fid
                LEFT JOIN `storage_core_bridge` scb ON scb.uri = fm.uri
                LEFT JOIN storage s ON s.storage_id = scb.storage_id
                LEFT JOIN storage_instance si ON si.file_id = s.file_id

                WHERE node.type IN  ('cw_listing') AND node.status = '1' AND laff.`field_listing_avail_for_fs_value` =1 AND node.nid = '".$node_id."'
                GROUP BY node.nid";
      $results = db_query($sql);
      if ($results) {
          while ($row = $results->fetchAssoc()) {
              $image = $row['reference'];
          }
      }
      db_set_active();
  } catch (Exception $e) {
      $msg = $e->getMessage();
      drush_print('error', $msg);
      db_set_active();
  } finally{
    Database::closeConnection('cw_db', 'default');
    return $image;
  }
}

function migrate_cw_content()
{
    $nodes = getNodesToMigrate();
    $total = 0;
    $listings = 0;
    $schools = 0;
    // insert nodes into new DB
    foreach ($nodes as $node) {
      $new = new StdClass();
      $new->title = $node['title'];
      $new->field_editor_description["und"][0]['value'] = $node['editor description'];
      $new->field_contributor_description["und"][0]['value'] = $node['contributor description'];
      $new->field_address_in_english["und"][0]['value'] = $node['address en'];
      $new->field_address_in_chinese["und"][0]['value'] = $node['address cn'];
      $new->field_website["und"][0]['value'] = $node['website'];
      $new->field_email["und"][0]['value'] = $node['email'];
      if($neighborhood = key(taxonomy_get_term_by_name($node['neighborhood'],'neighborhood')))
        $new->field_neighborhood["und"][0]['tid'] = $neighborhood;
      if(strtolower($node['category'])!= 'schools' && $node['school type'] === null){
        $item = $listings + 1;
        drush_print('processing listing: '. $item .' title: ' .$new->title);
        if($category = key(taxonomy_get_term_by_name($node['category'],'listing_category'))){
          $new->field_listing_category["und"][0]['tid'] = $category;
        } else{
          continue;
        }
        $new->field_operating_hours["und"][0]['value'] = $node['operating hours'];
        $new->field_telephone["und"][0]['value'] = $node['telephone'];
        $new->field_wechat["und"][0]['value'] = $node['wechat'];
        $new->price["und"][0]['value'] = getPriceRange($node['price range']);
        $new->closed["und"][0]['value'] = $node['closed'];
        if($metro = key(taxonomy_get_term_by_name($node['metro'])))
          $new->field_nearest_metro_station["und"][0]['tid'] = $metro;
        if($image_url = getImageURL($node['main image'])){
          if(($image = file_get_contents($image_url)) !== false){
              $file = file_save_data($image, file_default_scheme().'://'.basename($image_url), FILE_EXISTS_RENAME);
              $file->status = 1;
              $new->field_main_image ['und'][0] = (array)$file;
          }else if(($image = file_get_contents('http://files.cityweekend.com.cn/storage/'.getImageFromStorage($node['nid']))) !== false){
              $file = file_save_data($image, file_default_scheme().'://'.basename($image_url), FILE_EXISTS_RENAME);
              $file->status = 1;
              $new->field_main_image ['und'][0] = (array)$file;
          }
        }
        $new->field_map["und"][0]['lat'] = $node['lat'];
        $new->field_map["und"][0]['lon'] = $node['lon'];
        $new->type = 'listings';
        $new->language = 'und';
        $new->uid = '182';
        $listings++;
        $total++;
      } else {
        $item = $schools + 1;
        drush_print('processing school: '. $schools .' title: ' .$new->title);
        // need to check type first
        if($category = key(taxonomy_get_term_by_name($node['school type'],'school_type'))){
          $new->field_school_type["und"][0]['tid'] = $category;
        } else{
          continue;
        }
        $new->field_school_minimum_tuition["und"][0]['value'] = $node['min tuition'];
        $new->field_school_maximum_tuition["und"][0]['value'] = $node['max tuition'];
        $new->field_school_other_payments["und"][0]['value'] = $node['other payments'];
        $new->field_school_foundation_date["und"][0]['value'] = $node['foundation date'];
        $new->field_school_academic_program["und"] = getSchoolPrograms($node['nid']);
        $new->field_school_taught_languages["und"] = getTaughtLanguages($node['nid']);
//        $new->field_school_strengths["und"] = getStrengths($node['nid']);
        $new->field_school_curriculum["und"] = getCurriculums($node['nid']);
        if($image_url = getImageURL($node['main image'])){
          if(($image = file_get_contents($image_url)) !== false){
              $file = file_save_data($image, file_default_scheme().'://'.basename($image_url), FILE_EXISTS_RENAME);
              $file->status = 1;
              $new->field_school_logo ['und'][0] = (array)$file;
          }else if(($image = file_get_contents('http://files.cityweekend.com.cn/storage/'.getImageFromStorage($node['nid']))) !== false){
              $file = file_save_data($image, file_default_scheme().'://'.basename($image_url), FILE_EXISTS_RENAME);
              $file->status = 1;
              $new->field_school_logo ['und'][0] = (array)$file;
          }
        }
        if($main_image = getSchoolMainImage($node['nid']))
            $new->field_main_image["und"][0] = $main_image;
        $new->type = 'schools';
        $new->language = 'und';
        $new->uid = '182';
        $schools++;
        $total++;
      }

      node_save($new);
    }
    drush_print('there was '.$total.' nodes inserted');
}

function getSchoolMainImage($nid){
    $main_image = null;
    $file = null;
    connectToLegacyDB();
    try {
        db_set_active('cw_db');

        $sql = "SELECT DISTINCT
                node.nid AS 'nid',
                fm.`uri` as 'main_image'
                FROM
                node node
                LEFT JOIN field_data_field_city field_data_field_city ON node.nid = field_data_field_city.entity_id AND (field_data_field_city.entity_type = 'node' AND field_data_field_city.deleted = '0')
                LEFT JOIN field_data_field_pic_upload_opt_one fpuoo ON fpuoo.entity_id = node.nid
                LEFT JOIN file_managed fm ON fm.fid = fpuoo.`field_pic_upload_opt_one_fid`
                WHERE node.type IN  ('cw_listing') AND field_data_field_city.field_city_tid = '2' AND node.status = '1' AND node.nid = '".$nid."'
                LIMIT 1";
        $results = db_query($sql);
        db_set_active();
        if ($results) {
            while ($row = $results->fetchAssoc()){
                if($main_image = $row['main_image']){
                    if($image_url = getImageURL($main_image)){
                        if(($image = file_get_contents($image_url)) !== false){
                            $file = file_save_data($image, file_default_scheme().'://'.basename($image_url), FILE_EXISTS_RENAME);
                            $file->status = 1;
                        }
                    }
                }
            }
        }
    } catch (Exception $e) {
        $msg = $e->getMessage();
        drush_print('error', $msg);
        db_set_active();
    } finally{
        Database::closeConnection('cw_db', 'default');
        return (array)$file;
    }
}

function getSchoolPrograms($nid){
  $programs = array();
  connectToLegacyDB();
  try {
      db_set_active('cw_db');

      $sql = "SELECT DISTINCT
                node.nid AS 'nid',
                trd.name as 'name'
                FROM
                node node
                LEFT JOIN field_data_field_city field_data_field_city ON node.nid = field_data_field_city.entity_id AND (field_data_field_city.entity_type = 'node' AND field_data_field_city.deleted = '0')
                LEFT JOIN field_data_field_listing_academic_program lap ON lap.entity_id = node.nid
                LEFT JOIN `taxonomy_term_data` trd ON lap.field_listing_academic_program_tid = trd.tid
                WHERE node.type IN  ('cw_listing') AND field_data_field_city.field_city_tid = '2' AND node.status = '1' AND node.nid = '".$nid."'";
      $results = db_query($sql);
      db_set_active();
      if ($results) {
          while ($row = $results->fetchAssoc()) {
            if($term = taxonomy_get_term_by_name($row['name'],'academic_program')){
              $programs[] = array('tid'=>key($term));
            }
          }
      }
  } catch (Exception $e) {
      $msg = $e->getMessage();
      drush_print('error', $msg);
      db_set_active();
  } finally{
    Database::closeConnection('cw_db', 'default');
    return $programs;
  }
}

function getTaughtLanguages($nid){
  $languages = array();
  connectToLegacyDB();
  try {
      db_set_active('cw_db');

      $sql = "SELECT DISTINCT
                node.nid AS 'nid',
                trd.name as 'name'
                FROM
                node node
                LEFT JOIN field_data_field_city field_data_field_city ON node.nid = field_data_field_city.entity_id AND (field_data_field_city.entity_type = 'node' AND field_data_field_city.deleted = '0')
                LEFT JOIN field_data_field_listing_languages lap ON lap.entity_id = node.nid
                LEFT JOIN `taxonomy_term_data` trd ON lap.field_listing_languages_tid = trd.tid
                WHERE node.type IN  ('cw_listing') AND field_data_field_city.field_city_tid = '2' AND node.status = '1' AND node.nid = '".$nid."'";
      $results = db_query($sql);
      db_set_active();
      if ($results) {
          while ($row = $results->fetchAssoc()) {
            if($term = taxonomy_get_term_by_name($row['name'],'taught_language'))
              $languages[] = array('tid'=>key($term));
          }
      }
  } catch (Exception $e) {
      $msg = $e->getMessage();
      drush_print('error', $msg);
      db_set_active();
  } finally{
    Database::closeConnection('cw_db', 'default');
    return $languages;
  }
}

function getStrengths($nid){
  $strengths = array();
  connectToLegacyDB();
  try {
      db_set_active('cw_db');

      $sql = "SELECT DISTINCT
                node.nid AS 'nid',
                trd.name as 'name'
                FROM
                node node
                LEFT JOIN field_data_field_city field_data_field_city ON node.nid = field_data_field_city.entity_id AND (field_data_field_city.entity_type = 'node' AND field_data_field_city.deleted = '0')
                LEFT JOIN field_data_field_listing_facts lap ON lap.entity_id = node.nid
                LEFT JOIN `taxonomy_term_data` trd ON lap.field_listing_facts_tid = trd.tid
                WHERE node.type IN  ('cw_listing') AND field_data_field_city.field_city_tid = '2' AND node.status = '1' AND node.nid = '".$nid."'";
      $results = db_query($sql);
      db_set_active();
      if ($results) {
          while ($row = $results->fetchAssoc()) {
            if($term = taxonomy_get_term_by_name($row['name'],'school_strength'))
              $strengths[] = array('tid'=>key($term));
          }
      }
  } catch (Exception $e) {
      $msg = $e->getMessage();
      drush_print('error', $msg);
      db_set_active();
  } finally{
    Database::closeConnection('cw_db', 'default');
    return $strengths;
  }
}

function getCurriculums($nid){
  $curriculums = array();
  connectToLegacyDB();
  try {
      db_set_active('cw_db');

      $sql = "SELECT DISTINCT
                node.nid AS 'nid',
                trd.name as 'name'
                FROM
                node node
                LEFT JOIN field_data_field_city field_data_field_city ON node.nid = field_data_field_city.entity_id AND (field_data_field_city.entity_type = 'node' AND field_data_field_city.deleted = '0')
                LEFT JOIN field_data_field_listing_curriculum lap ON lap.entity_id = node.nid
                LEFT JOIN `taxonomy_term_data` trd ON lap.field_listing_curriculum_tid = trd.tid
                WHERE node.type IN  ('cw_listing') AND field_data_field_city.field_city_tid = '2' AND node.status = '1' AND node.nid = '".$nid."'";
      $results = db_query($sql);
      db_set_active();
      if ($results) {
          while ($row = $results->fetchAssoc()) {
            if($term = taxonomy_get_term_by_name($row['name'],'curriculum'))
              $curriculums[] = array('tid'=>key($term));
          }
      }
  } catch (Exception $e) {
      $msg = $e->getMessage();
      drush_print('error', $msg);
      db_set_active();
  } finally{
    Database::closeConnection('cw_db', 'default');
    return $curriculums;
  }
}
function getImageURL($path){
  $path = explode('://',$path);
  if ( $path[0] == 'storage-field-logo-visual-upload-feature') {
      return 'http://files.cityweekend.com.cn/storage/'.$path[1];
  } else if($path[0] == "storage-field-pic-upload-opt-one") {
      return 'http://www.cityweekend.com.cn/sites/default/files/storage/'.$path[1];
  } else {
    return null;
  }
}

function getPriceRange($id){
  $price_range = array(
    '1'=>'Less than  ¥99',
    '2'=>'¥100-199',
    '3'=>'¥200-299',
    '4'=>'¥300-399',
    '5'=>'¥400-600',
    '6'=>'More than ¥600'
  );
  return $price_range[$id];
}
