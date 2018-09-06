
   <?php if (!empty($items)): ?>

    <div class="tab-mega-menu">
      <ul class="nav nav-tabs nav-tabs-left nav-centered tab_color" role="tablist">
            <?php $i=1;foreach ($items as $item): ?>

                    <li role="presentation" <?php if($i==1){print 'class="active"';} ?> >
                        <a href="<?php print "#tab_megamenu_".$item['tid']; ?>" data-toggle="tab" role="tab">
                            <?php print $item['name'] ?>
                        </a>
                    </li>
            <?php $i++;endforeach; ?>
      </ul>
      <div id="my_side_tabs" class="tab-content side-tabs side-tabs-left">
              <?php $i=1; foreach ($items as $item): ?>
                      <div class="tab-pane fade <?php if($i==1){print 'in active';} ?>" id="<?php print "tab_megamenu_".$item['tid']; ?>" role="tabpanel">
                          <div class="col-xs-12 item-tabs">
                            <?php if (!empty($item['articles'])): ?>
                              <?php $i=1;foreach ($item['articles'] as $article): ?>
                                <?php if($i<4):?>
                                <div class="col-sm-4 col-md-4 col-lg-3">
                                        <div class="img_section">
                                    <a href="<?php print $article['url']; ?>">
                                        
                                        <img class="img-responsive home_style_img_item_menu" src="<?php if(!file_exists($article['image'])){print $article['image'];}else{ print variable_get("default_image",NULL);} ?>" />
                                         <div class="overlay_treding"></div>
                                    </a>
                                        
                                        </div>
                                    <a href="<?php print $article['url'];?>"><p>  <?php print($article['title']); ?> </p></a>
                                </div>
                               <?php else:?>
                                <div class="col-sm-4 col-md-4 col-lg-3 hidden-md hidden-sm">
                                          <div class="img_section">
                                    <a href="<?php print $article['url']; ?>">
                                        
                                        <img class="img-responsive home_style_img_item_menu" src="<?php if(!file_exists($article['image'])){print $article['image'];}else{ print variable_get("default_image",NULL);} ?>" />
                                         <div class="overlay_treding"></div>
                                    </a>
                                        
                                        </div>
                                    <a href="<?php print $article['url'];?>"><p>  <?php print($article['title']); ?> </p></a>
                                </div>
                               <?php endif ;?>
                              <?php $i++ ;endforeach; ?>
                            <?php endif; ?>
                          </div>

                          <div class="col-xs-12 read-more text-center"><a href="<?php print $item['link']; ?>" >See More</a></div> 

                     </div>

            <?php $i++; endforeach; ?>
      </div>
    </div>
  <?php endif; ?>
