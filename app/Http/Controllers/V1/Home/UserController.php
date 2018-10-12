<?php

namespace App\Http\Controllers\V1\Home;

use App\Http\Controllers\Controller;
use App\Models\Reply;
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
        $page = $request->input('page', '0');
        $pageSize = $request->input('pageSize', '10');
        $userService = new UserService();

        $userId = $userService->getUserId($openid);
        if (!$userId) {
            return ['code' => -200, 'msg' => '用户信息不存在'];
        }
        $bbsService = new BBSService();
        $bbsList = $bbsService->getUserStoreList($userId, $page, $pageSize);
        $result = [];
        if ($bbsList->isNotEmpty()) {
            foreach ($bbsList as $k => $v) {
                $result[] = [
                    'order' => $k + 1,
                    'id' => $v->bbs_id,
                    'forum_id' => $v->forum_id,
                    'title' => $v->bbs->title,
                    'content' => $v->bbs->content,
                    'top' => $v->bbs->top,
                    'super' => $v->bbs->super,
                    'lock' => $v->bbs->lock,
                    'udate' => $v->bbs->udate->format('Y-m-d H:i:s'),
                    'view_no' => $v->bbs->view_no ?? 0,
                    'store_no' => $v->bbs->store_no ?? 0,
                    'comment_no' => $v->bbs->comment_no ?? 0,
                    'surface_img' => $v->bss->surface_img ?? '',
                    'img_list' => array_values(array_column($v->bbs->images->toArray(),'url')),
                    'author_id' => $v->bbs->author_id,
                    'nick_name' => $v->author->nick_name,
                    'head_url' => $v->author->head_url,
                    'company' => $v->author->company,
                    'tag' => array_values(array_column($v->bbs->tags->toArray(),'tname'))
                ];

            }
        }
        return ['code' => 200, 'items' => $result, 'msg' => '获取数据成功'];

    }

    //我的回帖
    public function userReply(Request $request)
    {
        $openid = $request->input('openid', '');
        $page = $request->input('page', '0');
        $pageSize = $request->input('pageSize', '10');
        $userService = new UserService();

        $userId = $userService->getUserId($openid);
        if (!$userId) {
            return ['code' => -200, 'msg' => '用户信息不存在'];
        }
        $bbsService = new BBSService();
        $bbsList = $bbsService->getUserReplyList($userId, $page, $pageSize);
        $result = [];
        if ($bbsList->isNotEmpty()) {
            foreach ($bbsList as $k => $v) {
                $result[] = [
                    'order' => $k + 1,
                    'id' => $v->bbs_id,
                    'forum_id' => $v->forum_id,
                    'title' => $v->bbs->title,
                    'content' => $v->bbs->content,
                    'top' => $v->bbs->top,
                    'super' => $v->bbs->super,
                    'lock' => $v->bbs->lock,
                    'udate' => $v->bbs->udate->format('Y-m-d H:i:s'),
                    'view_no' => $v->bbs->view_no ?? 0,
                    'store_no' => $v->bbs->store_no ?? 0,
                    'comment_no' => $v->bbs->comment_no ?? 0,
                    'surface_img' => $v->bss->surface_img ?? '',
                    'img_list' => $v->bbs->images->toArray(),
                    'author_id' => $v->bbs->author_id,
                    'nick_name' => $v->author->nick_name,
                    'head_url' => $v->author->head_url,
                    'company' => $v->author->company,
                    'tag' => array_values(array_column($v->bbs->tags->toArray(),'tname'))
                ];

            }
        }
        return ['code' => 200, 'items' => $result, 'msg' => '获取数据成功'];
    }

    //我的发帖
    public function userPub(Request $request)
    {
        $openid = $request->input('openid', '');
        $page = $request->input('page', '0');
        $pageSize = $request->input('pageSize', '10');
        $userService = new UserService();

        $userId = $userService->getUserId($openid);
        if (!$userId) {
            return ['code' => -200, 'msg' => '用户信息不存在'];
        }
        $bbsService = new BBSService();
        $bbsList = $bbsService->getUserBBSList($userId, $page, $pageSize);
        $result = [];
        if ($bbsList->isNotEmpty()) {
            foreach ($bbsList as $k => $v) {
                $result[] = [
                    'order' => $k + 1,
                    'id' => $v->id,
                    'forum_id' => $v->forum_id,
                    'title' => $v->title,
                    'content' => $v->content,
                    'top' => $v->top,
                    'super' => $v->super,
                    'lock' => $v->lock,
                    'udate' => $v->udate->format('Y-m-d H:i:s'),
                    'view_no' => $v->view_no ?? 0,
                    'store_no' => $v->store_no ?? 0,
                    'comment_no' => $v->comment_no ?? 0,
                    'surface_img' => $v->surface_img ?? '',
                    'img_list' => array_values(array_column($v->images->toArray(),'url')),
                    'author_id' => $v->author_id,
                    'nick_name' => $v->author->nick_name,
                    'head_url' => $v->author->head_url,
                    'company' => $v->author->company,
                    'tag' => array_values(array_column($v->tags->toArray(),'tname'))
                ];

            }
        }
        return ['code' => 200, 'items' => $result, 'msg' => '获取数据成功'];


    }

    //我的精华帖
    public function userSuper()
    {
        return [];
    }

}
