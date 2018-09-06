<?php
global $base_url;
//related gallery block call
$block_related_gallery = module_invoke('fs_school', 'block_view', 'fs_school_related_gallery');
//related blogs block call
$block_related_blogs = module_invoke('fs_school', 'block_view', 'fs_school_related_blogs');
//testimonials block call
$block_testimonials = module_invoke('fs_school', 'block_view', 'fs_school_testimonials');
?>
<div class="divider-directory hidden" style="background-image: url('<?php print variable_get("path_theme"); ?>/images/family_style/divider_directory.png');">
    <div class="wrapper-details">
        <a href="/shanghai-schools" onclick="window.history.go(-1); return false;" >
            <span class="glyphicon glyphicon-menu-left" aria-hidden="true"></span>
            Back to School
        </a>
        <input type="hidden" id="item_type" value="school" />
    </div>
</div>
<div class='notifications top-left'></div>

<div class="col-xs-12 school_detail_main">
    <!-- Modal -->
    <div class="modal fade" id="myModalContact" tabindex="-1" role="dialog" aria-labelledby="myModalLabel">
        <div class="modal-dialog" role="document">
            <div class="modal-content">
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
                    <h4 class="modal-title" id="myModalLabel">Contact</h4>
                </div>
                <div class="modal-body">

                    <form id="contact_us_form_school" method="post" action="<?php print $base_url; ?>/school/contact_school">
                        <input type="hidden" id="email_contact" value="<?php print $item['field_email']; ?>" />
                        <input type="hidden" id="name_contact" value="<?php print $item['field_school_contact_name']; ?>" />

                        <div id="message_error_contact" class="form-group">
                            <p>
                            </p>

                        </div>
                        <div class="form-group">

                            <input type="type" class="form-control" id="name" name="name" placeholder="Name">
                        </div>
                        <div class="form-group">

                            <input type="email" class="form-control" id="email" name="email" placeholder="Email">
                        </div>
                        <div class="form-group">

                            <input type="text" class="form-control" id="contact_telephone" name="contact_telephone" placeholder="Telephone Number">
                        </div>
                        <div class="form-group">

                            <input type="type" class="form-control" id="subject" name="subject" placeholder="Subject">
                        </div>
                        <div class="checkbox"> <label> <input type="checkbox" checked="true" id="send_me" name="send_me" /> Send me copy </label> </div>

                        <div class="form-group">

                            <textarea class="form-control" id="message" name="message" rows="5"  placeholder="Message ..."></textarea>
                        </div>

                        <button type="button" id="btn_contact"    class="btn btn-default">
                            <span>Send</span>
                            <i class="fa fa-send" aria-hidden="true"></i>


                        </button>

                    </form>
                </div>
            </div>
        </div>
    </div>
    <div class="school-title-section" style="">
        <div class="col-sm-2">
            <img src="<?php
            print file_create_url($item['field_school_logo']);
//  print $base_url . "/" . drupal_get_path("theme", "family") . "/images/item/school_item.png";
            ?>" class="img-responsive img-replace">
        </div>
        <div class="col-sm-10">
            <div class="title" ><a href="#"><h1 style="color:#00B0AE"><?php print $item['title']; ?></h1></a></div>
        </div>
    </div>
    <div class="school-image-section">
        <div class="school-left-menu">
            <ul>
                <a href="#school-info"><li> <i class="fa fa-chevron-right" aria-hidden="true"></i>
                        School Information</li></a>
                <?php
                if ($item['field_school_premium']):
                  if ($item['field_school_videos']):
                    ?>
                    <a href="#school-videos"><li> <i class="fa fa-chevron-right" aria-hidden="true"></i>
                            Videos</li></a>
                    <?php
                  endif;
                  if ($block_related_gallery['content']):
                    ?>
                    <a href="#school-gallery"><li> <i class="fa fa-chevron-right" aria-hidden="true"></i>
                            Gallery</li></a>
                    <?php
                  endif;
                  if ($block_related_blogs['content']):
                    ?>
                    <a href="#school-blog"><li> <i class="fa fa-chevron-right" aria-hidden="true"></i>
                            Blog</li></a>
                    <?php
                  endif;
                  if ($block_testimonials['content']):
                    ?>
                    <a href="#school-testimonials"><li> <i class="fa fa-chevron-right" aria-hidden="true"></i>
                            Testimonials</li></a>
                    <?php
                  endif;
                endif;
                ?>
                <a href="#school-location"><li> <i class="fa fa-chevron-right" aria-hidden="true"></i>
                        School location</li></a>
                <?php if ($item['field_school_premium']): ?>
                  <div>
                      <div class="menu-btn-container">
                          <a href="<?php print $base_url . "/" . "school/detail_pdf/" . $item['nid'] ?>" class="menu-btn">Download profile</a></div>
                      <div class="menu-btn-container"><a href="" class="menu-btn" data-toggle="modal" data-target="#myModalContact"> Contact School</a></div>
                  </div>
                <?php endif; ?>

            </ul>
        </div>
        <div class="main-image">
            <img src="<?php
            print file_create_url($item['main_image']);
            //  print $base_url . "/" . drupal_get_path("theme", "family") . "/images/item/img.png";
            ?>" class="img-responsive img-replace">

        </div>

        <div class="school-bottom-menu">
            <ul>
                <a href="#school-info"><li> <i class="fa fa-chevron-right" aria-hidden="true"></i>
                        School Information</li></a>
                <?php
                if ($item['field_school_premium']):
                  if ($item['field_school_videos']):
                    ?>
                    <a href="#school-videos"><li> <i class="fa fa-chevron-right" aria-hidden="true"></i>
                            Videos</li></a>
                    <?php
                  endif;
                  if ($block_related_gallery['content']):
                    ?>
                    <a href="#school-gallery"><li> <i class="fa fa-chevron-right" aria-hidden="true"></i>
                            Gallery</li></a>
                    <?php
                  endif;
                  if ($block_related_blogs['content']):
                    ?>
                    <a href="#school-blog"><li> <i class="fa fa-chevron-right" aria-hidden="true"></i>
                            Blog</li></a>
                  <?php
                  endif;
                  if ($block_testimonials['content']):
                    ?>
                    <a href="#school-testimonials"><li> <i class="fa fa-chevron-right" aria-hidden="true"></i>
                            Testimonials</li></a>
                    <?php
                  endif;
                endif;
                ?>
                <a href="#school-location"><li> <i class="fa fa-chevron-right" aria-hidden="true"></i>
                        School location</li></a>
                <?php if ($item['field_school_premium']): ?>
                  <li class="menu-btn-container"><a href="<?php print $base_url . "/" . "school/detail_pdf/" . $item['nid'] ?>" class="menu-btn"> Download profile</a></li>
                  <li class="menu-btn-container"><a class="menu-btn" data-toggle="modal" data-target="#myModalContact"> Contact School</a></li>
<?php endif; ?>

            </ul>
        </div>

    </div>

    <!--    Mission Block Below Main Image-->
<?php if ($item['field_school_mission_statement']): ?>
      <div class="col-xs-12 mission-container">
          <div class="school-mission-box" >
              <span class="left-quat">“</span>    
              <img src="<?php
                   // print $item['field_main_image'];
                   print file_create_url($item['field_school_logo']);
                   ?>" class="img-responsive logo-img" >  
              <p class="mission-desc"><?php print $item['field_school_mission_statement']; ?></p>
              <span class="right-quat">”</span>  
          </div>
      </div>
<?php endif; ?> 
    <!--    School information Section-->
    <div class="school-info-section" id="school-info">

        <div class="reset">
            <div class="title_details">School Information</div>
            <div class="col-xs-12 main_details">
                <!--    Mission Block Right Info Section-->
<?php if ($item['field_school_mission_statement']): ?>
                  <div class="mission-container">
                      <div class="school-mission-box">
                          <span class="left-quat">“</span>    
                          <img src="<?php
                               // print $item['field_main_image'];
                               print file_create_url($item['field_school_logo']);
                               ?>" class="img-responsive logo-img" >  
                          <p class="mission-desc"><?php print $item['field_school_mission_statement']; ?></p>
                          <span class="right-quat">”</span>  
                      </div>
                  </div>
                    <?php endif; ?>
                <!-- School Info Section Left Inline-->
                <div style="info-container">
                    <?php if ($item['field_editor_description']): ?> 
                      <div class="item_content description"> <?php print $item['field_editor_description']; ?></div>
                    <?php else: ?>    
                      <?php if ($item['field_contributor_description']): ?>
                        <div class="item_content description"> <?php print $item['field_contributor_description']; ?></div>
                      <?php endif; ?>
<?php endif; ?>
<?php if ($item['field_school_foundation_date']): ?>
                      <div class="item_details">
                          <div class=" item_title">  Date Founded  </div>
                          <div class=" item_content"><?php print $item["field_school_foundation_date"]; ?></div>
                      </div>
                    <?php endif; ?>

<?php if ($item['field_neighborhood']): ?>
                      <div class="item_details">
                          <div class="item_title"> Neighborhood  </div>
                          <div class="item_content">
                              <?php
                              $type = "";
                              foreach ($item['field_neighborhood'] as $i) {
                                $type = $type . $i["name"] . ", ";
                              }
                              print substr($type, 0, floatval(strlen($type)) - 2);
                              ?>

                          </div>
                      </div>
                    <?php endif; ?>

<?php if ($item['field_school_academic_program']): ?>
                      <div class=" item_details">
                          <div class="item_title"> Grade levels  </div>
                          <div class="item_content">
                              <?php
                              $academic = "";
                              foreach ($item['field_school_academic_program'] as $i) {
                                $academic = $academic . $i["name"] . ", ";
                              }
                              print substr($academic, 0, floatval(strlen($academic)) - 2);
                              ?>

                          </div>
                      </div>
<?php endif; ?>
<?php if ($item['field_school_type']): ?>
                      <div class=" item_details">
                          <div class="item_title"> School Type </div>
                          <div class=" item_content">
                              <?php
                              $type = "";

                              foreach ($item['field_school_type'] as $i) {
                                $type = $type . $i["name"] . ", ";
                              }
                              print substr($type, 0, floatval(strlen($type)) - 2);
                              ?>

                          </div>
                      </div>
                    <?php endif; ?>


<?php if ($item['field_school_curriculum']): ?>
                      <div class=" item_details">
                          <div class="item_title"> Curriculum  </div>
                          <div class=" item_content">
                              <?php
                              $academic = "";
                              foreach ($item['field_school_curriculum'] as $i) {
                                $academic = $academic . $i["name"] . ", ";
                              }
                              print substr($academic, 0, floatval(strlen($academic)) - 2);
                              ?>

                          </div>
                      </div>
<?php endif; ?>
<?php if ($item['field_school_taught_languages']): ?>
                      <div class="item_details">
                          <div class="item_title"> Languages taught </div>
                          <div class="item_content">
                              <?php
                              $lg = "";
                              foreach ($item['field_school_taught_languages'] as $i) {
                                $lg = $lg . $i["name"] . ", ";
                              }
                              print substr($lg, 0, floatval(strlen($lg)) - 2);
                              ?>

                          </div>
                      </div>
<?php endif; ?>
<?php if ($item['field_school_strength']): ?>
                      <div class="item_details">
                          <div class="item_title"> School Strengths </div>
                          <div class="item_content">
                              <?php
                              print $item['field_school_strength'];
                              ?>


                          </div>
                      </div>
                    <?php endif; ?>

<?php if ($item['field_school_minimum_tuition']): ?>
                      <div class="item_details">
                          <div class="item_title"> Annual Tuition </div>
                          <div class="item_content"><?php print $item['field_school_minimum_tuition'] . " -  " . $item['field_school_maximum_tuition'] . " rmb"; ?>
                              <?php if ($item['field_school_other_payments']): ?>
    <?php print " ( " . $item['field_school_other_payments'] . " ) "; ?>
                      <?php endif; ?>
                          </div>
                      </div>
<?php elseif ($item['field_school_other_payments']): ?>
                      <div class="item_details">
                          <div class="item_title"> Payment </div>
                          <div class="item_content"><?php print $item['field_school_other_payments']; ?></div>
                      </div>
                        <?php endif; ?>

                    <div class="item_content">
                        <?php if ($item['field_website']): ?>
                          <a class="school_button" href="<?php print $item['field_website']; ?>" target="_blank">Visit website</a>
                        <?php endif; ?>
                        <?php if ($item['field_school_admission_inquiry']): ?>
                          <a class="school_button" href="<?php print $item['field_school_admission_inquiry']; ?>" target="_blank">Book a tour</a>
<?php endif; ?>
                    </div>
                </div>

            </div>

        </div>

    </div>

    <?php
    if ($item['field_school_videos']):
      $items = $item['field_school_videos'];
      print theme_render_template(drupal_get_path('module', 'fs_school') . '/templates/fs_school_related_videos.tpl.php', array('items' => $items));
    endif;

    //Print Gallery Block
    $fs_school_related_gallery = $block_related_gallery['content'];
    print render($fs_school_related_gallery);

    //Print Blog Block 
    $fs_school_related_blogs = $block_related_blogs['content'];
    print render($fs_school_related_blogs);

    //Print Testimonials Block
    $fs_school_testimonials = $block_testimonials['content'];
    print render($fs_school_testimonials);
    ?>




    <div class="adress_section reset col-xs-12" id="school-location">
        <div class="wrapper-details-new reset col-xs-12">

            <div class="title_details">Location</div>
            <div class="col-xs-12 main_details">
                <div class="col-xs-12 item_details">
                    <div class="col-xs-12 map-location reset">
                        <div id="map-content" style="height:300px"></div>

                    </div>
                    <div class="col-xs-12 other-campus">

                        <div class="col-sm-6 other-campus-detail">
                            <div class="title"><?php print $item['title'] ?></div>
                            <div class="detail"><?php print $item['field_address_in_chinese'] ?></div>
                            <div class="detail"><?php print $item['field_address_in_english'] ?></div>
                            <?php
                                if ($item['field_telephone']) {
                                    
                                  print '<div class="detail">Telephone : <a href="tel:'. $item['field_telephone'] .'">' . $item['field_telephone'] . '</a></div>';
                                }
                                ?>
                            <?php
                                if ($item['field_email']) {
                                  print '<div class="detail"><a href="mailto:'. $item['field_email'] .'">'. $item['field_email'] . '</a></div>';
                                }
                                ?>
                        </div>

                        <?php
                        foreach ($item['field_school_campuses'] as $item):
                          if ($item['adress_eng']):
                            ?>
                            <div class="col-sm-6 other-campus-detail">
                                <div class="title"><?php print $item['title'] ?></div>
                                <div class="detail"><?php print $item['adress_cn'] ?></div>
                                <div class="detail"><?php print $item['adress_eng'] ?></div>
                                <?php
                                if ($item['phone']) {
                                  print '<div class="detail">Telephone : <a href="tel:'. $item['phone'] .'">' . $item['phone'] . '</a></div>';
                                }
                                ?>
                                <?php
                                if ($item['email']) {
                                   print '<div class="detail"><a href="mailto:'. $item['email'] .'">'. $item['email'] . '</a></div>';
                                }
                                ?>
                            </div>
                            <?php
                          endif;
                        endforeach;
                        ?>
                    </div>

                </div>
            </div>

        </div>
    </div>



</div>






