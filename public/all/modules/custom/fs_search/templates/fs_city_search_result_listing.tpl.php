
   <?php

              print theme_render_template(drupal_get_path('module', 'fs_search_directory') . '/templates/fs_search_directory_directory_list_view.tpl.php', 
              array(
                         'item' => $item,
                         'name_section'=>'article',
              )); 
           ?>        
