
       <div class="col-xs-12 most-section" >

            <ul class="col-xs-12 title " id="most">
                <li class="tab-one active">Most Read</li>
                <li class="tab-two"> Most Popular</li>
            </ul>

            <div id="tab-one" class="tab-page active-page">
                <div class="col-xs-12 most-list">
                     <?php foreach ($items_most_read as $item_most_read): ?>
                        <div class="col-xs-6 col-sm-6 col-md-12 col-lg-12 item-most">

                            <div class="col-xs-4 img-most">
                                  <a href=" <?php print $item_most_read['url']; ?>" target="blank">
                                <img src='<?php print $item_most_read['image']; ?>' class="img-responsive"/>   </a>
                            </div>
                            <div class="col-xs-8 right-most">
                                <div class="date"><?php print $item_most_read['date']; ?></div>
                                <div class="description">  <?php print $item_most_read['title']; ?></div>
                                <div class="btn-list">
                                   <?php for($i=0 ;$i< sizeof($item_most_read['tags']);$i++): ?>
                                    <a class="btn btn-default btn-sm" href="#" role="button"><?php print $item_most_read['tags'][$i]; ?></a>
                                        <?php endfor; ?>
                                </div>
                            </div>
                        </div>
                    <?php endforeach; ?>

                </div>
            </div>

            <div id="tab-two" class="tab-page">
                       <div class="col-xs-12 most-list">
                     <?php foreach ($items_most_pop as $item_most_pop): ?>
                        <div class="col-xs-6 col-sm-6 col-md-12 col-lg-12 item-most">

                            <div class="col-xs-4 img-most">
                                <a href=" <?php print $item_most_pop['url']; ?>" target="blank">
                                <img src='<?php print $item_most_pop['image']; ?>' class="img-responsive"/>   </a>
                            </div>
                            <div class="col-xs-8 right-most">
                                <div class="date"><?php print $item_most_pop['date']; ?></div>
                                <div class="description"><?php print $item_most_pop['title']; ?></div>
                                <div class="btn-list">
                                        <?php for($i=0 ;$i< sizeof($item_most_pop['tags']);$i++): ?>
                                    <a class="btn btn-default btn-sm" href="#" role="button"><?php print $item_most_pop['tags'][$i]; ?></a>
                                        <?php endfor; ?>
                                </div>
                            </div>
                        </div>
                     <?php endforeach; ?>

                </div>
            </div>


        </div>
