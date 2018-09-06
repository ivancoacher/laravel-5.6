<div id="main-gallery-details">  
    <div class="content-details-gallery">
        <input type="hidden" id="status_collapse" value="0" />
        <div id="st-container" class="st-container st-effect-10">
            <div class="main clearfix">
                <a class="back_gallery hidden  visible-lg" href="/shanghai/gallery"><span class="glyphicon glyphicon-menu-left" aria-hidden="true"> </span><span class="text-back">Back to Gallery</span></a>

                <div class="col-md-4" id="menu-10">

                    <h2 class="text-center"> <span class="text"><?php print $item['title']; ?></span> 
                    </h2>
                    <p class="inline"></p>
                    <p class="date text-center"><?php print $item['date']; ?></p>
                    <div class="description text-center"> <?php print $item['desc']; ?></div>
                </div>
                <div id="st-trigger-effects" class="column  col-md-8 row">
                    <div class="bs-family-gallery-details" > 
                        <div id="owl-family-gallery-details" class="owl-carousel owl-theme">
                            <!--//**Large Screen Layout**//-->
                            <?php for ($i = 0; $i < sizeof($item['images']); $i++): ?>
                              <div class="item">
                                  <img   src=" <?php
                                  if (!file_exists($item['images'][$i]["image"])) {
                                    print $item['images'][$i]["image"];
                                  }
                                  else {
                                    print variable_get("default_image", NULL);
                                  }
                                  ?>" class="img-responsive1 img-gallery-details1" />
                                  <a class="mobal_gallery hidden-xs hidden-sm" href="<?php print print $item['images'][$i]["image"]; ?>" rel="prettyPhoto[gallery1]" ><span class="glyphicon glyphicon-search" aria-hidden="true"> </span></a>             
                              </div>
                            <?php endfor; ?>
                        </div>
                        <div class="customNavigation">
                            <a class="btn prev">     <span class="glyphicon glyphicon-menu-left carousel-control-family-left" aria-hidden="true"></span>
                                <span class="sr-only">Previous</span></a>
                            <a class="btn next">   <span class="glyphicon glyphicon-menu-right carousel-control-family-right" aria-hidden="true"></span> 
                                <span class="sr-only">Next</span> </a>
                        </div>

                    </div>


                </div>

            </div><!-- /main -->



        </div><!-- /st-container -->

    </div>
</div>

