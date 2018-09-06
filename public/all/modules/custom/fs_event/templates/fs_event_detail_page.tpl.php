


        <div class="hidden divider-directory" style='background-image: url("<?php print variable_get("path_theme");?>/images/family_style/divider_directory.png");'>
            <div class="wrapper-details">
                <a href="#">
                    List View
                </a>
            </div>
        </div>
        <div class="events-wrapper row">
            <div class="col-xs-12 main-details-image"><img src=" <?php print $item['field_main_image'];?>  " class="img-responsive" /></div>
             <div class="panel_details col-xs-12">
                <div class="wrapper-details-new col-xs-12">
                    <div class="col-xs-12 title_details">Information</div>
                    <div class="col-xs-12 main_details">


                        <div class="col-xs-12 item_details">
                            <div class="col-xs-12 item_details">
                                <div class="col-xs-3 item_title">Name</div>
                                <div class="col-xs-9 item_content"><?php print $item['title']; ?></div>
                            </div>
                            <div class="col-xs-3 item_title"><?php if($item['field_event_type']=='cinema') print 'Release ';?>Date</div>
                             <div class="col-xs-9 item_content">
                               <?php
                               $originalDate1 = $item['field_date']["date_start"];
                               $originalDate2 = $item['field_date']["date_end"];
                                if($originalDate1 != $originalDate2 && $originalDate2){
                                 print date("l jS\, F Y ", strtotime($originalDate1))." <span class='to_separe'>  &nbsp;&nbsp; TO &nbsp;&nbsp;  </span> ".date("l jS\, F Y ", strtotime($originalDate2));
                               } else {
                                 print date("l jS\, F Y ", strtotime($originalDate1));
                               }
                              ?>
                            </div>
                        </div>
                        <?php if($item['field_event_type']!='cinema' && $item['field_event_type']!='ticket') :?>
                         <div class="col-xs-12 item_details">
                            <div class="col-xs-3 item_title">Time</div>
                             <div class="col-xs-9 item_content">
                               <?php
                               $startTime = $item['time_start_s'];
                               $endTime = $item['time_end_s'];
                               if($startTime != $endTime && $endTime){
                                   print $item['time_start_s']." To ". $item['time_end_s'];
                               } else {
                                   print $item['time_start_s'];
                               }
                               ?>
                             </div>
                        </div>
                        <?php endif; ?>


                         <?php if($item['field_price']):?>
                        <div class="col-xs-12 item_details">
                            <div class="col-xs-3 item_title">Price</div>
                             <div class="col-xs-9 item_content">RMB <?php print $item['field_price']; ?></div>
                        </div>
                          <?php endif;?>

                      <?php if($item['field_email']):?>
                          <div class="col-xs-12 item_details">
                              <div class="col-xs-3 item_title">E-mail</div>
                              <div class="col-xs-9 item_content"> <?php print $item['field_email']; ?></div>
                          </div>
                      <?php endif;?>
                      <?php if($item['field_website']):?>
                          <div class="col-xs-12 item_details">
                              <div class="col-xs-3 item_title">Web Site</div>
                              <div class="col-xs-9 item_content">      <a href="<?php print $item['field_website']; ?>"> <?php print $item['field_website']; ?></a>
                              </div>
                          </div>
                      <?php endif;?>
                      <?php if($item['field_telephone']):?>
                          <div class="col-xs-12 item_details">
                              <div class="col-xs-3 item_title">Phone number</div>
                              <div class="col-xs-9 item_content">
                                <?php print $item['field_telephone']; ?>
                              </div>
                          </div>
                      <?php endif;?>
                      <?php if($item['field_wechat']):?>
                          <div class="col-xs-12 item_details">
                              <div class="col-xs-3 item_title">Wechat</div>
                              <div class="col-xs-9 item_content">
                                <?php print $item['field_wechat']; ?>
                              </div>
                          </div>
                      <?php endif;?>
        
                         <?php if($item['field_related_venue']):?>
                        <div class="col-xs-12 item_details">
                            <div class="col-xs-3 item_title">Venue Name</div>
                             <div class="col-xs-9 item_content">
                                 <?php foreach ($item['field_related_venue'] as $v){
                                     print "<a class='item_venue' href='".url('node/' . $v['nid'], array('absolute' => TRUE))."'>".$v["title"]."</a>";
                                 }?>

                             </div>
                        </div>
                           <?php endif;?>
                           <?php if($item['field_address_in_english']):?>
                          <div class="col-xs-12 item_details">
                              <div class="col-xs-3 item_title">Address</div>
                               <div class="col-xs-9 item_content"><?php print $item['field_address_in_english']; ?></div>
                          </div>
                                 <?php endif;?>
                           <?php if($item['field_address_in_chinese']):?>
                          <div class="col-xs-12 item_details">
                              <div class="col-xs-3 item_title">Address in Chinese</div>
                               <div class="col-xs-9 item_content"><?php print $item['field_address_in_chinese']; ?></div>
                          </div>
                                 <?php endif;?>
                         <?php if($item['body']):?>
                        <div class="col-xs-12 item_details">
                            <div class="col-xs-3 item_title">Description</div>
                            <div class="col-xs-9 item_content">
                                <?php print $item['body']; ?>
                           </div>
                        </div>
                          <?php endif;?>
                          <?php if($item['field_247_link']):?>
                        <div class="col-xs-12 item_details">
                            <div class="col-xs-3 item_title">  </div>
                            <div class="col-xs-9 item_content ">
                                <div class="booking_btn">
                                <a href='<?php print $item['field_247_link']; ?>' >Book Now</a>
                                </div>
                                </div>
                        </div>
                          <?php endif;?>
                    </div>
                </div>
            </div>
            <?php if($item['field_event_type']!='cinema' && $item['field_event_type']!='ticket') :?>
            <div class="col-xs-12 title-details"><span>Map</span>
              <div class="underline_directory"></div>
            </div>
            <div class="col-xs-12 map-location">
                 <div id="map-content" style="height:300px"></div>
            </div>
            <?php endif; ?>

        </div>
