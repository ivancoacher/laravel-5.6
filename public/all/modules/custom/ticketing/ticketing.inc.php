<?php

/**
 *
 */
class TicketingApi
{

    private $ticket_url_prefix_all_events = 'https://api.247tickets.com/o/v1/cityweekend/events';
    private $ticket_url_download_cinema_db = '182.92.149.52';
    private $ftp_username = 'cityweekend';
    private $ftp_pass = '247-cITywEekEnD';

    function __construct()
    {

    }

    public function get($url)
    {
        $curl = curl_init();
        curl_setopt($curl, CURLOPT_URL, $url);
        curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
        $response = curl_exec($curl);

        if (curl_error($curl)) {
            error_log('error:' . curl_error($curl));
        }
        curl_close($curl);
        return $response;
    }

    public function getFtpConnection($address, $username, $pass)
    {

        // Set up a connection
        $conn = ftp_connect($address);

        // Login
        if (ftp_login($conn, $username, $pass)) {
            // Change the dir
            // ftp_chdir($conn, $match[5]);

            // Return the resource
            ftp_pasv($conn, true) or die("Cannot switch to passive mode");
            return $conn;
        }

        // Or retun null
        return null;
    }

    function get_ftp_mode($file)
    {
        $path_parts = pathinfo($file);

        if (!isset($path_parts['extension'])) return FTP_BINARY;
        switch (strtolower($path_parts['extension'])) {
            case 'am':
            case 'asp':
            case 'bat':
            case 'c':
            case 'cfm':
            case 'cgi':
            case 'conf':
            case 'cpp':
            case 'css':
            case 'dhtml':
            case 'diz':
            case 'h':
            case 'hpp':
            case 'htm':
            case 'html':
            case 'in':
            case 'inc':
            case 'js':
            case 'm4':
            case 'mak':
            case 'nfs':
            case 'nsi':
            case 'pas':
            case 'patch':
            case 'php':
            case 'php3':
            case 'php4':
            case 'php5':
            case 'phtml':
            case 'pl':
            case 'po':
            case 'py':
            case 'qmail':
            case 'sh':
            case 'shtml':
            case 'sql':
            case 'tcl':
            case 'tpl':
            case 'txt':
            case 'vbs':
            case 'xml':
            case 'xrc':
                return FTP_ASCII;
        }
        return FTP_BINARY;
    }

    public function get_all_event()
    {
        $url = $this->ticket_url_prefix_all_events;

        $data = $this->get($url);
        return json_decode($data, true);
    }

    public function get_all_existing_tickets_delete_all($type)
    {
        $events = array();
        $query = db_select('node', 'n');
        $query->join('field_data_field_event_type', 't', 't.entity_id = n.nid');
        $query->fields('n', array('nid', 'title'))
            ->condition('n.status', 0, '>')
            ->condition('n.type', 'events')
            ->condition('t.field_event_type_value', $type, '=');
        $results = $query->execute()->fetchAllAssoc('nid');
        node_delete_multiple(array_keys($results)); 
    }

    public function download_cinema_db()
    {
        $success = false;
        $module_path = drupal_get_path('module', 'ticketing');
        $remote_db1 = '247cinema_part1.zip';
        $local_db1_archived = $module_path . '/' . $remote_db1;
        $remote_db2 = '247cinema_part2.zip';
        $local_db2_archived = $module_path . '/' . $remote_db2;

        $ftp_connection = $this->getFtpConnection($this->ticket_url_download_cinema_db, $this->ftp_username, $this->ftp_pass);
        if (ftp_get($ftp_connection, $local_db1_archived, $remote_db1, $this->get_ftp_mode($remote_db1))) {
            watchdog('ticketing', 'downloaded db 1 succesfully', [], WATCHDOG_INFO);
            if (ftp_get($ftp_connection, $local_db2_archived, $remote_db2, $this->get_ftp_mode($remote_db2))) {
                watchdog('ticketing', 'downloaded db 2 succesfully', [], WATCHDOG_INFO);
                $success = true;
            } else {
                watchdog('ticketing', 'error while downloading db2', [], WATCHDOG_WARNING);
            }
        } else {
            watchdog('ticketing', 'error while downloading db1', [], WATCHDOG_WARNING);
        }

        // close the connection
        ftp_close($ftp_connection);
        if ($success) {
            $zip = new ZipArchive;
            if ($zip->open($local_db1_archived) === TRUE) {
                $zip->extractTo($module_path);
                $zip->close();
                watchdog('ticketing', 'unarchived db 1 succesfully', [], WATCHDOG_INFO);
                if ($zip->open($local_db2_archived) === TRUE) {
                    $zip->extractTo($module_path);
                    $zip->close();
                    watchdog('ticketing', 'unarchived db 2 succesfully', [], WATCHDOG_INFO);
                } else {
                    watchdog('ticketing', 'error while unzipping db2', [], WATCHDOG_WARNING);
                    $success = false;
                }
            } else {
                watchdog('ticketing', 'error while unzipping db1', [], WATCHDOG_WARNING);
                $success = false;
            }
        }

        return $success;
    }

    function get_all_new_cinema_tickets()
    {
        if ($this->download_cinema_db()) {
            $module_path = drupal_get_path('module', 'ticketing');
            $db1 = array(
                'database' => $module_path . '/247cinema_part1.sqlite',
                'driver' => 'sqlite',
            );
            $db2 = array(
                'database' => $module_path . '/247cinema_part2.sqlite',
                'driver' => 'sqlite',
            );
            Database::addConnectionInfo('247', 'db1', $db1);
            Database::addConnectionInfo('247', 'db2', $db2);
            $cinema_tickets = query_247('247_film');
            Database::closeConnection('247', 'db1');
            Database::closeConnection('247', 'db2');
            return $cinema_tickets;
        }
        return array();
    }

    function build_node_from_ticket($ticket, $node = null)
    {
        if (!$node){
            $node = new StdClass();
            $node->type = 'events';
            $node->language = 'und';
            $node->uid = '182';
            $node->title = $ticket['title'];
        }
        $node->field_price['und'][0]['value'] = $ticket['ticket_price'];
        $node->field_247_link['und'][0]['value'] = $ticket['url'].'?utm_source=shanghaifamily&utm_medium=onsite';
        $node->field_event_venue_name['und'][0]['value'] = $ticket['venue_name'];
        $node->field_address_in_english['und'][0]['value'] = $ticket['venue_address'];
        if ($coordinates = $ticket['venue_coordinates']) {
            $coordinates = explode(',', $coordinates);
            $node->field_map['und'][0]['lat'] = $coordinates[0];
            $node->field_map['und'][0]['lon'] = $coordinates[1];
        }
        $image_url = $ticket['image'];
        if ($image_url && ($image = file_get_contents($image_url)) !== false) {
            $file = file_save_data($image, file_default_scheme() . '://' . basename($image_url), FILE_EXISTS_RENAME);
            $file->status = 1;
            $node->field_main_image ['und'][0] = (array)$file;
        }
        $node->field_date['und'][0]['value'] = $ticket['start_date'];
        $node->field_date['und'][0]['value2'] = $ticket['end_date'];
        $categories = explode(',', $ticket['category']);
        foreach ($categories as $category) {
            if ($tax = taxonomy_get_term_by_name($category, 'event_category')) {
                $node->field_event_category['und'][] = array('tid' => key($tax));
            }
        }
        $node->field_contributor_description["und"][0]['value'] = $ticket['description'];
        $node->field_event_type['und'][0]['value'] = 'ticket';
        $node->status = 1;

        return $node;
    }

    function build_node_from_cinema_ticket($ticket, $node = null)
    {
        if (!$node) {
            $node = new StdClass();
            $node->type = 'events';
            $node->language = 'und';
            $node->uid = '182';
            $node->title = $ticket['name'];
        }
        $node->field_247_link['und'][0]['value'] = 'https://www.247cinema.cn/movie/' . $ticket['sid'].'?utm_source=shanghaifamily&utm_medium=onsite';
        $image_url = $ticket['poster'];
        if (($image = file_get_contents($image_url)) !== false) {
            $file = file_save_data($image, file_default_scheme() . '://' . basename($image_url), FILE_EXISTS_RENAME);
            $file->status = 1;
            $node->field_main_image ['und'][0] = (array)$file;
        }
        $node->field_date['und'][0]['value'] = $ticket['release_date'];
        if ($tax = taxonomy_get_term_by_name('cinema', 'event_category')) {
            $node->field_event_category['und'][0] = array('tid' => key($tax));
        }
        $node->field_contributor_description["und"][0]['value'] = $this->build_cinema_description($ticket);
        $node->field_editor_description["und"][0]['value'] = $ticket['synopsis'];
        $node->field_event_type['und'][0]['value'] = 'cinema';
        $node->status = 1;

        return $node;
    }

    function build_cinema_description($ticket)
    {
        $description = '';
        $description .= 'IMDB Rating :' . $ticket['rating'];
        $description .= '<br/>Runtime :' . $ticket['runtime'];
        $description .= '<br/>Genre :' . $ticket['genre'];
        $description .= '<br/>Director :' . $ticket['director'];
        $description .= '<br/>Cast :' . $ticket['cast'];
        $description .= '<br/>Synopsis :' . $ticket['synopsis'];
        return $description;
    }
}
