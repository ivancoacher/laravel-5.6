<?php
header('Content-Type:text/html;Charset=utf-8;');
header('Access-Control-Allow-Origin:*');
header('Access-Control-Allow-Headers:x-requested-with,content-type');

//文本检测
function txtCheck($txt)
{
    //测试环境
    // $Region = 'bj';
    // $SecretId = 'AKIDeBZnpLKRwPgmgPpHpaIqFTly9E8qMKIF';
    // $SignKey = 'ymQs8FZpxugGe0EYhgU6jFcnxwkMrBKH';

    //正式环境
    $Region = 'ap-beijing';
    $SecretId = 'AKIDfDQbbPTWmqkgW6tmpfKrCKhw3znPj25y';
    $SignKey = '0Sp11LURCl7HODr0zmNp6B7sW2MWUHtK';

    $url = 'wenzhi.api.qcloud.com/v2/index.php';
    $action = 'TextSensitivity';
    $sign_method = 'HmacSHA256';//
    $sign_method_value = "sha1";//sha1  sha256

    $content = $txt;//待分析的文本（只能为utf8编码）
    $type = 2;//区分敏感词类型:1表示色情，2表示政治

    $param = array(
        "content" => $content,
        "Action" => $action,
        "Nonce" => rand(100000, 999999),
        "Region" => $Region,
        "SecretId" => $SecretId,
        "Timestamp" => time(),
        "type" => $type
    );
    $str = getSignature($url, $param, $SignKey);
    $url_to_post = "https://" . $url . "?" . $str;

    $result = curl_get($url_to_post);
    $result_obj = json_decode($result);

    if ($result_obj->code == 0 && $result_obj->sensitive > 0.6) {
        error_log("--code" . $result_obj->code . "--sensitive:" . $result_obj->sensitive . "\r\n", 3, 'log.log');
        return "true";
//	} else {
//		//对政治查询
//		$param = array(
//			"content"=>$content,
//			"Action"=>$action,
//			"Nonce"=>rand(100000, 999999),
//			"Region"=>$Region,
//			"SecretId"=>$SecretId,
//			"Timestamp"=>time(),
//			"type"=>2
//		);
//		$str = getSignature($url, $param, $SignKey);
//		$url_to_post = "https://".$url."?".$str;
//
//		$result = curl_get($url_to_post);
//		$result_obj = json_decode($result);
//		//echo $result;
//		if ($result_obj->code == 0 && $result_obj->sensitive > 0.5){
//			error_log("--code".$result_obj->code."--sensitive:".$result_obj->sensitive."\r\n",3,'log.log');
//			return "true";
//		}
//		error_log("--code".$result_obj->code."--sensitive:".$result_obj->sensitive."\r\n",3,'log.log');
//		return "false";
    }
}

//返回内容的格式
//code Int32   错误码。0：成功，其他值：失败
//message String  失败时候的错误信息，成功则无该字段
//sensitive   Double  敏感的概率
//nonsensitive    Double  不敏感的概率

function curl_get($url = '')
{
    if (empty($url)) {
        return false;
    }
    $ch = curl_init();//初始化curl
    curl_setopt($ch, CURLOPT_URL, $url);//抓取指定网页
    curl_setopt($ch, CURLOPT_HEADER, 0);//设置header
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);//要求结果为字符串且输出到屏幕上
    //https设置
    curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);//这个是重点。
    curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, FALSE);
    $data = curl_exec($ch);//运行curl
    curl_close($ch);
    return $data;
}

//生成sign
function getSignature($url, $param, $SignKey)
{
    ksort($param);
    $str = "";
    foreach ($param as $k => $v) {
        $str .= "$k=" . urldecode($v) . "&";
    }
    $str = substr($str, 0, -1);
    $sign_url = "GET" . $url . "?" . $str;
    return $str . "&Signature=" . urlencode(base64_encode(hash_hmac("sha1", $sign_url, $SignKey, true)));
}

//获取毫秒时间
function getMTime()
{
    list($msec, $sec) = explode(' ', microtime());
    return (float)sprintf('%.0f', (floatval($msec) + floatval($sec)) * 1000);
}

//##########图片检测##########//
function imgCheck($filename)
{
    //测试环境
    //$image_domain = "http://www.jiyou-tech.com/2018/wxC/php/bbsImg/";	//本地图片路径
    //正式环境
    $image_domain = "https://community.yinghootech.cn/php/bbsImg/";    //本地图片路径
    $filename = $filename;                                                //图片文件名

    //测试环境
    // $appid = "1254507050";
    // $bucket = "insect";
    // $secret_id = "AKIDeBZnpLKRwPgmgPpHpaIqFTly9E8qMKIF";
    // $secret_key = "ymQs8FZpxugGe0EYhgU6jFcnxwkMrBKH";

    //正式环境
    $appid = "1252927871";
    $bucket = "weixin-1252927871";
    $secret_id = "AKIDfDQbbPTWmqkgW6tmpfKrCKhw3znPj25y";
    $secret_key = "0Sp11LURCl7HODr0zmNp6B7sW2MWUHtK";

    $expired = time() + 2592000;
    $onceExpired = 0;
    $current = time();
    $rdm = rand();
    $userid = "0";

    $srcStr = 'a=' . $appid . '&b=' . $bucket . '&k=' . $secret_id . '&e=' . $expired . '&t=' . $current . '&r=' . $rdm . '&u='
        . $userid . '&f=';

    $signStr = base64_encode(hash_hmac('SHA1', $srcStr, $secret_key, true) . $srcStr);

    $srcWithFile = base64_encode(hash_hmac('SHA1', $srcWithFile, $secret_key, true) . $srcWithFile);

    $signStrOnce = base64_encode(hash_hmac('SHA1', $srcStrOnce, $secret_key, true) . $srcStrOnce);

    $post_url = "http://service.image.myqcloud.com/detection/porn_detect";

    $body = new stdclass();
    $body->appid = $appid;
    $body->url_list = array();
    $body->url_list[0] = $image_domain . $filename;
    //$body->url_list[1] = "http://www.jiyou-tech.com/app/buluogou/pic/test2.jpg";
    $body_str = json_encode($body);
    //echo $body_str."<br>";

    $headers = array(
        "Authorization:" . $signStr,
        "Host:service.image.myqcloud.com",
        "Content-Type:application/json",
        "Content-length:" . strlen($body_str)
    );

    $result = curl_post($post_url, $headers, $body_str);

    $result_obj = json_decode($result);
    foreach ($result_obj->result_list as $item) {
        if ($item->code == 0 && $item->data->confidence >= 50) {
            return "true";
        }
    }
    return "false";
}

function post2($url, $headers, $post_data)
{
    $o = "";
    $i = 0;
    foreach ($headers as $k) {
        $o .= $k . ",";
    };
    $post_header = substr($o, 0, -1);
    echo "post_header=" . $post_header . "<br>";

    $context = stream_context_create(array(
        'http' => array(
            'method' => 'POST',
            'header' => $post_header,
            'content' => $post_data,
            'timeout' => 20
        )
    ));
    $result = file_get_contents($url, false, $context);
}

function curl_post($url, $headers, $post_data)
{
    if (empty($url) || empty($post_data)) {
        return false;
    }

    /*
        $o = "";
        foreach ( $post_data as $k => $v )
        {
            $o.= "$k=" . urlencode( $v ). "&" ;
        }
        $post_data = substr($o,0,-1);
    */
    $postUrl = $url;
    $curlPost = $post_data;

    $ch = curl_init();//初始化curl
    curl_setopt($ch, CURLOPT_URL, $postUrl);//抓取指定网页
    curl_setopt($ch, CURLOPT_HEADER, 0);//设置header
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);//要求结果为字符串且输出到屏幕上
    curl_setopt($ch, CURLOPT_POST, 1);//post提交方式
    curl_setopt($ch, CURLOPT_POSTFIELDS, $post_data);
    curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);

    //https设置
    if (0 === strpos(strtolower($postUrl), 'https')) {
        curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);//这个是重点。
        curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, FALSE);
    }
    $data = curl_exec($ch);//运行curl
    $curl_info = curl_getinfo($ch);

    if (curl_errno($ch)) {
        return curl_error($ch);
    }
    curl_close($ch);

    return $data;
}


//###########对象存储##########//
function objStore($picname)
{
    //require 'vendor/autoload.php';
    //测试环境
    //$base_domain="/home/wwwroot/www.jiyou-tech.com/2018/wxC/php/bbsImg/"; 	//图片存放当前服务器的目录位置
    //正式环境
    $base_domain = "/home/wxC/php/bbsImg/";    //图片存放当前服务器的目录位置
    $filename = $picname;                                                        //待处理图片名称
    $key = 'wxC/pic/' . $filename;                                            //腾讯云保存图片位置

    // 若初始化 Client 时未填写 appId，则 bucket 的命名规则为{name}-{appid} ，此处填写的存储桶名称必须为此格式
    // $COS_APPID = '1252927871';
    // $COS_REGION = 'bj';
    // $COS_KEY = 'AKIDgDYhcJtyvc3EAphNHSN2jBQVLxJPvLxJ';
    // $COS_SECRET = 'IL9hyzlHWVGsHTSFo9KI3av63nKejY8S';
    // $bucket = 'community';

    // 正式环境
    $COS_APPID = '1252927871';
    $COS_REGION = 'ap-beijing';
    $COS_KEY = 'AKIDfDQbbPTWmqkgW6tmpfKrCKhw3znPj25y';
    $COS_SECRET = '0Sp11LURCl7HODr0zmNp6B7sW2MWUHtK';
    $bucket = 'weixin-1252927871';

    $local_path = $base_domain . $filename;
    $contentype = 'image/png';//image/jpeg

    $cosClient = new Qcloud\Cos\Client(array(
        'region' => $COS_REGION,
        'credentials' => array(
            'appId' => $COS_APPID,
            'secretId' => $COS_KEY,
            'secretKey' => $COS_SECRET,
        ),
    ));


    ### 上传文件流
    try {
        $result = $cosClient->putObject(array(
            'Bucket' => $bucket,
            'Key' => $key,
            'contenttype' => $contentype, //可选,设置文件的类型
            'Body' => fopen($local_path, 'rb')
        ));
        //print_r($result);
        return $result['ObjectURL'];
    } catch (\Exception $e) {
        print_r($e);
    }
}


/*
 * 生成唯一随机字符串
 * @param int $len 			生成随机字符串的长度
 * @param string $char 		组成随机字符串的字符串
 * @return string $string 	生成的随机字符串
 */

function randString($len = 8)
{
    $chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz';
    $string = time();

    for (; $len >= 1; $len--) {
        $position = rand() % strlen($chars);
        $position2 = rand() % strlen($string);
        $string = substr_replace($string, substr($chars, $position, 1), $position2, 0);
    }
    return $string;
}

?>