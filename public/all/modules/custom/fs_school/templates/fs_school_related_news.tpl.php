<h1>News</h1>
<?php
$start = 0;
      foreach ($items as $item):
        if($start == 0):
          $start = $start+1;
              ?>
              <p><h3><?php print $item['title']?></h3></p>
              <p><img src='<?php print $item['image_url']?>'></p>
              <p><?php print $item['summery']?></p>
              <p><a href=<?php print $item['url']?> target="_blank">Read More</a></p>

            <?php else: ?>
            <p><a href=<?php print $item['url']?> target="_blank"><h3><?php print $item['title']?></h3></a></p>

          <?php endif?>
        <?php   endforeach?>
