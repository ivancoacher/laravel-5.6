
<a href="#" class="city_current_select shadow-topbar   dropdown-toggle" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false">
    <?php foreach ($cities as $cid => $city){      
      if ($city['selected'] == TRUE)
      print $city['name']." ";   
    }?>

    <span class="glyphicon glyphicon-menu-down glyphicon-menu-down-font-size" aria-hidden="true"></span> 
</a>
  <?php if (!empty($cities)): ?>
    <ul class="dropdown-menu menu-city" id="fs-city-navigation">
        <div class="arrow-city"><img src="<?php print $theme_family;?>/images/icon/arrow.png"></div>
      <?php foreach ($cities as $cid => $city) : ?>  
          <li id="<?php print $cid; ?>">
           <a href="<?php print $city['url']; ?>"> <?php print $city['name']; ?></a>
          </li>
      <?php endforeach; ?>
    </ul>
  <?php endif; ?>