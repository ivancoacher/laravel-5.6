<?php

namespace App\Service;

use App\Models\Bbs;
use App\Models\Comment;
use App\Models\Reply;
use App\Models\Store;

class BBSService
{
    public function getBBSList($param, $page, $pageSize)
    {
//        $result = Bbs::


    }

    public function getBBSById($id)
    {
        return Bbs::with(['author', 'tags', 'images'])->where('id', $id)->first();
    }

    public function storeBBS($data)
    {
        $result = Bbs::create($data);
        return $result->id;
    }

    public function storeComment($data)
    {
        $result = Comment::create($data);
        return $result->id;
    }

    public function storeReply($data)
    {
        $result = Reply::create($data);
        return $result->id;
    }

    public function incrementBBSCommentNo($bbsId)
    {
        return Bbs::where('idx', $bbsId)->increment('comment_no');
    }

    public function incrementBBSReplyNo($bbsId)
    {
        return Bbs::where('idx', $bbsId)->increment('reply_no');
    }

    public function incrementBBSViewNo($bbsId)
    {
        return Bbs::where('id', $bbsId)->increment('view_no');
    }

    public function getBBSListByIds($bbsIds, $page, $pageSize)
    {
        if (empty($bbsIds)) {
            return [];
        } elseif (!empty($bbsIds)) {
            $result = Bbs::whereIn($bbsIds)
                ->skip($page * $pageSize)
                ->take($pageSize)
                ->take()
                ->get();
            return $result;
        }
    }

    //获取用户comment的帖子编号
    public function getBBSIdsWithComment($userId)
    {
        return Comment::where('user_id', $userId)->select('bbs_id')->get();
    }

    //获取用户reply的帖子编号
    public function getBBSIdsWithReply($userId)
    {
        return Reply::where('user_id', $userId)->select('bbs_id')->get();
    }

    //获取用户所有回帖信息
    public function getUserComments($userId)
    {
        return Comment::with('bbs')->where('user_id', $userId)->get();
    }

    //获取用户所有回帖信息
    public function getUserReplyList($userId, $page, $pageSize)
    {
        $result = Reply::with(['bbs', 'bbs.tags:tname', 'bbs.images:url'])
            ->where('user_id', $userId)
            ->groupBy('bbs_id')
            ->orderBy('cdate')
            ->skip($page * $pageSize)
            ->take($pageSize)
            ->get();
        return $result;
    }


    //获取用户发帖列表
    public function getUserBBSList($userId, $page, $pageSize)
    {
        $result = Bbs::with(['tags', 'images','author'])
            ->where('author_id', $userId)
            ->skip($page * $pageSize)
            ->take($pageSize)
            ->get();
        return $result;
    }


    //获取用户收藏列表
    public function getUserStoreList($userId, $page, $pageSize)
    {
        $result = Store::with(['bbs', 'bbs.tags:tname', 'bbs.images:url'])
            ->where('user_id', $userId)
            ->where('type', 1)
            ->skip($page * $pageSize)
            ->take($pageSize)
            ->get();
        return $result;
    }

    //获取用户收藏情况
    public function checkStore($bbsId, $userId)
    {
        return Store::where('bbs_id', $bbsId)->where('user_id', $userId)->first();
    }

    //获取用户agree情况
    public function checkUserAgree($commentId, $userId)
    {

    }

}


?>