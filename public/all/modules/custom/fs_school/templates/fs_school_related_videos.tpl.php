<?php
global $base_url;
if(isset($items)):?>

<div class="school-videos col-sm-12" id="school-videos">
    <div class="title_details">Videos</div>
<div class="bs-family-school-video" >
             <div id="owl-school-videos" class="owl-carousel">
                 <!--//**Large Screen Layout**//-->
              <?php
                    //should change the same variable
                    foreach ($items as $item):
                            ?>
                               <div class="item">
                                  <a class="various fancybox fancybox.iframe" href="<?php if(!file_exists($item['url'])){print$item['url'];}?>">
                                     <img src="<?php if(!file_exists($item['image'])){print $item['image'];}else{print variable_get("default_image",NULL);} ?>" /></a>
                               </div>
              <?php endforeach; ?>
              </div>
       <div class="customNavigation">
           <a class="prev">     <span class="carousel-control-family-left" aria-hidden="true">
                   <img src="<?php print $base_url.'/'.drupal_get_path("module", "fs_school").'/images/arrow-l.png'?>"/>
               </span>
            <span class="sr-only">Previous</span></a>
            <a class="next">   <span class="carousel-control-family-right" aria-hidden="true">
                
                    <img src="<?php print $base_url.'/'.drupal_get_path("module", "fs_school").'/images/arrow-r.png'?>"/>
                </span>
            <span class="sr-only">Next</span> </a>
       </div>
    
</div>
</div>
<?php endif;?>