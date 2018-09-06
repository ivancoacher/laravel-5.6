
<?php 
//**This is for sliptting the blocks list content existing in this region*
//* 
//*// 
if ($content){$block_list_pre_footer = explode('<span class="hidden">split-block</span>', $content);

}
global $base_url;
$path_logo= $base_url."/".drupal_get_path("theme","family");

$menu_footer_one=menu_tree("menu-footer-menu-one");
$menu_footer_two=menu_tree("menu-footer-menu-two");
//var_dump($menu_footer_one);
?>

 <div class="pre-footer-container">
        <div class="container">
              <?php 
              $block_new = module_invoke('fs_menu','block_view','fs_menu_footer');
              print render($block_new['content']);
             ?> 
              <?php if(isset($block_list_pre_footer[1]))
                                print  render($block_list_pre_footer[1]);
              ?>
           
          
        </div>
<div class="container section_logo">
    <div class="wrapper_logo">
        <div class="col-xs-6 col-sm-3 logo_item ringier_logo" >
            <a href="#"  >
                <img id="color" class="hidden" src="<?php print $path_logo ; ?>/images/logo/xinmin.png">
                <img id="grey"   src="<?php print $path_logo ; ?>/images/logo/grey/xinmin.png">
            </a>

            <div class="vertical_line"></div>
        </div>
        <div class="col-xs-6  col-sm-3 logo_item" >
            <a href="#"  >
                <img id="color" class="hidden" src="<?php print $path_logo ; ?>/images/logo/family.png">
                <img id="grey" src="<?php print $path_logo ; ?>/images/logo/grey/family.png">
            </a>
        </div>
        <div class="col-xs-6  col-sm-3 logo_item" >
            <a href="#"  >
                <img id="color" class="hidden" src="<?php print $path_logo ; ?>/images/logo/parentkids.png">
                <img id="grey" src="<?php print $path_logo ; ?>/images/logo/grey/parentkids.png">
            </a>
        </div>
        <div class="col-xs-6 col-sm-3 logo_item" >
            <a href="http://humaniuwa.com" target="_blank">
                <img id="color" class="hidden" src="<?php print $path_logo ; ?>/images/logo/hmw.png">
                <img id="grey" src="<?php print $path_logo ; ?>/images/logo/grey/hmw.png">
            </a>
        </div>
    </div>
</div>
    </div>
<script>
var _hmt = _hmt || [];
(function() {
  var hm = document.createElement("script");
  hm.src = "https://hm.baidu.com/hm.js?c2797c61767d6acd0496ba882cc8f36f";
  var s = document.getElementsByTagName("script")[0]; 
  s.parentNode.insertBefore(hm, s);
})();
</script>

