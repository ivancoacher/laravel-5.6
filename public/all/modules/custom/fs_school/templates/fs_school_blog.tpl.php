<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

?>


<div class="col-xs-12 title">
    <h1><?php  print $item['title']; ?></h1>
</div>
 <div class="col-xs-12 description-title"><span><?php  //print $item['sub_headline']; ?></p></span></div>
<div class="col-xs-12 sub-title">
    By <a href="<?php //print $item['author_profile_url']; ?>"><span> <?php print $item['author']; ?></span></a> | <?php print explode(",", $item['date'])[0]; ?>,<span> <?php print explode(",", $item['date'])[1] . "," . explode(",", $item['date'])[2]; ?></span>
</div>  
<div class="col-xs-12 details-articles">

    <div class="  social-network static_social hidden-xs hidden-sm ">
        <div class="comment hidden"><span class="glyphicon glyphicon-comment" aria-hidden="true"></span><br/><?php //print $item['num_comments']; ?></div>
        <div class="soc">
            <div class="fb a2a_kit a2a_kit_size_32 "><a class="a2a_button_facebook" href="#"><i class="fa fa-facebook-official" aria-hidden="true"></i></a></div>
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
            <button type="button" class="btn btn-default btn-lg comment"><span class="glyphicon glyphicon-comment" aria-hidden="true"></span> <span class="text"><?php //print $item['num_comments']; ?></span></button> 
            <a href="#" class="a2a_button_facebook btn btn-default btn-lg fb"><i class="fa fa-facebook-official" aria-hidden="true"></i></a> 
            <button type="button" class="a2a_dd addtoany_share_save btn btn-default btn-lg share"><i class="fa fa-share-alt" aria-hidden="true"></i></button> 
            <button type="button" class="btn btn-default btn-lg heart"><i class="fa fa-heart" aria-hidden="true"></i></button> 
        </div>

    </div>
   
    <div class="col-xs-12 description"><p><?php  print $item['body']; ?></p></div>

</div>


<div class="clearfix"></div>
<div class="row col-xs-12 hidden"><h2>Related Schools:</h2></div>
<div class="blog_school hidden col-xs-12">
    <div class="item-wrapper col-xs-12">
        <div class="col-sm-2 img_section"> <a href="/node/679" target="_blank"><img src="/sites/all/modules/custom/fs_search/images/placeholder.jpg" class="img-responsive"></a></div>
        <div class="col-sm-10 text_section">
            <div class="wrapper_school_item">
                <div class="col-xs-12  description-item-school-container">
                    <div class="title-item-school">
                        <span><a href="/node/679" target="_blank">Amber Montessori School of Shanghai &gt; Wuding Lu</a></span>
                        <div class="underline_school"></div>
                    </div>
                    <div class="description-item-school"><p style="height: 61px; overflow: hidden;">
                            Amber Montessori School was established in 2010. We have a really strong team with professional experience in Montessori education and a Full International Member School of America Montessori Society. We are the only professional ...</p>
                    </div>
                </div>

            </div>
        </div>
    </div>
</div>
