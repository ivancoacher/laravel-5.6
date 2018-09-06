
<div class="col-xs-12 pick-of-week-container">
                <div class="col-xs-12 title-pick-of-week">
                   <span>Pick of the week</span>
                </div>

                <div class="header-pick-of-week">
                        <div id="owl-family-editor-week" class="owl-carousel" > 
                          
                          <?php $i = 1; $j=1; foreach($items as $content):?>
                            <?php  if(isset($content['nodes'])): ?>
                          <div class="col-xs-4 col-sm-12 col-md-12 col-lg-12 menu-week   ">
                              
                              <a id="menu_week_<?php print $i;?>" class="<?php if($j==1){print "active_week underline_menu_week";}?>" href="javascript:void(0)"> <?php print $content['name']; ?></a>
                          </div>                              
                                  <?php $j++; endif; ?>
                           <?php $i++; endforeach;?>
            
                            
                        </div> 
                        <div class="pick_week_container_navigator">
                        <a class="prev_editor_w">     <span class="glyphicon glyphicon glyphicon-chevron-left carousel-control-editor" aria-hidden="true"></span>
                            <span class="sr-only">Previous</span></a>
                        <a class="next_editor_w">   <span class="glyphicon glyphicon glyphicon-chevron-right carousel-control-editor" aria-hidden="true"></span> 
                            <span class="sr-only">Next</span> </a>
                       </div>

                </div>  
              
                <div class="pick-of-week-lists-tab">
                    <input type="hidden" id="current_active_week"  value="0" />  
<?php $i = 1; $j=1;foreach($items as $content):?>   
            <?php  if(isset($content['nodes'])): ?>
                        <div class="pick-of-week-list <?php if ($j == 1) { print "display_custom_week"; } ?> data_menu_week_<?php print $i; ?>"> 
                            <?php $k=0; foreach($content['nodes'] as $value):?>
                                 <?php if($k<6):?>
                            <div class="col-xs-6 col-sm-6 col-md-12  week-item">
                                <div class="col-xs-4 week-img"> 
                                    <a href="<?php print $value['url'];?>"><img src="<?php print $value['image'];?>" class="img-responsive img-item" /></a>
                                </div>
                                <div class="col-xs-8 week-right">
                                    <div class="title-week"><a href="<?php print $value['url'];?>"><?php print $value['title'];?></a> </div>
                                    <div class="country-week"><?php if(isset($value['country']))print $value['country'];?></div>
                                    <div class="local-week"><i class="fa fa-map-marker" aria-hidden="true"></i> <?php print $value['address'];?></div>
                                </div>
                            </div>
                                <?php endif;?>
                            <?php $k++; endforeach; ?>                          
                        </div>
            <?php $j++; endif; ?>
<?php $i++;endforeach; ?> 

                </div>
       </div>
        
            <!--  end pick-of-week         -->

<?php 

//foreach ($items as $content){
  //  $category[]=$item->name
//}

?>