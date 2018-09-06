
  <?php if (!empty($links)): ?>
    <?php foreach ($links as $link): ?>
        <?php
        $dropdown = "";
        if($link['type']=="wechat"):
            $dropdown = "dropdown"; ?>
            <?php endif;?>
        <li class="follow-us-topbar <?php print $dropdown ?>">
            <?php if($link['type']=="wechat"):?>
             <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false"><i class="fa fa-wechat" aria-hidden="true"></i></a>
             <ul class="dropdown-menu wechat-topbar ">
                 <li>
                       <div class="arrow-wechat"><img src="<?php print $theme_family?>/images/icon/arrow.png"></div>
                       <img src="<?php print $theme_family?>/images/qr_<?php print $link['current_city'];?>.png"     width="165px" />  
                      
                 </li>
             </ul>
            <?php elseif($link['type']=='<i class="fa fa-twitter" aria-hidden="true"></i>') :?>
             <a class="hidden" href="<?php print $link['btn_type'] ?>" target="_blank"><?php print $link['type']; ?></a>
            <?php else: ?>
             <a href="<?php print $link['btn_type'] ?>" target="_blank"><?php print $link['type']; ?></a>
        
            <?php endif;?>  
        </li>
    <?php endforeach; ?>
  <?php endif; ?>


<!-- AddToAny END -->