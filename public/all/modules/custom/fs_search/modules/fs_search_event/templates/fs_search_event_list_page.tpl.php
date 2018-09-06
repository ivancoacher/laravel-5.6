<div class="container"><div class="col-xs-12 title_events_search_top">Events Search</div></div>
<div class="pagination-search-day container"  >
     <input type="hidden" id="current_city" value="<?php print $city ;?>">  
               
                  <div class="col-xs-12 col-sm-12 seach-day ">
                      <div class="wrapper_search_day">
                          <div class="title_search_day">Scheduled Date</div>
                          <div class="wrapper_search_day_post">
                              
                            <?php
                            
                            foreach ($dates_filters as $dates_filter):
                                ?>  
                                <?php
                                 $active = "";
                                if(isset($filters['date_start'])){
                                
                                $start_data_bool = strpos(explode('%',$dates_filter['url'])[0] ,explode(' ',$filters['date_start'])[0]);
                              
                                if (isset($filters["date_start"])&& $start_data_bool!== false) {
                                    $active = "active_day";
                                }
                               
                                
                                }
                                ?>
                                <a href = "<?php print $dates_filter['url'];  ?>" class = "item-pagination-day-content">
                                <div class = "col-xs-3 col-sm-2 col-md-1 item-pagination-day  <?php print $active ;?>" >
                                <div class = "week_events"><?php print strtoupper($dates_filter['DAY']); ?></div>
                                <div class = "day_events "><?php print ($dates_filter['day']);?></div>
                                    <div class="status_events hidden">
                                        <div class="col-xs-3 color-item color-blue "></div>
                                        <div class="col-xs-3  color-item color-red "></div>
                                        <div class="col-xs-3  color-item color-yellow"></div>
                                    </div>
                                </div>
                                </a>    
                        <?php endforeach;  ?>
                               </div>
                      </div>

                </div>    
                <div class='event-search  col-xs-12 col-sm-12'>
                    <div class="wrapper_fields_search">
                       <div class="form-group category_field_container col-sm-8 row">
                            <select id="category_event" title="Category" name="category_event" class="form-control" >
                                
                               <?php  
                               //   print "<option value='Category'>All</option>";
                               
                                foreach ($category as $type){
                                    $status="";
                                    if (isset($filters["category"])){
                                        if($filters["category"]==$type["tid"]) {
                                        //foreach ($filters["category"] as $filter) {

                                          //  if ($filter == $type["tid"]) {
                                                $status = "selected";
                                          //  }
                                        //}
                                        }
                                    }

                                print "<option value='".$type["tid"]."' ".$status.">".$type["name"]."</option>";
                                }
                               
                                ?>
                               
                            </select> 
                        </div>
                        <div class="form-group btn_search_container col-sm-4">
                            <input type="button" id="edit-submit" name="op" value="Search" class="form-submit">
                        </div>
                      <?php ///print $form; ?>
                    </div>
                </div>
 

</div>
<div class="container">
    <div class="events-wrapper row">

          <?php 
        
          
             function is_filter($filters) {
                       if (isset($filters["category"])){
                           return true;
                       } else {
                           return false;
                       }
              }
              $is_filter = (is_filter($filters));
              $title="Featured Events";
              print theme_render_template(drupal_get_path('module', 'fs_search') . '/templates/fs_search_list_listing.tpl.php', 
              array(
                         'items' => $items,
                         'title'=>$title,                        
                         'pager'=>$pager,
                         'count' => $count,
                         'filter'=>$is_filter
              )); 
           ?>  
     
     





