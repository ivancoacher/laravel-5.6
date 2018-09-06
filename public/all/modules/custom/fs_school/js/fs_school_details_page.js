/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


////// Contact us API
jQuery(document).ready(function () {
    // get the max height of a collection of elements using map
    var maxHeight = Math.max.apply(null, jQuery(".other-campus-detail").map(function ()
    {
        return jQuery(this).outerHeight();
    }).get());
// set all divs to the same height
    jQuery('.other-campus-detail').css({height: maxHeight + 'px'});



    jQuery("#btn_contact").click(function () {

        jQuery("#btn_contact").find("span").text("Loading...");
        jQuery("#btn_contact").find("i").addClass("hidden");
        var url = jQuery("#contact_us_form_school").attr("action");
        var jqxhr = jQuery.post(url,
                {name: jQuery("#name").val(),
                    message: jQuery("#message").val(),
                    subject: jQuery("#subject").val(),
                    email: jQuery("#email").val(),
                    contact_email: jQuery("#email_contact").val(),
                    contact_name: jQuery("#name_contact").val(),
                    contact_telephone: jQuery("#contact_telephone").val(),
                    send_me: (jQuery('#send_me').is(":checked") ? 1 : 0),
                }, function () {
        })
                .done(function (data) {

                    if (data["success"] == 0) {
                        jQuery("#message_error_contact").find('p').text(data["message"]);
                        jQuery("#btn_contact").css("border-color", "red");
                    } else {
                        jQuery(".modal-header").find(".close").click();
                        jQuery("#message_error_contact").find('p').text("");
                        jQuery("#btn_contact").css("border-color", "transparent");
                        jQuery("#message").text("");
                        jQuery("#subject").val("");
                        jQuery("#name").val("");
                        jQuery("#email").val("");
                        jQuery("#contact_telephone").val(""),
                                jQuery('.top-left').notify({
                            message: {
                                text: 'Email Sent Sucessfully !'
                            },
                            closable: false
                        }).show();
                    }

                    jQuery("#btn_contact").find("span").text("Send");
                    jQuery("#btn_contact").find("i").removeClass("hidden");
                });

    });

//
//    var map_1 = new AMap.Map('map-content-1',{
//        resizeEnable: false,
//        zoom: 10,
//        scrollWheel:false,
//        center: [116.397428, 39.90923],
//    });
//    var markers = [];
//    var marker = new AMap.Marker({
//        position: [116.391467, 39.927761],
//        title: '11111',
//        map: map_1
//    });
//     marker.on('click',function(e){
//                    marker.markOnAMAP({
//                        name:'首开广场',
//                        position:marker.getPosition()
//                    })
//                });
//    markers.push(marker);
//    map.setLang("en");
//    map.setFitView();

    var owl = jQuery("#owl-school-videos");
    owl.owlCarousel({
        autoplay: true,
        autoplayTimeout: 5000,
        responsiveClass: true,
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
    jQuery(".bs-family-school-video").find(".next").click(function () {
        owl.trigger('next.owl.carousel');
    });
    jQuery(".bs-family-school-video").find(".prev").click(function () {
        owl.trigger('prev.owl.carousel');
    });

    // School Gallery slider
    var owl_gallery = jQuery("#owl-school-gallery");
    owl_gallery.owlCarousel({
        autoplay: true,
        autoplayTimeout: 5000,
        autoplayHoverPause: true,
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
    jQuery(".bs-family-school-gallery").find(".next").click(function () {
        owl_gallery.trigger('next.owl.carousel');
    });
    jQuery(".bs-family-school-gallery").find(".prev").click(function () {
        owl_gallery.trigger('prev.owl.carousel');
    });

    // School testimonials slider
    var owl_testimonials = jQuery("#owl-school-testimonial");
    owl_testimonials.owlCarousel({
        autoplay: false,
        autoHeight: true,
        items: 1
    });
    jQuery(".bs-family-school-testimonial").find(".next").click(function () {
        owl_testimonials.trigger('next.owl.carousel');
    });
    jQuery(".bs-family-school-testimonial").find(".prev").click(function () {
        owl_testimonials.trigger('prev.owl.carousel');
    });

    // Fancybox js for videos
    jQuery(".various").fancybox({
        maxWidth: '90%',
        maxHeight: '60%',
        fitToView: false,
        width: '600px',
        height: '400px',
        autoSize: false,
        closeClick: true,
        openEffect: 'none',
        closeEffect: 'none'
    });

});
