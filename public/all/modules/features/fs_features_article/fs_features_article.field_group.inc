<?php
/**
 * @file
 * fs_features_article.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function fs_features_article_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editor_pick_section|node|article|form';
  $field_group->group_name = 'group_editor_pick_section';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Editor\'s pick Section',
    'weight' => '17',
    'children' => array(
      0 => 'field_article_editor_pick_push',
      1 => 'field_article_editor_pick_pin',
      2 => 'field_article_editor_pick_weight',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Editor\'s pick Section',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-editor-pick-section field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_editor_pick_section|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_most_popular_section|node|article|form';
  $field_group->group_name = 'group_most_popular_section';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Most Popular Section',
    'weight' => '19',
    'children' => array(
      0 => 'field_article_most_pop_push',
      1 => 'field_article_most_pop_pin',
      2 => 'field_article_most_pop_weight',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Most Popular Section',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-most-popular-section field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_most_popular_section|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_most_read_section|node|article|form';
  $field_group->group_name = 'group_most_read_section';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Most Read Section',
    'weight' => '18',
    'children' => array(
      0 => 'field_article_most_read_push',
      1 => 'field_article_most_read_pin',
      2 => 'field_article_most_read_weight',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Most Read Section',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-most-read-section field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_most_read_section|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_others_section|node|article|form';
  $field_group->group_name = 'group_others_section';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Others ',
    'weight' => '21',
    'children' => array(
      0 => 'field_article_win',
      1 => 'field_article_sponsored',
      2 => 'field_qr_code_pk',
      3 => 'field_qr_code_sf',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Others ',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-others-section field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_others_section|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_slider_section|node|article|form';
  $field_group->group_name = 'group_slider_section';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Slider Section',
    'weight' => '16',
    'children' => array(
      0 => 'field_article_slider_push',
      1 => 'field_article_slider_pin',
      2 => 'field_article_slider_weight',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Slider Section',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-slider-section field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_slider_section|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_trending_now_section|node|article|form';
  $field_group->group_name = 'group_trending_now_section';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Trending Now',
    'weight' => '20',
    'children' => array(
      0 => 'field_article_trending_push',
      1 => 'field_article_trending_pin',
      2 => 'field_article_trending_weight',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Trending Now',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-trending-now-section field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_trending_now_section|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_what_new|node|article|form';
  $field_group->group_name = 'group_what_new';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'What\'s New',
    'weight' => '22',
    'children' => array(
      0 => 'field_article_what_new',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'What\'s New',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-what-new field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_what_new|node|article|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Editor\'s pick Section');
  t('Most Popular Section');
  t('Most Read Section');
  t('Others ');
  t('Slider Section');
  t('Trending Now');
  t('What\'s New');

  return $field_groups;
}
