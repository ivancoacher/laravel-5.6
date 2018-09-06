<?php
global $base_url;
$items = (isset($items) ? $items : array());
$title = (isset($title) ? $title : NULL);
$name_section = (isset($name_section) ? $name_section : NULL);
$count = (isset($count) ? $count : 0);
$pager = (isset($pager) ? $pager : NULL);
$filter = (isset($filter) ? $filter : 0);
?>
<div class="row col-xs-12 col-md-9 directory_list_container">
    <?php if($count):?>
    <div class="col-xs-12 search_directory_list">
        <div class="col-xs-12 title_list">
            <h1> <?php if($filter==0){print $title;}else{print "Search Results";} ?> </h1>
            <div class="result_list">
                <?php if ($filter == 1): ?>
                  <a  href="<?php print $base_url . "/" . current_path(); ?>" class="btn btn-default">Reset <span class="glyphicon glyphicon-remove" aria-hidden="true"></span></a>| <?php endif; ?> Results : <?php print $count; ?>

            </div>
        </div>
       
    </div>    
    <div class="item-directory-list col-xs-12">
        <?php foreach ($items as $item): ?>
          <?php print $item; ?>                                  
        <?php endforeach; ?>               
    </div>
    <?php if($count > 9):?>
    <div class="pagination-directory text-pull  col-xs-12">
        <?php //print $pager;  ?>
        <p id="loading_school" class="hidden text-center">
                <i class="fa fa-spinner fa-pulse fa-3x fa-fw"></i>
                <span class="sr-only">Loading...</span>
            </p>
        <a href="javascript:void(0)" class="school_scroll btn-more-school hidden " > 
            <div class="more_text_change"><data id='text_more'>Load More</data>
                <div class="three_point">
                    <span class="glyphicon glyphicon-off" aria-hidden="true"></span>
                    <span class="glyphicon glyphicon-off" aria-hidden="true"></span>
                    <span class="glyphicon glyphicon-off" aria-hidden="true"></span>
                </div>
            </div> 
        </a>
    </div>
    <?php endif ;?>
    
    <?php else:?>
<div class="top-section">
    <div class="search-result-info"><p class="result"> Sorry, no result found for your request ! </p></div>
</div>
<?php endif; ?>
</div>

