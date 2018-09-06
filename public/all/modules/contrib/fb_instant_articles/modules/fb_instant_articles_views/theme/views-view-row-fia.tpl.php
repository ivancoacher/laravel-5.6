<?php

/**
 * @file
 * Default theme implementation to display an item in a Facebook Instant
 * Articles feed.
 *
 * Available variables:
 * - $title: RSS item title.
 * - $link: canonical URL for this item.
 * - $content: the fully rendered instant article markup.
 * - $item_elements: additional optional <item> child tags.
 *
 * @see template_preprocess_views_view_row_fia()
 *
 * @ingroup themeable
 */
?>
<item>
  <title><?php print $title; ?></title>
  <link><?php print $link; ?></link>
  <content:encoded>
    <![CDATA[
    <!-- Article body started -->
    <!doctype html>
      <html lang="en" prefix="op: http://media.facebook.com/op#">
        <head>
          <meta charset="utf-8">
          <link rel="canonical" href="<?php print $link; ?>">
          <meta property="op:markup_version" content="v1.0">
        </head>
        <body>
          <figure class="op-tracker">
              <iframe>
                <script>
                (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
                (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
                m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
                })(window,document,'script','https://www.google-analytics.com/analytics.js','ga');

                ga('create', 'UA-464050-49', 'auto');
                ga('send', 'pageview');

                </script>
              </iframe>
          </figure>
          <article>
            <header>
                <h1><?php print $title; ?></h1>
                <time class="op-published" datetime="<?php print $date; ?>"></time>
                <figure><img src="<?php print $main_image; ?>"/></figure>
                <?php
                    if($subTitle){
                      print '<h2>'.$subTitle.'</h2>';
                    }
                ?>
                <address>
                  <a><?php print $author; ?></a>
                </address>
            </header>
        <?php
          print $content;
        ?>
      </article>
        </body>
        </html>
    ]]>
  </content:encoded>
  <?php print $item_elements; ?>
</item>
