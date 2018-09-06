<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_preprocess_page().
 */
function family_preprocess_page(&$variables) {


  global $base_url;
  $path_theme = $base_url . "/" . drupal_get_path('theme', 'family');
  variable_set('path_theme', $path_theme);
  variable_set('default_image', $path_theme . "/images/default.jpeg");
  drupal_add_js('var default_image="' . $path_theme .'/images/default.jpeg";var path_theme="' . $path_theme . '";var base_url="' . $base_url . '";var current_path="' . current_path() . '";', array('type' => 'inline'));
  if(current_path()=="user/register"){
      drupal_add_css(drupal_get_path('theme', 'family'). '/css/components/registration.css', array('group' => CSS_THEME));
      drupal_add_js(drupal_get_path('theme', 'family') . '/lib/jquery.pwstrength/pwstrength-bootstrap.min.js', array('scope' => 'footer'));
   
  }
  //var_dump(current_path());
  if (menu_get_object()) {
    $menu_object = menu_get_object();

    if ($menu_object->type && $menu_object->type == "article"||$menu_object->type == "school_blog") {
      // dpm($menu_object->type);
      $path = drupal_get_path('module', 'fs_taxonomy');
      drupal_add_css($path . '/css/article.css', array('group' => CSS_THEME));
      $variables['attr_page'] = "arctile-detail-section";
    }
    elseif ($menu_object->type && $menu_object->type == "school_blog") {
      // dpm($menu_object->type);
      $path = drupal_get_path('module', 'fs_taxonomy');
      drupal_add_css($path . '/css/article.css', array('group' => CSS_THEME));
      $variables['attr_page'] = "arctile-detail-section";
    }
    elseif ($menu_object->type && $menu_object->type == "city") {
      $variables['theme_hook_suggestions'][] = 'page__front';
      $path = drupal_get_path('module', 'fs_article');
      drupal_add_css(drupal_get_path('theme', 'family') . '/lib/owl-carousel/owl.carousel.css', array('group' => CSS_THEME));
      drupal_add_js($path_theme . '/lib/owl-carousel/owl.carousel.min.js');
      drupal_add_css($path . '/css/slide_onhover.css', array('group' => CSS_THEME));
      drupal_add_css(drupal_get_path('theme', 'family') . '/css/components/home.css', array('group' => CSS_THEME));
      drupal_add_js($path_theme . '/lib/modernizr/modernizr.js');
      drupal_add_js($path_theme . '/js/components/home.js');
    }
    elseif ($menu_object->type && $menu_object->type == "gallery") {
      $variables['theme_hook_suggestions'][] = 'page__gallery_details';
      $path = drupal_get_path('module', 'fs_article');
      drupal_add_css(drupal_get_path('theme', 'family') . '/css/components/gallery.css', array('group' => CSS_THEME));
      drupal_add_css(drupal_get_path('theme', 'family') . '/lib/owl-carousel/owl.carousel.css', array('group' => CSS_THEME));
    //  drupal_add_css(drupal_get_path('theme', 'family') . '/lib/sidebartransitions/css/normalize.css', array('group' => CSS_THEME));
     // drupal_add_css( $path_theme. '/lib/sidebartransitions/css/component.css', array('group' => CSS_THEME));
    //  drupal_add_css($path . '/css/slide_onhover.css', array('group' => CSS_THEME));
      drupal_add_js($path_theme . '/lib/owl-carousel/owl.carousel.min.js');
      drupal_add_library('prettyphoto_formatters', 'jquery.prettyPhoto');
  
    //  drupal_add_css($path_theme . '/lib/prettyPhoto/prettyPhoto.css', array('group' => CSS_THEME));
    //  drupal_add_js($path_theme . '/lib/prettyPhoto/prettyPhoto.js', array('group' => JS_THEME));
 
     // drupal_add_js($path_theme . '/lib/sidebartransitions/js/classie.js', array('scope' => 'footer'));
     // drupal_add_js($path_theme . '/lib/modernizr/modernizr.js');
     // drupal_add_js($path_theme . '/lib/sidebartransitions/js/modernizr.custom.js', array('scope' => 'footer'));
      //drupal_add_js($path_theme . '/lib/sidebartransitions/js/sidebarEffects.js', array('scope' => 'footer'));
      drupal_add_js($path_theme . '/js/components/gallery.js', array('scope' => 'footer'));
    }
    else {

    }
  }
  if (strpos(current_path(), 'beijing/gallery') !== FALSE || strpos(current_path(), 'shanghai/gallery') !== FALSE) {
    $variables['theme_hook_suggestions'][] = 'page__gallery';
  }
  if (strpos(current_path(), 'beijing/event') !== FALSE || strpos(current_path(), 'shanghai/event') !== FALSE) {
    $variables['theme_hook_suggestions'][] = 'page__event';
  }
  if (strpos(current_path(), 'beijing/directory') !== FALSE || strpos(current_path(), 'shanghai/directory') !== FALSE) {
    $variables['theme_hook_suggestions'][] = 'page__directory';
  }
  if (strpos(current_path(), 'shanghai/school') !== FALSE || strpos(current_path(), 'shanghai-schools') !== FALSE) {
    $variables['theme_hook_suggestions'][] = 'page__school';
  }
   if (strpos(current_path(), 'shanghai/school/compare') !== FALSE || strpos(current_path(), 'shanghai-schools/compare') !== FALSE|| strpos(current_path(), 'school/compare') !== FALSE) {
    $variables['theme_hook_suggestions'][] = 'page__school_compare';
  }
  if (strpos(current_path(), 'beijing/search') !== FALSE || strpos(current_path(), 'shanghai/search') !== FALSE) {
          $variables['theme_hook_suggestions'][] = 'page__search';
      
  }
  global $user;
  //var_dump(current_path());
  if (strpos(current_path(), 'user/'.$user->uid) !== FALSE){
  drupal_add_css(drupal_get_path('theme', 'family') . '/css/components/user-profile.css', array('group' => CSS_THEME));
  }
  
  $static_page=array("node/92","node/93","node/94","node/95","node/97");
  if (in_array(current_path(), $static_page)) {
     drupal_add_css(drupal_get_path('theme', 'family') . '/css/components/static.css', array('group' => CSS_THEME));
 
      $variables['theme_hook_suggestions'][] = 'page__static';
  }

  //    $variables['theme_hook_suggestions'][]='page__admin_login';

 $variables['page']['footer'] = family_footer();
 
 $variables['page']['logo'] = family_logo($variables);
  
}
function family_footer() {
    global $base_url ;
    $footer_ouput ='<i class="fa fa-copyright" aria-hidden="true"></i> 2016 Family. All rights reserved. Design by Ringier';
    $footer_ouput .='&nbsp;<a target="_blank" href="http://www.beian.gov.cn/portal/registerSystemInfo?recordcode=11010102000140">';
    $footer_ouput .= '<img src="'.$base_url."/".drupal_get_path('theme', 'family').'/images/icon/beian.png" class="img-check-processed">';
    $footer_ouput .= '京公网安备 11010102000140号';
    $footer_ouput .= ' </a>';
    return $footer_ouput;
}
/**
 * Implements hook_preprocess_node().
 */
function family_preprocess_node(&$variables) {
  if (isset($variables['nid'])) {
    if ($variables['nid'] == '58') {
      //Contact form
      module_load_include('inc', 'entityform', 'entityform.admin');
      $entity_form_name = 'contact_us';
      $render_estimate_form = entityform_form_wrapper(entityform_empty_load($entity_form_name), 'submit', 'embedded');
      $variables['contact_form'] = $render_estimate_form;
    }
  }
}


function family_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  if (!empty($breadcrumb)) {
    // Adding the title of the current page to the breadcrumb.
    $breadcrumb[] = drupal_get_title();

    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    foreach ($breadcrumb as $value) {
      $crumbs[] = '<a href="#">' . $value . '</a>';
    }
    $output .= '<div class="breadcrumb">' . implode(' | ', $crumbs) . '</div>';

    return $output;
  }
}
function family_menu_top(){
  //dpm(menu_tree("menu-shanghai-main-menu"));
  $menu_top_sh = menu_tree("menu-menu-top");
  $output = '<ul>';
  
  foreach ($menu_top_sh as $menu) {
   // if (in_array(strtolower(trim($menu['#title'])), $listing)) {
      $options = [];
      if(isset($menu['#localized_options']['query'])) {
        $options['query'] = $menu['#localized_options']['query'];
        if(isset($options['query']['category']) && $options['query']['category'] == '454') {
          $options['query']['category'] = [
            '454',
            '458'
          ];
        }
      }
      if(isset($menu['#href'])){
            if(current_path() == $menu['#href']){
                 if(isset($options['query']['category']) && $options['query']['category'] == ['454','458']) {

                  $output .= '<li><a class="health" href="' . url($menu['#href'], $options) . '">' . $menu['#title']. '</a></li>';   

                 }else{

                  $output .= '<li><a class="directory_other active_menu_top" href="' . url($menu['#href'], $options) . '">' . $menu['#title'] . '</a></li>';   

                 }
            }else{
                 $output .= '<li><a href="' . url($menu['#href'], $options) . '">' . $menu['#title'] . '</a></li>';



            }
      
      }
   // }
  }
  $output .= '</ul>';

  return $output;

}
function family_menu_tree($variables) {  
    global $base_url;
  $add_your_listing = '<ul class="dropdown-menu menu-add-listing ">
                                <li class="add-venue"><a href="/node/add/listings" target="_blank"><span class="glyphicon glyphicon-map-marker"></span>&nbsp; Add Venue</a></li>
                                <li class="add-venue"><a href="/node/add/events" target="_blank"> <span class="glyphicon glyphicon-calendar"></span>&nbsp; Add Event</a></li>
                                <li class="add-event"><a href="/node/add/schools" target="_blank"> <span class=""></span>&nbsp; Add School</a></li>
</ul>';  
    
  $str = '<div class="megamenu-container-new   hidden-xs">';
  $str .= '<div class="megamenu-section container">';

  $str .= '<nav class="navbar navbar-family">';
  $str .= '<div class="collapse navbar-collapse js-navbar-collapse collapse-family">';
  $str .='<ul class="nav navbar-nav menu_top">';
  
  $school_directory_dropdown = '<ul class="dropdown-menu dropdown-menu-school menu-option">
                                    <li><a href="/shanghai-schools">School Directory</a></li>                               
                                    <li><a href="/shanghai/article/guide-kindergartens-and-preschools-shanghai">Preschools & Kindergartens Guide</a></li>
                                    <li><a href="/shanghai/article/guide-bilingual-schools-shanghai">Bilingual Schools Guide</a></li>
                                    <li><a href="/shanghai/article/guide-international-schools-shanghai">International Schools Guide</a></li>
                                </ul>';
          
  $menu_top_sh = menu_tree("menu-menu-top"); 
    foreach ($menu_top_sh as $item => $content){
        $str .=  '<li>';
    if(isset($content['#href']))
        if ($content["#title"] == "School Directory"){
            $str .=  '<a href="#" class=" menu_mobile hvr-overline-from-center dropdown-toggle" id="drop" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false">School Directory</a>';
            $str .=  $school_directory_dropdown;
            } else {
            $str .=  '<a class="menu_mobile hvr-overline-from-center" href="'.$base_url.'/'.$content['#href'].'">'.$content["#title"].'</a>';       
        }
        $str .=  '</li>';
    }
  $str .='<li class="bar_small"></li>';  
  $str .='</ul>';
  $str .= $variables['tree'];
 
  //Main menu right side
  $str .= '<ul class="nav navbar-nav main-menu-right">';
  $str .= '<li class="dropdown win">';
  $str .= '<a href="/shanghai/articles/win" class="right-menu-item hvr-overline-from-center">WIN</a>';
  $str .= '</li>';
  
  $str .= '<li class="dropdown hidden">';
  $str .= "<a href='/shanghai/articles/quick-reads'  class='right-menu-item'>QUICK READS</a>";
  $str .= '</li>';
  
  
  $str .= '<li class="dropdown hidden">';
  $str .= '<a class="dropdown-toggle right-menu-item" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="true">+ ADD YOUR LISTING</a>';
  $str .= $add_your_listing;
  $str .= '</li></ul>';
  
   $str .= '</div>';
  $str .= '</nav></div></div>';

  return $str;
}



function family_menu_link__menu_shanghai_main_menu($variables) {
  $output = '';

  $element = $variables['element'];  
//  $sub_menu = '';
//
//  if ($element['#below']) {
//    $sub_menu = drupal_render($element['#below']);
//  }

//  $dropdown_items = '';
//  if ($element['#original_link']['router_path'] == 'taxonomy/term/%') {
//    $link_path = $element['#original_link']['link_path'];
//    $link_path_info = explode('/', $link_path);
//    $tid = $link_path_info[2];
//    if (is_numeric($tid)) {
//      $term = taxonomy_term_load($tid);
//      if (!empty($term)) {
//        $dropdown_items = fs_menu_generate_dropdown_items($term);
//      }
//    }
//  }

//  $listing = array(
//    "other directories",
//    "events",
//    "schools",
//    "school",
//    "school directory",
//    "pictures",
//    "health directory",
//  );
//  $str_1 = explode("&", str_replace(" ", "", $element['#title']));
//  $class_val = strtolower(join("_", $str_1));
//  if (in_array(strtolower(trim($element['#title'])), $listing)) {
//    //    $output = '<ul class="nav navbar-nav listing ' . $class_val . '_container_menu">';
//    //    $output .= ' <li class="mega-dropdown">';
//    //    $output .= ' <a href="'.url($element['#href']).'"  onclick="redirectTo(\'' .url($element['#href']) . '\')"  class="icon_menu" >' . $element['#title'] . '</a>';
//    //    $output .= '</li></ul>';
//  }
//  else {
    $options = [];
    if(isset($element['#localized_options']['query'])) {
      $options['query'] = $element['#localized_options']['query'];
      if(isset($options['query']['category']) && $options['query']['category'] == '454') {
        $options['query']['category'] = [
          '454',
          '458'
        ];
      }
    }

    $output = '<ul class="nav navbar-nav menu_article">';
  
                       
    $output .= '<li class="dropdown mega-dropdown">';

    $output .= ' <a href="' . url($element['#href'], $options) . '" onclick="redirectTo(\'' . url($element['#href'], $options) . '\')"   class="dropdown-toggle  hvr-overline-from-center icon_menu"   data-toggle="dropdown">' . $element['#title'] . '</a>';
//    $output .= '<ul class="dropdown-menu  dropdown-menu-family mega-dropdown-menu  container">';
//    $output .= $sub_menu . $dropdown_items;
//    $output .= '</ul>';
    $output .= '</li></ul>';
  //}

  // return '<ul' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . $dropdown_items . "</ul>\n";

  return $output;

}


function family_menu_link__menu_beijing_main_menu($variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  $dropdown_items = '';
  if ($element['#original_link']['router_path'] == 'taxonomy/term/%') {
    $link_path = $element['#original_link']['link_path'];
    $link_path_info = explode('/', $link_path);
    $tid = $link_path_info[2];
    if (is_numeric($tid)) {
      $term = taxonomy_term_load($tid);
      if (!empty($term)) {
        $dropdown_items = fs_menu_generate_dropdown_items($term);
      }
    }
  }

  global $base_url;
  $listing = array(
    "directory",
    "events",
    "schools",
    "school",
    "pictures",
    "picture",
  );
  $str_1 = explode("&", str_replace(" ", "", $element['#title']));
  $class_val = strtolower(join("_", $str_1));
  if (in_array(strtolower(trim($element['#title'])), $listing)) {
//    $output = '<ul class="nav navbar-nav listing ' . $class_val . '_container_menu">';
//    $output .= ' <li class="mega-dropdown">';
//    $output .= ' <a href="'.url($element['#href']).'"   onclick="redirectTo(\'' .url($element['#href']) . '\')"   class="icon_menu" >' . $element['#title'] . '</a>';
//    $output .= '</li></ul>';
  }
  else {
    $output = '<ul class="nav navbar-nav ' . $class_val . '_container_menu">';
    $output .= ' <li class="dropdown mega-dropdown">';
    $output .= ' <a href="'.url($element['#href']).'"    onclick="redirectTo(\'' .url($element['#href']) . '\')"  class="dropdown-toggle underline_m icon_menu"   data-toggle="dropdown">' . $element['#title'] . '</a>';
//    $output .= '<ul class="dropdown-menu  dropdown-menu-family mega-dropdown-menu  container">';
//    $output .= $sub_menu . $dropdown_items;
//    $output .= '</ul>';
    $output .= '</li></ul>';
  }

  // return '<ul' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . $dropdown_items . "</ul>\n";

  return $output;
}
/**
 * Theme registration
 * @return array
 */
function family_theme() {

    $themes = array(
        'family_logo' => array(
            'template' => 'templates/logo',
            'render element' => 'content',
        ),
    );
    return $themes;
}

function family_logo($variables) {

    $content = array();
    global  $base_url;
    //var_dump(theme_get_setting('logo','family'));
    //Setting default flags
    $content['home_page']=$base_url;
    $content['logo']= theme_get_setting('logo','family');
    $content['#theme'] = 'family_logo';
    $content['menu-top'] = family_menu_top();
    return $content;
}