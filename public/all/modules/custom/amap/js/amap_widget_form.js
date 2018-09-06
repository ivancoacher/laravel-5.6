/**
 * Add code to generate the map on page load.
 */
(function ($) {
    Drupal.behaviors.amapWidgetForm = {
        attach: function (context) {
            amapFieldPreviews();
            /*
             var selectLocation = function (event) {
             if (event.poi && event.poi.location) {
             map.setZoom(18);
             map.setCenter(event.poi.location);
             }
             };
             var getLocation = function (mapsEvent) {
             // $lat.val(mapsEvent.lnglat.getLat());
             // $lng.val(mapsEvent.lnglat.getLng());
             lat.value = mapsEvent.lnglat.getLat()
             lng.value = mapsEvent.lnglat.getLng()
             marker.setPosition(mapsEvent.lnglat);
             };

             // Get the settings for the map from the Drupal.settings object.
             // var fname = Drupal.settings.amap_widget_form['fname'];
             var delta = Drupal.settings.amap_widget_form_setting.delta;
             var key1 = 'lng' + delta;
             var lng_id = Drupal.settings.amap_widget_form_setting[key1];
             var key2 = 'lat' + delta;

             var lat_id = Drupal.settings.amap_widget_form_setting[key2];

             var key3 = 'search' + delta;
             var search_id = Drupal.settings.amap_widget_form_setting[key3];
             var lat = document.getElementById(lat_id);
             // var $lat = $("#edit-"+fname+"-und-0-lat");
             // var $lng = $("#edit-"+fname+"-und-0-lng");
             var lng = document.getElementById(lng_id);
             // var zoom = parseInt($("#edit-"+fname+"-und-0-zoom").val());
             // var zoom = parseInt($("#edit-"+fname+"-und-0-zoom").val());
             // var v1 = document.getElementById(lng_id).value;
             // try {
             var map_id = 'amap' + delta;
             var map_name = 'map' + delta;
             var map = new AMap.Map(map_name, {
             lang: 'zh_en',
             resizeEnable: true,
             zoom: 13,
             center: [lng.value, lat.value]
             });
             var marker = new AMap.Marker({
             map: map
             });

             toolBar = new AMap.ToolBar({
             visible: true
             });
             map.addControl(toolBar);

             map.on('click', getLocation);

             // AMap.plugin(['AMap.Autocomplete'],function(){
             //     var autoOptions = {
             //         // input: "edit-"+fname+"-und-0-search"
             //         input: search_id
             //     };
             //     var autoComplete = new AMap.Autocomplete(autoOptions);
             //     AMap.event.addListener(autoComplete, "select", selectLocation);
             // });

             // } catch(err) {
             //     console.log(err.toString());
             // }


             // map = new BMap.Map('baidumap_picker');
             // var point = new BMap.Point(lng, lat);
             // map.centerAndZoom(point, zoom);
             // var marker = new BMap.Marker(point);
             // map.addOverlay(marker);
             // map.addControl(new BMap.NavigationControl());
             // map.enableScrollWheelZoom(true);
             //
             // map.addEventListener("click", function(e){
             //     map.clearOverlays();
             //     var point = new BMap.Point(e.point.lng, e.point.lat);
             //     var new_marker = new BMap.Marker(point);  // create new marker
             //     map.addOverlay(new_marker);
             //
             //     document.getElementById("edit-"+fname+"-und-0-lat").value = e.point.lat;
             //     document.getElementById("edit-"+fname+"-und-0-lng").value = e.point.lng;
             // });
             //
             // map.addEventListener("zoomend", function(){
             //     document.getElementById("edit-"+fname+"-und-0-zoom").value = this.getZoom();
             // });
             */
        }
    };

    amapFieldPreviews = function (delta) {
        delta = typeof delta !== 'undefined' ? delta : -1;

        $('.amap-field-preview').each(function () {
            var data_delta = $(this).attr('data-delta');
            var data_field_id = $(this).attr('data-field-id');

            if (data_delta == delta || delta == -1) {
                try {
                    var data_lat = $('input[data-lat-delta="' + data_delta + '"][data-lat-field-id="' + data_field_id + '"]').val();
                    var data_lng = $('input[data-lng-delta="' + data_delta + '"][data-lng-field-id="' + data_field_id + '"]').val();
                    var search_input = $('input[data-search-delta="' + data_delta + '"][data-search-field-id="' + data_field_id + '"]');

                    if (data_zoom == null || data_zoom == '') {
                        var data_zoom = '13';
                    }

                    var amap_field_map = new AMap.Map(this, {
                        lang: 'zh_en',
                        resizeEnable: true,
                        zoom: data_zoom,
                        center: [data_lng, data_lat]
                    });
                    var marker = new AMap.Marker({
                        map: amap_field_map
                    });

                    toolBar = new AMap.ToolBar({
                        visible: true
                    });

                    amap_field_map.addControl(toolBar);
                    amap_field_map.setFitView();
                    amap_field_map.setZoom(16);

                    amap_field_map.on('click', function (event) {
                        var container = event.target.getContainer();
                        var lat = event.lnglat.getLat();
                        var lng = event.lnglat.getLng();
                        var data_delta = $(container).attr('data-delta');
                        var data_field_id = $(container).attr('data-field-id');

                        $('input[data-lat-delta="' + data_delta + '"][data-lat-field-id="' + data_field_id + '"]').val(lat);
                        $('input[data-lng-delta="' + data_delta + '"][data-lng-field-id="' + data_field_id + '"]').val(lng);

                        marker.setPosition(event.lnglat);
                    }, data_delta + data_field_id);


                    var search_id = search_input.attr('id');


                    AMap.plugin(['AMap.Autocomplete'], function () {
                        var autoOptions = {
                            input: search_id
                        };
                        var autoComplete = new AMap.Autocomplete(autoOptions);
                        AMap.event.addListener(autoComplete, "select", function (event) {
                            if (event.poi && event.poi.location) {
                                amap_field_map.setZoom(16);
                                amap_field_map.setCenter(event.poi.location);
                            }
                        });
                    });
                } catch (err) {
                    console.log(err.toString());
                }
            }
        });
    };
})(jQuery);