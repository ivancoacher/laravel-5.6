<?php

namespace App\Http\Controllers\V1\Home;

use App\Http\Controllers\Controller;
use App\Service\BBSService;
use App\Service\UserService;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Config;


class UserController extends Controller
{
    //
    public function index1()
    {

    }


    public function getOpenid(Request $request)
    {
        $code = $request->input('code');
        $appId = Config::get('min.APP_ID');
        $appSecret = Config::get('mini.APP_SECRET');
        $url = "https://api.weixin.qq.com/sns/jscode2session?appid=" . $appId . "&secret=" . $appSecret . "&js_code=" . $code . "&grant_type=authorization_code";
        $result = curl_get($url);
        return $result;
    }

    //我的收藏
    public function userStore(Request $request)
    {
        $openid = $request->input('openid', '');
        $page = $request->input('page', '1');
        $userService = new UserService();
        $userId = $userService->getUserId($openid);




        $bbsService = new BBSService();

    }

    //我的回帖
    public function userReply()
    {

    }

    //我的发帖
    public function userPub()
    {

    }

    //我的精华帖
    public function userSuper()
    {
        return [];
    }

}
