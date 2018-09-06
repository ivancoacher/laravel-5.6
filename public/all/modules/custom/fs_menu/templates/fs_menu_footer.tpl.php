<?php

/**
 * @file
 * Default theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: An ID for the block, unique within each module.
 * - $block->region: The block region embedding the current block.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - block: The current template type, i.e., "theming hook".
 *   - block-[module]: The module generating the block. For example, the user
 *     module is responsible for handling the default user navigation block. In
 *     that case the class would be 'block-user'.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see template_process()
 *
 * @ingroup themeable
 */
global $base_url;
?>
<!--<style>
    .menu_footer:hover a.contextual-links-trigger{
        display:block;
    }
    .menu_footer:hover {
        border:1px dashed #ccc;
    }

    a.contextual-links-trigger:hover div.contextual-links-wrapper ul.contextual-links{
       display:block!important;
    }
</style>-->

    <div class="col-xs-12 col-md-12 col-md-4 menu_footer">
<!--        <div class="contextual-links-wrapper contextual-links-processed"><a class="contextual-links-trigger" href="#">Configure</a><ul class="contextual-links" style="display: none;"><li class="bean- first"><a href="/block/downloaded-magazine/edit?destination=shanghai/directory">Edit Block</a></li>
<li class="block-configure last"><a href="/admin/structure/block/manage/bean/downloaded-magazine/configure?destination=shanghai/directory">Configure block</a></li>
</ul></div>-->
                <div class="col-sm-6 menu_footer_one">
                    <div  class="col-xs-12 title-footer-new"><h2>About Us</h2>
                        <div class="line_footer"></div>
                    </div>
                    <div class="col-xs-12 menu_main">
                    <ul class="animated bounceInLeft hover-effect">
                    <?php
                        foreach($menu_footer_one as $menu){
                            if(isset($menu['#href'])){
                             print '<li><a class="animated bounceInLeft" href="'.url($menu['#href']).'">'.$menu['#title'].'</a></li>';
                            }
                        }

                    ?>
                    </ul>
                    </div>
                </div>
                <div class="col-sm-6 menu_footer_two">
                    <div  class="col-xs-12 title-footer-new"><h2>Connect With Us</h2>
                    <div class="line_footer"></div>
                    </div>
                    <div class="col-xs-12 menu_main">
                        <ul class="animated bounceInRight hover-effect">
                    <?php
                        foreach($menu_footer_two as $menu){
                               if(isset($menu['#href'])){
                                 $html ='';
                                 switch ($menu['#title']) {
                                   case 'Wechat':
                                     $html = '<li><i class="fa fa-wechat"></i><a  href="'.url($menu['#href']).'"> ';
                                     break;
                                   case 'Facebook':
                                     $html = '<li><i class="fa fa-facebook"></i><a  href="'.url($menu['#href']).'"> ';
                                     break;
                                   default:
                                     $html = '<li><a  href="'.url($menu['#href']).'">';
                                     break;
                                 }
                                 $html.= $menu['#title'].'</a></li>';
                             print $html;
                            }
                        }

                    ?>
                            <li><a  href="<?php print $base_url;?>/node/add/listings">Add Your Venue</a></li>
                        <li><a   href="<?php print $base_url;?>/node/add/events">Add Your Event</a></li>
                        <li><a href="<?php print $base_url;?>/node/add/schools">Add Your School</a></li>
               
                    </ul>
                    </div>
                </div>
            </div>
