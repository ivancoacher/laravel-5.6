<?php
    global $base_url;
    if($items):
  ?> 
<div class="school_testimonial school-videos col-sm-12" id="school-testimonials">
    <div class="title_details">Testimonials</div>
<div class="bs-family-school-testimonial" >
             <div id="owl-school-testimonial" class="owl-carousel">
              <?php
              foreach ($items as $item):
               ?>
            <div class="item">
                
                <div class="description">
                    <span class="left-quat">“</span> 
                    <?php print $item['message']; ?>
                <span class="right-quat">”</span>
                </div>
                <div class="title"><?php print $item['signature']; ?></div>
                  
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
