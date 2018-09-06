<?php
/**
 * @file
 * fs_features_all_contexts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function fs_features_all_contexts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'all_page';
  $context->description = '';
  $context->tag = 'Generality';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'header_top_ad',
          'weight' => '-10',
        ),
        'fs_city-fs_city_navigation' => array(
          'module' => 'fs_city',
          'delta' => 'fs_city_navigation',
          'region' => 'topbar',
          'weight' => '-10',
        ),
        'fs_base-fs_social_links' => array(
          'module' => 'fs_base',
          'delta' => 'fs_social_links',
          'region' => 'topbar',
          'weight' => '-9',
        ),
        'fs_search-fs_global_search' => array(
          'module' => 'fs_search',
          'delta' => 'fs_global_search',
          'region' => 'topbar',
          'weight' => '-8',
        ),
        'fs_menu-fs_menu_mobile_mega_menu' => array(
          'module' => 'fs_menu',
          'delta' => 'fs_menu_mobile_mega_menu',
          'region' => 'topbar',
          'weight' => '-7',
        ),
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'topbar',
          'weight' => '-6',
        ),
        'menu-menu-beijing-main-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-beijing-main-menu',
          'region' => 'megamenu',
          'weight' => '-10',
        ),
        'menu-menu-shanghai-main-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-shanghai-main-menu',
          'region' => 'megamenu',
          'weight' => '-9',
        ),
        'bean-downloaded-magazine' => array(
          'module' => 'bean',
          'delta' => 'downloaded-magazine',
          'region' => 'pre_footer',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Generality');
  $export['all_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_detail_apge_education';
  $context->description = '';
  $context->tag = 'Detail Page';
  $context->conditions = array(
    'fs_article_category' => array(
      'values' => array(
        7 => 7,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-education-detail-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh-education-detail-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
        'bean-sh-education-detail-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-education-detail-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-sh-education-detail-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-education-detail-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'fs_article-fs_most_read_and_pop' => array(
          'module' => 'fs_article',
          'delta' => 'fs_most_read_and_pop',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-sh-education-detail-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-education-detail-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'bean-sh-education-detail-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-education-detail-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Detail Page');
  $export['article_detail_apge_education'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_detail_food_drink';
  $context->description = '';
  $context->tag = 'Detail Page';
  $context->conditions = array(
    'fs_article_category' => array(
      'values' => array(
        2 => 2,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-food-detail-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh-food-detail-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
        'bean-sh-food-detail-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-food-detail-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-sh-food-detail-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-food-detail-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'fs_article-fs_most_read_and_pop' => array(
          'module' => 'fs_article',
          'delta' => 'fs_most_read_and_pop',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-sh-food-detail-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-food-detail-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'bean-sh-food-detail-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-food-detail-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Detail Page');
  $export['article_detail_food_drink'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_detail_page';
  $context->description = '';
  $context->tag = 'Detail Page';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'fs_article-fs_article_related_articles' => array(
          'module' => 'fs_article',
          'delta' => 'fs_article_related_articles',
          'region' => 'content',
          'weight' => '-9',
        ),
        'fs_article-fs_most_read_and_pop' => array(
          'module' => 'fs_article',
          'delta' => 'fs_most_read_and_pop',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Detail Page');
  $export['article_detail_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_detail_page_health_wellness';
  $context->description = '';
  $context->tag = 'Detail Page';
  $context->conditions = array(
    'fs_article_category' => array(
      'values' => array(
        5 => 5,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-health-detail-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh-health-detail-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
        'bean-sh-health-detail-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-health-detail-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-sh-health-detail-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-health-detail-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'fs_article-fs_most_read_and_pop' => array(
          'module' => 'fs_article',
          'delta' => 'fs_most_read_and_pop',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-sh-health-detail-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-health-detail-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'bean-sh-health-detail-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-health-detail-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Detail Page');
  $export['article_detail_page_health_wellness'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_detail_page_home_style';
  $context->description = '';
  $context->tag = 'Detail Page';
  $context->conditions = array(
    'fs_article_category' => array(
      'values' => array(
        10 => 10,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-home-detail-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh-home-detail-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
        'bean-sh-home-detail-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-home-detail-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-sh-home-detail-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-home-detail-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'fs_article-fs_most_read_and_pop' => array(
          'module' => 'fs_article',
          'delta' => 'fs_most_read_and_pop',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-sh-home-detail-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-home-detail-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'bean-sh-home-detail-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-home-detail-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Detail Page');
  $export['article_detail_page_home_style'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_detail_page_parenting';
  $context->description = '';
  $context->tag = 'Detail Page';
  $context->conditions = array(
    'fs_article_category' => array(
      'values' => array(
        6 => 6,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-parenting-detail-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh-parenting-detail-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
        'bean-sh-parenting-detail-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-parenting-detail-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-sh-parenting-detail-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-parenting-detail-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'fs_article-fs_most_read_and_pop' => array(
          'module' => 'fs_article',
          'delta' => 'fs_most_read_and_pop',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-sh-parenting-detail-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-parenting-detail-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'bean-sh-parenting-detail-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-parenting-detail-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Detail Page');
  $export['article_detail_page_parenting'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_detail_page_shopping';
  $context->description = '';
  $context->tag = 'Detail Page';
  $context->conditions = array(
    'fs_article_category' => array(
      'values' => array(
        9 => 9,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-shopping-detail-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh-shopping-detail-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
        'bean-sh-shopping-detail-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-shopping-detail-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-sh-shopping-detail-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-shopping-detail-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'fs_article-fs_most_read_and_pop' => array(
          'module' => 'fs_article',
          'delta' => 'fs_most_read_and_pop',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-sh-shopping-detail-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-shopping-detail-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'bean-sh-shopping-detail-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-shopping-detail-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Detail Page');
  $export['article_detail_page_shopping'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_detail_page_things_to_do';
  $context->description = '';
  $context->tag = 'Detail Page';
  $context->conditions = array(
    'fs_article_category' => array(
      'values' => array(
        4 => 4,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-things-detail-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh-things-detail-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
        'bean-sh-things-detail-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-things-detail-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-sh-things-detail-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-things-detail-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'fs_article-fs_most_read_and_pop' => array(
          'module' => 'fs_article',
          'delta' => 'fs_most_read_and_pop',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-sh-things-detail-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-things-detail-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'bean-sh-things-detail-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-things-detail-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Detail Page');
  $export['article_detail_page_things_to_do'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_list_community';
  $context->description = '';
  $context->tag = 'List Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'taxonomy/term/244' => 'taxonomy/term/244',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-shanghai-frontpage-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'shanghai-frontpage-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-shanghai-frontpage-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'shanghai-frontpage-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('List Page');
  $export['article_list_community'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_list_education';
  $context->description = '';
  $context->tag = 'List Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'education' => 'education',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh--education-list-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh--education-list-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bean-sh-education-list-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-education-list-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-sh-education-list-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-education-list-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean-sh-education-list-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-education-list-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-sh-education-list-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-education-list-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('List Page');
  $export['article_list_education'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_list_food';
  $context->description = '';
  $context->tag = 'List Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'food-drink' => 'food-drink',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-food-list-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh-food-list-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bean-sh-food-list-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-food-list-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-79',
        ),
        'bean-sh-food-list-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-food-list-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-78',
        ),
        'bean-sh-food-list-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-food-list-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-77',
        ),
        'bean-sh-food-list-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-food-list-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-76',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('List Page');
  $export['article_list_food'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_list_health';
  $context->description = '';
  $context->tag = 'List Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'health-wellness' => 'health-wellness',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-health-list-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh-health-list-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bean-sh-health-list-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-health-list-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-sh-health-list-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-health-list-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean-sh-health-list-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-health-list-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-sh-health-list-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-health-list-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('List Page');
  $export['article_list_health'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_list_home';
  $context->description = '';
  $context->tag = 'List Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'home-style' => 'home-style',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-home-list-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh-home-list-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bean-sh-home-list-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-home-list-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-sh-home-list-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-home-list-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean-sh-home-list-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-home-list-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-sh-home-list-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-home-list-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('List Page');
  $export['article_list_home'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_list_parenting';
  $context->description = '';
  $context->tag = 'List Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'parenting' => 'parenting',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-parenting-list-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh-parenting-list-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bean-sh-parenting-list-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-parenting-list-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-sh-parenting-list-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-parenting-list-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean-sh-parenting-list-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-parenting-list-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-sh-parenting-list-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-parenting-list-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('List Page');
  $export['article_list_parenting'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_list_shopping';
  $context->description = '';
  $context->tag = 'List Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'shopping' => 'shopping',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-shopping-list-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh-shopping-list-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bean-sh-shopping-list-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-shopping-list-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-sh-shopping-list-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-shopping-list-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean-sh-shopping-list-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-shopping-list-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-sh-shopping-list-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-shopping-list-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('List Page');
  $export['article_list_shopping'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_list_thingstodo';
  $context->description = '';
  $context->tag = 'List Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'things-to-do' => 'things-to-do',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-things-list-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh-things-list-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bean-sh-things-list-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-things-list-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-sh-things-list-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-things-list-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean-sh-things-list-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-things-list-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-sh-things-list-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-things-list-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('List Page');
  $export['article_list_thingstodo'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'beijing_front_page';
  $context->description = '';
  $context->tag = 'Front page for city';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/2' => 'node/2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-shanghai-frontpage-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'shanghai-frontpage-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'fs_article-fs_what_new' => array(
          'module' => 'fs_article',
          'delta' => 'fs_what_new',
          'region' => 'content',
          'weight' => '-9',
        ),
        'bean-shanghai-frontpage-728x90-two' => array(
          'module' => 'bean',
          'delta' => 'shanghai-frontpage-728x90-two',
          'region' => 'content',
          'weight' => '-8',
        ),
        'fs_article-fs_trending_now' => array(
          'module' => 'fs_article',
          'delta' => 'fs_trending_now',
          'region' => 'content',
          'weight' => '-7',
        ),
        'bean-shanghai-frontpage-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'shanghai-frontpage-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-shanghai-frontpage-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'shanghai-frontpage-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean-shanghai-frontpage-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'shanghai-frontpage-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-shanghai-frontpage-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'shanghai-frontpage-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'fs_event-fs_event_home_calendar' => array(
          'module' => 'fs_event',
          'delta' => 'fs_event_home_calendar',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'fs_gallery-fs_home_gallery' => array(
          'module' => 'fs_gallery',
          'delta' => 'fs_home_gallery',
          'region' => 'gallery_home',
          'weight' => '-10',
        ),
        'fs_article-fs_home_slider' => array(
          'module' => 'fs_article',
          'delta' => 'fs_home_slider',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Front page for city');
  $export['beijing_front_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'directory_details_page';
  $context->description = '';
  $context->tag = 'Detail Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'shanghai/directory/*' => 'shanghai/directory/*',
        'beijing/directory/*' => 'beijing/directory/*',
        'directory/*' => 'directory/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-directory-detail-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-directory-detail-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-sh-directory-detail-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-directory-detail-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean-sh-directory-detail-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-directory-detail-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-sh-directory-detail-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-directory-detail-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Detail Page');
  $export['directory_details_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'directory_list';
  $context->description = '';
  $context->tag = 'List Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'shanghai/directory' => 'shanghai/directory',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-directory-list-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-directory-list-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-sh-directory-list-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-directory-list-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean-sh-directory-list-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-directory-list-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-sh-directory-list-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-directory-list-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
    'metatag_context_reaction' => array(
      'metatags' => array(
        'und' => array(
          'title' => array(
            'value' => 'Other directories',
            'default' => '[current-page:title] | [current-page:pager][site:name]',
          ),
          'description' => array(
            'value' => 'Find out what you want and need. Our directory has everything. ',
            'default' => '',
          ),
          'abstract' => array(
            'value' => '',
            'default' => '',
          ),
          'keywords' => array(
            'value' => '',
            'default' => '',
          ),
          'robots' => array(
            'value' => array(
              'index' => 'index',
              'follow' => 'follow',
              'noindex' => 0,
              'nofollow' => 0,
              'noarchive' => 0,
              'nosnippet' => 0,
              'noodp' => 0,
              'noydir' => 0,
              'noimageindex' => 0,
              'notranslate' => 0,
            ),
            'default' => array(
              'index' => 'index',
              'follow' => 'follow',
              'noindex' => 0,
              'nofollow' => 0,
              'noarchive' => 0,
              'nosnippet' => 0,
              'noodp' => 0,
              'noydir' => 0,
              'noimageindex' => 0,
              'notranslate' => 0,
            ),
          ),
          'news_keywords' => array(
            'value' => '',
            'default' => '',
          ),
          'standout' => array(
            'value' => '',
            'default' => '',
          ),
          'rating' => array(
            'value' => '',
            'default' => '',
          ),
          'referrer' => array(
            'value' => '',
            'default' => '',
          ),
          'generator' => array(
            'value' => 'Drupal 7 (http://drupal.org)',
            'default' => 'Drupal 7 (http://drupal.org)',
          ),
          'rights' => array(
            'value' => '',
            'default' => '',
          ),
          'image_src' => array(
            'value' => '',
            'default' => '',
          ),
          'canonical' => array(
            'value' => '[current-page:url:absolute]',
            'default' => '[current-page:url:absolute]',
          ),
          'shortlink' => array(
            'value' => '[current-page:url:unaliased]',
            'default' => '[current-page:url:unaliased]',
          ),
          'publisher' => array(
            'value' => '',
            'default' => '',
          ),
          'author' => array(
            'value' => '',
            'default' => '',
          ),
          'original-source' => array(
            'value' => '',
            'default' => '',
          ),
          'prev' => array(
            'value' => '',
            'default' => '',
          ),
          'next' => array(
            'value' => '',
            'default' => '',
          ),
          'content-language' => array(
            'value' => '',
            'default' => '',
          ),
          'geo.position' => array(
            'value' => '',
            'default' => '',
          ),
          'geo.placename' => array(
            'value' => '',
            'default' => '',
          ),
          'geo.region' => array(
            'value' => '',
            'default' => '',
          ),
          'icbm' => array(
            'value' => '',
            'default' => '',
          ),
          'refresh' => array(
            'value' => '',
            'default' => '',
          ),
          'revisit-after' => array(
            'value' => '',
            'period' => '',
            'default' => '',
          ),
          'pragma' => array(
            'value' => '',
            'default' => '',
          ),
          'cache-control' => array(
            'value' => '',
            'default' => '',
          ),
          'expires' => array(
            'value' => '',
            'default' => '',
          ),
        ),
      ),
      'metatag_admin' => 0,
      'weight' => '0',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('List Page');
  $export['directory_list'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'education_sub_category';
  $context->description = '';
  $context->tag = 'Sub Category';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'education/*' => 'education/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh--education-list-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh--education-list-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bean-sh-education-list-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-education-list-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-79',
        ),
        'bean-sh-education-list-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-education-list-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-78',
        ),
        'bean-sh-education-list-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-education-list-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-77',
        ),
        'bean-sh-education-list-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-education-list-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-76',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sub Category');
  $export['education_sub_category'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'event_detail_page';
  $context->description = '';
  $context->tag = 'Detail Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'shanghai/event/*' => 'shanghai/event/*',
        'beijing/event/*' => 'beijing/event/*',
        'event/*' => 'event/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-event-detail-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-event-detail-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-sh-event-detail-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-event-detail-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean-sh-event-detail-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-event-detail-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-sh-event-detail-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-event-detail-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Detail Page');
  $export['event_detail_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events_list';
  $context->description = '';
  $context->tag = 'List Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'shanghai/event' => 'shanghai/event',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-event-list-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-event-list-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-sh-event-list-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-event-list-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean-sh-event-list-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-event-list-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-sh-event-list-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-event-list-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
    'metatag_context_reaction' => array(
      'metatags' => array(
        'und' => array(
          'title' => array(
            'value' => 'Events in Shanghai',
            'default' => '[current-page:title] | [current-page:pager][site:name]',
          ),
          'description' => array(
            'value' => 'Ready for family fun and the best family events Shanghai has to offer? Plan ahead to give your family unforgettable memory. See what\'s happening in Shanghai for the whole family!',
            'default' => '',
          ),
          'abstract' => array(
            'value' => '',
            'default' => '',
          ),
          'keywords' => array(
            'value' => '',
            'default' => '',
          ),
          'robots' => array(
            'value' => array(
              'index' => 'index',
              'follow' => 'follow',
              'noindex' => 0,
              'nofollow' => 0,
              'noarchive' => 0,
              'nosnippet' => 0,
              'noodp' => 0,
              'noydir' => 0,
              'noimageindex' => 0,
              'notranslate' => 0,
            ),
            'default' => array(
              'index' => 'index',
              'follow' => 'follow',
              'noindex' => 0,
              'nofollow' => 0,
              'noarchive' => 0,
              'nosnippet' => 0,
              'noodp' => 0,
              'noydir' => 0,
              'noimageindex' => 0,
              'notranslate' => 0,
            ),
          ),
          'news_keywords' => array(
            'value' => '',
            'default' => '',
          ),
          'standout' => array(
            'value' => '',
            'default' => '',
          ),
          'rating' => array(
            'value' => '',
            'default' => '',
          ),
          'referrer' => array(
            'value' => '',
            'default' => '',
          ),
          'generator' => array(
            'value' => 'Drupal 7 (http://drupal.org)',
            'default' => 'Drupal 7 (http://drupal.org)',
          ),
          'rights' => array(
            'value' => '',
            'default' => '',
          ),
          'image_src' => array(
            'value' => '',
            'default' => '',
          ),
          'canonical' => array(
            'value' => '[current-page:url:absolute]',
            'default' => '[current-page:url:absolute]',
          ),
          'shortlink' => array(
            'value' => '[current-page:url:unaliased]',
            'default' => '[current-page:url:unaliased]',
          ),
          'publisher' => array(
            'value' => '',
            'default' => '',
          ),
          'author' => array(
            'value' => '',
            'default' => '',
          ),
          'original-source' => array(
            'value' => '',
            'default' => '',
          ),
          'prev' => array(
            'value' => '',
            'default' => '',
          ),
          'next' => array(
            'value' => '',
            'default' => '',
          ),
          'content-language' => array(
            'value' => '',
            'default' => '',
          ),
          'geo.position' => array(
            'value' => '',
            'default' => '',
          ),
          'geo.placename' => array(
            'value' => '',
            'default' => '',
          ),
          'geo.region' => array(
            'value' => '',
            'default' => '',
          ),
          'icbm' => array(
            'value' => '',
            'default' => '',
          ),
          'refresh' => array(
            'value' => '',
            'default' => '',
          ),
          'revisit-after' => array(
            'value' => '',
            'period' => '',
            'default' => '',
          ),
          'pragma' => array(
            'value' => '',
            'default' => '',
          ),
          'cache-control' => array(
            'value' => '',
            'default' => '',
          ),
          'expires' => array(
            'value' => '',
            'default' => '',
          ),
        ),
      ),
      'metatag_admin' => 0,
      'weight' => '0',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('List Page');
  $export['events_list'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'food_drink_sub_category';
  $context->description = '';
  $context->tag = 'Sub Category';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'food-drink/*' => 'food-drink/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-food-list-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh-food-list-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bean-sh-food-list-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-food-list-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-79',
        ),
        'bean-sh-food-list-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-food-list-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-78',
        ),
        'bean-sh-food-list-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-food-list-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-77',
        ),
        'bean-sh-food-list-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-food-list-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-76',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sub Category');
  $export['food_drink_sub_category'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'health_sub_category';
  $context->description = '';
  $context->tag = 'Sub Category';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'health-wellness/*' => 'health-wellness/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-health-list-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh-health-list-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bean-sh-health-list-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-health-list-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-79',
        ),
        'bean-sh-health-list-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-health-list-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-78',
        ),
        'bean-sh-health-list-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-health-list-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-77',
        ),
        'bean-sh-health-list-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-health-list-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-76',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sub Category');
  $export['health_sub_category'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home_style_sub_category';
  $context->description = '';
  $context->tag = 'Sub Category';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'home-style/*' => 'home-style/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-home-list-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh-home-list-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bean-sh-home-list-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-home-list-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-79',
        ),
        'bean-sh-home-list-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-home-list-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-78',
        ),
        'bean-sh-home-list-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-home-list-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-77',
        ),
        'bean-sh-home-list-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-home-list-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-76',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sub Category');
  $export['home_style_sub_category'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'parenting_sub_category';
  $context->description = '';
  $context->tag = 'Sub Category';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'parenting/*' => 'parenting/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-parenting-list-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh-parenting-list-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bean-sh-parenting-list-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-parenting-list-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-79',
        ),
        'bean-sh-parenting-list-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-parenting-list-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-78',
        ),
        'bean-sh-parenting-list-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-parenting-list-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-77',
        ),
        'bean-sh-parenting-list-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-parenting-list-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-76',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sub Category');
  $export['parenting_sub_category'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'profile_editor';
  $context->description = '';
  $context->tag = 'Profile';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'profile-editor/*' => 'profile-editor/*',
        '~profile-editor/*/*' => '~profile-editor/*/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'fs_user_editor-fs_user_editor_related_articles' => array(
          'module' => 'fs_user_editor',
          'delta' => 'fs_user_editor_related_articles',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Profile');
  $export['profile_editor'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'school_compare_page';
  $context->description = '';
  $context->tag = 'Detail Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'shanghai-schools/compare' => 'shanghai-schools/compare',
        'schools/compare' => 'schools/compare',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-school-compare-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-school-compare-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-sh-school-compare-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-school-compare-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean-sh-school-compare-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-school-compare-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-sh-school-compare-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-school-compare-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
    'metatag_context_reaction' => array(
      'metatags' => array(
        'und' => array(
          'title' => array(
            'value' => 'School Comparator',
            'default' => '[current-page:title] | [current-page:pager][site:name]',
          ),
          'description' => array(
            'value' => '',
            'default' => '',
          ),
          'abstract' => array(
            'value' => '',
            'default' => '',
          ),
          'keywords' => array(
            'value' => '',
            'default' => '',
          ),
          'robots' => array(
            'value' => array(
              'index' => 'index',
              'follow' => 'follow',
              'noindex' => 0,
              'nofollow' => 0,
              'noarchive' => 0,
              'nosnippet' => 0,
              'noodp' => 0,
              'noydir' => 0,
              'noimageindex' => 0,
              'notranslate' => 0,
            ),
            'default' => array(
              'index' => 'index',
              'follow' => 'follow',
              'noindex' => 0,
              'nofollow' => 0,
              'noarchive' => 0,
              'nosnippet' => 0,
              'noodp' => 0,
              'noydir' => 0,
              'noimageindex' => 0,
              'notranslate' => 0,
            ),
          ),
          'news_keywords' => array(
            'value' => '',
            'default' => '',
          ),
          'standout' => array(
            'value' => '',
            'default' => '',
          ),
          'rating' => array(
            'value' => '',
            'default' => '',
          ),
          'referrer' => array(
            'value' => '',
            'default' => '',
          ),
          'generator' => array(
            'value' => 'Drupal 7 (http://drupal.org)',
            'default' => 'Drupal 7 (http://drupal.org)',
          ),
          'rights' => array(
            'value' => '',
            'default' => '',
          ),
          'image_src' => array(
            'value' => '',
            'default' => '',
          ),
          'canonical' => array(
            'value' => '[current-page:url:absolute]',
            'default' => '[current-page:url:absolute]',
          ),
          'shortlink' => array(
            'value' => '[current-page:url:unaliased]',
            'default' => '[current-page:url:unaliased]',
          ),
          'publisher' => array(
            'value' => '',
            'default' => '',
          ),
          'author' => array(
            'value' => '',
            'default' => '',
          ),
          'original-source' => array(
            'value' => '',
            'default' => '',
          ),
          'prev' => array(
            'value' => '',
            'default' => '',
          ),
          'next' => array(
            'value' => '',
            'default' => '',
          ),
          'content-language' => array(
            'value' => '',
            'default' => '',
          ),
          'geo.position' => array(
            'value' => '',
            'default' => '',
          ),
          'geo.placename' => array(
            'value' => '',
            'default' => '',
          ),
          'geo.region' => array(
            'value' => '',
            'default' => '',
          ),
          'icbm' => array(
            'value' => '',
            'default' => '',
          ),
          'refresh' => array(
            'value' => '',
            'default' => '',
          ),
          'revisit-after' => array(
            'value' => '',
            'period' => '',
            'default' => '',
          ),
          'pragma' => array(
            'value' => '',
            'default' => '',
          ),
          'cache-control' => array(
            'value' => '',
            'default' => '',
          ),
          'expires' => array(
            'value' => '',
            'default' => '',
          ),
        ),
      ),
      'metatag_admin' => 0,
      'weight' => '0',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Detail Page');
  $export['school_compare_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'school_details_page';
  $context->description = '';
  $context->tag = 'Detail Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'shanghai-schools/*' => 'shanghai-schools/*',
        'beijing/school/*' => 'beijing/school/*',
        '~shanghai-schools/compare' => '~shanghai-schools/compare',
        '~beijing/school/compare' => '~beijing/school/compare',
        'school/*' => 'school/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bean-sh-school-detail-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-school-detail-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-sh-school-detail-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-school-detail-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean-sh-school-detail-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-school-detail-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-sh-school-detail-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-school-detail-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Detail Page');
  $export['school_details_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'school_list';
  $context->description = '';
  $context->tag = 'List Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'shanghai-schools' => 'shanghai-schools',
        '/school' => '/school',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-school-list-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-school-list-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-sh-school-list-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-school-list-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean-sh-school-list-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-school-list-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-sh-school-list-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-school-list-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
    'metatag_context_reaction' => array(
      'metatags' => array(
        'und' => array(
          'title' => array(
            'value' => 'Schools in Shanghai',
            'default' => '[current-page:title] | [current-page:pager][site:name]',
          ),
          'description' => array(
            'value' => 'Find the right schools in Shanghai for your kids with Shanghai Family\'s school comparator tool!',
            'default' => '',
          ),
          'abstract' => array(
            'value' => '',
            'default' => '',
          ),
          'keywords' => array(
            'value' => '',
            'default' => '',
          ),
          'robots' => array(
            'value' => array(
              'index' => 'index',
              'follow' => 'follow',
              'noindex' => 0,
              'nofollow' => 0,
              'noarchive' => 0,
              'nosnippet' => 0,
              'noodp' => 0,
              'noydir' => 0,
              'noimageindex' => 0,
              'notranslate' => 0,
            ),
            'default' => array(
              'index' => 'index',
              'follow' => 'follow',
              'noindex' => 0,
              'nofollow' => 0,
              'noarchive' => 0,
              'nosnippet' => 0,
              'noodp' => 0,
              'noydir' => 0,
              'noimageindex' => 0,
              'notranslate' => 0,
            ),
          ),
          'news_keywords' => array(
            'value' => '',
            'default' => '',
          ),
          'standout' => array(
            'value' => '',
            'default' => '',
          ),
          'rating' => array(
            'value' => '',
            'default' => '',
          ),
          'referrer' => array(
            'value' => '',
            'default' => '',
          ),
          'generator' => array(
            'value' => 'Drupal 7 (http://drupal.org)',
            'default' => 'Drupal 7 (http://drupal.org)',
          ),
          'rights' => array(
            'value' => '',
            'default' => '',
          ),
          'image_src' => array(
            'value' => '',
            'default' => '',
          ),
          'canonical' => array(
            'value' => '[current-page:url:absolute]',
            'default' => '[current-page:url:absolute]',
          ),
          'shortlink' => array(
            'value' => '[current-page:url:unaliased]',
            'default' => '[current-page:url:unaliased]',
          ),
          'publisher' => array(
            'value' => '',
            'default' => '',
          ),
          'author' => array(
            'value' => '',
            'default' => '',
          ),
          'original-source' => array(
            'value' => '',
            'default' => '',
          ),
          'prev' => array(
            'value' => '',
            'default' => '',
          ),
          'next' => array(
            'value' => '',
            'default' => '',
          ),
          'content-language' => array(
            'value' => '',
            'default' => '',
          ),
          'geo.position' => array(
            'value' => '',
            'default' => '',
          ),
          'geo.placename' => array(
            'value' => '',
            'default' => '',
          ),
          'geo.region' => array(
            'value' => '',
            'default' => '',
          ),
          'icbm' => array(
            'value' => '',
            'default' => '',
          ),
          'refresh' => array(
            'value' => '',
            'default' => '',
          ),
          'revisit-after' => array(
            'value' => '',
            'period' => '',
            'default' => '',
          ),
          'pragma' => array(
            'value' => '',
            'default' => '',
          ),
          'cache-control' => array(
            'value' => '',
            'default' => '',
          ),
          'expires' => array(
            'value' => '',
            'default' => '',
          ),
        ),
      ),
      'metatag_admin' => 0,
      'weight' => '0',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('List Page');
  $export['school_list'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'shanghai_front_page';
  $context->description = '';
  $context->tag = 'Front page for city';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/1' => 'node/1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-shanghai-main-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-shanghai-main-menu',
          'region' => 'megamenu',
          'weight' => '-10',
        ),
        'bean-shanghai-frontpage-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'shanghai-frontpage-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'fs_article-fs_what_new' => array(
          'module' => 'fs_article',
          'delta' => 'fs_what_new',
          'region' => 'content',
          'weight' => '-9',
        ),
        'bean-shanghai-frontpage-728x90-two' => array(
          'module' => 'bean',
          'delta' => 'shanghai-frontpage-728x90-two',
          'region' => 'content',
          'weight' => '-8',
        ),
        'fs_article-fs_trending_now' => array(
          'module' => 'fs_article',
          'delta' => 'fs_trending_now',
          'region' => 'content',
          'weight' => '-7',
        ),
        'fs_event-fs_event_home_calendar' => array(
          'module' => 'fs_event',
          'delta' => 'fs_event_home_calendar',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-shanghai-frontpage-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'shanghai-frontpage-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean-shanghai-frontpage-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'shanghai-frontpage-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-shanghai-frontpage-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'shanghai-frontpage-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'bean-shanghai-frontpage-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'shanghai-frontpage-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'fs_user_editor-fs_user_editor_meet_editors' => array(
          'module' => 'fs_user_editor',
          'delta' => 'fs_user_editor_meet_editors',
          'region' => 'gallery_home',
          'weight' => '-10',
        ),
        'fs_gallery-fs_home_gallery' => array(
          'module' => 'fs_gallery',
          'delta' => 'fs_home_gallery',
          'region' => 'gallery_home',
          'weight' => '-9',
        ),
        'fs_article-fs_home_slider' => array(
          'module' => 'fs_article',
          'delta' => 'fs_home_slider',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'fs_newsletter-fs_newsletter_subscribe' => array(
          'module' => 'fs_newsletter',
          'delta' => 'fs_newsletter_subscribe',
          'region' => 'newsletter',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Front page for city');
  $export['shanghai_front_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'shopping_sub_category';
  $context->description = '';
  $context->tag = 'Sub Category';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'shopping/*' => 'shopping/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-shopping-list-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh-shopping-list-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bean-sh-shopping-list-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-shopping-list-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-79',
        ),
        'bean-sh-shopping-list-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-shopping-list-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-78',
        ),
        'bean-sh-shopping-list-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-shopping-list-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-77',
        ),
        'bean-sh-shopping-list-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-shopping-list-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-76',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sub Category');
  $export['shopping_sub_category'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'things_to_do_sub_category';
  $context->description = '';
  $context->tag = 'Sub Category';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'things-to-do/*' => 'things-to-do/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sh-things-list-728x90-one' => array(
          'module' => 'bean',
          'delta' => 'sh-things-list-728x90-one',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bean-sh-things-list-300x600-one' => array(
          'module' => 'bean',
          'delta' => 'sh-things-list-300x600-one',
          'region' => 'sidebar_second',
          'weight' => '-79',
        ),
        'bean-sh-things-list-300x300-one' => array(
          'module' => 'bean',
          'delta' => 'sh-things-list-300x300-one',
          'region' => 'sidebar_second',
          'weight' => '-78',
        ),
        'bean-sh-things-list-300x300-two' => array(
          'module' => 'bean',
          'delta' => 'sh-things-list-300x300-two',
          'region' => 'sidebar_second',
          'weight' => '-77',
        ),
        'bean-sh-things-list-300x600-two' => array(
          'module' => 'bean',
          'delta' => 'sh-things-list-300x600-two',
          'region' => 'sidebar_second',
          'weight' => '-76',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sub Category');
  $export['things_to_do_sub_category'] = $context;

  return $export;
}
