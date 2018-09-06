  <?php 
  global $base_url;
  $items = (isset($items) ? $items : array());
  $title = (isset($title) ? $title : NULL);
  $name_section = (isset($name_section) ? $name_section : NULL);
  $count = (isset($count) ? $count : 0);
  $pager = (isset($pager) ? $pager : NULL);
  $search_form = (isset($search_form) ? $search_form : NULL); 
  $filter = (isset($filter) ? $filter : 0);
  ?>
    <div class="row col-xs-12 col-md-9 directory_list_container">       
            <div class="col-xs-12 search_directory_list">                
                <div class="col-xs-12 title_list">
                   <h1> <?php print $title; ?> </h1>
                   <div class="result_list">
                       <?php if($filter==1): ?>
                       <a  href="<?php print $base_url."/".current_path() ;?>" class="btn btn-default">Reset <span class="glyphicon glyphicon-remove" aria-hidden="true"></span></a>| <?php endif;?> Results : <?php print $count; ?>                  
                   </div>
                </div>
                <?php if($search_form!=NULL):?>
                <div class="col-xs-12 search_list">
                    <?php print $search_form; ?>
                </div>
                <?php endif?>
            </div>    
            <div class="item-directory-list col-xs-12">
                 <?php if($count):?>
              <?php foreach ($items as $item): ?>
                       <?php print $item; ?>                                  
              <?php endforeach; ?>
             <?php else:?>
        <div class="top-section">
             <div class="search-result-info"><p class="result"> Sorry, no result found for your request ! </p></div>
        </div>
            <?php endif; ?>                
       </div>
            <div class="pagination-directory  col-xs-12">
              <?php print $pager; ?>
            </div>              
   </div>
