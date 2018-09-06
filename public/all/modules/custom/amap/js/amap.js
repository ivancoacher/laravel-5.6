/**
 * Add code to generate the map on page load.
 */
(function ($) {
    Drupal.behaviors.amapDisplay = {
        attach: function (context) {
            var maps = Drupal.settings.amap;
            for (var map_id in Drupal.settings.amap) {
                var map_settings = maps[map_id].map;
                var markers = maps[map_id].markers;

                var map = new AMap.Map(map_id, {
                    lang: 'en',
                    resizeEnable: true,
                    scrollWheel: false,
                    level: map_settings.zoom 
                });

                toolBar = new AMap.ToolBar({
                    visible: true
                }),
                map.addControl(toolBar);
                $('#' + map_id).css({width: map_settings.width, height: map_settings.height});

                for (var i in markers) {
                    var marker =
                    new AMap.Marker({
                        title: markers[i].name,
                        //content: markers[i].description,
                        position: new AMap.LngLat(markers[i].lng, markers[i].lat),
                        map: map
                    });
                }
                map.setFitView();
                map.setZoom(map_settings.zoom);

            }
        }
    };
})(jQuery);