/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


(function () {
	'use strict';

	var sideTabsPaneHeight = function() {
		var navHeight = jQuery('.nav-tabs.nav-tabs-left').outerHeight() || jQuery('.nav-tabs.nav-tabs-right').outerHeight() || 0;

		var paneHeight = 0;

		jQuery('.tab-content.side-tabs .tab-pane').each(function(idx) {
			paneHeight =jQuery(this).outerHeight() > paneHeight ? jQuery(this).outerHeight() : paneHeight;
		});

		jQuery('.tab-content.side-tabs .tab-pane').each(function(idx) {
			jQuery(this).css('min-height', navHeight + 'px');
		});
	};
	
  jQuery(function() {
    sideTabsPaneHeight();

		jQuery( window ).resize(function() {
			sideTabsPaneHeight();
		});

		jQuery( '.nav-tabs.nav-tabs-left' ).resize(function() {
			sideTabsPaneHeight();
		});
	});
}());

jQuery( document ).ready(function() {
    /// megamenu on hover :  
    jQuery('.megamenu-container').find('ul.nav li.dropdown').hover(function() {   
      jQuery(this).find('.dropdown-menu').stop(true, true).delay(200).fadeIn(500);
      jQuery(this).find('.underline_m').addClass("underline_menu");
    }, function() {
     jQuery(this).find('.dropdown-menu').stop(true, true).delay(200).fadeOut(500);
     jQuery(this).find('.underline_m').removeClass("underline_menu");
    });
   jQuery('.megamenu-container').find('ul.nav li.dropdown').focus(function(){
       jQuery(this).find('.underline_m').addClass("underline_menu");
   });
});