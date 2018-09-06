<?php

/**
 * Created by PhpStorm.
 * User: admin
 * Date: 16/03/2018
 * Time: 12:58
 */


class AbstractUMail
{

    protected function curl_sendEmail($list_id,$tpl_id)
    {

        $param["do"] = "add-task";
        $param["tpl_id"] = $tpl_id ;
        $param["send_domain"] =  "service.shfamily.com" ; //"shfamily.com";
        $param["send_account"] = "hello@service.shfamily.com";
        $param["send_fullname"] = "Family Community";
        $param["maillist_id"] = $list_id;
       // $param["time"] =  date("Y-m-d G:i") ;// "2017-11-24+09%3A54%3A01";
        $param["send_qty"]= 1 ;
        $param["send_qty_start"]= 1 ;
        $param["status"]= 2 ; // send immediately
        $param_string = drupal_http_build_query($param);
        $url = "http://www.bestedm.org/mm-ms/apinew/task.php?" . $param_string;
        return $this->base_api_get_curl($url);
    }
    protected function base_api_get_curl($url)
    {
        if (extension_loaded('curl')) {

            $username = variable_get('fs_umail_username', '');//用户名

            $password = variable_get('fs_umail_password', '');//密码

            $opts = array(
                CURLOPT_TIMEOUT => 5,

                CURLOPT_HTTPAUTH => CURLAUTH_BASIC,

                CURLOPT_USERPWD => "$username:$password",

                CURLOPT_RETURNTRANSFER => 1,

                CURLOPT_URL => $url,

                CURLOPT_HEADER => 0,

                CURLOPT_USERAGENT => $_SERVER['HTTP_USER_AGENT']

            );
            /* 初始化并执行curl请求 */

            return $this->curl_result($opts);

        }
    }

    protected function base_api_post_curl($url, $params)
    {
        if (extension_loaded('curl')) {

            $username = variable_get('fs_umail_username', '');//用户名

            $password = variable_get('fs_umail_password', '');//密码

            $vars = http_build_query($params);

            //post 方式

            $opts = array(

                CURLOPT_TIMEOUT => 5,

                CURLOPT_HTTPAUTH => CURLAUTH_BASIC,

                CURLOPT_USERPWD => "$username:$password",

                CURLOPT_RETURNTRANSFER => 1,

                CURLOPT_URL => $url,

                CURLOPT_POST => 1,

                CURLOPT_POSTFIELDS => $vars,

                CURLOPT_USERAGENT => $_SERVER['HTTP_USER_AGENT']

            );
            /* 初始化并执行curl请求 */
            return $this->curl_result($opts);


        }
    }

    protected function curl_result($opts)
    {
        $ch = curl_init();
        curl_setopt_array($ch, $opts);
        $status_code = curl_getinfo($ch, CURLINFO_HTTP_CODE);   //get status code
        $data = curl_exec($ch);
        $error = curl_error($ch);
        curl_close($ch);
        return array(
            "data" => $data,
            "error" => $error,
            "code_status" => $status_code
        );
    }

    public function smtp_sendEmail($param)
    {

//        module_load_include('inc', 'fs_umail', 'fs_umail_smtp');
//        $smtpserver = "service.shfamily.com";
//        $smtpserverport = 25;
////你的umail服务器邮箱账号
//        $smtpusermail = "miandrila@service.shfamily.com";
////收件人邮箱
//        $smtpemailto = "miandrilala9@yahoo.fr";
//
//        $smtpuser = variable_get('fs_umail_username', '');//
////你的邮箱密码
//        $smtppass = variable_get('fs_umail_password', ''); //
//
////邮件主题
//        $mailsubject = "subject";
////邮件内容
//        $mailbody = "content";
////邮件格式（HTML/TXT）,TXT为文本邮件
//        $mailtype = "HTML/TXT";
////这里面的一个true是表示使用身份验证,否则不使用身份验证.
//        $smtp = new smtp($smtpserver, $smtpserverport, true, $smtpuser, $smtppass);
////是否显示发送的调试信息
//        $smtp->debug = TRUE;
////发送邮件
//        $smtp->sendmail($smtpemailto, $smtpusermail, $mailsubject, $mailbody, $mailtype);
    }

    protected function fs_umail_empty_list($list_id)
    {
        $info["do"] = "ml-addr-empty";
        $info["list_id"] = $list_id;
        $param_string = drupal_http_build_query($info);
        $url = "http://www.bestedm.org/mm-ms/apinew/mloperate.php?" . $param_string;

        return $this->base_api_get_curl($url);
    }
}