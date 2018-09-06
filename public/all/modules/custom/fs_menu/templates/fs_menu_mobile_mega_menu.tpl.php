<?php

$school_directory_dropdown = '<ul class="collapse navmenu-nav nav" id="collapse">
                                    <li id="sub-item"><a class="menu_mobile" id="sub-item-style" href="/shanghai-schools">School Directory</a></li>                               
                                    <li id="sub-item"><a class="menu_mobile" id="sub-item-style" href="/shanghai/article/guide-kindergartens-and-preschools-shanghai">Preschools & Kindergartens Guide</a></li>
                                    <li id="sub-item"><a class="menu_mobile" id="sub-item-style" href="/shanghai/article/guide-bilingual-schools-shanghai">Bilingual Schools Guide</a></li>
                                    <li id="sub-item"><a class="menu_mobile" id="sub-item-style-last" href="/shanghai/article/guide-international-schools-shanghai">International Schools Guide</a></li>
                                </ul>';?>

<?php foreach ($menu as $item => $content): ?>  
    <?php if (is_int($item)): ?>
            <li><a class="menu_mobile" href="<?php print url($content['#href']); ?>"><?php print $content["#title"]; ?></a></li>                               
        <?php endif; ?>
<?php endforeach; ?>  

<li><div class="divider-mobile"></div></li>

<?php $menu_top_sh = menu_tree("menu-menu-top"); 
    foreach ($menu_top_sh as $item => $content): ?>  
    <?php if (is_int($item)): ?>
        <?php if ($content["#title"] == "School Directory"){ ?>
           <li><a class="menu_mobile dropdown-toggle" href="#" id="drop" role="button" data-toggle="collapse" data-target="#collapse" aria-expanded="false" aria-controls="collapseExample"><?php print $content["#title"]; ?></a>
                <?php print $school_directory_dropdown;?>
           </li>
        <?php } else { ?>
            <li><a class="menu_mobile" href="<?php print url($content['#href']); ?>"><?php print $content["#title"]; ?></a></li> 
        <?php } ?>
        <?php endif; ?>
<?php endforeach; ?>   

<li><div class="divider-mobile"></div></li>

