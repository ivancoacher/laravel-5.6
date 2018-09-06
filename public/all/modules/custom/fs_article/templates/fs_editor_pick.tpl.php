<div class="editor_pick_container">
    <div class="col-xs-12 header-item"> 
        <img src="<?php print variable_get("path_theme",NULL);?>/images/family_style/editor_pick.png" class="img-responsive title-list" />
    </div>
    <div class="clearfix"></div>    
    <div class="editor_pick_header">
         <div id="owl-family-editor-pick" class="owl-carousel">
                       <!--//**Large Screen Layout**//-->
                      <?php if (!empty($items)):?>
                            <?php $i=1 ; foreach ($items as $item): ?>                     
                            <?php if($item['articles']): ?>
                            <?php if($i==1):?>
                             <div class="item ">
                                <a id="menu_<?php print $i;?>" class="menu-editor active_editor underline_menu" href="javascript:void(0)"><?php print ($item["name"]) ; ?> </a> 
                             </div> 
                          <?php else: ?>
                            <div class="item">
                                <a id="menu_<?php print $i;?>" class="menu-editor"  href="javascript:void(0)"><?php print ($item["name"]) ; ?> </a> 
                             </div> 
                          <?php endif;?>
                              <?php endif;?>
                       
                        <?php $i++; endforeach;?>
                       <?php endif;?>
                                                                                           
   
                <?php //include("item_slide_show.php") ?>
         </div>
        <div class="editor_pick_container_navigator">
        <a class="prev_editor">     <span class="glyphicon glyphicon glyphicon-chevron-left carousel-control-editor" aria-hidden="true"></span>
            <span class="sr-only">Previous</span></a>
        <a class="next_editor">   <span class="glyphicon glyphicon glyphicon-chevron-right carousel-control-editor" aria-hidden="true"></span> 
            <span class="sr-only">Next</span> </a>
       </div>
    </div>
    
        <div class="item-list-tab"> 
          <input type="hidden" id="current_active"  value="0" />   
          <?php if (!empty($items)):?>
                    <?php $i=1 ; foreach ($items as $item): ?>
                       <?php if (!empty($item['articles'])): ?>   
                                <div class="col-xs-12 items item_editor_pick <?php if($i==1){print "display_custom";} ?> data_menu_<?php print $i; ?> " >                              
                                 <div class="col-md-6 item-large">
                                           <div class="col-md-12  item-content-editor hidden-xs hidden-sm">
                                               <a href="<?php print $item['articles'][0]["url"];?>"><img src="<?php print $item['articles'][0]["image"];?>" class="img-responsive img-item" /></a>
                                                        <p class="title-item"> <a href="<?php print $item['articles'][0]["url"];?>"><?php print $item['articles'][0]["title"];?></a></p>
                                          </div>   
                                 </div> 
                                 <div class="col-md-6 item-small">
                                     <?php $j=1; foreach ($item['articles'] as $article): ?>
                                         <?php if($j==1):?>                                     
                                                    <div class="col-xs-6 col-sm-6 col-md-6 item-content-editor hidden-md hidden-lg">
                                                         <a href="<?php print $article["url"];?>"><img src="<?php print $article["image"];?>" class="img-responsive img-item" /></a>
                                                         <p class="title-item"> <a href="<?php print $article["url"];?>"><?php print $article["title"];?></a></p>
                                                    </div>  
                                             
                                         <?php else:?>                                          
                                                    <div class="col-xs-6 col-sm-6 col-md-12 item-content-editor">
                                                         <a href="<?php print $article["url"];?>"><img src="<?php print $article["image"];?>" class="img-responsive img-item" /></a>
                                                        <p class="title-item"> <a href="<?php print $article["url"];?>"><?php print $article["title"];?></a></p>
                                                    </div>  
                                            
                                 
                                         <?php endif;?> 
                                <?php $j++; endforeach; ?>
                                </div>     
                             </div>              
   
                  <?php endif; ?>
             <?php $i++; endforeach;?>
        <?php endif;?>
        </div>
       

    </div>  
   
