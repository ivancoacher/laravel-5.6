
<?php if ($items):
    ?>
    <div class="col-xs-12 school-related-blog" id="school-blog">
        <div class="title_details main-title" >Blog</div>


        <div class="col-sm-4 image">
            <img src='<?php print $items[0]['image_url'] ?>' class="img-responsive">
        </div>
        <div class="col-sm-4 content">
            <div class="title"><?php print $items[0]['title'] ?></div>
            <div class="description"><?php print truncate_utf8($items[0]['body'], 200, FALSE, TRUE); ?>
                <span> <a href=<?php print $items[0]['url'] ?> target="_blank">Read More</a></span>
            </div>
        </div>
        <div class="col-sm-4 more-article">
           <?php if(count($items) > 1):?>
            <div class="title">More articles</div>
            
            <ul>       
                <?php foreach (array_splice($items, 1, 3) as $item): ?>
                    <li><a href=<?php print $item['url'] ?> target="_blank"><span><?php print $item['title'] ?></span></a></li>
                <?php endforeach; ?> 
            </ul>
            <?php endif; ?>
        </div>

    </div>   

<?php endif; ?>