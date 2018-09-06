function is_json_exist(value) {
//    if(typeof value =='string'){
//          if(value=='Array'){
//              return " ";
//          }else{
//           return value;
//          }
//    }else{
//          return " ";
//    }
    return value;
}
function details(url) {
    window.location = url + "?id=1";
}

jQuery(document).ready(function () {


//    var  msnry =jQuery('.article_grid').masonry({
//        // options
//        itemSelector: '.grid-item',
//        percentPosition: true,
//        transitionDuration: '0.8s',
//        fitWidth: true
//
//
//
//    });
//
//    jQuery('.article_grid').imagesLoaded( function(){
//            jQuery('.article_grid').masonry({
//                itemSelector: '.grid-item',
//                percentPosition: true,
//                transitionDuration: '0.8s',
//                fitWidth: true,
//                isAnimated: true
//               });
//      });


//    if(jQuery(window).width() > 768){
//    jQuery('.article_grid').masonry( 'remove', jQuery("#grid-item-one") ).masonry();
//    }else{
//        jQuery('.article_grid').masonry('reloadItems');
//        jQuery('.article_grid').masonry('layout');
//    }
//    jQuery(window).resize(function() {
//
//        if(jQuery(window).width() > 768){
//            jQuery('.article_grid').masonry( 'remove', jQuery("#grid-item-one") ).masonry();
//        }else{
//            //jQuery('.article_grid').masonry('reloadItems');
//            //jQuery('.article_grid').masonry('layout');
//        }
//
//    });
//
    var win = jQuery(window);
    var status = true;
    var grid = document.querySelector('#timeline');
//
//    // Each time the user scrolls

    win.scroll(function () {
        // End of the document reached?
        var ftr_h = jQuery(".pre-footer-container").height();
        var wg = parseFloat(jQuery(document).height()) - parseFloat(win.height()) - parseFloat(ftr_h) - 50;
        //console.log(wg);
        //console.log(win.scrollTop());
        if (wg < win.scrollTop()) {

            var current_page = parseFloat(jQuery("#current_page").val()) + 1;

            if (status) {
                jQuery('#loading').show();
                status = false;
                jQuery.ajax({
                    url: base_url + '/api/fs_taxonomy_get_article/' + tid + '/' + current_page,
                    dataType: 'json',
                    success: function (json) {



                        if (json == 0) {
                            jQuery('#loading').hide();
                        } else {

                            jQuery.each(json, function (i, value) {
                                //  console.log("articles="+value.image);
                                var item = "<div class=\"item added\">";
                                item = item + "<div class=\"wrapper-masonry\"> <div class=\"shadow\">";

                                item = item + "<div class=\"img-content\">";
                                item = item + "<a href=\"" + is_json_exist(value.url) + "\">";
                                item = item + "<img src=\"" + is_json_exist(value.image) + "\" class=\"img-responsive\"/>";
                                item = item + "</a>";
                                item = item + "</div>";

                                item = item + "<div class=\"title-item\">";
                                item = item + "<a href=\"" + is_json_exist(value.url) + "\"><span>" + is_json_exist(value["title"]) + "</span></a>";
                                item = item + "<div class=\"underline_articles\"></div>";
                                item = item + "</div>";

                                item = item + "<div class=\"description\">";
                                item = item + is_json_exist(value["summary"]); ///.substring(0,200);
                                item = item + "</div>";

                                item = item + "</div></div></div>";

                                var item_div = document.createElement('div');
                                salvattore.appendElements(grid, [item_div]);
                                item_div.outerHTML = item;

                            });

                            status = true;

                        }
                        jQuery("#current_page").val(current_page);
                        jQuery('#loading').hide();



                    }
                });
            }
        }

    });

});
