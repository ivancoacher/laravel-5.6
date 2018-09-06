<div id="gallery">
<div class="highlight">
    <div class="container">
        <div class="col-xs-6"><span>Gallery</span></div>
        <div class="col-xs-6 hidden-xs hidden"><p>
                Go from Tutorial for Converting a Module from Drupal 7 to Drupal 8 to the Blog. Return to the Unleashed Technologies Home Page. Search form. Search.</p></div>
    </div>
</div> 
<div class="container main-gallery">
    <div class="wrapper row">
       
        <div class="col-xs-12 item_list">
             <?php $i=1;foreach ($items as $item) :?>
            <div class="col-xs-6 col-sm-6 col-md-4 item <?php print "item_".$i;?> hover-blur">                
                <a href="<?php print $item['url']; ?>" title="">
                <img src="<?php print $item['image']; ?>" class="img-reponsive" alt=""/>
              <h2>
                  <span class="text-white"><?php print $item['title']; ?></span>
                  <p class="inline"></p>
                  <p class="date"><?php print $item['date']; ?><p>
                  <p class="description"> <?php print $item['summary']; ?> </p>
<!--                  <p class="number">34<p>-->
              </h2>
            </a> 
            </div>
              <?php $i++;endforeach; ?>

        </div> 
        <div class="col-xs-12 pagination-content">
          
            <div class="wrapper_page">
                  <?php print $pager; ?>
            </div>    
        </div>
    </div>
</div>
 </div>

