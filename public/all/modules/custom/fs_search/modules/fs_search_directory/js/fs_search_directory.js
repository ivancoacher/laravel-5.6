/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//*** Function  section
//Function search directory
jQuery("#category_select").selectpicker({
    liveSearch: true,
    size: 6
});
jQuery("#neighbourhood_select").selectpicker({
    liveSearch: true,
    size: 6
});


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
var submit_search = function () {
    var url = "";
    var city = jQuery("#current_city").val();
    url = base_url + "/" + city + "/directory?";

    var directory = get_select_value({'select': jQuery("#category_select")});
    for (var index = 0; index < directory.length; index++) {
             if(directory[index]!=0){
        url = url + "category[]=" + directory[index] + "&";
           }
    }

    var neighborhood = get_select_value({'select': jQuery("#neighbourhood_select")});
    for (var index = 0; index < neighborhood.length; index++) {
         if(neighborhood[index]!=0){
              url = url + "neighbourhood[]=" + neighborhood[index] + "&";
          }
    }
//    if(jQuery("#edit-keyword").val().length != 0 ){
//    url = url + "keyword=" + jQuery("#edit-keyword").val();
//    }else{
//
//    }



    window.location = url;


}

jQuery(document).ready(function () {
   /// jQuery(".directory-search").find("#edit-submit").attr("type", "button");
});

///// events js list for search school

jQuery(".directory-search").find("#edit-submit-top").click(function () {
    jQuery(this).val('Loading...');
    submit_search();
});
jQuery('#category_select').on('changed.bs.select', function (e) {
      jQuery(".directory-search").find("#edit-submit-top").val('Loading...');
      submit_search();
});
jQuery('#neighbourhood_select').on('changed.bs.select', function (e) {
      jQuery(".directory-search").find("#edit-submit-top").val('Loading...');
      submit_search();
});


jQuery( document ).ready(function() {
    //////seach list directory   
    jQuery(".search_list").find("#edit-keyword").keydown(function(event) {
        if (event.which == 13) {     
             jQuery(".search_list").find("#edit-submit-top").click();
        }
    });
      //// Hidden request url 
      if(current_path=="shanghai/directory"||current_path=="beijing/directory"){
        history.pushState('data', '', base_url+'/shanghai/directory');
      }
     //// End Hidden request url
});
