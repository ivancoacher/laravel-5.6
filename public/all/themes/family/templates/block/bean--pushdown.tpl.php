<?php
global $base_url;
$items = ($content["field_item"]["#object"]->field_item);
$current_date = new DateTime('now');
$pushDowns = array();

foreach (reset($items) as $item){
    $collection =  entity_load_single("field_collection_item",$item['value']);
    if(is_object($collection)){
        $image = file_create_url($collection->field_image ["und"][0]["uri"]);
        $url = $collection->field_url["und"][0]["url"];
        $bg = $collection->field_bg["und"][0]["value"];
        $field_start_date =  $collection->field_start_date["und"][0]["value"];
        $field_end_date =  $collection->field_end_date["und"][0]["value"];
        $date_end = new DateTime($field_end_date);
        $date_start = new DateTime($field_start_date);
        if (($current_date->getTimestamp() >= $date_start->getTimestamp()) && ($current_date->getTimestamp() <= $date_end->getTimestamp())) {
            $pushDowns[] = array(
                'image_name' => $image,
                'url' => $url ,
                'bg_color' => $bg
            );
        }

    }


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
                <img id="img_large"   src="<?php print $pushDowns[$rand]['image_name'] ; ?>"/>
            </div>
        </div>
    </a>
    <?php
}

