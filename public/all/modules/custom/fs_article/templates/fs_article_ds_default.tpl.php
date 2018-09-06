
<div class="col-xs-12 title">
    <h1><?php  print $item['title']; ?></h1>
</div>
 <div class="col-xs-12 description-title"><span><?php  print $item['sub_headline']; ?></p></span></div>
<div class="col-xs-12 sub-title">
    <a href="<?php print $item['author_profile_url']; ?>"><img src="<?php print $item['author_photo']; ?>" class="img-circle"/></a> by <a href="<?php print $item['author_profile_url']; ?>"><span> <?php print $item['author']; ?></span></a> | <?php print explode(",", $item['date'])[0]; ?>,<span> <?php print explode(",", $item['date'])[1] . "," . explode(",", $item['date'])[2]; ?></span>
</div>  
<div class="col-xs-12 details-articles">

    <div class="  social-network static_social hidden-xs hidden-sm ">
        <div class="comment"><span class="glyphicon glyphicon-comment" aria-hidden="true"></span><br/><?php print $item['num_comments']; ?></div>
        <div class="soc">
            <div class="fb a2a_kit a2a_kit_size_32"><a class="a2a_button_facebook" href="#"><i class="fa fa-facebook-official" aria-hidden="true"></i></a></div>
            <div class="wechat"><a  tabindex="0" class="btn-social" role="button" data-toggle="popover" data-trigger="focus" data-html="true"  data-content="<img src='<?php print $item['qrcode']; ?>' width='165px'>"><i class="fa fa-wechat" aria-hidden="true"></i></a></div>
            <div class="share a2a_kit a2a_kit_size_32"><a  class="a2a_dd addtoany_share_save" href="#"><i class="fa fa-share-alt" aria-hidden="true"></i></a></div>
        </div>
        <div class="heart"><i class="fa fa-heart" aria-hidden="true"></i></div>
    </div>
    <?php if(!empty($item["image"])): ?>
    <div class="col-xs-12 img-content"><img src="<?php print $item['image']; ?>" class="img-responsive" />
    </div>  
    <?php endif; ?>
    <div class="a2a_kit a2a_kit_size_32 social-mobile hidden-md hidden-lg">
        <div class="btn-group" role="group" aria-label="First group"> 
            <button type="button" class="btn btn-default btn-lg comment"><span class="glyphicon glyphicon-comment" aria-hidden="true"></span> <span class="text"><?php print $item['num_comments']; ?></span></button> 
            <a href="#" class="a2a_button_facebook btn btn-default btn-lg fb"><i class="fa fa-facebook-official" aria-hidden="true"></i></a> 
            <a  class="btn btn-default btn-lg wechat" tabindex="0" class="btn-social" role="button" data-placement="top" data-toggle="popover"  data-trigger="focus" data-html="true"  data-content="<img src='<?php print $item['qrcode']; ?>' width='165px'>"><i class="fa fa-wechat" aria-hidden="true"></i></a> 
            <button type="button" class="a2a_dd addtoany_share_save btn btn-default btn-lg share"><i class="fa fa-share-alt" aria-hidden="true"></i></button> 
            <button type="button" class="btn btn-default btn-lg heart"><i class="fa fa-heart" aria-hidden="true"></i></button> 
        </div>

    </div>
   
    <div class="col-xs-12 description"><p><?php  print $item['body']; ?></p></div>

</div>
<?php if(sizeof($item['tags'])!=0): ?>
<div class="col-xs-12 tag-section">
    <div class="title-tag col-sm-2">Tag :</div>
    <div class="tag-list col-xs-12 col-sm-10">
        <?php for($i=0 ;$i< sizeof($item['tags']);$i++): ?>
 
            <div class="tab-btn-content"><a href="#" class="tab-btn"><?php print $item['tags'][$i] ; ?></a></div>
        <?php endfor; ?>
    </div>
</div> 
<?php endif;?> 
 <?php if(isset($item['qr_code_sf'])&&isset($item['qr_code_pk'])):?>
 <div class="col-xs-6 qr_code_section">
     <img src="<?php  print $item['qr_code_sf']; ?>" class="img-responsive" />
 </div>
 <div class="col-xs-6 qr_code_section">
     <img src="<?php  print $item['qr_code_pk']; ?>" class="img-responsive" />
 </div>
 <?php else: ?>
 
 <?php if(isset($item['qr_code_sf'])):?>
 <div class="col-xs-12 qr_code_section">
     <img src="<?php  print $item['qr_code_sf']; ?>" class="img-responsive" />
 </div>
 <?php endif; ?>
 <?php if(isset($item['qr_code_pk'])):?>
 <div class="col-xs-12 qr_code_section">
     <img src="<?php  print $item['qr_code_pk']; ?>" class="img-responsive" />
 </div>
 <?php endif; ?>
 
 
 <?php endif; ?>

<div class="clearfix"></div>

