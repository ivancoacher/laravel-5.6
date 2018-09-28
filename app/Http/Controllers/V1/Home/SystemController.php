<?php

namespace App\Http\Controllers\V1\Home;

use App\Http\Controllers\Controller;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Config;

class SystemController extends Controller
{
    public function getOpenid(Request $request)
    {
        $code = $request->input('code');
        $appId = Config::get('min.APP_ID');
        $appSecret = Config::get('mini.APP_SECRET');
        $url = "https://api.weixin.qq.com/sns/jscode2session?appid=" . $appId . "&secret=" . $appSecret . "&js_code=" . $code . "&grant_type=authorization_code";
        $result = curl_get($url);
        return $result;
    }
}
