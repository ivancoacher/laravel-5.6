<?php

function fs_base_sailthru_settings_form($form, &$form_state) {
  $form['fs_sailthru_key'] = [
    '#type' => 'textfield',
    '#title' => t('Key'),
    '#default_value' => variable_get('fs_sailthru_key', ''),
  ];

  $form['fs_sailthru_secret'] = [
    '#type' => 'textfield',
    '#title' => t('Secret'),
    '#default_value' => variable_get('fs_sailthru_secret', ''),
  ];


  $form = system_settings_form($form);

  return $form;
}