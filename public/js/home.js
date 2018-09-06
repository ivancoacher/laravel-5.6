/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//  Ajax more function
function cat_class(value) {
    try
    {
        value = value.split("&").join("");
        value = value.split(" ").join("_");
    } catch (err)
    {
        value = " ";
    }

    return value;
}
function stick(json_item, url) {
    var val = "";
    if (json_item.editor_pick == true) {
        val = "<div class=\"img-icon-item\"><img  src=\"" + path_theme + "/images/icon/editor_pick.png\" /></div> ";
    } else if (json_item.sponsored == true) {
        val = "<div class=\"img-icon-item\"><img  src=\"" + path_theme + "/images/icon/sponsored.png\" /></div> ";
    } else if (json_item.win == true) {
        val = "<div class=\"img-icon-item\"><img  src=\"" + path_theme + "/images/icon/win.png\" /></div> ";
    } else {
        if (url.indexOf("fs_get_trending_now") >= 0) {
            val = "<div class=\"img-btn-item \">";
            val = val + "<a  href=\"#\" class='btn btn-default-1 " + cat_class(json_item.categories[0]) + "' >" + json_item.categories[0] + "</a>";
            val = val + "</div>";
        }
    }
    return val;
}
function item(json_item, url) {
    var value = "";
    value = value + "<div class=\"col-xs-6 col-sm-6 col-md-4 item-content parenting_item \">";
    value = value + stick(json_item, url);
    value = value + " <div class=\"img_section\"><a  href=\"" + json_item.url + "\"  >";
    value = value + "<img src=\"" + json_item.image + "\" class=\"img-responsive img-item\" />";
    value = value + "<div class=\"overlay_treding\"></div></a></div>";
    value = value + "<p class=\"title-item\">" + json_item.title + "</p>";
    value = value + "</div>";
    return value;
}
;
var ajaxMore = function (options) {
    this.build = function () {
        // console.log(options);
        options.btn_more.hide();
        options.btn_load.show();
        jQuery.ajax({
            url: options.url,
            dataType: 'json',
            error: function () {
                // field_prod_com.attr("placeholder","SKU n'existe pas");

                options.btn_load.hide();
                options.btn_more.show();

            },
            beforeSend: function () {

            },
            success: function (json) {
                // console.log(json);
                // console.log(options.next_page);
                jQuery.each(json, function (i, value) {
                    var str = "";
                    str = str + "<div class=\"col-xs-6 col-sm-6 col-md-4 item-content parenting_item \">";
                    str = str + stick(value, options.url);
                    str = str + " <div class=\"img_section\"><a  href=\"" + value["url"] + "\"  >";
                    str = str + "<img src=\"" + value["image"] + "\" class=\"img-responsive img-item\" />";
                    str = str + "<div class=\"overlay_treding\"></div></a></div>";
                    str = str + "<p class=\"title-item\"><a  href=\"" + value["url"] + "\">" + value["title"] + "</a></p>";
                    str = str + "</div>";
                    options.place.append(str);
                });
                options.current_page.val(options.next_page);
                options.btn_load.hide();
                options.btn_more.show();
            }

        });

    };
};

// trending now events
jQuery(document).ready(function () {
    var cid_current = jQuery(".treding").find("#cid").val();
    var place = jQuery(".treding").find('.items');
    jQuery(".treding").find('.btn-more').click(function () {
        var next_page = parseFloat(jQuery(".treding").find(".current_page").val()) + 1;
        var url = base_url + '/api/fs_get_trending_now/' + cid_current + '/' + next_page;
        var options = {
            place: place,
            url: url,
            next_page: next_page,
            btn_load: jQuery('.loading_tred'),
            current_page: jQuery(".treding").find(".current_page"),
            btn_more: jQuery(".treding").find('.btn-more')
        }
        var ajax_treding = new ajaxMore(options);
        ajax_treding.build();
    });

});

// what new   events
jQuery(document).ready(function () {
    var cid_current = jQuery(".what_new").find("#cid").val();
    var place = jQuery(".what_new").find('.items');
    jQuery(".what_new").find('.btn-more').click(function () {
        var next_page = parseFloat(jQuery(".what_new").find(".current_page").val()) + 1;
        var url = base_url + '/api/fs_get_what_new/' + cid_current + '/' + next_page;
        var options = {
            place: place,
            url: url,
            next_page: next_page,
            btn_load: jQuery(".what_new").find('#loading'),
            current_page: jQuery(".what_new").find(".current_page"),
            btn_more: jQuery(".what_new").find('.btn-more')
        }
        var ajax_what_new = new ajaxMore(options);
        ajax_what_new.build();
    });

});



/////tab  editor pick :

jQuery(document).ready(function () {
    var owl_editor = jQuery("#owl-family-editor-pick");
    owl_editor.owlCarousel({
        items: 4,
        itemsDesktop: [1199, 3],
        itemsDesktopSmall: [979, 3],
        pagination: false,
        stopOnHover: true
    });
    // Custom Navigation Events
    jQuery(".next_editor").click(function () {

        owl_editor.trigger('owl.next');
    });
    jQuery(".prev_editor").click(function () {

        owl_editor.trigger('owl.prev');
    });




    //*** declaration section***//
    var tab_item = jQuery(".item_editor_pick");
    //*** declaration section***//
    var show_tab = function () {

        var item = "data_" + jQuery(this).attr("id");
        var act = jQuery("#current_active").val();
        //  console.log(act);
        if (act == item) {
            // console.log(act);
        } else {
            tab_item.each(function () {
                if (!jQuery(this).hasClass(item)) {
                    jQuery(this).removeClass('display_custom');
                    jQuery(".active_editor").removeClass("underline_menu");
                }
            });
            jQuery("." + item).addClass('display_custom');
            jQuery("." + item).addClass('active_custom');
            jQuery("#current_active").val(item);
            jQuery(this).addClass("active_editor");
            jQuery(this).addClass("underline_menu");
        }
    }
    //*** event section***//
    jQuery(".menu-editor").click(show_tab);


});
/////tab  pick of week  :

//*** declaration section***//
var show_tab_week = function (option) {

    var item = "data_" + option.id.attr("id");
    var tab_item_week = jQuery(".pick-of-week-list");
    var act = jQuery("#current_active_week").val();
    //  console.log("var="+act+" et "+item);
    if (act == item) {
        // console.log("same");
    } else {
        tab_item_week.each(function (e) {
            if (!jQuery(this).hasClass(item)) {
                jQuery(this).removeClass('display_custom_week');
                jQuery(".active_week").removeClass("underline_menu_week");
            }
        });
        jQuery("." + item).addClass('display_custom_week');
        jQuery("#current_active_week").val(item);
        option.id.addClass("active_week");
        option.id.addClass("underline_menu_week");
    }
}
//*** event section***//
jQuery(document).ready(function () {
    var owl_editor_w = jQuery("#owl-family-editor-week");
    owl_editor_w.owlCarousel({
        items: 1,
        itemsDesktop: [1199, 1],
        itemsDesktopSmall: [979, 3],
        autoHeight: true,
        pagination: false,
        stopOnHover: true
    });
    // Custom Navigation Events
    jQuery(".next_editor_w").click(function () {

        owl_editor_w.trigger('owl.next');
    });
    jQuery(".prev_editor_w").click(function () {

        owl_editor_w.trigger('owl.prev');
    });

    jQuery('.menu-week a').click(function () {
        //  console.log("work");
        show_tab_week({'id': jQuery(this)});
    });
});

//***Home slide section***//
jQuery(document).ready(function () {
    var owl = jQuery("#owl-family");
    owl.owlCarousel({
        items:3,
        loop:true,
        autoplay: true,
        autoplayTimeout:4000,
        stopOnHover: true,
        responsive: {
            0: {
                items: 1 // In this configuration 1 is enabled from 0px up to 479px screen size 
            },
            480: {
                items: 1, // from 480 to 677 

            },
            678: {
                items: 2, // from this breakpoint 678 to 959

            },
            960: {
                items: 3, // from this breakpoint 960 to 1199


            },
            1200: {
                items: 3,
            }
        }
    });
    // Custom Navigation Events
    jQuery(".next").click(function () {
        owl.trigger('next.owl.carousel');
    });
    jQuery(".prev").click(function () {
        owl.trigger('prev.owl.carousel');
    });
    if (Modernizr.touch) {
        // show the close overlay button
        jQuery(".close-overlay").removeClass("hidden");
        // handle the adding of hover class when clicked
        jQuery(".img").click(function (e) {
            if (!jQuery(this).hasClass("hover")) {
                jQuery(this).addClass("hover");
            }
        });
        // handle the closing of the overlay
        jQuery(".close-overlay").click(function (e) {
            e.preventDefault();
            e.stopPropagation();
            if (jQuery(this).closest(".img").hasClass("hover")) {
                jQuery(this).closest(".img").removeClass("hover");
            }
        });
    } else {
        // handle the mouseenter functionality
        jQuery(".img").mouseenter(function () {
            jQuery(this).addClass("hover");
        })
                // handle the mouseleave functionality
                .mouseleave(function () {
                    jQuery(this).removeClass("hover");
                });
    }
});



//***Home gallery section***//
jQuery(document).ready(function () {
    var owl = jQuery("#owl-home-gallery");
    owl.owlCarousel({
        loop:true,
        autoplay: true,
        autoplayTimeout:4000,
        autoHeight:true,
        stopOnHover: true,
        responsive: {
            0: {
                items: 1 // In this configuration 1 is enabled from 0px up to 479px screen size 
            },
            480: {
                items: 1, // from 480 to 677 

            },
            678: {
                items: 2, // from this breakpoint 678 to 959

            },
            960: {
                items: 3, // from this breakpoint 960 to 1199


            },
            1200: {
                items: 4,
            }
        }

    });
    // Custom Navigation Events
    jQuery(".bs-family-home-gallery").find(".next").click(function () {
        owl.trigger('next.owl.carousel');
    });
    jQuery(".bs-family-home-gallery").find(".prev").click(function () {
        owl.trigger('prev.owl.carousel');
    });

    jQuery(".owl-numbers").html("<i class=\"fa fa-asterisk\" aria-hidden=\"true\"></i>");
});
jQuery(window).resize(function () {
    jQuery(".owl-numbers").html("<i class=\"fa fa-asterisk\" aria-hidden=\"true\"></i>");
});
