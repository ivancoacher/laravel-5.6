<?php

class FsElasticsearchBase {

  private $es_host;

  function __construct() {
    $this->es_host = variable_get('fs_search_hosts_localhost');
  }

  static function getInstance() {
    global $es_api;
    if ($es_api instanceof FsElasticsearchBase) {
      return $es_api;
    }
    else {
      $es_api = new FsElasticsearchBase();
      return $es_api;
    }
  }

  public function get($uri = '') {
//headers
    $headers = array();
    //$headers = array("username:miandry","password:miandry",); example
    $curl = curl_init();
    curl_setopt($curl, CURLOPT_URL, $this->es_host . $uri);
    curl_setopt($curl, CURLOPT_HEADER, true);
    curl_setopt($curl, CURLOPT_HTTPHEADER, $headers);
    curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
    $response = curl_exec($curl);
    $http_status = curl_getinfo($curl, CURLINFO_HTTP_CODE);
    if (curl_error($curl)) {
      error_log('error:' . curl_error($curl));
    }
    curl_close($curl);

    return $response;
  }

  public function put($uri, $data) {
//headers
    $headers = array();
    $curl = curl_init();
    curl_setopt($curl, CURLOPT_URL, $this->es_host . $uri);
    curl_setopt($curl, CURLOPT_HEADER, true);
    curl_setopt($curl, CURLOPT_HTTPHEADER, $headers);

    curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($curl, CURLOPT_CUSTOMREQUEST, "PUT");
    curl_setopt($curl, CURLOPT_POSTFIELDS, $data);
    $response = curl_exec($curl);
    $http_status = curl_getinfo($curl, CURLINFO_HTTP_CODE);
    if (curl_error($curl)) {
      error_log('error:' . curl_error($curl) . $response);
    }
    curl_close($curl);

    return $response;
  }

  public function post($uri, $data) {
//headers

    $headers = array();
    $curl = curl_init();
    curl_setopt($curl, CURLOPT_URL, $this->es_host . $uri);
    curl_setopt($curl, CURLOPT_HTTPHEADER, $headers);

    curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($curl, CURLOPT_CUSTOMREQUEST, "POST");
    curl_setopt($curl, CURLOPT_POSTFIELDS, $data);
    $response = curl_exec($curl);
    $http_status = curl_getinfo($curl, CURLINFO_HTTP_CODE);
    if (curl_error($curl)) {
      error_log('error:' . curl_error($curl) . $response);
    }
    curl_close($curl);

    return $response;
  }

  public function delete($uri) {
//headers
    $headers = array();
    $curl = curl_init();
    curl_setopt($curl, CURLOPT_URL, $this->es_host . $uri);
    curl_setopt($curl, CURLOPT_HTTPHEADER, $headers);

    curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($curl, CURLOPT_CUSTOMREQUEST, "DELETE");

    $response = curl_exec($curl);
    $http_status = curl_getinfo($curl, CURLINFO_HTTP_CODE);
    if (curl_error($curl)) {
      error_log('error:' . curl_error($curl) . $response);
    }
    curl_close($curl);

    return $response;
  }

  public function insert($nid, $_id, $type) {
    $return_value = NULL;
    try {
      $return_value = db_insert('fs_elasticsearch')
          ->fields(array("nid" => $nid, "_id" => $_id, "type" => $type))
          ->execute();
    }
    catch (Exception $e) {
      drupal_set_message(t('db_insert failed. Message = %message, query= %query', array('%message' => $e->getMessage(), '%query' => $e->query_string)), 'error');
    }
    return $return_value;
  }

  function update($nid, $_id) {
    try {
      // db_update()...->execute() returns the number of rows updated.
      $count = db_update('fs_elasticsearch')
          ->fields(array("_id" => $_id))
          ->condition('nid', $nid)
          ->execute();
    }
    catch (Exception $e) {
      drupal_set_message(t('db_update failed. Message = %message, query= %query', array('%message' => $e->getMessage(), '%query' => $e->query_string)), 'error');
    }
    return $count;
  }

  public function load_by($field_name, $field) {
    return db_select('fs_elasticsearch', 'n')
            ->fields('n', array('nid', '_id', 'type'))
            ->condition($field_name, $field, '=')
            ->range(0, 1)
            ->execute()
            ->fetchObject();
  }

  public function load_multi_by($field_name, $field) {
    return db_select('fs_elasticsearch', 'n')
            ->fields('n', array('nid', '_id', 'type'))
            ->condition($field_name, $field, '=')
            ->execute()
            ->fetchAll();
  }

  public function delete_by_nid($nid) {
    db_delete('fs_elasticsearch')
        ->condition('nid', $nid)
        ->execute();
  }

  public function delete_by__id($_id) {
    db_delete('fs_elasticsearch')
        ->condition('_id', $_id)
        ->execute();
  }

  public function _json_encode_string($encode) {

    $needle = array();
    $replace = array();

    $needle[] = "'";
    $replace[] = '\u0027';

    $needle[] = '"';
    $replace[] = '\u0022';


    $needle[] = '&';
    $replace[] = '\u0026';



    $needle[] = '<';
    $needle[] = '>';
    $replace[] = '\u003C';
    $replace[] = '\u003E';



    $encode = str_replace($replace, $needle, $encode);

    return $encode;
  }

}

class FsElasticsearch extends FsElasticsearchBase {

  public $es_query;

//list of all mapping entity


  
  function es_size_default(){
    //10000 maximun default size for elasticsearch
    $this->es_query(array(), 10000);
  }

  function index_mapping() {
    return array(
      'node' => array(
        'article',
        'listings',
        'events',
        'schools',
      ),
      'taxonomy' => array(
        'category',
      ),
    );
  }

  function create_index_mapping($type = null) {
    $index = 'family';
    $m_a = array(
      'settings' => array(
        'number_of_shards' => 1,
      ),
      'mappings' => array()
    );
    $index_mapping = $this->index_mapping();
    $index_types = $index_mapping['node'];

    if ($type == null) {
      foreach ($index_types as $type) {
        include_once "mappings/{$type}.php";
        $document_s = "{$type}_mapping";
        $document = $document_s();
        $m_a['mappings'][$type]['properties'] = $document;
        $rs = $this->put($index . '/', drupal_json_encode($m_a));
        if (drupal_json_decode($rs)["error"]["type"] != "index_already_exists_exception") {
          print_r($rs);
        }
      }
    }
    else {
      if (in_array(trim($type), $index_types)) {

        include_once "mappings/{$type}.php";
        $document_s = "{$type}_mapping";
        $document = $document_s();
        $m_a['mappings'][$type]['properties'] = $document;
//  print drupal_json_encode($m_a) ;die();
        $rs = $this->put($index . '/', drupal_json_encode($m_a));
        if (drupal_json_decode($rs)["error"]["type"] != "index_already_exists_exception") {
          print_r($rs);
        }
      }
      else {
        print $type . " entity not exist";
      }
    }
  }

  function delete_index_mapping_all() {
    $index = 'family';
    $rs = $this->delete($index . '/');
    $result = drupal_json_decode($rs);
    if ($result["acknowledged"]) {
      db_truncate('fs_elasticsearch')->execute();
    }
    print $rs;
  }

  function update_index_mapping($type) {
    $index = 'family';
    $uri = $index . '/' . $type . '/_mapping';
    include_once "mappings/{$type}.php";
    $document_s = "{$type}_mapping";
    $document = $document_s();

    $post = array();
    $post[$type] = array(
      'properties' => $document,
    );
    $rs = $this->put($uri, drupal_json_encode($post));
    print $rs;
  }

  function es_node_create($node) {
    if (!is_object($node)) {
      return false;
    }
    include_once "mappings/{$node->type}.php";
    $func = "{$node->type}_load";
    $es_node = $func($node);
    if (!$es_node) {
      return false;
    }

    $document = $node->type;
    $index = 'family';
    $uri = "{$index}/{$document}";
    $rt = $this->post($uri, drupal_json_encode($es_node));
    $response = drupal_json_decode($rt);
    if ($response["created"]) {
      $this->insert($node->nid, $response["_id"], $node->type);
    }
    return $rt;
  }

  function es_node_save($node) {
    if (!is_object($node)) {
      return false;
    }
    $map = $this->load_by("nid", $node->nid);
    if (is_object($map)) {
      $rt = $this->es_node_update($node);
    }
    else {
      $rt = $this->es_node_create($node);
    }
    return $rt;
  }

  function es_node_update($node) {
    if (!is_object($node)) {
      return false;
    }
    include_once "mappings/{$node->type}.php";
    $func = "{$node->type}_load";
    $es_node = $func($node);
    if (!$es_node) {
      return;
    }
    $document = $node->type;
    $index = 'family';
    $map = $this->load_by("nid", $node->nid);

    $uri = "{$index}/{$document}/" . $map->_id;
    $rt = $this->post($uri, drupal_json_encode($es_node));
    $response = drupal_json_decode($rt);
    if ($response["_shards"]["successful"] == 1) {
      $this->update($node->nid, $response["_id"]);
    }
    unset($es_node);
    return $rt;
  }

  function es_node_get($node) {
    $document = $node->type;
    $index = 'family';
    $uri = "{$index}/{$document}/_search";
    $query['query']['match_all']["nid"] = $node->nid;
// var_dump(drupal_json_encode($query));die();
    $rt = drupal_json_decode($this->get($uri, drupal_json_encode($query)));
    return ($rt);
  }

  function es_node_delete($node) {
    $map = $this->load_by("nid", $node->nid);
    if (!is_object($map)) {
      return null;
    }
    $document = $node->type;
    $index = 'family';
    $uri = "{$index}/{$document}/{$map->_id}";
    $rt = $this->delete($uri);
    $reponse = drupal_json_decode($rt);
    if ($reponse["found"]) {
      $this->delete_by__id($reponse["_id"]);
    }
    return($rt);
  }

  function es_node_delete_by_type($type = null) {
    if ($type != null) {
      $res = $this->load_multi_by('type', $type);
      if (!empty($res)) {
        foreach ($res as $key => $value) {
          $node = node_load($value->nid);
          $r = $this->es_node_delete($node);
          if (drupal_json_decode($r)["found"]) {
            print "deleted indexing  successfull nid " . $value->nid;
          }
        }
      }
      else {
        print "all " . $type . " indexing are deleted   already ";
      }
    }
  }

  function es_node_list($query, $document = '') {
    $index = 'family';
    if (!empty($document)) {
      $uri = "/" . $index . "/$document/_search";
    }
    else {
      $uri = "/" . $index . "/_search";
    }
    $json_format = $this->_json_encode_string(drupal_json_encode($query));
    $rs = $this->post($uri, $json_format);
    return ($rs);
  }
  function es_query($filter, $size = 9) {
    $this->es_query["size"] = $size;
    if (isset($filter['page'])) {

      $this->es_query["from"] = floatval($filter['page']) * floatval($this->es_query["size"]);
    }
    else {
      $this->es_query["from"] = 0;
    }

    return $this->es_query;
  }
  //search by keyword 
  function es_search($fields_array, $keyword) {
    $this->es_query["query"]['bool']['must'][] = array(
      "query_string" => array("query" => $keyword . "*", "fields" => $fields_array)
    );
    return $this->es_query;
  }
  //add filter 
  function es_add_filter($field_name, $value) {
    $this->es_query['query']['bool']['must'][] = array(
      'term' => array(
        $field_name => $value,
      )
    );
    return $this->es_query;
  }

  function es_add_filter_multi_value($field_name, $array) {
    $this->es_query['query']['bool']['filter']['terms'][$field_name] = $array;
    return $this->es_query;
  }
  function es_sort_multi($sort_array) {
    foreach ($sort_array as $key => $value) {
      $this->es_query["sort"][$key] = array('order' => $value);
    }
    return $this->es_query;
  }
  function es_sort_random() {
    $this->es_query["sort"]["_script"] = array(
      'order' => 'asc',
      'script' => 'Math.random()',
      'type' => 'number',
    );
    return $this->es_query;
  }

}
