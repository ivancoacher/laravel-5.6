<?php
/**
 * @file
 * Display Suite 1 column template.
 */
?>

<<?php print $ds_content_wrapper;
print $layout_attributes; ?> class="ds-1col <?php print $classes; ?> clearfix">

<?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
<?php endif; ?>

<div class="article_win_item">
    <div class="col-sm-6 image_win">
        <a href="<?php print $url ?>"> <img src="<?php print $image; ?>" class="img-reponsive" /> </a>
    </div>
    <div class="col-sm-6 text_win">
         <a  href="<?php print $url ?>"><h2><?php print $node->title; ?></h2></a>
        <div class="post-info">
            <a href="<?php print $author_url; ?>"><img  src="<?php print $user_picture; ?>" class="alignleft attachment-thumbnail author-thumbnail " alt="Stephanie Cheung headshot" ></a> <?php print $author_name ;?> | <i class="fa fa-clock-o"></i> <?php print date("j F Y",$post_date);  ?></div>
    </div>
    
<hr class="col-xs-12 bar-wins" />
</div>

</<?php print $ds_content_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
