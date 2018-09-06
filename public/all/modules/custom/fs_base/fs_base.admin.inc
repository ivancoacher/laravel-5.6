<?php

function fs_base_social_settings_form($form, &$form_state) {
  $form['fs_base_social_facebook'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook'),
    '#default_value' => variable_get('fs_base_social_facebook', ''),
  );

  $form['fs_base_social_twitter'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter'),
    '#default_value' => variable_get('fs_base_social_twitter', ''),
  );

  $form['fs_base_social_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#default_value' => variable_get('fs_base_social_email'),
  );

  $form['fs_base_social_weichat'] = array(
    '#type' => 'textfield',
    '#title' => t('Weichat'),
    '#default_value' => variable_get('fs_base_social_weichat'),
  );

  $form = system_settings_form($form);

  return $form;
}