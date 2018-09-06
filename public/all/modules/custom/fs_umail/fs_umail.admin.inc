<?php

function fs_base_umail_settings_form($form, &$form_state) {
    $form['fs_umail_username'] = [
        '#type' => 'textfield',
        '#title' => t('U-Mail Username'),
        '#default_value' => variable_get('fs_umail_username', ''),
    ];
    $form['fs_umail_password'] = [
        '#type' => 'textfield',
        '#title' => t('U-Mail Password'),
        '#default_value' => variable_get('fs_umail_password', ''),
    ];
    $form['fs_umail_list_id'] = [
        '#type' => 'textfield',
        '#title' => t('U-Mail List Id'),
        '#default_value' => variable_get('fs_umail_list_id', ''),
    ];
    $form['fs_umail_action_list_id'] = [
        '#type' => 'textfield',
        '#title' => t('U-Mail List Id Action'),
        '#default_value' => variable_get('fs_umail_action_list_id', ''),
    ];
    $form['fs_umail_newsletter_confirmation_tlp_id'] = [
        '#type' => 'textfield',
        '#title' => t('U-Mail Template Newsletter confirmation Id '),
        '#default_value' => variable_get('fs_umail_newsletter_confirmation_tlp_id', ''),
    ];
    $form['fs_umail_forget_password_tlp_id'] = [
    '#type' => 'textfield',
    '#title' => t('U-Mail Template Forgot Password Id '),
    '#default_value' => variable_get('fs_umail_forget_password_tlp_id', ''),
    ];
  $form['fs_umail_account_confirmation_tlp_id'] = [
    '#type' => 'textfield',
    '#title' => t('U-Mail Template Account Confirmation  Id '),
    '#default_value' => variable_get('fs_umail_account_confirmation_tlp_id', ''),
  ];
    $form['fs_umail_registration_tlp_id'] = [
     '#type' => 'textfield',
     '#title' => t('U-Mail Template Registration  Id '),
     '#default_value' => variable_get('fs_umail_registration_tlp_id', ''),
    ];

    $form = system_settings_form($form);

    return $form;
}