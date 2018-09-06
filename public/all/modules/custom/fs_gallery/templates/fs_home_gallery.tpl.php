<div class="col-xs-12 gallery-container">
    <div class="title-gallery">
        <a href="/shanghai/gallery"><span>PHOTO GALLERY</span></a>
    </div>
<div class="bs-family-home-gallery" > 
             <div id="owl-home-gallery" class="owl-carousel">
                       <!--//**Large Screen Layout**//-->
                       
                        <?php if (!empty($items)): ?>
                            <?php foreach ($items as $item) : ?>
                       <div class="item hover-blur">
                           <a href="<?php print $item['url']; ?>"><img src="<?php if(!file_exists($item['image'])){print $item['image'];}else{print variable_get("default_image",NULL);} ?>" />              
             <h2>
                  <span class="text-white"><?php print $item['title']; ?></span>
             </h2>
             </a>              
                       </div>     
                       <?php endforeach; ?>
                          <?php endif; ?>
              </div>
       <div class="customNavigation">
        <a class="btn prev">     <span class="glyphicon glyphicon-menu-left carousel-control-family-left" aria-hidden="true"></span>
            <span class="sr-only">Previous</span></a>
        <a class="btn next">   <span class="glyphicon glyphicon-menu-right carousel-control-family-right" aria-hidden="true"></span> 
            <span class="sr-only">Next</span> </a>
       </div>
            
        
</div>
    <div class="col-xs-12 see_more"><a href="/shanghai/gallery"><span>See more</span></a></div>
 
</div> 


