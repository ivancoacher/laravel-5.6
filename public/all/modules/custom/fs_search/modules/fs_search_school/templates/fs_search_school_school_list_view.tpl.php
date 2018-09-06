<?php  
if($item['premium']):
?>
<div class="item-school premium item-school-<?php print $item["nid"]; ?> col-xs-12">
    <?php else: ?>
    <div class="item-school item-school-<?php print $item["nid"]; ?> col-xs-12">
    <?php endif; ?>
    <div class="overlay_item_school active_overlay"></div>
    <div class="item-wrapper col-xs-12">
        <div class="col-sm-2 img_section"> <a href="<?php print $item['url']; ?>" target="_blank"><img src="<?php print $item['preview_image']; ?>" class="img-responsive"/></a></div>
        <div class="col-sm-10 text_section">
            <div class="wrapper_school_item">
                <div class="col-xs-12  description-item-school-container">
                    <div class="title-item-school">
                        <span><a href="<?php print $item['url']; ?>" target="_blank"><?php print $item['title']; ?></a></span>
                        <div class="underline_school"></div>
                    </div>
                    <div class="description-item-school"><p>
                            <?php
                            if (isset($item['summary'])) {
                                print ($item['summary']);
                            }
                            ?></p>
                    </div>
                </div>

                <div class="col-xs-12 down_item_school">
                    <div class="my-price-school col-sm-8 col-md-8">
                        <?php if(!empty($item['school_type'])):?><div class="col-sm-6"><span class="title_span">School Type: </span>&nbsp;<?php print $item['school_type']; ?></div><?php endif ?>
                        <?php if(!empty($item['neighborhood'])):?><div class="col-sm-6"><span class="title_span">Neighborhood: </span>&nbsp;<?php print $item['neighborhood']; ?> </div><?php endif ?>
                     
                        <?php if(!empty($item['language'])):?><div class="col-sm-6"><span class="title_span">Languages taught: </span>&nbsp; <?php print $item['language']; ?></div><?php endif ?>
                
                        <?php if(!empty($item['curriculum'])):?><div class="col-sm-6"><span class="title_span">Curriculum: </span>&nbsp;<?php print $item['curriculum']; ?> </div><?php endif ?>
                    </div>
                    <div class="btn-details-school col-sm-1 col-md-1">
                        <a href="<?php print $item['url']; ?>" class="btn btn-default" target="_blank">Details</a>
                    </div>
                    <div class="btn-compare-school col-sm-1 col-md-1">
                        <input type="hidden" class="variable" value="0"/>
                        <a id="<?php print $item['nid']; ?>" href="javascript:void(0)" class="btn btn-compare-item btn-default"  >Select to Compare</a>
                        <div class="btn-group hidden">
                            <button type="button" class="btn btn-default compare_now">Compare Now</button>
                            <button type="button" class="btn btn-danger cancel"  >
                                <span class="glyphicon glyphicon-remove-circle" aria-hidden="true"></span>
                            </button>
                        </div>
                    </div>

                </div>
            </div>
        </div>
    </div>
</div>
