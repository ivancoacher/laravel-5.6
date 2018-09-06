
<div class="col-xs-12 calandar-container">
    <div class="col-xs-12 title-calandar">
         <span>Upcoming Events</span>
    </div>
    <div class="pagination-by-day col-xs-12" >
        <ul id="calandar_tab">
         <?php $i=1; foreach ($items as $item) :if($i==1){$activep="active ";$today="Today";}else{$activep="";$today=$item["day_week"] ;}  ?>
          <?php if($i<4):?>
         <li class="calandar_tab_<?php print $i; ?> <?php print $activep ;?> col-xs-2" >

        <div id="calandar_menu_2" class="calandar_tab_one  pg_day ">
            <div class="week"><?php print $today; ?> </div>
            <div class="day"><?php print $item["day"] ;?></div>
        </div>

        </li>
        <?php endif ;?>
        <?php $i++; endforeach;?>

        <li class="calandar_tab_<?php print $i; ?> col-xs-2 best_of_li">
         <div class="col-xs-4 best_of-container">
             <div class="best_of"><button class="">Best of</buttom></div>
         </div>
        </li>
        </ul>
        <?php $i=1; foreach ($items as $item) :if($i==1){$active="active-page ";}else{$active="";}  ?>
        <div id="calandar_tab_<?php print $i;?>"  class="tab-page <?php print $active ;?> list-calandar col-xs-12 calandar_menu_2">
           <?php if(isset($item["nodes"])): foreach ($item["nodes"] as $node):?>
             <div class="item_calandar col-xs-12 col-sm-6 col-md-12">
                <div class="col-xs-4 col-sm-4 col-md-4 img-calandar">
                    <a href="<?php print $node["_source"]["url"]; ?>"><img src='<?php print image_style_url("event_calandar",$node['_source']['field_main_image']);  ?>' class="img-responsive"/></a>
                </div>
                <div class="col-xs-8 col-sm-8 col-md-8 right-calandar">
<!--                    <div class="date">   <?php
//                    $originalDate = $node['_source']['field_date']['date_start'];
//                    print date("D j M  Y g:i a", strtotime($originalDate));
                    ?></div>-->
                    <div class="description"><?php if(isset($node['_source']['title'])){
                      //  print substr($node['body'],0,296);
                      if(strlen($node['_source']['title']) > 50){
                         print substr($node['_source']['title'],0,50)." ...";
                      }else{
                         print substr($node['_source']['title'],0,50);
                      }
                      

                    } ?></div>
                    <?php if($node['_source']['field_247_link']!=null) : ?>
                    <div class="booking-btn">                    
                        <a target="_blanck" class="btn btn-default btn-sm" href="<?php print $node['_source']['field_247_link']; ?>" role="button">Book Now</a>                     
                    </div>
                    <?php endif;?>
                </div>
            </div>
            
           <?php endforeach;?>
            <div class="more-btn">                    
                        <a target="_blanck" class="btn" href="/shanghai/event" role="button">See More</a>                     
            </div>
            <?php else:?>
            <div class="empty_calendar col-xs-12">
              <p>There doesn't seem to be much going on this day. Check out our <a href="/shanghai/event"><span style="color:#ED4E76;">Events</span></a> page for more.</p>
            </div>
            <?php endif; ?>



        </div>
        <?php $i++; endforeach; ?>
         <div id="calandar_tab_<?php print $i;?>"  class="tab-page  list-calandar col-xs-12 calandar_menu_2">
          <?php if(!empty($items_best_of_month)):?>
          <?php $k=1; foreach ($items_best_of_month as $node): ?>
              <?php if($k<5): ?>
            <div class="item_calandar col-xs-12 col-sm-6 col-md-12">
                <div class="col-xs-4 col-sm-4 col-md-4 img-calandar">
                    <a href="<?php print $node['_source']["url"]; ?>"><img src='<?php  print image_style_url("event_calandar",$node['_source']['field_main_image']);  ?>' class="img-responsive"/></a>
                </div>
                <div class="col-xs-4 col-sm-4 col-md-8 right-calandar">
<!--                    <div class="date">   <?php
//                    $originalDate = $node['_source']['field_date']['date_start_s'];
//                    print date("D j M  Y g:i a", strtotime($originalDate));
                    ?></div>-->

                    <div class="description"><?php if(isset($node['_source']['title'])){
                        print substr($node['_source']['title'],0,70);

                    }
                        ?></div>
                    <?php if($node['_source']['field_247_link']!=null) : ?>
                    <div class="booking-btn">                    
                        <a target="_blanck" class="btn btn-default btn-sm" href="<?php print $node['_source']['field_247_link']; ?>" role="button">booking</a>                     
                    </div>
                    <?php endif ; ?>
                </div>
            </div>
                <?php endif;?>
          <?php $k++; endforeach ;?>
              <div class="more-btn">                    
                <a target="_blanck" class="btn" href="/shanghai/event" role="button">See More</a>                     
            </div>
          <?php else:?>
            <div class="empty_calendar col-xs-12">
              <p>There doesn't seem to be much going on this day. Check out our <a href="/shanghai/event"><span style="color:#EE4F77;">Events</span></a> page for more.</p>
            </div>
          <?php endif; ?>
        </div>
    </div>

</div>
