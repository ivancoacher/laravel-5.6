        <?php
                $stick="";
                if (isset($item['editor_pick'])&&$item['editor_pick']) {
                    $stick = "<div class=\"img-icon-item\"><img alt=\"\" class=\"img-icon-content\" src=\"" . variable_get("path_theme", NULL) . "/images/icon/editor_pick.png\" alter=\"\" /></div>  ";
                }
                else if (isset($item['sponsored'])&&$item['sponsored']) {
                    $stick = "<div class=\"sponsored img-icon-item\"><img alt=\"\" class=\"img-icon-content\" src=\"" . variable_get("path_theme", NULL) . "/images/icon/sponsored.png\" alter=\"\" /></div>  ";
                }
                elseif (isset($item['win'])&&$item['win']) {
                    $stick = "<div class=\"img-icon-item\"><img class=\"img-icon-content\" alt=\"\" src=\"" . variable_get("path_theme", NULL) . "/images/icon/win.png\" alter=\"\" /></div>  ";
                }
                else {
                    $stick = "";
                   
                }
                ?>
            <div class="col-xs-6 col-sm-6 col-md-4 item-content parenting_item <?php if(isset($hidden)){print $hidden;} ?>">
      
        <?php if ($stick!=""): ?>
                        <?php print $stick; ?>
        <?php else: ?>
                    <?php if(isset($item['categories'])&&$item['categories']&&isset($category_active)&&$category_active!='0'):?>
                        <div class="img-btn-item ">
                            <a  class='btn btn-default-1 <?php print str_replace(" ", "_", str_replace("&", "", $item['categories'][0])); ?>'><?php print $item['categories'][0]; ?></a>
                        </div>
                    <?php endif;?>
        <?php endif; ?>      
                
                    <div class="img_section">
                    <a href="<?php print $item['url']; ?>">
                        <img src="<?php print $item['image']; ?>" class="img-responsive img-item" alt="" />
                        <div class="overlay_treding"></div>
                    </a>
                    </div>    
                <p class="title-item"><a class="cut-item" href="<?php print $item['url']; ?>"><?php print $item['title']; ?></a></p>
                    
         </div>