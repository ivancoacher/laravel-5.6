<div class="trending_now what_new">
    <input type="hidden" id="cid" value="<?php print $cid ;?>"/>
    <input type="hidden" class="current_page" value="0"/>
<div class="col-xs-12 animated bounceInLeft  header-item"> 
    <span> WHAT'S NEW </span>
</div>
<?php if (!empty($items)): ?>
    <div class="col-xs-12 first-item  parenting_item hidden-xs"> 
        <?php
        if ($items[0]['editor_pick']){
            $stick_1 = "<div class=\"img-icon-item\"><img class=\"img-icon-content\" src=\"" . variable_get("path_theme", NULL) . "/images/icon/editor_pick.png\" alter=\"\" /> </div>";
        }
        else if ($items[0]['sponsored']){
            $stick_1 = "<div class=\"sponsored img-icon-item\"> <img class=\"img-icon-content\" src=\"" . variable_get("path_theme", NULL) . "/images/icon/sponsored.png\" alter=\"\" /> </div>";
        }
        elseif ($items[0]['win']){
            $stick_1 = "<div class=\"img-icon-item\"><img class=\"img-icon-content\" src=\"" . variable_get("path_theme", NULL) . "/images/icon/win.png\" alter=\"\" /> </div>";
        }
        else{
            $stick_1 = "";
        }
        ?>
          <?php if ($items[0]['editor_pick'] || $items[0]['sponsored'] || $items[0]['win']): ?>
                <?php print $stick_1; ?>
          <?php endif; ?> 
        <div class="img_section">
           <a href="<?php print $items[0]['url']; ?>">
               <img src="<?php print $items[0]['image']; ?>" class="img-responsive  img-item " />
            <div class="overlay_treding"></div>
           </a>
        </div>    
           <span class="title-item title-item-first">  <a href="<?php print $items[0]['url']; ?>" style="color: white;"><?php print $items[0]['title']; ?></a></span>
    </div>
    <div class="col-xs-12 items ">
        <?php $i=0;foreach ($items as $item): if($i==0){$hidden="hidden-lg hidden-md hidden-sm";}else{$hidden="";}?>      
                 <?php 
                print theme_render_template(drupal_get_path('module', 'fs_article') . '/templates/fs_article_item_small.tpl.php', array('item' => $item,'hidden'=>$hidden,'category_active'=>'0')); 
                 ?>  
        <?php $i++; endforeach; ?>

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
        </a>
        <p id="loading" class="load_treding">
                <i class="fa fa-spinner fa-pulse fa-3x fa-fw"></i>
                <span class="sr-only">Loading...</span>
        </p>
    </div>    
</div>             


