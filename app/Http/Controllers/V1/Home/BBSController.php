<?php

namespace App\Http\Controllers\V1\Home;

use App\Http\Controllers\Controller;
use App\Http\Requests\StoreBbs;
use App\Service\BBSService;
use App\Service\TagService;
use App\Service\UserService;
use Illuminate\Support\Facades\Request;

class BBSController extends Controller
{
    //
    public function store(StoreBbs $request)
    {

        $validate = $request->validated();

        $openid = $request['openid'];

        //1、判断用户身份

        //2、判断用户发帖时间

        //3、文字校验
        $titleResult = txtCheck($validate['title']);
        $contentResult = txtCheck($validate['content']);

        if (!$titleResult || !$contentResult) {
            return ['code' => self::RETURN_FAIL, 'msg' => '文本检测未通过', 'log1' => $titleResult, 'log2' => $contentResult];
        }
        //4、添加帖子记录

        //5、更新用户发帖相关信息
        $rand_str_bbs = randString(5);
        $idBBS = 'bbs_' . time() . '_' . mt_rand(1111, 9999) . '_' . $rand_str_bbs;

        $data = [
            'id' => $idBBS,
            'author_id' => $user_id,
            'forum_id' => $validate['forum_id'],
            'content' => htmlspecialchars($validate['content'], ENT_QUOTES),
            'title' => htmlspecialchars($validate['title'], ENT_QUOTES),
            'nick_name' => htmlspecialchars($validate['nick_name'], ENT_QUOTES),
            'tag' => htmlspecialchars($validate['tag'], ENT_QUOTES),
            'tag_content' => htmlspecialchars($validate['tag_content'], ENT_QUOTES),
            'img_list' => $validate['img_list']
        ];
        $bbsService = new BBSService();
        $bbsService->storeBBS($data);

        $openid = $request->input('openid', '');
        $nickname = $request->input('nick_name', '');
        $head_url = $request->input('head_url', '');

        $forum_id = $request->input('forum_id', '');
        $title = $request->input('title', '');
        $content = $request->input('content', '');
        $tag = $request->input('tag', '');
        $tag_content = $request->input('tag_content', '');
        $expert = $request->input('expert', '');

        $img_list = $request->input('img_list', '');


    }

    public function index(Request $request)
    {
        echo 11111;exit;
        $forumId = $request->input('forum_id');
        $bbsId = $request->input('bbs_id');
        $handleType = $request->input('handleType', 'next');
        $range = $request->input('range', 10);

        $tagService = new TagService();

        $rst = $tagService->getTagList();
        $tagList = [];
        foreach ($rst as $k => $v) {
            $tagList[$v->id] = $v->tname;
        }

        $bbsService = new BBSService();

        //获取帖子列表
        $result = $bbsService->getBBSList();


    }

    public function show(Request $request)
    {
        $bbsId = $request->input('bbs_id', '');
        $openid = $request->input('openid', '');

        $bbsService = new BBSService();
        $bbsService->incrementBBSViewNo($bbsId);

        $bbsInfo = $bbsService->getBBSById($bbsId);

        if (empty($bbsInfo) || !empty($bbsInfo->ddate)) {
            return ['code' => self::RETURN_FAIL, 'msg' => '该帖已隐藏'];
        }

        $userService = new UserService();
        $userInfo = $userService->getUserByOpenid($openid);


    }


}
