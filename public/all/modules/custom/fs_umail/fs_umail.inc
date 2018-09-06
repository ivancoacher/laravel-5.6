<?php

require "AbstractUMail.php";

class UMail extends AbstractUMail
{


    //** @param  ['address' => 'EMAIL','fullname' => 'NAME','var1' => 'registed or not'];
    public function addUser($info)
    {
        if(!isset($info["list_id"])){
            $list_id = variable_get('fs_umail_list_id', '');
            $info["list_id"] = $list_id;
        }
        $url = "http://www.bestedm.org/mm-ms/apinew/mloperate.php?do=ml-addr-add";
        return $this->base_api_post_curl($url, $info);
    }

    //** @param  ['address' => 'EMAIL']
    public function deleteUser($info)
    {
        $list_id = variable_get('fs_umail_list_id', '');//密码
        $info["list_id"] = $list_id;
        $url = "http://www.bestedm.org/mm-ms/apinew/mloperate.php?do=ml-addr-delete";
        return $this->base_api_post_curl($url, $info);
    }

    //** @param  ['address' => 'EMAIL','name' => 'NAME'];
    //@note add new user and subscribe are included --  VERIFIED
    //**//
    public function fs_umail_newsletter_subscribe($info)
    {
        $info["list_id"] = variable_get('fs_umail_list_id', '');
        $info["do"] = "ml-sub";
        $info["name"] =  $info["fullname"];
        unset($info["fullname"]);
        $param_string = drupal_http_build_query($info);
        $url = "http://www.bestedm.org/mm-ms/apinew/mloperate.php?" . $param_string;
        return $this->base_api_get_curl($url);
    }
    //** @param  ['address' => 'EMAIL'];
    //@note delete  user from UMAIL -- VERIFIED
    //**//
    public function fs_umail_newsletter_unsubscribe($info)
    {
        $info["list_id"] = variable_get('fs_umail_list_id', '');
        $info["do"] = "ml-unsub";
        $param_string = drupal_http_build_query($info);
        $url = "http://www.bestedm.org/mm-ms/apinew/mloperate.php?" . $param_string;
        return $this->base_api_get_curl($url);
    }

    //** @param  ['address' => 'EMAIL','fullname' => 'NAME','list_id'=> 'List ACTION ID']; -- VERIFIED
    protected function fs_umail_preprocess_sendEmail($info)
    {

        // empty list newsletter confirmation
        $status = $this->fs_umail_empty_list($info["list_id"]);
        $result_status = true;
        if ($status["error"]!="") {
            return false;
        }
        // add user
        $add_status = $this->addUser($info);

        if ($add_status["error"]!="") {
            return false;
        }
        return $result_status;
    }

    //** @param  ['address' => 'EMAIL','fullname' => 'NAME',];
    public function fs_umail_newsletter_confirmation($info)
    {

        $tpl_id = variable_get('fs_umail_newsletter_confirmation_tlp_id', '');
        $list_id =  variable_get('fs_umail_action_list_id', '');
        $param["address"] =  $info["address"];
        $param["fullname"] = $info["fullname"];
        $param["list_id"] =  $list_id ;
        $status = $this->fs_umail_preprocess_sendEmail($param);
        $result=[];
        if($status){
        $result = $this->curl_sendEmail($list_id,$tpl_id);
        }
        return $result;
    }
  //** @param  ['address' => 'EMAIL','fullname' => 'NAME',];
  public function fs_umail_reset_password($account, $reset_link)
  {

    $tpl_id = variable_get('fs_umail_forget_password_tlp_id', '');
    $list_id =  variable_get('fs_umail_action_list_id', '');
    $param["address"] =  $account->mail;
    $param["fullname"] = $account->name;
    $param["var4"] = $reset_link;
    $param["var5"] = $account->name;
    $param["list_id"] =  $list_id ;
    $status = $this->fs_umail_preprocess_sendEmail($param);
    $result=[];
    if($status){
      $result = $this->curl_sendEmail($list_id,$tpl_id);
    }
    return $result;
  }
  public function fs_umail_edit_tpl($contents,$tpl_id) {
    $param["do"]= "edit-tpl";
    $param["tpl_id"]= $tpl_id;
    $param["content"]= "<a>test</a>" ;
    $param_string = drupal_http_build_query($param);
    $url = "http://www.bestedm.org/mm-ms/apinew/template.php?".$param_string;
    return $this->base_api_get_curl($url);
  }

  public function fs_umail_user_confirmation_email($account){
    $tpl_id = variable_get('fs_umail_registration_tlp_id', '');
    $list_id =  variable_get('fs_umail_action_list_id', '');
    $param["address"] =  $account->mail;
    $param["fullname"] = $account->name;
    $param["list_id"] =  $list_id ;
    $param["var3"]="dadsdad";
    $status = $this->fs_umail_preprocess_sendEmail($param);
    $result=[];
    if($status){
      $result = $this->curl_sendEmail($list_id,$tpl_id);
    }
    return $result;

  }

  public function fs_umail_user_activation_email($account, $activation_link){
      $tpl_id = variable_get('fs_umail_account_confirmation_tlp_id', '');
      $list_id =  variable_get('fs_umail_action_list_id', '');
      $param["address"] =  $account->mail;
      $param["fullname"] = $account->name;
      $param["list_id"] =  $list_id ;
      $param["var3"] = $activation_link ;
      $status = $this->fs_umail_preprocess_sendEmail($param);
      $result=[];
      if($status){
           $result = $this->curl_sendEmail($list_id,$tpl_id);
      }
    return $result;
  }

}

?>