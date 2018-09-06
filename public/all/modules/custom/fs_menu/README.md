In order to dropdown menu works well, please put the follow code inside templates.php file

```php
function [theme_name]_menu_link__menu_shanghai_main_menu($variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  $dropdown_items = '';
  if($element['#original_link']['router_path'] == 'taxonomy/term/%') {
    $link_path = $element['#original_link']['link_path'];
    $link_path_info = explode('/', $link_path);
    $tid = $link_path_info[2];
    if(is_numeric($tid)){
      $term = taxonomy_term_load($tid);
      if(!empty($term)) {
        $dropdown_items = fs_menu_generate_dropdown_items($term);
      }
    }
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . $dropdown_items . "</li>\n";
}
```