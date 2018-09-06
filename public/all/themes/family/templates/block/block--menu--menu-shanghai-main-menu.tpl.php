<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
?>
<?php if(isset($_COOKIE['fs_city'])&&$_COOKIE['fs_city']=="shanghai"):?>
<?php print $content ; ?>
<?php endif; ?>


<?php if(!isset($_COOKIE['fs_city'])):?>
<?php print $content ; ?>
<?php endif; ?>

