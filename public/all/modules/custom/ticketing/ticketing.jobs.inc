<?php

function ticketing_get_all_tickets()
{
    require 'ticketing.inc.php';
    $event_object = new TicketingApi();
    
    $new_events = $event_object->get_all_event();
    
    // Insert new tickets
    if(!empty($new_events)){
      $event_object->get_all_existing_tickets_delete_all('ticket');
      $count_new_insert  = 0;
      foreach ($new_events as $ticket) {
          $node = $event_object->build_node_from_ticket($ticket);
          node_save($node);
          $count_new_insert++;
      }  
      watchdog('tickets', 'there is ' . $count_new_insert . '  tickets', [], WATCHDOG_INFO);

    }else{
      drupal_set_message(t('Message = %message'), array('%message' => ' Api Tickers Result Empty'), 'error');
    }
}

function ticketing_download_sqlite_db()
{
    require 'ticketing.inc.php';
    $event_object = new TicketingApi(); 
    $new_events =  $event_object->get_all_new_cinema_tickets();
    $count_new_insert = 0;
    if(empty($new_events)){
    // Insert new tickets
    $event_object->get_all_existing_tickets_delete_all('cinema');
    foreach ($new_events as $ticket) {
        $node = $event_object->build_node_from_cinema_ticket($ticket);
        node_save($node);
        $count_new_insert++;
    }
    watchdog('tickets', 'there is ' . $count_new_insert . '  tickets cinema', [], WATCHDOG_INFO);
    }else{
          drupal_set_message(t('Message = %message'), array('%message' => ' Api Tickers Cinema Result Empty'), 'error');
  
    }
}
