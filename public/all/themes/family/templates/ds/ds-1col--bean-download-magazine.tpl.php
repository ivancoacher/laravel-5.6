<?php  
//print $ds_content ;
if ($ds_content){$block_list_pre_magazine = explode('<span class="hidden">split-block-magazine</span>', $ds_content);
}
//var_dump($block_list_pre_magazine);
print $block_list_pre_magazine[1];
?>