/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

var h_fixed = 324;
jQuery(document).ready(function () {
    h_fixed = parseFloat(jQuery('.megamenu-container-new').offset().top) + 35;
 
    // i need for Internet explore browser
    // jQuery('.topbar-section').addClass('topbar_mobile_fixed');
    jQuery('.megamenu-container').removeClass('navbar-fixed-top').addClass('navbar-static-top');
    jQuery('.megamenu-container').removeClass('navbar-fixed-top-family');

});

///// menu fixed on top :

jQuery(document).scroll(function (e) {
    var scrollTop = jQuery(document).scrollTop();
    if (jQuery(window).width() > 991) {
        
        if (scrollTop > h_fixed) {

            // console.log(jQuery(window).width()); // New width
            jQuery('.megamenu-container-new ').removeClass('navbar-static-top').addClass('navbar-fixed-top');
            jQuery('.megamenu-container-new ').addClass('navbar-fixed-top-family');
            //jQuery('#logo_main').addClass('fix');
            // jQuery('.menu_top_container').addClass('fix');


        } else {
            jQuery('.megamenu-container-new').removeClass('navbar-fixed-top').addClass('navbar-static-top');
            jQuery('.megamenu-container-new').removeClass('navbar-fixed-top-family');
            //  jQuery('#logo_main').removeClass('fix');
            //  jQuery('.menu_top_container').removeClass('fix');
        }
    } else {

        //  if(scrollTop > 130){
        //  console.log(scrollTop);
        // console.log(jQuery(window).width()); // New width
//           jQuery('.topbar-section').addClass('topbar_mobile_fixed');
//        } else {
//            jQuery('.topbar-section').removeClass('topbar_mobile_fixed');
//        }

    }

});
//*** reset default menu fixed***//
jQuery(window).resize(function () {
    jQuery('.topbar-section').removeClass('topbar_mobile_fixed');
    jQuery('.megamenu-container').removeClass('navbar-fixed-top').addClass('navbar-static-top');
    jQuery('.megamenu-container').removeClass('navbar-fixed-top-family');

    // jQuery('#logo_main').removeClass('fix');
    // jQuery('.menu_top_container').removeClass('fix');

//    if (jQuery(window).width() < 992) {
//        if (jQuery(".form-login-topbar").lenght != 0 && jQuery(".mobile-login-content").find(".title-login-section").lenght == 0) {
//            var login = jQuery(".form-login-topbar").find("li").html();
//            jQuery(".mobile-login-content").html(login);
//        }
//    } else {
//
//        if (jQuery(".form-login-topbar").lenght != 0 && jQuery(".form-login-topbar").find(".title-login-section").lenght == 0) {
//            var login = jQuery(".mobile-login-content").html();
//            jQuery(".form-login-topbar").find("li").html(login);
//        }
//
//    }

});


/////// redirect function
function redirectTo(url) {
    window.location = url;
}





/////tab  calandar  :
//jQuery('.pg_day').click(show_tab_calandar);



//// Tab simple
var SimpleTabs = function (elem) {
    //get tab objects and store as pane + tab
    var activeTabObject;

    var TabObject = function () {
        var self = this;
        this.tab; //element
        this.pane; //element
        this.setClick = function () {
            jQuery(self.tab).click(function () {
                self.showThisTab();
            });
        };

        this.showThisTab = function () {
            if (self !== activeTabObject) {
                //change the tab page and update the active tab
                jQuery(activeTabObject.pane).removeClass('active-page');
                jQuery(activeTabObject.tab).removeClass('active');
                jQuery(self.pane).addClass('active-page');
                jQuery(self.tab).addClass('active');
                activeTabObject = self;
            }
        };

    };

    jQuery.each(elem.children(), function (id, val) {
        var tab = new TabObject();
        tab.tab = val;
        var classString = jQuery(val).attr('class');
        var className = classString.split(' ')[0];
        tab.pane = jQuery('#' + className);
        tab.setClick();
        if (classString.indexOf('active') > -1) {
            activeTabObject = tab;
        }
    });

};
jQuery(document).ready(function () {
    var tabscalandar = new SimpleTabs(jQuery('#calandar_tab'));
});
jQuery(document).ready(function () {
    //// Popover bootstrap
    jQuery('[data-toggle="popover"]').popover();

    var tabsmost = new SimpleTabs(jQuery('#most'));
});
/// SOCIAL NETWORK IN ARTICLE DETAILS
jQuery(document).scroll(function (e) {
    var scrollTop = jQuery(document).scrollTop();
    if (jQuery(window).width() > 992) {
        if (scrollTop > 424) {
            // console.log(scrollTop);
            jQuery('.social-network').removeClass('static_social').addClass('hover_social');
        } else {
            jQuery('.social-network').removeClass('hover_social').addClass('static_social');

        }
    } else {
        if (scrollTop > 600) {
            //  console.log(scrollTop);
            jQuery('.social-mobile').addClass('hover_social_m');
        } else {
            jQuery('.social-mobile').removeClass('hover_social_m');

        }
    }

});
/// GOBAL SEARCH
jQuery(document).ready(function () {
    //////seach topbar section
    //jQuery("#fs-search-global-search-from").find("input").attr()
    // jQuery("#search-topbar").find("#fs-search-global-search-from").find("input").keydown(function(event) {
    //     if (event.which == 13) {
    //
    //          jQuery("#search-topbar").find("#fs-search-global-search-from").find("#edit-submit").click();
    //     }
    // });
    // jQuery("#fs-search-school-search-from").find("input").keydown(function(event) {
    //     if (event.which == 13) {
    //          jQuery("#fs-search-school-search-from").find("#edit-submit").click();
    //     }
    // });
    //////Newsletter
//     jQuery("#fs-newsletter-subscribe-form").find(".form-item-mail").find("input").keydown(function(event1) {
//        if (event1.which == 13) {
//             console.log("ok newsletter");
//             jQuery("#fs-newsletter-subscribe-form").find("#edit-submit--2").click();//submit();
//        }
//    });

});




//jQuery( document ).ready(function() {
//         //Check if browser is IE or not
//                if(navigator.appVersion.indexOf("MSIE")!=-1){
//                  //  alert("Browser is InternetExplorer");
//                }
//                //Check if browser is Chrome or not
//                else if (navigator.userAgent.search("Chrome") >= 0) {
//                   // alert("Browser is Chrome");
//
//                   //jQuery('.megamenu-container').addClass('chrome_fix');
//                }
//                //Check if browser is Firefox or not
//                else if (navigator.userAgent.search("Firefox") >= 0) {
//                  //  alert("Browser is FireFox");
//                }
//                //Check if browser is Safari or not
//                else if (navigator.userAgent.search("Safari") >= 0 && navigator.userAgent.search("Chrome") < 0) {
//                   // alert("Browser is Safari");
//                }
//                //Check if browser is Opera or not
//                else if (navigator.userAgent.search("Opera") >= 0) {
//                  //  alert("Browser is Opera");
//                }
//            });
// IMAGE CHECK IF EMPTY

jQuery(window).load(function () {

//     jQuery('.img-replace').each(function() {
//        // if (jQuery(this).height() > 100) {
//                 if (!this.complete || typeof this.naturalWidth == "undefined" || this.naturalWidth == 0) {
//                 // image was broken, replace with your new image
//                 this.src = path_theme+"/images/default.jpeg";
//                 this.width="100%";
//                 }
//      //  }
//     });
    //
    // jQuery('.item').find('img').each(function() {
    //    // if (jQuery(this).height() > 100) {
    //             if (!this.complete || typeof this.naturalWidth == "undefined" || this.naturalWidth == 0) {
    //             // image was broken, replace with your new image
    //             this.src = path_theme+"/images/default.jpeg";
    //
    //             }
    //  //  }
    // });


});
//jQuery(document).ajaxStop(function () {
//
//     jQuery('img').each(function() {
//       //  if (jQuery(this).height() > 100) {
//                if (!this.complete || typeof this.naturalWidth == "undefined" || this.naturalWidth == 0) {
//                // image was broken, replace with your new image
//                this.src = path_theme+"/images/default.jpeg";
//                }
//       // }
//    });
//
//});
//DFP SECTION

var DFP_function = function (frame) {
    if (frame != null) {

        var frmHead = frame.contents().find('#google_image_div');
        var frmHeadImg = frame.contents().find('img');
        if (frmHead != null) {
            //frmHead.append(jQuery('style, link[rel=stylesheet]').clone()); // clone existing css link
            //   frmHead.append(jQuery("<link/>", { rel: "stylesheet", href: path_theme+"/css/family.css", type: "text/css" })); // or create css link yourself
            frmHead.css("position", "initial");
        }
        if (frmHeadImg != null) {
            //frmHead.append(jQuery('style, link[rel=stylesheet]').clone()); // clone existing css link
            //   frmHead.append(jQuery("<link/>", { rel: "stylesheet", href: path_theme+"/css/family.css", type: "text/css" })); // or create css link yourself
            frmHeadImg.css("width", "100%");
            //frmHeadImg.css("height","initial");
            jQuery(".sidebar_second").removeClass("dfp_fix_size");
            jQuery(".sidebar_second_section").removeClass("dfp_fix_size");
            jQuery(".col-md-9").find(".dfs_family").removeClass("dfp_fix_main");
            jQuery(".col-sm-9").find(".dfs_family").removeClass("dfp_fix_main");

        }

    }
}
jQuery(document).ready(function () {
    //jQuery(".sidebar_second").addClass("dfp_fix_size");
    //jQuery(".sidebar_second_section").addClass("dfp_fix_size");
    jQuery(".col-md-9").find(".dfs_family").addClass("dfp_fix_main");
    jQuery(".col-sm-9").find(".dfs_family").addClass("dfp_fix_main");

});

jQuery(window).load(function () {
    jQuery('.sidebar_second_section').find('iframe').each(function () {
        DFP_function(jQuery(this));
    });
    jQuery('.sidebar_second').find('iframe').each(function () {
        DFP_function(jQuery(this));
    });
    jQuery('.col-md-9').find('iframe').each(function () {
        DFP_function(jQuery(this));
    });
    jQuery('.col-sm-9').find('iframe').each(function () {
        DFP_function(jQuery(this));
    });
});





//HIDDEN URL
jQuery(document).ready(function () {

    if (current_path == "shanghai/search") {
        //  document.location.hash =
        //  console.log("another page="+current_path);
        history.pushState('data', '', base_url + '/shanghai/search');
    }
    if (current_path == "beijing/search") {
        //  document.location.hash =
        //  console.log("another page="+current_path);
        history.pushState('data', '', base_url + '/beijing/search');
    }
    if (current_path == "shanghai/event") {
        //  document.location.hash =
        //  console.log("another page="+current_path);
        history.pushState('data', '', base_url + '/shanghai/event');
    }
    if (current_path == "beijing/event") {
        //  document.location.hash =
        //  console.log("another page="+current_path);
        history.pushState('data', '', base_url + '/beijing/event');
    }
});
//   CONTACT

var contact = function (option) {
    if (option.item.val() == "") {
        option.item.parent().find("label").html(option.icon + " Name");

    } else {
        option.item.parent().find("label").addClass("hidden");
    }
    option.item.focus(function () {
        console.log("ok");
        jQuery(this).parent().find("label").addClass("hidden");
    });
    option.item.blur(function () {
        if (jQuery(this).val() == "")
        {
            jQuery(this).parent().find("label").html(option.icon + " Name");
            jQuery(this).parent().find("label").removeClass("hidden");
        }
    });
}

jQuery(document).ready(function () {
    //jQuery("#edit-field-ef-name-und-0-value").attr("placeholder",encodeURIComponent("&#xf007; Name"));
    var user = '<span class="glyphicon glyphicon-user" aria-hidden="true"></span>';
    var item = jQuery("#edit-field-ef-name-und-0-value");
    contact({'item': item, 'icon': user});

    var sms = '<span class="glyphicon glyphicon-envelope" aria-hidden="true"></span>';
    item = jQuery("#edit-field-ef-email-und-0-email");
    contact({'item': item, 'icon': sms});
    var write = '<span class="glyphicon glyphicon-pencil" aria-hidden="true"></span>';
    if (jQuery("#edit-field-ef-message-und-0-value").val() == "") {
        jQuery("#edit-field-ef-message-und-0-value").parent().parent().find("label").html(write + " Message");
    } else {
        jQuery("#edit-field-ef-message-und-0-value").parent().parent().find("label").addClass("hidden");
    }
    jQuery("#edit-field-ef-message-und-0-value").focus(function () {
        jQuery(this).parent().parent().find("label").addClass("hidden");
    });
    jQuery("#edit-field-ef-message-und-0-value").blur(function () {
        if (jQuery("#edit-field-ef-message-und-0-value").val() == "")
        {
            jQuery("#edit-field-ef-message-und-0-value").parent().parent().find("label").html(write + " Message");
            jQuery("#edit-field-ef-message-und-0-value").parent().parent().find("label").removeClass("hidden");
        }
    });
});
//////registration form
jQuery("#reg-info").height(jQuery("#reg-form").height() + 50);
jQuery(document).ready(function () {

    jQuery("#reg-info").height(jQuery("#reg-form").height() + 50);


});
jQuery(document).ajaxStop(function () {

    jQuery("#reg-info").height(jQuery("#reg-form").height() + 50);

});


jQuery(document).ready(function () {

    // jQuery("#edit-submit--4").attr("type","button");
    if (jQuery("#main-directory").length) {
        var category = jQuery("#category_select").val();
        ////jQuery("#category_select select option:selected").text();
        /// console.log("cat="+category);
        if (category == '454' || category == '458') {
            jQuery(".health").addClass("active_menu_top");
            jQuery(".directory_other").removeClass("active_menu_top");
        } else {
            jQuery(".health").removeClass("active_menu_top");
            jQuery(".directory_other").addClass("active_menu_top");

        }
    }
    jQuery(".back_to").click(function () {
        var city = jQuery.trim(jQuery(".city_current_select").text().toLowerCase());

        var url = base_url + city + "/" + jQuery("#item_type").val();
        console.log(url);
        window.location = url;
    });
/// LOGIN
    jQuery(".form-login-topbar").find("#user-login-form").submit(function (e) {
        jQuery(this).find(".form-actions").find("input").val('Loading...');
    });
    jQuery(".mobile-login-content").find("#user-login-form").submit(function (e) {
        jQuery(this).find(".form-actions").find("input").val('Loading...');
    });

    jQuery(".result_list").find("a").click(function () {
        console.log("work");
        jQuery(this).html('Loading...');
    });

});

/// LOGIN
jQuery(".form-login-topbar").find("#user-login-form").find("input").keydown(function (event) {
    if (event.which == 13) {
        event.preventDefault();
        /// jQuery(".form-login-topbar").find("#user-login-form").find("#edit-actions--2").html('<a  class="form-submit"  name="op" id="edit-submit--4"><i class="fa fa-spinner fa-pulse fa-3x fa-fw margin-bottom"></i></a>');

        jQuery(".form-login-topbar").find("#user-login-form").find("#edit-submit--4").val('Loading...');
        jQuery(".form-login-topbar").find("#user-login-form").submit();
    }
});

///// BACK TO TOP
//if (jQuery('#back-to-top').length) {
jQuery(function () {
    var scrollTrigger = 200, // px
            backToTop = function () {
                var scrollTop = jQuery(document).scrollTop();
                if (scrollTop > scrollTrigger) {
                    jQuery('#back-to-top').addClass('show');
                } else {
                    jQuery('#back-to-top').removeClass('show');
                }
            };
    backToTop();
    jQuery(document).scroll(function () {
        backToTop();
    });
    jQuery('#back-to-top').click(function () {
        jQuery('body,html').animate({
            scrollTop: 0
        }, 800);
        return false;
    });

});

// (function ($) {
// Drupal.jsAC.prototype.select = function (node) {
//   this.input.value = $(node).data('autocompleteValue');
//   if(jQuery(this.input).hasClass('auto_submit')){
//     this.input.form.submit();
//   }};
// })(jQuery);
//// END BACK TO TOP



///// FIX OVERFLOW TEXT
var reset_over_flow_text = function (item) {

}
var over_flow_text = function (item, length_text, height_text) {
    var size = item.height();

    item.each(function (index) {
        jQuery(this).height(height_text);
        jQuery(this).css("overflow", "hidden");
        var str = jQuery(this).text();
        if (str.length > length_text) {
            jQuery(this).text(str.substr(0, length_text) + "...");
        }
    });
}

///// LIST OF ITEM FIX OVERFLOW TEXT
var execute_over_flow_text = function () {
    var w = jQuery(window).width();
    if (w >= 1200) {
        over_flow_text(jQuery(".cut-item"), 65, 35);
        over_flow_text(jQuery(".description-item-directory"), 275, 53);
        over_flow_text(jQuery(".small_item").find(".description-school"), 210, 80);
        over_flow_text(jQuery(".description-item-school > p"), 259, 61);
        over_flow_text(jQuery(".description-item-events"), 259, 61);
        over_flow_text(jQuery(".compare_items .item .description p"), 129, 45);
        //  console.log("+1199");

    } else if (992 <= w && w < 1200) {
        //  console.log("992-1200");
        over_flow_text(jQuery(".compare_items .item .description p"), 129, 45);

        over_flow_text(jQuery(".description-item-events"), 259, 61);

        over_flow_text(jQuery(".description-item-school > p"), 259, 61);
        over_flow_text(jQuery(".cut-item"), 65, 35);
        over_flow_text(jQuery(".description-item-directory"), 255, 53);
        over_flow_text(jQuery(".small_item").find(".description-school"), 210, 105);

    } else if (768 <= w && w < 991) {
        //      console.log("768-991");
        over_flow_text(jQuery(".small_item").find(".description-school"), 155, 104);

        // over_flow_text(jQuery(".cut-item"),65,35);

    } else if (487 <= w && w < 767) {
        //    console.log("487-767");
        //  over_flow_text(jQuery(".large_item").find(".description-school"),225,65);
        // over_flow_text(jQuery(".description-item-directory"),140,60);
    } else if (w < 486) {
        //     console.log("<486");
        over_flow_text(jQuery(".description-item-directory"), 140, 60);
        // over_flow_text(jQuery(".large_item").find(".description-school"),140,65);
    }

}

jQuery(document).ready(function () {
    execute_over_flow_text();

    //Header Dropdown Open focus search input

    jQuery("#search-dd").on('shown.bs.dropdown', function ()
    {
        jQuery('input:text:visible:first', this).focus();
    });

    jQuery("#search-mdd").on('shown.bs.dropdown', function ()
    {
        jQuery('input:text:visible:first', this).focus();
    });

});
jQuery(window).load(function () {
    /// execute_over_flow_text();
});

jQuery(document).ajaxStop(function () {
    execute_over_flow_text();
});
jQuery(window).resize(function () {
    execute_over_flow_text();
});

///// FIX OVERFLOW TEXT END
