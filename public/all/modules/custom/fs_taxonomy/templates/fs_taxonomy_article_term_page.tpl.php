
<div class="col-xs-12" id="arctile-section">
    <input type="hidden" value="<?php print "0";?>"  id="current_page"/>
    <div class="col-xs-12 title-content">
        <div class="title">
            <div class="text" style="#"><?php print strtoupper($name) ;?></div>
        </div>
    </div>
    <div class="col-xs-12 item-articles">
        <div class="col-xs-12 first-item hidden-xs">
            <?php if (!empty($items)) :  ?>
            <a href="<?php print $items[0]['url']; ?>">
            <img src="<?php print $items[0]['image']; ?>"
                 class="img-responsive"/>

            <div class="wrapper-first">
                <div>  <?php  print  $items[0]['title']; ?></div>
            </div>
             </a>
            <?php endif; ?>
        </div>
        <div class="clearfix"></div>
        <div class="item-masonry col-xs-12">
            <div id="timeline" class="article_grid" data-columns >
                <?php if (!empty($items)) : $i=0; ?>
                    <?php $t=1;foreach ($items as $item) : ?>
                         <?php if($i==1):?>
                            <div class="item " id="grid-item-one">
                                <div class="wrapper-masonry">
                                    <div class="shadow">
                                        <div class="img-content"><a href="<?php print $item['url']; ?>"><img
                                                    src="<?php print $item['image'] ?>"  class="img-responsive"/></a></div>
                                        <div class="title-item">
                                            <a href="<?php print $item['url']; ?>"     <span><?php print $item['title']; ?></span> </a>

                                            <div class="underline_articles"></div>
                                        </div>
                                        <div class="description" >
                                            <p>
                                            <?php if(isset($item['summary'])){
                                               /// if(strlen($item['summary'])>130){
                                                  //  print substr($item['summary'],0, $rand[mt_rand(0,5)])."...";
                                                    
                                                
                                              //  }else{
                                                    print ($item['summary']);
                                              //  }
                                            
                                            } ?>
                                            </p> 
                                             
                                        </div>
                                       
                      
                                    </div>
                                </div>
                            </div>
              
                       
                         <?php elseif($i>1):?>
                        <div class="item ">
                            <div class="wrapper-masonry ">
                                <div class="shadow">
                                    <div class="img-content"><a href="<?php print $item['url']; ?>"><img
                                                src="<?php print $item['image'] ?>"  class="img-responsive"/></a></div>
                                    <div class="title-item">
                                        <a href="<?php print $item['url']; ?>"  >   <span><?php print $item['title']; ?></span> </a>

                                        <div class="underline_articles"></div>
                                    </div>
                                    <div class="description" >
                                                <p>
                                               <?php if(isset($item['summary'])){
                                                   
                                                    print ($item['summary']);
                                                
                                            
                                               } ?>
                                            </p> 
                                           
                                    </div>
                                   
                                </div>
                            </div>
                        </div>
                        <?php endif; ?>
                    <?php $i++; endforeach; ?>
                <?php endif; ?>
            </div>
            <div id="posts" class="col-xs-12">
            <p id="loading">
                <i class="fa fa-spinner fa-pulse fa-3x fa-fw"></i>
                <span class="sr-only">Loading...</span>
            </p>
            </div>
        </div>
    </div>
</div>

