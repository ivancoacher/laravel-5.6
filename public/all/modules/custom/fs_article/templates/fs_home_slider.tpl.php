
<div class="bs-family-slideshow  " > 
             <div id="owl-family" class="owl-carousel">
                       <!--//**Large Screen Layout**//-->
                        <?php  if (!empty($items)): ?> 
                         <?php  foreach ($items as $item): ?>
                                <?php fs_article_item_slide($item) ; ?>              
                        <?php endforeach;?>
                       <?php endif;?>
              </div>
        <div class="customNavigation">
        <a class="btn prev">     <span class="glyphicon glyphicon-menu-left carousel-control-family-left" aria-hidden="true"></span>
            <span class="sr-only">Previous</span></a>
        <a class="btn next">   <span class="glyphicon glyphicon-menu-right carousel-control-family-right" aria-hidden="true"></span> 
            <span class="sr-only">Next</span> </a>
       </div>

</div>
