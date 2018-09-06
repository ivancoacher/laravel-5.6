<?php
/**
 * see fs_search_directory_list_page() function.
 */
?>
<div class="container">
    <div class="col-xs-12 title_directories">
        <h1>Directories Search</h1>
    </div>
 </div>
<div class="map-container container">
   <div class="collapse" id="collapsemap">
        <div id="map-content" style="height:300px"></div>
    </div>
    <div class="directory-search">
        <input type="hidden" id="current_city" value="<?php print $city; ?>">
        <div class="map-directory-control_section_xs col-xs-12 col-sm-12 hidden-md hidden-lg">
            <div class="map-directory-control_xs col-xs-12 form-group">
                <a class="btn collapsed" role="button" data-toggle="collapse"
                   href="#collapsemap" aria-expanded="false"
                   aria-controls="collapseExample">
                    Map
                    <span class="collpase_map collpase_map_open glyphicon glyphicon-menu-up"
                          aria-hidden="true"></span>
                    <span class="collpase_map collpase_map_close glyphicon glyphicon-menu-down"
                          aria-hidden="true"></span>
                </a>
            </div>
        </div>
        <div class="wrapper_search_directory">
            <div class="col-xs-12 col-sm-6 col-md-4 form-group category-section">
                <select id='category_select' class="form-control selectpicker"
                        title="Category">

                  <?php if ($category !== NULL): foreach ($category as $item):$status = ""; ?>

                    <?php
                    if (isset($filters["category"])) {
                      foreach ($filters["category"] as $filter) {

                        if ($filter == $item["tid"]) {
                          $status = "selected";
                        }
                      }
                    }
                    ?>
                    <?php print "<option value='" . $item["tid"] . "'  " . $status . ">" . $item["name"] . "</option>"; ?>

                  <?php endforeach; endif; ?>
                </select>
            </div>
            <div class="col-xs-12 col-sm-6 col-md-4 form-group">
                <select id='neighbourhood_select' title="Neighbourhood"
                        class="form-control selectpicker">

                  <?php foreach ($neighbourhood as $item): $status = ""; ?>

                    <?php
                    if (isset($filters["neighbourhood"])) {
                      foreach ($filters["neighbourhood"] as $filter) {

                        if ($filter == $item["tid"]) {
                          $status = "selected";
                        }
                      }
                    }
                    ?>
                    <?php print "<option value='" . $item["tid"] . "'  " . $status . ">" . $item["name"] . "</option>"; ?>


                  <?php endforeach; ?>
                </select>
            </div>
           <div class="col-xs-12 col-sm-6 col-md-4 hidden-xs hidden-sm">
                <div class="map-directory-control col-xs-12 form-group">
                    <a class="btn collapsed" role="button" data-toggle="collapse"
                       href="#collapsemap" aria-expanded="false"
                       aria-controls="collapseExample">
                        Map
                        <span class="collpase_map collpase_map_open glyphicon glyphicon-menu-up"
                              aria-hidden="true"></span>
                        <span class="collpase_map collpase_map_close glyphicon glyphicon-menu-down"
                              aria-hidden="true"></span>

                    </a>
                </div>
           </div>
        </div>
        <div class="col-xs-12 description_seach_section">
           <div class="col-xs-12 col-md-8 description_seach">
            <?php if(isset($category)):?>
                <p>
                Looking for the best hospital, spa or health provider in Shanghai? Use our search function to filter our listings and find immedialty what you need.
                </p>
            <?php else:?>
                <p>
                Select a category and find all our Family friendly venues from restaurants, cafes to shops and markets near your neighborhood. Use our search function to filter our listings and get immediately what you need.
                </p>
            <?php endif; ?>
            </div>
            <div class=" col-xs-12 col-md-4 input-section-search-directory ">

              <input type="button" id="edit-submit-top" name="op" value="Search" class="form-submit">

            </div>
        </div>

    </div>
</div>
<div class="container ">
    <div class="directory-wrapper row">
           <?php
             function is_filter($filters) {
                       if (isset($filters["category"])||isset($filters["neighbourhood"])){
                           return true;
                       } else {
                           return false;
                       }
              }
              $is_filter = (is_filter($filters));
              $title="Featured Directories";
              print theme_render_template(drupal_get_path('module', 'fs_search') . '/templates/fs_search_list_listing.tpl.php',
              array(
                         'items' => $items,
                         'title'=>$title,
                         'search_form'=>$search_form,
                         'pager'=>$pager,
                         'count'=>$count,
                         'filter'=>$is_filter

              ));
           ?>


<!--  div is not finished continue in page directory-->
