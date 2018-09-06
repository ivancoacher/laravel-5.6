
<?php if($count):?>

<div class="top-section">
    <div class="container search-result-info"><p class="result">  <?php print $count; ?> Results:  <?php print $keyword; ?> </p></div>
</div>
<div>
 

</div>
<div class="container main-search-content">
    <div class="col-md-9">
        <div class="wrapper row">
            <div class="col-xs-12 filter-content"> 
                <div class="wrapper-filter col-xs-12">
                    <div class="col-xs-12 hidden-xs col-sm-2 item-filter label-filter">Filters :</div>
                     <?php $default_active="active"; foreach($filter_links as $filter_link){
                         if($filter_link['attributes']['class'][0]!=''){
                             $default_active='';
                         }
                     }?>
                    <?php foreach ($filter_links as $filter_link) :  ?>
                      
                       <div class="col-xs-4 col-sm-2 item-filter"><a
                             class="<?php if($filter_link['title']=='All'){ print $default_active." ";} print $filter_link['attributes']['class'][0]; ?>";      
                        href="<?php  print url($filter_link['href'], ['query'=> $filter_link['query']]); ?>"><?php print $filter_link['title'] ?></a></div>
                                    
                      <?php endforeach; ?>

<!--                    <div class="col-xs-4 col-sm-2 item-filter"><a href="#">All</a></div>
                    <div class="col-xs-4 col-sm-2 item-filter "><a class="active_filter" href="#">Articles</a></div>
                    <div class="col-xs-4 col-sm-2 item-filter"><a href="#">Listings</a></div>
                    <div class="col-xs-4 col-sm-2 item-filter"><a href="#">Events</a></div>
                    <div class="col-xs-4 col-sm-2 item-filter"><a href="#">School</a></div>-->
                </div>
            </div>
            <div class="col-xs-12 item-events-list item-school-list item-directory-list main-result-search">
<!--                <div class="item-directory item-article col-xs-12">
                    <div class="item-wrapper col-xs-12">
                        <div class="col-sm-12 col-md-4"><img src="<?php //print variable_get("path_theme");?>/images/item/rectangle-14.png" class="img-responsive"></div>
                        <div class="col-sm-12 col-md-8 description-item-directory-container">
                            <div class="row title-item-directory">
                                <span>Articles Fukuok Nori</span>
                                <div class="underline_directory"></div>                               
                            </div>
                            
                            <div class="row description-item-directory">For folks using standard links that are not within the regular navbar navigation component, 
                                use the  class to add the proper colors 
                                for the default and inverse navbar options.use the  class to add the proper colors 
                                for the default and inverse navbar options.use the  class to add the proper colors 
                                for the default and inverse navbar options.
                            </div>
                            <div class="row btn-item-more">
                                   <a href="./school_details.php" class="btn btn-default">Read More </a>                             
                            </div>
                        </div>
                    </div>
                </div>-->
<!--                <div class="item-school col-xs-12">
                    <div class="item-wrapper col-xs-12">
                        <div class="col-sm-12 col-md-4"><img src="<?php //print variable_get("path_theme");?>/images/item/school_item.png" class="img-responsive"></div>
                        <div class="col-sm-12 col-md-6 description-item-school-container">
                            <div class="row title-item-school">
                                <span>University of Minnesota Crookston</span>
                                <div class="underline_school"></div>                               
                            </div>
                            <div class="row description-item-school">For folks using standard links that are not within the regular navbar navigation component, 
                                use the  class to add the proper colors 
                            </div>
                        </div>
                        <div class="col-sm-12 col-md-2 rigth-container">
                            <div class="my-price-school col-sm-12 col-md-12">
                                <div class="pull-left old_price">Ұ34 777</div>
                                <div class="pull-right cuurent_price">Ұ24 777</div>

                            </div>
                            <div class="btn-compare-school col-sm-12 col-md-12">
                                <a href="./compare.php" class="btn btn-default">Compares Now </a>
                            </div>
                            <div class="btn-details-school col-sm-12 col-md-12">
                                <a href="./school_details.php" class="btn btn-default">Details </a>
                            </div>
                        </div>
                    </div>
                </div>-->
            
                <?php foreach ($items as $item): ?>
                    <?php print $item ;?>
                <?php endforeach;?>
<!--                <div class="item-directory col-xs-12">
                    <div class="item-wrapper col-xs-12">
                        <div class="col-sm-12 col-md-4"><img src="<?php //print variable_get("path_theme");?>/images/item/rectangle-14.png" class="img-responsive"></div>
                        <div class="col-sm-12 col-md-6 description-item-directory-container">
                            <div class="row title-item-directory">
                                <span>Fukuok Nori</span>
                                <div class="underline_directory"></div>                               
                            </div>
                            <div class="row description-item-directory">For folks using standard links that are not within the regular navbar navigation component, 
                                use the  class to add the proper colors 
                                for the default and inverse navbar options.use the  class to add the proper colors 
                                for the default and inverse navbar options.use the  class to add the proper colors 
                                for the default and inverse navbar options.
                            </div>
                        </div>
                        <div class="col-sm-12 col-md-2 rigth-container">
                            <div class="my-rate col-sm-4 col-md-12">Rating 3.5/5</div>
                            <div class="btn-details col-sm-4 col-md-12"><a href="./directory_details.php">Details</a></div>
                            <div class="btn-website col-sm-4 col-md-12"><button type="button" class="btn btn-default">Web Site <span class="glyphicon glyphicon-menu-right" aria-hidden="true"></span></button></div>
                        </div>
                    </div>
                </div>
              -->
<!--                <div class="item-events col-xs-12">
                    <div class="item-wrapper col-xs-12">
                        <div class="col-sm-12 col-md-4 item-events-img-content"><a href="<?php //print variable_get("path_theme");?>/events_details.php"><img src="./images/item/rectangle-13.png" class="img-responsive"></a></div>
                        <div class="col-sm-12 col-md-8 description-item-events-container">
                            <div class="row title-item-events">
                                <span>KIDZ BOP KIDS Life of the Party 2016 Tour</span>
                                <div class="underline_events"></div>                               
                            </div>
                            <div class="row events-time">

                                <div class=" today_details">
                                    <span class="glyphicon glyphicon-calendar" aria-hidden="true"></span>
                                    Wednesday,July 27,2016
                                </div>
                                <div class=" time_details"><i class="fa fa-clock-o" aria-hidden="true"></i>
                                    6:00pm(July 6,2016) - 9:00pm 
                                </div>
                            </div>
                            <div class="row description-item-events">
                                KIDZ BOP KIDS Life of the Party 2016 Tour Friday,October 21,2016 
                                Showtime - 7:00 PM Theatre Doors Open - 6:00 PM Club Doors Open - 5:00
                                PM Ticket ...
                            </div>
                        </div>

                    </div>
                </div>-->

            </div>
            
            <div class="col-xs-12 pagination-search pagination-directory">
                <?php print $pager; ?>
<!--                  <ul class="pagination"> 
                    <li class="disabled"><a href="#" aria-label="Previous"><span aria-hidden="true">«</span></a></li> 
                    <li class="active"><a href="#">1 <span class="sr-only">(current)</span></a></li> 
                    <li><a href="#">2</a></li> <li><a href="#">3</a></li> 
                 
                    <li><a href="#" aria-label="Next"><span aria-hidden="true">»</span></a></li> 
                </ul>-->
           </div>
        </div>

    </div>
</div>
<?php else:?>
<div class="top-section">
    <div class="container search-result-info"><p class="result"> Sorry, no result found for your request ! </p></div>
</div>
<?php endif; ?>
