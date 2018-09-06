<?php
/**
 * @file
 * fs_features_bean_download_magazine.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function fs_features_bean_download_magazine_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_guide_one|bean|download_magazine|form';
  $field_group->group_name = 'group_guide_one';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'download_magazine';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_section_two';
  $field_group->data = array(
    'label' => 'Guide one',
    'weight' => '44',
    'children' => array(
      0 => 'field_guide_one_back_cover',
      1 => 'field_guide_one_file',
      2 => 'field_guide_one_thumb',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Guide one',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-guide-one field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_guide_one|bean|download_magazine|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_guide_two|bean|download_magazine|form';
  $field_group->group_name = 'group_guide_two';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'download_magazine';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_section_two';
  $field_group->data = array(
    'label' => 'Guide two',
    'weight' => '45',
    'children' => array(
      0 => 'field_guide_two_back_cover',
      1 => 'field_guide_two_file',
      2 => 'field_guide_two_thumb',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-guide-two field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_guide_two|bean|download_magazine|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_magazine_one|bean|download_magazine|form';
  $field_group->group_name = 'group_magazine_one';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'download_magazine';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_section_one';
  $field_group->data = array(
    'label' => 'Magazine One',
    'weight' => '6',
    'children' => array(
      0 => 'field_magazine_one_file',
      1 => 'field_magazine_one_thumb',
      2 => 'field_magazine_one_back_cover',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-magazine-one field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_magazine_one|bean|download_magazine|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_magazine_two|bean|download_magazine|form';
  $field_group->group_name = 'group_magazine_two';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'download_magazine';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_section_one';
  $field_group->data = array(
    'label' => 'Magazine Two',
    'weight' => '7',
    'children' => array(
      0 => 'field_magazine_two_file',
      1 => 'field_magazine_two_thumb',
      2 => 'field_magazine_two_back_cover',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-magazine-two field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_magazine_two|bean|download_magazine|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_section_one|bean|download_magazine|form';
  $field_group->group_name = 'group_section_one';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'download_magazine';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Download the latest issues',
    'weight' => '2',
    'children' => array(
      0 => 'group_magazine_one',
      1 => 'group_magazine_two',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-section-one field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_section_one|bean|download_magazine|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_section_two|bean|download_magazine|form';
  $field_group->group_name = 'group_section_two';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'download_magazine';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Download the guide',
    'weight' => '3',
    'children' => array(
      0 => 'group_guide_one',
      1 => 'group_guide_two',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-section-two field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_section_two|bean|download_magazine|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Download the guide');
  t('Download the latest issues');
  t('Guide one');
  t('Guide two');
  t('Magazine One');
  t('Magazine Two');

  return $field_groups;
}
