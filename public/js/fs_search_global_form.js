//(function ($) {
//    Drupal.behaviors.searchGlobalForm = {
//        attach: function (context, settings) {
//            $("#fs-search-global-search-from #keyword-global").autocomplete({
//                source: function (request, response) {
//                    $.ajax({
//                        url: Drupal.settings.fs_search_global_search_form.query_url,
//                        dataType: "json",
//                        data: {
//                            term: request.term
//                        },
//                        success: function (data) {
//                            response(data);
//                        }
//                    });
//                },
//                minLength: 2,
//                select: function (event, ui) {
//                    if (typeof ui.item.url !== 'undefined') {
//                        window.location.href = ui.item.url;
//                    }
//                },
//            }).autocomplete("widget").addClass("ui-autocomplete-global");
//        }
//    };
//})(jQuery);

jQuery(document).ready(function () {
    jQuery("#keyword-global")
            .focus(function () {

                jQuery(".search_input_global").find(".fa-search").addClass("set_bg");
            })
            .blur(function () {

                jQuery(".search_input_global").find(".fa-search").removeClass("set_bg");
            })
            .keydown(function (event) {
                if (event.which == 13) {
                    event.preventDefault();
                    jQuery("#fs-search-global-search-from").submit();
                }
            });           
            jQuery(".search_input_global").find(".fa-search").click(function(){
                  jQuery("#keyword-global").focus();
            });

});
