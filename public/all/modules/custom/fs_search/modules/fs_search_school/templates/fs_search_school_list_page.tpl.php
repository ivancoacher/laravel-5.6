    <?php
    global $base_url;
    $max_price = 300000;

    function is_search_adv($filters) {

      if (isset($filters["tuition_min"]) && ($filters["tuition_min"]) != 0 || isset($filters["tuition_max"]) && floatval($filters["tuition_max"]) != 300000 || isset($filters["academic_program"]) || isset($filters["languages"]) || isset($filters["curriculum"]) || isset($filters["school_neighborhood"])|| isset($filters["keyword"])) {

        return true;
      }
      else {
        return false;
      }
    }
    $is_filter = (is_search_adv($filters)) || isset($filters["school_type"]);

    drupal_add_js('var is_filter_school="' . $is_filter . '";', array('type' => 'inline'));
    
     $local = key(taxonomy_get_term_by_name('Bilingual & Local Schools','school_type'));
     $kids = key(taxonomy_get_term_by_name('Preschools & Kindergartens','school_type'));
     $inter = key(taxonomy_get_term_by_name('International Schools','school_type'));
    ?>
<div class="container school-seach-container">
    <input type="hidden" id="current_city" value="<?php print $city; ?>">
    <div class="title col-xs-12 ">
        <span>School directory</span><br/>
        <span class="sub_title_school hidden">Use the filters to define your criteria and compare from the available list of schools </span></div>
    <div class="col-xs-12 wrapper_school_search">

        <div class="col-xs-12 btn_school_list ">
            <ul>
            <li>
                <button type="button" id="all" value="all" class="category_school btn btn-primary <?php
    if (!isset($filters["school_type"])) {
      print "active";
    }
    ?>" data-toggle="button" aria-pressed="false" autocomplete="off">
                    All
                </button>
            </li>
            <li>
                <button type="button" value="<?php print $kids ;?>"  id="kids" class="category_school btn btn-primary <?php
                        if (isset($filters["school_type"][0]) && $filters["school_type"][0] == $kids) {
                          print "active";
                        }
                        ?>" data-toggle="button" aria-pressed="false" autocomplete="off">
                    Preschools & Kindergartens
                </button>
            </li>
            <li>
                <button type="button" value="<?php print $local ; ?>" id="local" class="category_school btn btn-primary <?php
                        if (isset($filters["school_type"][0]) && $filters["school_type"][0] == $local) {
                          print "active";
                        }
                        ?>" data-toggle="button" aria-pressed="false" autocomplete="off">
                    Bilingual & Local Schools
                </button>
            </li>
            <li>
                <button type="button" value="<?php print $inter ;?>" id="international" class="category_school btn btn-primary <?php
                        if (isset($filters["school_type"][0]) && $filters["school_type"][0] == $inter) {
                          print "active";
                        }
                        ?>" data-toggle="button" aria-pressed="false" autocomplete="off">
                    International School
                </button>
            </li>
            </ul>
        <?php if ($search_form != NULL): ?>
          <div class="search_list">
              <div class="search_txt"> <?php print $search_form; ?></div>
            <div class="search_btn form-group">
            <button type="submit" class="btn-search-school">SEARCH</button>
            </div>
          </div>
        <?php endif ?>
            
        </div>
        
        <div class="school-search-filters">
            <ul>
            <li class="selectdiv form-group">
                 <select id="neighborhood" title="Neighborhood"  nane="neighborhood" class="form-control" >
                       <option value="all"> -- None -- </option>
                        <?php
                        foreach ($school_neighborhood as $type) {
                          
                          $status = "";
                          if (isset($filters["school_neighborhood"])) {
                            foreach ($filters["school_neighborhood"] as $filter) {

                              if ($filter == $type["tid"]) {
                                $status = "selected";
                              }
                            }
                          }
                          print "<option value=" . $type["tid"] . "  " . $status . ">" . $type["name"] . "</option>";
                        }
                        ?>
                    </select>
                </li>
                <li class="selectdiv form-group">
                    <select id="taught" name="languages" title="Languages" class="form-control" >
                        <option value="all">  -- None -- </option>
                        <?php
                        foreach ($languages as $type) {
                          $status = "";
                          if (isset($filters["languages"])) {
                            foreach ($filters["languages"] as $filter) {

                              if ($filter == $type["tid"]) {
                                $status = "selected";
                              }
                            }
                          }
                          print "<option value=" . $type["tid"] . "  " . $status . ">" . $type["name"] . "</option>";
                        }
                        ?>
                    </select>
                </li>
            <li class="selectdiv form-group">
             <select id="curiculum" title="Curriculum" name="curiculum" class="form-control" >
                       <option value="all">  -- None -- </option>
                        <?php
                        foreach ($curriculum as $type) {
                          $status = "";
                          if (isset($filters["curriculum"])) {
                            foreach ($filters["curriculum"] as $filter) {

                              if ($filter == $type["tid"]) {
                                $status = "selected";
                              }
                            }
                          }
                          print "<option value=" . $type["tid"] . "  " . $status . ">" . $type["name"] . "</option>";
                        }
                        ?>
                    </select>
            </li>
                        
            
            <li class="selectdiv form-group">
                
         <select id="academic" title="Academic Program" name="academic" class="form-control" >
             <option value="all">  -- None -- </option>
     <?php
        foreach ($academic_program as $type) {

         $status = "";
        if (isset($filters["academic_program"])) {
         foreach ($filters["academic_program"] as $filter) {
             if ($filter == $type["tid"]) {
        $status = "selected";
      }
    }
  }
  print "<option value=" . $type["tid"] . "  " . $status . ">" . $type["name"] . "</option>";
}
?>
 </select>              
            </li>
            
             <li class="">
                 <div class="tuition">
                     <span  id="tuition-title">Yearly Tuition <i class="fa fa-chevron-down"></i></span>
               <div id="tuition-fee">
                         <div class="form-group tuition-content">
                        <?php
                        if (isset($filters["tuition_min"]) && isset($filters["tuition_max"])) {
                          $price = $filters["tuition_min"] . "," . $filters["tuition_max"];
                        }
                        else {
                          $price = "0," . $max_price;
                        }
                        ?>

                      <b>Ұ0</b>&emsp;<input id="ex8" name="tuition" type="text" class="span2" value="" data-slider-min="0" data-slider-max="<?php print $max_price; ?>"  data-slider-value="[<?php print $price; ?>]" data-slider-handle="custom"/>   &emsp;<b>Ұ<?php print number_format($max_price, 0, '.', ','); ?></b>
                    </div>
                    </div> 
                </div>
            </li>

            <li><a href="/node/add/schools" class="contact-new-link">Get your school listed now!</a></li>
        </ul>
            
        </div>
      
    </div>
    
<!--    <div class="col-xs-12 description_seach_section">

        <div class="col-xs-12 col-md-8 description_seach">
            <p>
                Step 1:  Select a category and use our search function to filter the schools that fit to your requirements.<br/>
                Step 2: Compare the most qualified results and find the perfect school for your needs.
            </p>
        </div>

    </div>-->

</div>
</div>
</div>
<div class="container watap">

    <div class="container-main-school">
        <?php global $base_url; ?>
        <input type="hidden" id='page' value="<?php if ($filters["page"]) {
          print $filters["page"];
        }
        else {
          print "0";
        } ?>"/>
        <input type="hidden" id='school_url' value="<?php print $base_url . "/shanghai/school/api" ?>"/>

<?php
$title = "Featured Schools";
print theme_render_template(drupal_get_path('module', 'fs_search_school') . '/templates/fs_search_list_school.tpl.php', array(
  'items' => $items,
  'title' => $title,
  'pager' => $pager,
  'count' => $count,
  'filter' => $is_filter
));
?>

