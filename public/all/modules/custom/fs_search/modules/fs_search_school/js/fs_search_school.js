/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
jQuery('#school_type').selectpicker({
    liveSearch: true,
    size: 6
});

jQuery('#academic').selectpicker({
    liveSearch: true,
    size: 6
});
jQuery('#taught').selectpicker({
    liveSearch: true,
    size: 6
});
jQuery('#neighborhood').selectpicker({
    liveSearch: true,
    size: 6
});
jQuery("#ex8").slider({
    tooltip: 'always',
});
jQuery('#curiculum').selectpicker({
    liveSearch: true,
    size: 6
});



//*** Function  section
//Function search school
var get_select_value = function (option) {
    var arr = new Array();
    var t = option.select.parent().find("ul.dropdown-menu");
    ///console.log(t.html());
    jQuery.each(t.find("li"), function () {
        if (jQuery(this).hasClass("selected")) {

            var selected_item = jQuery(this).text();
            jQuery.each(option.select.find("option"), function () {
                var selected_same = jQuery(this).text();
                if (selected_item == selected_same) {
                    arr.push(jQuery(this).val());
                }


            });
        }
    });

    // console.log(arr);
    return arr;
}
var add_to_request_param = function (item, name) {
    var param = "";
    var lang = get_select_value({'select': item});
    for (var index = 0; index < lang.length; index++) {
        if (lang[index] != 0 && lang[index] != "all") {
            param = name + "[]=" + lang[index] + "&";
        }
    }
    return param;
}
var submit_search = function () {
    var url = "";
    var city = jQuery("#current_city").val();
    url = base_url + "/" + city + "/school?";
    jQuery(".category_school").each(function () {
        if (jQuery(this).hasClass("active")) {
            var category_school = jQuery(this).attr("value");
            if (category_school != "all") {
                url = url + "school_type[]=" + category_school + "&";
            }
        }
    });


    url = url + add_to_request_param(jQuery("#taught"), "languages");
    url = url + add_to_request_param(jQuery("#academic"), "curriculum");
    url = url + add_to_request_param(jQuery("#neighborhood"), "school_neighborhood");
    url = url + add_to_request_param(jQuery("#curiculum"), "academic_program");

    var prix = jQuery("#ex8").val().split(",");
    url = url + "tuition_min=" + prix[0] + "&";

    if (jQuery("#keyword-school").val().length != 0) {
        url = url + "tuition_max=" + prix[1] + "&";
        url = url + "keyword=" + jQuery("#keyword-school").val();
    } else {
        url = url + "tuition_max=" + prix[1];
    }
    window.location = url;


}
var submit_search_by_category = function (item) {
    var url = "";
    var city = jQuery("#current_city").val();
    url = base_url + "/" + city + "/school?";
    var category_school = item.attr("value");
            if (category_school != "all") {
                url = url + "school_type[]=" + category_school + "&";
            }



    url = url + add_to_request_param(jQuery("#taught"), "languages");
    url = url + add_to_request_param(jQuery("#academic"), "curriculum");
    url = url + add_to_request_param(jQuery("#neighborhood"), "school_neighborhood");
    url = url + add_to_request_param(jQuery("#curiculum"), "academic_program");

    var prix = jQuery("#ex8").val().split(",");
    url = url + "tuition_min=" + prix[0] + "&";

    if (jQuery("#keyword-school").val().length != 0) {
        url = url + "tuition_max=" + prix[1] + "&";
        url = url + "keyword=" + jQuery("#keyword-school").val();
    } else {
        url = url + "tuition_max=" + prix[1];
    }
    window.location = url;


}

//////Function add compare

var school_add_compare = function (option) {
    option.btn.addClass("hidden");
    option.btn.parent().find(".btn-group").removeClass("hidden");
    var nid = option.btn.parent().parent().find(".btn-compare-item").attr("id");
    if (cookie.get('temp')) {
        var temp = cookie.get('temp');
        cookie.set('compare_' + temp, nid);
        temp = parseFloat(temp) + 1;
        cookie.set('temp', temp);

    } else {
        var temp_init = 1;
        cookie.set('temp', 2);
        cookie.set('compare_' + temp_init, nid);
    }
    console.log(cookie.all());





}

var cancel_compare = function (option) {
    option.btn.parent().addClass("hidden");
    option.btn.parent().parent().find(".btn-compare-item").removeClass("hidden");

    var nid = option.btn.parent().parent().find("a").attr("id");
    var lg = 1;
    if (cookie("temp")) {
        lg = cookie("temp");

    }
    for (var i = 1; i < lg; i++) {
        var nid_added = cookie("compare_" + i);
        if (nid_added == nid) {
            cookie.remove("compare_" + i);
            if (cookie("temp")) {
                var t = parseFloat(cookie("temp")) - 1;
                cookie.set('temp', t);
            }
        }
    }
    // console.log(cookie.all());
}
var submit_compare = function (option) {
    var url = "";
    url = base_url + "/shanghai-schools/compare?";   //ids[]=261536
    var lg = 1;
    if (cookie("temp")) {
        lg = cookie("temp");
    }
    if (lg > 2) {
        jQuery(".btn-compare-school").find(".compare_now").text("Loading...");
        for (var i = 1; i < lg; i++) {
            var nid = cookie("compare_" + i);
            url = url + "ids[]=" + nid + "&";
        }
        var lng = url.length - 1;
        // console.log(url.substring(0,lng));
        clear_added_compare();
        window.location = url.substring(0, lng);
    } else {
        ///alert("Select more than 2 items");
    }

}
/// delete all cookie about compare
var clear_added_compare = function () {
    var lg = 1;
    if (cookie("temp")) {
        lg = cookie("temp");
    }
    for (var i = 1; i <= lg; i++) {
        cookie.remove("compare_" + i);
    }
    cookie.remove("temp");
}
//// on load check a compared item
var check_all_compared = function () {
    jQuery.each(jQuery(".btn-compare-school").find("a"), function () {
        var lg = 1;
        if (cookie("temp")) {
            lg = cookie("temp");
        }
        for (var i = 1; i <= lg; i++) {
            if (cookie("compare_" + i) == jQuery(this).attr("id")) {
                jQuery(this).addClass("hidden");
                jQuery(this).parent().find(".btn-group").removeClass("hidden");
            }
        }
    });
}

///// events js list for add compare

jQuery(".btn-compare-school").find("a").click(function () {
    jQuery(this).parent().parent().parent().parent().parent().addClass("active_compare");

    school_add_compare({'btn': jQuery(this)});

});
jQuery(".btn-compare-school").find(".cancel").click(function () {
    cancel_compare({'btn': jQuery(this)});
    jQuery(this).parent().parent().parent().parent().parent().parent().removeClass("active_compare");
});
jQuery(".btn-compare-school").find(".compare_now").click(function () {
    submit_compare({'btn': jQuery(this)});
});

///// events js list for search school

jQuery(".school-seach-container").find(".btn-search-school").click(function () {
    jQuery(this).text("LOADING...");
    submit_search();
});

//////events js for category button
jQuery(".category_school").click(function () {
    jQuery(this).addClass("active_current");
    jQuery(".category_school").each(function () {
        if (!jQuery(this).hasClass("active_current")) {
            jQuery(this).removeClass("active");
        }
    });
    jQuery(this).removeClass("active_current");
    jQuery(".school-seach-container").find(".btn-search-school").text("LOADING...");
    submit_search_by_category(jQuery(this));
    

});



jQuery(document).ready(function () {
    check_all_compared();
    jQuery(".btn-compare-item").each(function () {
        if (jQuery(this).hasClass("hidden")) {
            jQuery(this).parent().parent().parent().parent().parent().addClass("active_compare");
        }
    });
    if (current_path.indexOf("shanghai-schools") === -1 || current_path.indexOf("beijing/school") === -1) {
        clear_added_compare();
        // console.log("another page="+current_path);

    }
    if (current_path === "shanghai-schools" || current_path === "beijing/school") {
        //  document.location.hash =
        // console.log("another page="+current_path);
        history.pushState('data', '', base_url + '/shanghai-schools');
    }
    //  document.location.hash = base_url+"/shanghai/school";

    //console.log(cookie.all());

    //// School to search
    if (is_filter_school == "1") {
        jQuery(document).scrollTop(jQuery(".school-seach-container").offset().top);
    }

    //Tuition Price Show and Hide
    jQuery('#tuition-title').click(function () {
        jQuery('#tuition-fee').toggle();
    });
    jQuery('.wrapper_school_search').find("select").on('changed.bs.select', function (e) {
        if (jQuery(this).find("option:selected").val() == "all") {
            var title = jQuery(this).attr("title");
            jQuery(this).parent().find(".filter-option").text(title);
        }
    });
});
var item_school = function (item) {
    var str = '<div class="item-school item-school-' + item.nid + ' col-xs-12">';
    str = str + ' <div class="overlay_item_school active_overlay"></div>';
    str = str + '    <div class="item-wrapper col-xs-12">';
    str = str + '        <div class="col-sm-2 img_section"> <a href="' + item.url + '" target="_blank"><img src="' + item.preview_image + '" class="img-responsive"></a></div>';
    str = str + '        <div class="col-sm-10 text_section">';
    str = str + '           <div class="wrapper_school_item">';
    str = str + '        <div class="col-xs-12  description-item-school-container">';
    str = str + '<div class="title-item-school">';
    str = str + ' <span><a href="' + item.url + '" target="_blank">' + item.title + '</a></span>';
    str = str + '     <div class="underline_school"></div>';
    str = str + '</div>';
    str = str + '<div class="description-item-school"><p style="height: 61px; overflow: hidden;">' + item.summary + '</p>';
    str = str + '  </div>';
    str = str + '   </div>';
    str = str + '   <div class="col-xs-12 down_item_school">';
    str = str + '      <div class="my-price-school col-sm-8 col-md-8">';
    str = str + ' <div class="col-sm-6"><span class="title_span">School Type: </span>' + item.school_type + '</div>';
    if (item.neighborhood != "")
        str = str + '<div class="col-sm-6"><span class="title_span">Neighborhood: </span> ' + item.neighborhood + ' </div> ';
    if (item.language != "")
        str = str + '<div class="col-sm-6"><span class="title_span" >Languages taught : </span>' + item.language + ' </div>';
    if (item.curriculum != "")
        str = str + '<div class="col-sm-6"><span class="title_span">Curriculum: </span> ' + item.curriculum + ' </div>   ';
    str = str + '   </div>';
    str = str + '    <div class="btn-details-school col-sm-1 col-md-1">';
    str = str + '    <a href="' + item.url + '" class="btn btn-default" target="_blank">Details</a>';
    str = str + '  </div>';
    str = str + '  <div class="btn-compare-school col-sm-1 col-md-1">';
    str = str + '      <input type="hidden" class="variable" value="0">';
    str = str + '     <a id="' + item.nid + '" href="javascript:void(0)" class="btn btn-compare-item btn-default">Select to Compare</a>';
    str = str + '     <div class="btn-group hidden">';
    str = str + '         <button type="button" class="btn btn-default compare_now">Compare Now</button>';
    str = str + '         <button type="button" class="btn btn-danger cancel">';
    str = str + '             <span class="glyphicon glyphicon-remove-circle" aria-hidden="true"></span>';
    str = str + '         </button>';
    str = str + '     </div>';
    str = str + '  </div>';
    str = str + '  </div>';
    str = str + ' </div>';
    str = str + ' </div>';
    str = str + '  </div>';
    str = str + ' </div>';
    return str;
}
var submit_search_ajax = function () {
    var url = "";
    // var city = jQuery("#current_city").val();
    url = base_url + "/shanghai-schools/api?";

    jQuery(".category_school").each(function () {
        if (jQuery(this).hasClass("active")) {
            var category_school = jQuery(this).attr("value");
            if (category_school != "all") {
                url = url + "school_type[]=" + category_school + "&";
            }
        }
    });

    var lang = get_select_value({'select': jQuery("#taught")});
    for (var index = 0; index < lang.length; index++) {
        if (lang[index] != 0) {
            url = url + "languages[]=" + lang[index] + "&";
        }
    }
    var academic = get_select_value({'select': jQuery("#academic")});
    for (var index = 0; index < academic.length; index++) {
        if (academic[index] != 0) {
            url = url + "curriculum[]=" + academic[index] + "&";
        }
    }
    var neighborhood = get_select_value({'select': jQuery("#neighborhood")});
    for (var index = 0; index < neighborhood.length; index++) {
        if (neighborhood[index] != 0) {
            url = url + "school_neighborhood[]=" + neighborhood[index] + "&";
        }
    }
    var curiculum = get_select_value({'select': jQuery("#curiculum")});
    for (var index = 0; index < curiculum.length; index++) {
        if (curiculum[index] != 0) {
            url = url + "academic_program[]=" + curiculum[index] + "&";
        }
    }
    if (jQuery("#keyword-school").val().length != 0) {
        url = url + "keyword=" + jQuery("#keyword-school").val() + "&";
    }
    if (jQuery("#ex8").val().length != 0) {
        var prix = jQuery("#ex8").val().split(",");
        url = url + "tuition_min=" + prix[0] + "&";
        url = url + "tuition_max=" + prix[1];

    } else {
        url = url + "tuition_min=0&tuition_max=300000";
    }
    var next_page = parseFloat(jQuery("#page").val()) + 1;
    url = url + "&page=" + next_page;
    var request = jQuery.ajax({
        url: url,
        method: "GET",
    });
    request.done(function (msg) {
        console.log(msg);
        if (msg.items.length != 0) {
            jQuery.each(msg.items, function (i, item) {

                if (jQuery(".item-directory-list").find(".item-school-" + item.nid).length == 0) {
                    jQuery(".item-directory-list").append(item_school(item));
                }
                // jQuery('.school_scroll').find("#text_more").html("Load More");
            });
            jQuery("#page").val(next_page);
            jQuery("#loading_school").addClass("hidden");
        } else {
            jQuery('#loading_school').remove();
        }

    });
}

jQuery(document).ajaxStop(function () {
    jQuery(".btn-compare-school").find("a").click(function () {
        jQuery(this).parent().parent().parent().parent().parent().addClass("active_compare");
        school_add_compare({'btn': jQuery(this)});
    });
    jQuery(".btn-compare-school").find(".cancel").click(function () {
        cancel_compare({'btn': jQuery(this)});
        jQuery(this).parent().parent().parent().parent().parent().parent().removeClass("active_compare");
    });
    jQuery(".btn-compare-school").find(".compare_now").click(function () {
        submit_compare({'btn': jQuery(this)});
    });

});


var win = jQuery(window);
//
//    // Each time the user scrolls

win.scroll(function () {
    // End of the document reached?
    var ftr_h = jQuery(".pre-footer-container").height();
    var wg = parseFloat(jQuery(document).height()) - parseFloat(win.height()) - parseFloat(ftr_h) - 90;
    //console.log(wg);
    //console.log(win.scrollTop());
    if (wg < win.scrollTop()) {
        if (jQuery("#loading_school").hasClass("hidden")) {
            jQuery("#loading_school").removeClass("hidden");
            submit_search_ajax();
        }

    }
});