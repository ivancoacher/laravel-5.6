(function ($) {
    $(document).ready(function() {
        $.ajax({
            type: "POST",
            cache: false,
            url: Drupal.settings.fs_article_point.url,
            data: Drupal.settings.fs_article_point.data
        });
    });
})(jQuery);
