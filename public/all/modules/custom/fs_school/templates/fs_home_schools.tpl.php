<?php global $base_url;
 if($items):
?>
<div class="col-sm-12 hp-featured-school">
    <h4 class="title">Featured Schools</h4>
<div class="top-blue-line"></div>
<?php foreach ($items as $item): ?>
<!--    <a href='<?php print $item['url']?>' style="">-->
<div class="item-container">
<div  class="col-xs-4 col-sm-2 col-md-5 image">
<img class="img-responsive" src="<?php print $item['image_url']?>" />
</div>
<div class="col-xs-8 col-sm-10 col-md-7 content-cont">
    <a href="<?php print $item['url'] ?>"><div class="title"><?php print $item['title']?></div></a>
  <?php if($item['field_school_premium']):?>
   
    <a href="<?php print $item['inquiry']; ?>"><div class="read-more-link">Learn More</div></a>
  <?php else: ?>  
    <a href="<?php print $item['url'] ?>"><div class="read-more-link">Learn More</div></a>
  <?php endif;?>  
</div>
</div>
<!--</a>-->
<?php endforeach?>

<a href="<?php print $base_url.'/shanghai-schools'?>">
<div class="see-more-btn">
    See More
</div>
</a>
</div>
<?php endif;?>