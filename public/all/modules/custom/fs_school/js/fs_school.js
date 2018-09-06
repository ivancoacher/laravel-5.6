/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


var same_height = function (id) {
    var max = 0;
    id.find(".item").find(".wrapper").each(function () {
        //  console.log(jQuery(this).height());
        if (max < jQuery(this).height()) {
            max = jQuery(this).height();
        }
    });
    // console.log(max);
    id.find(".item").find(".wrapper").each(function () {
        jQuery(this).height(max + 20);
    });
}

var submit_compare_add = function () {
    var url = "";
    //var city=jQuery("#current_city").val();
    // console.log("path="+current_path);
    url = base_url + "/shanghai-schools/compare?";   //ids[]=261536
    jQuery(".school_nid").each(function () {

        var nid = jQuery(this).val();
        url = url + "ids[]=" + nid + "&";

    });
    if (jQuery(".auto_id_item").val()!=0) {
        var add = jQuery(".auto_id_item").val();
        url = url + "ids[]=" + add;
    }
    // console.log(url);
    window.location = url;
}

jQuery(document).ready(function () {

    // same_height(jQuery("#info"));
    // same_height(jQuery("#language"));
    ///  same_height(jQuery("#academic"));
    // same_height(jQuery("#curriculum"));



    jQuery(".fancybox").fancybox();

    jQuery(".add-school").find("#edit-submit").click(function () {
        if (jQuery(".auto_id_item").val()!=0) {
            jQuery(this).text("Loading...");
            submit_compare_add();
        }

    });

    jQuery("#back_to_school").click(function () {

        /// console.log(current_path);
        // if(current_path.lenght>0){
        var url_chool = base_url + "/" + current_path.split("/compare")[0];
        // }
        window.location = url_chool;
    });


});
jQuery(window).resize(function () {
    //    same_height(jQuery("#info"));
    //    same_height(jQuery("#language"));
    //    same_height(jQuery("#academic"));
    //    same_height(jQuery("#curriculum"));
});
jQuery.fn.fadeOutAndRemove = function(speed){
    jQuery(this).fadeOut(speed,function(){
        jQuery(this).remove();
    })
}
jQuery(document).ready(function () {
       jQuery(".rm_compare").click(function(){
             jQuery(this).parent().parent().find(".school_nid").remove();
            submit_compare_add();
       });
});

var maxHeight = function (elems) {
    return Math.max.apply(null, elems.map(function ()
    {
        return jQuery(this).height();
    }).get());
}
var make_same_height = function () {
    var fields_compare_list = Drupal.settings.fields_compare;
    jQuery(".item_content_odd").each(function () {
        for (var key in fields_compare_list) {
            var max = maxHeight(jQuery(this).find("." + fields_compare_list[key]).find("p"));
            jQuery(this).find("." + fields_compare_list[key]).height(max);
        }
    });
}
jQuery(document).ready(function () {
    make_same_height();
    jQuery(window).resize(function () {
        make_same_height();
    });

    //jQuery(".item_content_container").removeClass("hidden");
});



jQuery(document).ready(function () {
    var engine, remoteHost, template, empty;

    jQuery.support.cors = true;

    remoteHost = base_url;
    template = Handlebars.compile(jQuery("#result-template").html());
    empty = Handlebars.compile(jQuery("#empty-template").html());

    engine = new Bloodhound({
        identify: function (o) {
            return o.nid;
        },
        queryTokenizer: Bloodhound.tokenizers.whitespace,
        datumTokenizer: Bloodhound.tokenizers.obj.whitespace,
 
        prefetch: remoteHost + '/school_compare/autocomplete',
        remote: {
            url: remoteHost + '/school_compare/autocomplete/%QUERY',
            wildcard: '%QUERY'
        }
    });

    // ensure default users are read on initialization
 //   engine.get(['799', '876', '971', '886'])

    function engineWithDefaults(q, sync, async) {
//        if (q === '') {
//            sync(engine.get(['799', '876', '971', '886']));
//            async([]);
//        } else {
            engine.search(q, sync, async);
    //    }
    }

    jQuery('#demo-input').typeahead({
        hint: jQuery('.Typeahead-hint'),
        menu: jQuery('.Typeahead-menu'),
        minLength: 0,
        classNames: {
            open: 'is-open',
            empty: 'is-empty',
            cursor: 'is-active',
            suggestion: 'Typeahead-suggestion',
            selectable: 'Typeahead-selectable'
        }
    }, {
        source: engineWithDefaults,
        displayKey: 'title',
        templates: {
            suggestion: template,
            empty: empty
        }
    })
            .on('typeahead:asyncrequest', function () {
                jQuery('.Typeahead-spinner').show();
            })
            .on('typeahead:asynccancel typeahead:asyncreceive', function () {
                jQuery('.Typeahead-spinner').hide();
            }).on('typeahead:selected', function (e, suggestion, name) {
                jQuery(".auto_id_item").val(suggestion.nid);
    });

});

