<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//var_dump($item);
?>
<div class="school_top_item col-xs-12 col-sm-4 <?php print $item["class"]; ?> ">
    <div class="col-xs-12 section_img_school_top_item">
      <?php if (strpos($item["class"], 'large_item') !== false): ?>
         <a href="#school_results">
      <?php elseif (strpos($item["class"], 'small_item hidden-md') !== false):?>
         <a href="#school_results">
      <?php else: ?>
         <a href="<?php print $item["button_url"]; ?>">
      <?php endif; ?>

    <img class="img_school_top_item" src="<?php print $item["img_bg"];
    ?>">
    <div class="title_school_top"><h2><?php print $item["title"]; ?></h2></div>
    <div class="overlay_school"></div>
    </a>
    </div>
    <div class="col-xs-12 section_descr_school_top_item">
      <?php if (strpos($item["class"], 'large_item') !== false): ?>
         <a href="#school_results">
      <?php elseif (strpos($item["class"], 'small_item hidden-md') !== false):?>
         <a href="#school_results">
      <?php else: ?>
          <a href="<?php print $item["button_url"]; ?>" class="btn_school">
      <?php endif; ?>
          <p class="description-school"> <?php print $item["desc"]; ?> </p>
         </a>
    </div>
    <div class="col-xs-12 section_btn_school_top_item">
        <a href="<?php print $item["button_url"]; ?>" class="btn_school"> <?php print $item["button"]?> </a>
    </div>
</div>
