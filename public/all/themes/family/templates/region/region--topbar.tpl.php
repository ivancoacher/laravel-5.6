
<?php
//**This is for sliptting the blocks list content existing in this region*
//*
//*//

global $user, $base_url;

if ($content) {
  $block_list_top_bar = explode('<span class="hidden">split-block</span>', $content);

  $theme_name = 'family';
  $settings = variable_get('theme_' . $theme_name . '_settings', array());
  if (isset($settings['logo_path'])) {
    $logo = file_create_url($settings['logo_path']);
  }
}
?>
<div class="topbar-section">
    <div class="container">
        <nav class="navbar">
            <div id="content-topbar">
                <nav id="myNavmenu" class="navmenu navmenu-default navmenu-fixed-left offcanvas" role="navigation">
                    <ul class="nav navmenu-nav">
                        <li class="city_mobile">
                            <div class="col-xs-6 hidden city-mobile-section" >
   <!--                            <select  id="city_mobile" class="form-control">
                                   <option>Shanghai</option>
                                   <option>Beijing</option>
                               </select>-->
                                <?php //if (!empty($block_list_top_bar[1])): ?>
                                <?php //print ($block_list_top_bar[1]); ?>
                                <?php ///endif; ?>
                            </div>
                            <div class="col-xs-12 login-mobile-section"  >
                                <?php if (!user_is_logged_in()): ?>
                                  <a  id="login_mobile" class="btn btn-primary" role="button" data-toggle="collapse" href="#collapse_login" aria-expanded="false" aria-controls="collapse_login">
                                      Sign In
                                  </a>
                              </div>
                              <div class="mobile-login-content col-xs-12 collapse" id="collapse_login">
                                  <?php  if (!empty($block_list_top_bar[5])): ?>
                                  <?php
                                  print ($block_list_top_bar[5]);
//                                  $block_login = module_invoke('user', 'block_view', 'login');
//                                  print render($block_login);
                                  ?>
                                  <?php  endif; ?>
                              </div>


                            <?php else : ?>

                              <a href="#" class=" shadow-topbar  dropdown-toggle user_login_ok" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false">
                                  <span class="glyphicon glyphicon-user" aria-hidden="true"></span>
                              </a>
                              <ul class="dropdown-menu menu-city list_profil ">
                                  <div class="arrow-city"><img src="<?php print variable_get("path_theme"); ?>/images/icon/arrow.png"></div>
                                  <li><a href="<?php print url("/user/" . $user->uid); ?>">Profile</a></li>
                                  <li><a href="/user/logout">Logout </a></li>
                              </ul>

                            <?php endif; ?>


                        </li>
                        <div class="clearfix"></div>
                        <?php if (!empty($block_list_top_bar[4])): ?>
                          <?php print ($block_list_top_bar[4]); ?>
                        <?php endif; ?>

                        <li class="social-mobile ">
                            <div class="col-xs-3 text-center"><a href="https://www.facebook.com/SHfam/" target="_blank"><i class="fa fa-facebook" aria-hidden="true"></i></a></div>
                            <div class="col-xs-3 wechat"><a   role="button" data-toggle="collapse" href="#collapse_wechat" aria-expanded="false" aria-controls="collapse_wechat"><i class="fa fa-wechat" aria-hidden="true"></i></a></div>
                            <div class="col-xs-3 text-center"><a  href="https://www.instagram.com/shanghaifamilyofficial/" target="_blank" ><i class="fa fa-instagram" aria-hidden="true"></i></a></div>
                            <div class="col-xs-3 text-center"><a  href="#" target="_blank"><i class="fa fa-weibo" aria-hidden="true"></i></a></div>

                            <div class="mobile-wechat-content col-xs-12 collapse" id="collapse_wechat">
                                <img src="<?php print variable_get("path_theme"); ?>/images/qr_shanghai.png" width="165px">

                            </div>
                            <div class="clearfix"></div>
                        </li>
                    </ul>
                </nav>
                <div class="navbar-header">
                    <button type="button" class="navbar-toggle" type="button" data-canvas="body" data-toggle="offcanvas" data-target="#myNavmenu">
                        <span class="sr-only">Toggle navigation</span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                    </button> 
                </div>
                <!-- Collect the nav links, forms, and other content for toggling -->

            </div><!-- /.container-fluid -->
        </nav>
    </div>
</div>


<!--        Logo Header Section-->
<div class="container">
    <div class="header_top">
        <?php if ($logo): ?>
          <div class="logo-img"><a href="<?php print $base_url; ?>" title="<?php print t('Home'); ?>"  id="logo">
                  <img  id="logo_main" src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" class="img-responsive"/>
              </a>
          </div>
        <?php endif; ?>
        <?php if (!empty($block_list_top_bar[3])): ?>

          <?php print ($block_list_top_bar[3]); ?>
        <?php endif; ?>
        <?php if (!user_is_logged_in()): ?>                   
          <div class="signin-right new">
              <div class="signin"> 
                  <ul class="nav navbar-nav family_top_bar_left ">
                      <li class="login_hidden">
                          <?php if (!empty($block_list_top_bar[5])): ?>
                            <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false">
                                Sign in
                            </a>

                            <ul class="dropdown-menu form-login-topbar">
                                <li>
                                    <?php print ($block_list_top_bar[5]);
                                    
//                                      $block_login_2 = module_invoke('user', 'block_view', 'login');
//                                      print render($block_login_2);
//                                    
                                    ?>
                                    
                                </li>

                            </ul>
                          <?php endif; ?>                
                      </li>
                  </ul>
              </div>
          </div>
        <?php else : ?>
          <div class="signin-right">
              <div class="signin"> 
                  <ul class="nav navbar-nav family_top_bar_left ">
                      <li class="login_hidden">
                          <a href="#" class="dropdown-toggle user_login_ok" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false">
                              <span class="glyphicon glyphicon-user" aria-hidden="true"></span> <span class="">&nbsp;<?php print ucwords($user->name); ?> </span>
                          </a>
                          <ul class="dropdown-menu menu-city list_profil">
                              <div class="arrow-city"><img src="<?php print variable_get("path_theme"); ?>/images/icon/arrow.png"></div>
                              <li><a href="<?php print url("/user/" . $user->uid); ?>">Profile</a></li>
                              <li><a href="/user/logout">Logout </a></li>
                          </ul>

                      </li>
                  </ul>
              </div>
          </div>

        <?php endif; ?>

        
        <div class="follow_new_container">
            <ul class="follow_new">
                <?php if (!empty($block_list_top_bar[2])): ?>
                  <?php print ($block_list_top_bar[2]); ?>
                <?php endif; ?>
            </ul>  
        </div> 
        <div class="logo-pk-new">
            <a href="<?php print $base_url; ?>" title="<?php print t('Home'); ?>"  id="logo"> <span>PARTNERED WITH</span>
                <img  src="<?php print variable_get("path_theme") . "/pk_new.png"; ?>" alt="parents and kids" class="img-responsive"/>                           </a>
        </div>





    </div>


</div>
