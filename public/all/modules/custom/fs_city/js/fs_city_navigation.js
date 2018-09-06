(function ($) {
    Drupal.behaviors.cwCity = {
        attach: function (context, settings) {
            $('select#fs-city-navigation').change(function(){
                var url = $("select#fs-city-navigation :selected").attr('data-url')
                window.location.href = url;
            })
        }
    };
})(jQuery);