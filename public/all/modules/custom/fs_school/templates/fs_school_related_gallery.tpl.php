<?php
    global $base_url;
    if(count($items) >0 ):
  ?>

<div class="school-videos col-sm-12" id="school-gallery">
    <div class="title_details">Gallery</div>
<div class="bs-family-school-gallery" >
             <div id="owl-school-gallery" class="owl-carousel">
              <?php
              foreach ($items as $item):
               ?>
            <div class="item">
            <a href="<?php print $base_url.'/'.$item['url']; ?>" target="_blank"><img src="<?php if(!file_exists($item['image_url'])){print $item['image_url'];}else{print variable_get("default_image",NULL);}?>"/></a>
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
<?php endif; ?>