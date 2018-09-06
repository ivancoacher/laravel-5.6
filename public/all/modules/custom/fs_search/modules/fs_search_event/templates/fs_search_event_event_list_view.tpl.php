 <div class="item-directory col-xs-12">
                    <div class="item-wrapper col-xs-12">
                        <div class="col-sm-3 item-directory-img-section"><a href="<?php print $item['url']; ?>"><img  src="<?php print $item['preview_image']; ?>" class="img-responsive"/></a></div>
                    <div class="col-sm-9 description-item-directory-container">
                        <div class="row title-item-directory">
                            <span><a href="<?php print $item['url']; ?>"><?php print $item['title']; ?></a></span>
                            <div class="underline_directory"></div>
                        </div>
                        <div class="row event_day"> <span class="glyphicon glyphicon-calendar" aria-hidden="true"></span>
                         <?php
                         $originalDate1 = $item['date_start_s'];
                         $originalDate2 = $item['date_end_s'];
                         if($item['type']!='cinema'){
                             if($originalDate1 != $originalDate2){
                               print date("l jS\, F Y ", strtotime($originalDate1))." <span class='to_separe'>  &nbsp;&nbsp; TO &nbsp;&nbsp;  </span> ".date("l jS\, F Y ", strtotime($originalDate2));
                             } else {
                              print date("l jS\, F Y ", strtotime($originalDate1));
                             }
                         } else{
                             print 'Release date: '.date("l jS\, F Y ", strtotime($originalDate1));
                         }
                        ?>
                        </div>
                        <?php if($item['type'] !='cinema' && $item['type'] !='ticket') :?>
                        <div class="row event_time"> <i class="fa fa-clock-o" aria-hidden="true"></i>
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
                        <?php endif; ?>
                        <div class="row description-item-directory">
                             <?php  print $item['summary']; ?>
                         </div>
                        <div class="row btn-details">
                            <?php if(!empty($item['247_url'])) :?>
                         <a class="btn btn-default" href="<?php print $item['url']; ?>">Details</a>
                         <a class="btn btn-error booking_btn" href="<?php print $item['247_url']; ?>" target="_blank">Book Now</a>
                        <?php else:?>
                         <a class="btn btn-default big" href="<?php print $item['url']; ?>">Details</a>

                             <?php endif;?>
                        
                        </div>
                    </div>
                    </div>
                </div>
