<?php

use Endroid\QrCode\QrCode;

function fs_generate_qrcode($type, $id) {
  $text = '';
  switch ($type) {
    case 'node':
      $text = url('node/' . $id, ['absolute' => TRUE]);
      break;
  }

  $file_path = drupal_get_path('module', 'fs_qrcode');
  $qrCode = new QrCode();
  $qrCode
    ->setText($text)
    ->setSize(100)
    ->setPadding(5)
    ->setErrorCorrection('high')
    ->setForegroundColor(array('r' => 0, 'g' => 0, 'b' => 0, 'a' => 0))
    ->setBackgroundColor(array('r' => 255, 'g' => 255, 'b' => 255, 'a' => 0))
    // ->setLabel('Scan the code')
    // ->setLabelFontSize(16)
    ->setLogo($file_path . '/cityweekend-logo.png')
    ->setLogoSize(20)
    ->setImageType(QrCode::IMAGE_TYPE_PNG);

  // now we can directly output the qrcode
  header('Content-Type: ' . $qrCode->getContentType());
  $qrCode->render();
}