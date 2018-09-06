
<div class="divider-articles" style="background-image: url('<?php print variable_get("path_theme");?>/images/family_style/divider_article.png');">
    <div class="wrapper-details">
        <a href="#">
            You Might Like
        </a>
    </div>  
</div>

<div class="related-content  col-xs-12">
    <?php if (!empty($items)):  ?>
        <?php foreach ($items as $item): ?>
            <div class="col-xs-6 col-sm-6 col-md-4 related-item">
                <div class="col-xs-12 img-related"><a href="<?php print $item['url'] ?>"><img src="<?php print $item['image'] ?>" class="img-responsive" /></a></div>
                <div class="col-xs-12 title-related"><?php print $item['title']; // print  substr($item['title'],0,50); ?></div>
            </div>
        <?php endforeach; ?>
    <?php endif; ?>
</div>