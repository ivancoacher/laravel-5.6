<?php if($items): ?>
<div class="col-sm-12 fs-similar-school">
    <h4 class="title">Similar Schools</h4>
<?php foreach ($items as $item): ?>
<!--    <a href='<?php print $item['url']?>' style="">-->
<div class="item-container">
<div  class="col-xs-4 col-sm-2 col-md-5 image">
<img class="img-responsive" src="<?php print $item['image_url']?>" />
</div>
<div class="col-xs-8 col-sm-10 col-md-7 content-cont">
    <a href="<?php print $item['url'];?>"><div class="title"><?php print $item['title']?></div></a>
  <?php if($item['field_school_premium']):?>
    <a href="<?php print $item['inquiry'];?>"><div class="read-more-link">Learn More</div></a>
  <?php else: ?>  
    <a href="<?php print $item['url'];?>"><div class="read-more-link">Learn More</div></a>
  <?php endif;?>  
</div>
</div>
<!--</a>-->
<?php endforeach?>

</div>
<?php endif;?>

