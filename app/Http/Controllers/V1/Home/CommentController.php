<?php

namespace App\Http\Controllers\V1\Home;

use App\Http\Controllers\Controller;
use App\Http\Requests\StoreComment;
use App\Service\BBSService;
use App\Service\SystemService;
use App\Service\UserService;
use Illuminate\Support\Facades\DB;

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

        //3、判断用户发帖时间
        if (!empty($userInfo->thresh_time)) {
            $systemService = new SystemService();
            $threshold = $systemService->getThreshTime();
            if (time() - $threshold < strtotime($userInfo->thresh_time)) {
                return ['code' => self::RETURN_FAIL, 'msg' => '操作过于频繁,请稍后再试'];
            }
        }

        //4、文字校验
        $checkText = txtCheck($validate['content']);

        if ($checkText) {
            return ['code' => self::RETURN_FAIL, 'msg' => '文本检测未通过'];
        }

        //5、添加帖子记录

        DB::beginTransaction();
        $level = $validate['level'];
        $rst = $rst1 = false;
        if ($level == 1) {      //comment表添加数据
            $rand_str_comment = randString();
            $idComment = 'comment_' . time() . '_' . mt_rand(1111, 9999);


            $data = [
                'id' => $idComment,
                'user_id' => $userInfo->id,
                'bbs_id' => $validate['bbs_id'],
                'comment' => $validate['comment'],
            ];
            $rst = $bbsService->storeComment($data);
            $rst1 = $bbsService->incrementBBSCommentNo($validate['bbs_id']);


        } elseif ($level == 2) {    //reply表添加数据
            $rand_str_reply = randString();
            $idReply = 'reply_' . time() . '_' . mt_rand(1111, 9999);

            $data = [
                'id' => $idReply,
                'user_id' => $userInfo->id,
                'bbs_id' => $validate['bbs_id'],
                'comment' => $validate['comment'],
            ];
            $rst = $bbsService->storeComment($data);
            $rst1 = $bbsService->incrementBBSReplyNo($validate['bbs_id']);
        }
        if ($rst && $rst1) {
            $userService->updateUserThreshTime($userId);
            DB::commit();
            return ['code' => self::RETURN_SUCCESS, 'msg' => '回复成功'];
        } else {
            DB::rollBack();
            return ['code' => self::RETURN_FAIL, 'msg' => '回复失败'];

        }


    }
}
