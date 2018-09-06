<?php


function fs_user_info_update($uid, $status){
    $account = user_load($uid);
    if(is_object($account)){
    $account->status = $status;
    user_save($account);
      $result['success'] = true ;

    }else{
      $result['success'] = false ;
    }
  return $result ;
}

?>