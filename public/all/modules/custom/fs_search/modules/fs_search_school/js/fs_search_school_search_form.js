//(function ($) {
//    Drupal.behaviors.searchSchoolForm = {
//        attach: function (context, settings) {
//            $("#fs-search-school-search-form #keyword-school").autocomplete({
//                source: function (request, response) {
//                    $.ajax({
//                        url: Drupal.settings.fs_search_school_search_form.query_url,
//                        dataType: "json",
//                        data: {
//                            term: request.term
//                        },
//                        success: function (data) {
//                            console.log(data);
//                            response(data);
//                        }
//                    });
//                },
//                minLength: 2,
//                select: function (event, ui) {
//                    if(typeof ui.item.url !== 'undefined') {
//                        window.location.href = ui.item.url;
//                    }
//                },
//            });
//
//            $("#fs-search-school-search-form").find("input#keyword-school").keydown(function(event) {
//                if (event.which == 13) {
//                     $("#fs-search-school-search-form").submit();
//                }
//            });
//        }
//    };
//})(jQuery);
