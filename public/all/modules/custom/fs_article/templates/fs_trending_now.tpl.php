
<div class="trending_now treding">
    <input type="hidden" id="cid" value="<?php print $cid; ?>"/>
    <input type="hidden" class="current_page" value="0"/>
  <div class="col-xs-12 header-item animated bounceInLeft"> 
    <span>TRENDING NOW</span>
</div>
    <?php if (!empty($items)): ?>
        <?php
//        if ($items[0]['editor_pick']) {
//            $stick_1 = "<img class=\"img-icon-content\" src=\"" . variable_get("path_theme", NULL) . "/images/icon/editor_pick.png\" alter=\"\" />";
//        }
//        else 
        if ($items[0]['sponsored']) {
            $stick_1 = "<div class=\"sponsored img-icon-item\"><img class=\"img-icon-content\" src=\"" . variable_get("path_theme", NULL) . "/images/icon/sponsored.png\" alter=\"\" /></div>  ";
        }
        elseif ($items[0]['win']) {
            $stick_1 = "<div class=\"img-icon-item\"><img class=\"img-icon-content\" src=\"" . variable_get("path_theme", NULL) . "/images/icon/win.png\" alter=\"\" /></div>  ";
        }
        else {
            $stick_1 = "";
        }
        ?>
        <div class="col-xs-12 first-item  parenting_item hidden-xs"> 
            <?php if ($items[0]['sponsored'] || $items[0]['win']): ?>
                <?php print $stick_1; ?>
            <?php else: ?>
                <div class="img-btn-item ">
                    <?php if($items[0]['categories'][0]):?>
                    <a  class='btn btn-default-1 <?php print str_replace(" ", "_", str_replace("&", "", $items[0]['categories'][0])); ?>'><?php print $items[0]['categories'][0]; ?></a>
                   <?php endif; ?> 
                </div>  
           <?php endif; ?> 
                  <div class="img_section">
            <a href="<?php print $items[0]['url']; ?>">
                <img src="<?php print $items[0]['image']; ?>" class="img-responsive  img-item" alt="" />
                <div class="overlay_treding"></div>
            </a>
                      </div>
            <span class="title-item title-item-first"><a href="<?php print $items[0]['url']; ?>"><?php print $items[0]['title']; ?></a></span>
        </div>
        <div class="col-xs-12 items">
            <?php $i = 0;
            foreach ($items as $item): 
                if ($i == 0) {
                    $hidden = "hidden-lg hidden-md hidden-sm";
                }
                else {
                    $hidden = "";
                } ?>
                  <?php 
                print theme_render_template(drupal_get_path('module', 'fs_article') . '/templates/fs_article_item_small.tpl.php', array('item' => $item,'hidden'=>$hidden)); 
                 ?>            
        <?php $i++;
    endforeach; ?>

        </div>
<?php endif; ?>
    <div class="more-item col-xs-12">
        <a href="javascript:void(0)" class="btn-more" >
            <div class="more_text_change">Load More
                <div class="three_point">
                    <span class="glyphicon glyphicon-off" aria-hidden="true"></span>
                     <span class="glyphicon glyphicon-off" aria-hidden="true"></span>
                      <span class="glyphicon glyphicon-off" aria-hidden="true"></span>
                </div>
            </div> 
<!--            <img  src="<?php //print variable_get("path_theme", NULL); ?>/images/background/more-btn.png" width="100px" />
       -->
        </a>
        <p id="loading" class="load_treding loading_tred">
            <i class="fa fa-spinner fa-pulse fa-3x fa-fw"></i>
            <span class="sr-only">Loading...</span>
        </p>
    </div>    
</div>             

