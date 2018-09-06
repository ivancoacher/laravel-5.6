/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


jQuery(document).ready(function () {

    var owl = jQuery("#owl-family-gallery-details");

    owl.owlCarousel({
        stagePadding: 80,
        loop: true,
        margin: 5,
        items: 1,
        itemsDesktop: [1199, 1],
        itemsDesktopSmall: [979, 1],
        autoplay: true,
        autoplayHoverPause: true

    });
    // Custom Navigation Events
    jQuery(".next").click(function () {
        owl.trigger('next.owl.carousel');
        //jQuery('.owl-dot:nth(2)').trigger('click');
    });
    jQuery(".prev").click(function () {
        owl.trigger('prev.owl.carousel');
        //  jQuery('.owl-dot:nth(1)').trigger('click');
    });
    // jQuery("a[rel^='prettyPhoto[pp_gal]']").prettyPhoto();

 //   jQuery("a[rel^='prettyPhoto']").prettyPhoto();
  ///  jQuery("area[rel^='prettyPhoto']").prettyPhoto();

});

