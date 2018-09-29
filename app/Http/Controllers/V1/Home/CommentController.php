<?php

namespace App\Http\Controllers\V1\Home;

use App\Http\Controllers\Controller;
use App\Http\Requests\StoreComment;
use App\Service\BBSService;
use App\Service\UserService;

class CommentController extends Controller
{
    //
    public function store(StoreComment $request)
    {
        $validate = $request->validated();
        $openid = $validate['openid'];
        $bbsId = $validate['bbs_id'];

        $userId = '';
        $isMember = false;

        //1、判断帖子状态
        $bbsService = new BBSService();
        $bbsInfo = $bbsService->getBBSById($bbsId);
        if (!empty($bbsInfo) && $bbsInfo->lock == 1) {
            return ['code' => self::RETURN_FAIL, 'msg' => '该贴已被锁定，无法回复'];
        }

        //2、判断用户身份
        $userService = new UserService();
        $userInfo = $userService->getUserByOpenid($openid);
        if (!empty($userInfo) && $userInfo->state == 2) {
            return ['code' => self::RETURN_FAIL, 'msg' => '该用户已进入黑名单，无权回复'];
        }

        //3、更新用户信息
        $data = [
            'nick_name' => $validate['nick_name'],
            'head_url' => $validate['head_url'],
        ];
        if ($validate['expert'] == 2) {
            $data['expert'] = 2;
        }
        $userService->updateUserByOpenid($openid, $data);
        //3、判断用户发帖时间


        //4、文字校验
        //5、添加帖子记录
        //6、更新用户发帖相关信息


    }
}
