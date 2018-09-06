<?php

/**
 * @file
 * Default theme implementation for profiles.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) profile type label.
 * - $url: The URL to view the current profile.
 * - $page: TRUE if this is the main view page $url points too.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-profile
 *   - profile-{TYPE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
module_load_include('inc', 'fs_base', 'fs_base');
$item =array();
//var_dump($content["field_pe_first_name"]);
if(isset($content["field_pe_desc"]["#items"][0]["value"])){
$item["description"] = $content["field_pe_desc"]["#items"][0]["value"];
}else{
$item["description"] ="";  
}
$uri =$content["field_pe_photo"]["#items"][0]["uri"];

$item["photo"] = fs_base_image_rebuild_style('profile_editor',$uri);
//$item["photo"] = file_create_url($uri);

$item["first_name"] = ($content["field_pe_first_name"]["#items"][0]["value"]);
$item["last_name"] = ($content["field_pe_last_name"]["#items"][0]["value"]);
?>
<div class="container">
    <div class="row">
        <div class="col-xs-12 editor_profile_section_container">
           <div  class="col-xs-12 editor_profile_section">
            <div class="photo_container"><img  id="photo_profil" src="<?php  print $item["photo"] ?>" /></div>
          
            <div class="col-xs-12 name_editor text-center">
                <?php print $item["first_name"]." ".$item["last_name"];?>
            </div>
            <div class="col-xs-12 description text-center">
                <?php print $item["description"];?>
            </div>
            </div>    
        </div>    
    </div>
</div>