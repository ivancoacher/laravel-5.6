<style>

 
</style>

<div class="container">

    <div class="col-xs-12 col-md-9">

        <div class="divider-directory compare_divider hidden" style='background-image: url("<?php print variable_get("path_theme"); ?>/images/family_style/divider_directory.png");'>
            <div class="wrapper-details">
                <a id="back_to_school" href="#">
                    <span class="glyphicon glyphicon-menu-left" aria-hidden="true"></span>
                    Back to School
                </a>
            </div>
        </div>
        <div class="title_compare  col-xs-12"><span>Compare Schools</span></div>

        <div id="search_panel" class="compare_items col-xs-12">
            <div class='add-school'>
                <input  type="hidden" class="auto_id_item" value="0" />


                <form class="form-inline text-center" role="form">
                    <!-- SEARCH PLACE -->
                    <div class="form-group">
                        <label></label>
                    </div>

                    <div class="form-group input_search" >
                        <input type="hidden"  id="school_search" data-link="<?php print $url_search; ?>" name="school_search"  data-provide="typeahead"  class="search-query form-control" />                        
                        <div class="Typeahead Typeahead--twitterUsers">
                            <div class="u-posRelative">
                                <input dir="ltr" class="Typeahead-hint" tabindex="-1" readonly="readonly" type="text">
                                <input class="Typeahead-input tt-input" id="demo-input" name="q" placeholder="Find more schools ..." type="text">
                                <img class="Typeahead-spinner" src="<?php print "/" . drupal_get_path('theme', 'family') ?>/images/spinner.gif" style="display: none;">
                            </div>
                            <div class="Typeahead-menu"><div class="tt-dataset tt-dataset-0"></div></div>
                        </div>
                        <button class="hidden" type="submit">blah</button>
                    </div>
                    <!-- Button Drop Down -->
                    <div class="form-group btn-section-add">
                        <a id="edit-submit" class="btn-add-school" >Add to compare</a>

                    </div>
                </form>
            </div>
        </div>
        <div class=" compare_details">

            <div class="col-xs-12 item_content_container">
                <?php foreach ($items as $i => $val) : ?>
                  <div class="col-xs-12 item_content_odd item_content_odd_<?php print $i; ?>">
                      <?php foreach ($val as $key => $item) : ?> 
                       <div class="col-md-2 col-xs-4 item_content  <?php
                        if ($key % 2 != 0) {
                          print "hidden-md hidden-lg";
                        }
                        ?>   " >
                            <div class="col-xs-12 item_content_item title_content">
                                <div class="empty_section">
                                    <img src="<?php print $item["field_school_logo"]; ?>" width="80" height="80" class="hidden visible-xs" />

                                </div>
                            </div>
                            <?php foreach ($item as $field => $data) : ?>
                              <?php if (in_array($field, array_keys($fields_compare))): ?>
                                
                                <div class="col-xs-12 item_content_item item_field <?php print $field; ?> "><p><?php print $fields_compare[$field]; ?></p></div> 
                              <?php endif; ?>
                            <?php endforeach; ?>

                        </div> 

                        <div class="col-md-5 col-xs-8 item_content ">
                            <div class="col-xs-12 item_content_item title_content">
                                  <input  type="hidden" class="school_nid" value="<?php print $item["nid"]; ?>" />
                       
                                <img src="<?php print $item["field_school_logo"]; ?>" width="80" height="80" class="hidden-xs" />
                                <div class="title_text_compare"> <?php print $item["title"]; ?> </div>
                                <a href="<?php print $item["url"]; ?>">School details</a>
                                <a href="javascript:void" data-nid="<?php print $item["nid"]; ?>" class="rm_compare"><span class="glyphicon glyphicon-remove" aria-hidden="true"></span></a>
                            </div>
                            <?php foreach ($item as $field => $data) : ?>
                              <?php if (in_array($field, array_keys($fields_compare))): ?>
                                <?php if (!is_array($data)): ?>  

                                  <div class="col-xs-12 item_content_item  <?php print $field; ?> "><p><?php print $data; ?></p></div>
                                <?php else: ?>   

                                  <div class="col-xs-12 item_content_item  <?php print $field; ?>">
                                      <p>
                                          <?php
                                          $type = "";
                                          foreach ($data as $i) {
                                            $type = $type . $i["name"] . ", ";
                                          }
                                          print substr($type, 0, floatval(strlen($type)) - 2);
                                          ?>
                                      </p>
                                  </div>  
                                <?php endif; ?>
                              <?php endif; ?>

                            <?php endforeach; ?>
                        </div>   
                      <?php endforeach; ?>
                  </div>   
                <?php endforeach; ?>
            </div>
        </div>
    </div>
    <script id="empty-template" type="text/x-handlebars-template">
        <div class="EmptyMessage">No result found for your search !!</div>
    </script>

    <script id="result-template" type="text/x-handlebars-template">
      <div class="ProfileCard u-cf">
      <div class="col-sm-2 hidden-xs" >
        <img class="ProfileCard-avatar" src="{{preview_image}}">
      </div>   
        <div class="col-sm-10 ProfileCard-details">
          <div class="ProfileCard-realName">{{title}}</div>
          <div class="ProfileCard-screenName">{{school_type}}</div>
          
        </div>
      </div>
    </script>

