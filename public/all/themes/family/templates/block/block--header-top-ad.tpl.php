<?php
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
 global $base_url;
 $path_theme = drupal_get_path('theme', 'family');

 $current_date = new DateTime('now');


 $period_one_start = new DateTime('2017-11-07 00:00:00');
 $period_one_end = new DateTime('2017-11-18 23:59:59');
 $period_two_start = new DateTime('2017-10-12 00:00:00');
 $period_two_end = new DateTime('2017-10-27 23:59:59');
 $pushDowns = array();
 if (($current_date->getTimestamp() >= $period_one_start->getTimestamp()) && ($current_date->getTimestamp() <= $period_one_end->getTimestamp())) {
   $pushDowns[] = array(
       'image_name' => "glamour_lab_1140x600.jpg",
       'url' => "http://family.cityweekend.com.cn/shanghai/article/join-next-glamourlab-beauty-party?utm_source=onsite&utm_medium=banner&utm_campaign=glamourlab_nov17",
       'bg_color' => "#D0DDE5"
   );
 }
 if(($current_date->getTimestamp() >= $period_two_start->getTimestamp()) && ($current_date->getTimestamp() <= $period_two_end->getTimestamp())) {
   $pushDowns[] = array(
     'image_name' => "neon_1140X600.gif",
     'url' => "http://family.cityweekend.com.cn/shanghai/article/register-now-and-win-submit-your-childrens-neon-artwork",
     'bg_color' => "#100A20"
   );
 }

if(count($pushDowns)!=0){
$rand = rand(0,count($pushDowns)-1);
    ?>
    <style>
        @media all and (min-width: 768px) {
            #header-ad{display:block!important;}
            .sticky-header{position:relative!important;}
            .ghost-header{display:none!important;}
            a#pushdown_small{text-decoration:none;}
            a#pushdown_small:hover,a#pushdown_small:focus{text-decoration:none;}
            .pushdown_section{height: 180px;overflow: hidden;}
        }
    </style>
    <script>

        jQuery(document).ready(function () {
            var rand = <?php echo $rand; ?>;
            var pushDowns = <?php echo json_encode($pushDowns, JSON_HEX_TAG); ?>;

            jQuery(".pushdown_container").mouseleave(function () {
                var h = jQuery("#img_large").height();
                jQuery(".pushdown_section").animate({"height": "180px"}, "slow");
                jQuery(".pushdown_section").removeClass("in");
            });
            jQuery("#pushdown_small").click(function () {
                var h = jQuery("#img_large").height();
                if (jQuery(this).find(".pushdown_section").hasClass("in")) {
                    ga('send', 'event', 'push down', pushDowns[rand].url + ' redirect', 'User clicked second time on pushdown to redirect');
                    window.open(pushDowns[rand].url, '_blank');
                    return false;
                } else {
                    jQuery(".pushdown_section").animate({"height": h}, "slow");
                    jQuery(this).find(".pushdown_section").addClass("in");
                    ga('send', 'event', 'push down', pushDowns[rand].url + ' expanded', 'User clicked on pushdown to expand');
                }
            });
        });
    </script>
    <a id="pushdown_small">
      <div class="pushdown_container" style="background:<?php print $pushDowns[$rand]['bg_color'];?>">
        <div  class="pushdown_section" >
            <img id="img_large"   src="<?php print $base_url."/".$path_theme."/images/pushdown/".$pushDowns[$rand]['image_name'] ; ?>"/>
        </div>
      </div>
    </a>
	<script>
var _hmt = _hmt || [];
(function() {
  var hm = document.createElement("script");
  hm.src = "https://hm.baidu.com/hm.js?c2797c61767d6acd0496ba882cc8f36f";
  var s = document.getElementsByTagName("script")[0];
  s.parentNode.insertBefore(hm, s);
})();
</script>
<?php
}
