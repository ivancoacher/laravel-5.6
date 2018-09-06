<div class="container">
 <div class="col-xs-12 title_articles_editor"><h1><?php print $editor_first_name;?>'s articles</h1></div>   
 <div class="col-xs-12 editor_articles">  
    <?php foreach($items as $item) : ?>
      <?php ///print $item['title'];  
       print theme_render_template(drupal_get_path('module', 'fs_article') . '/templates/fs_article_item_small.tpl.php', array('item' => $item)); 
      ?>
    <?php endforeach; ?>
</div>
</div>
<div class="container "> 
     <div class="editor_page col-xs-12">                
                     <?php print $pager; ?>                
            </div>
</div>