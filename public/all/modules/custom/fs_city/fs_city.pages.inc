<?php


function fs_city_change_city_callback() {
  drupal_page_is_cacheable(FALSE);
  $parms = drupal_get_query_parameters();
  $city = check_plain($parms['city']);
  $cities = _fs_city_get_cities();
  if (!in_array($city, $cities)) {
    $city = 'shanghai';
  }
  header('Location: ' . base_path() . $city, TRUE, 301);
  setcookie('fs_city', $city, REQUEST_TIME + 31536000, '/');
  exit;
}