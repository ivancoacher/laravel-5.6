<?php

function fs_umail_drush_command()
{
      $items = [];
  // Name of the drush command.
      $items['fs_umail_content'] = [
        'description' => 'Migrate User NewsLetter from EMD U-MAIL',
        'callback' => 'fs_umail_content',
      ];

    return $items;
}

function fs_umail_content(){
    module_load_include('inc', 'fs_umail', 'fs_umail');
    $all_users = entity_load('user');
    $count =0 ;
    $umail = new UMail();

    foreach($all_users as $value) {
        $user_list = (array)$value;
        if(isset($user_list['field_user_family_newsletter']["und"][0]["value"])&&$user_list['field_user_family_newsletter']["und"][0]["value"]==1) {

            $last_name = isset($user_list['field_last_name']["und"][0]["value"])?$user_list['field_last_name']["und"][0]["value"]:"" ;
            $fisrt_name = isset($user_list['field_first_name']["und"][0]["value"])?$user_list['field_first_name']["und"][0]["value"]:"" ;

            $fullname = $fisrt_name." ".$last_name ;
            if(trim($fullname)==""){
                $fullname = $user_list["name"];
            }
            $info = [
            'address' => $user_list['mail'],
            'fullname' => $fullname ,
            'var1' => "registered"
            ];
            var_dump($info);
            $result = $umail->addUser($info);
            if($result["data"]){
            drush_print($result["data"]);
            }else{
            drush_print($result["error"]);
            }
            $count++;
        }


    }
    drush_print($count);

}