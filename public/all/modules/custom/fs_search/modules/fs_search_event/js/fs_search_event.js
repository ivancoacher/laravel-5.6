/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
var get_select_value =function(option){
       var arr = new Array();
       var t=option.select.parent().find("ul.dropdown-menu") ;
        ///console.log(t.html());
        jQuery.each(t.find("li"),function (){         
            if(jQuery(this).hasClass("selected")){
                 
                  var selected_item = jQuery(this).text(); 
                   jQuery.each(option.select.find("option"),function (){
                                 var selected_same=jQuery(this).text(); 
                                 if(selected_item==selected_same){
                                      arr.push(jQuery(this).val());
                                 }
                      
                   
                   });  
            }
        });

      return arr ;
}
var submit_search_event = function () {
         //var keyword=jQuery("#fs-search-event-list-page-form").find("#edit-keyword").val();
         var category =get_select_value({'select':jQuery("#category_event")});
         var city=jQuery("#current_city").val();
         var url="";
         url=jQuery.trim(base_url)+"/"+jQuery.trim(city)+"/event?";  
         
//         var hid = jQuery(".event-search").find("input[name=variables]").val();
//       
//         var list = hid.split('"');
//         var date_start="";
//         var date_end="";
//         var temp=0;
//         for(var i=0;i<list.length;i++){
//            
//                if (list[i].toLowerCase().indexOf("date_start") != -1) {
//                  date_start = list[i] +"="+  list[i+2] ;
//                }
//                 if (list[i].toLowerCase().indexOf("date_end") != -1) {
//                  date_end = list[i]+"="+ list[i+2] ;
//                }
//         }
         
//         if(jQuery("#fs-search-event-list-page-form").find("#edit-keyword").val().length != 0 ){
//         url=url+"keyword="+keyword ;
//         temp=1;
//         }
         if(category!=""){
//            if(temp==1){
//             url=url+"&"+"category="+category ;
//            }else{
             url=url+"category="+category ;    
           // }
          //  temp=2;
         }
//         if(date_end!=""&&date_start!=""){
//            if(temp==1||temp==2){
//            url=url+"&"+ date_start + "&" + date_end;  
//            }else{
//            url=url+ date_start + "&" + date_end;
//            }
//         }
        // console.log("base url ="+jQuery.trim(base_url)+" End base url ");
        // console.log("city ="+jQuery.trim(city)+" End city");
         window.location=url;
}
 jQuery('#category_event').selectpicker({
                liveSearch: true,
                   size: 6
            });
          
jQuery(".btn_search_container").find("#edit-submit").click(function(){
        jQuery(this).val('Loading...'); 
         submit_search_event();
});
jQuery('#category_event').on('changed.bs.select', function (e) {
    //  jQuery("#fs-search-event-list-page-form").find("#edit-submit").val('Loading...'); 
    //  submit_search_event();
});
jQuery( document ).ready(function() {
  
      
      
});
