<?php

function amap_admin_settings() {
    $form['amap_api_key'] = array(
        '#type' => 'textfield',
        '#title' => t('AMap API Key'),
        '#default_value' => variable_get('amap_api_key', ''),
        '#description' => t('AMap API key to be created at http://lbs.amap.com/dev.'),
        '#required' => TRUE,
    );

    return system_settings_form($form);
}