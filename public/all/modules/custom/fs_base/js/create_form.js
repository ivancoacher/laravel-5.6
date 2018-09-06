
jQuery(document).ready(function () {
    var root = jQuery(".section_add");
    root.find('#edit-field-nearest-metro-station-und').selectpicker({
        liveSearch: true,
        size: 6
    });
    root.find('#edit-field-neighborhood-und').selectpicker({
        liveSearch: true,
        size: 6
    });
    
    
});