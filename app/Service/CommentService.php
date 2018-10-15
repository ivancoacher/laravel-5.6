<?php

namespace App\Service;

use App\Models\Agree;
use App\Models\Comment;
use App\Models\Reply;
use App\Models\Store;

class CommentService
{

    public function getCommentList($bbsId)
    {
        return Comment::with(['reply', 'author'])
            ->where('bbs_id', $bbsId)
            ->where('hide', 0)
            ->whereNull('ddate')
            ->orderBy('tdate', 'desc')
            ->get();
    }

    public function checkoutStore($userId, $bbsId)
    {
        return Store::firstOrCreate(['user_id' => $userId, 'bbs_id' => $bbsId]);
    }

    public function checkoutAgree($userId, $commentId, $level, $bbsId)
    {
        return Agree::firstOrCreate(['user_id' => $userId, 'index' => $commentId, 'level' => $level, 'bbs_id' => $bbsId]);
    }

    public function updateAgree($agreeId, $handleType)
    {
        return Agree::where('id', $agreeId)->update(['type' => $handleType]);
    }

    public function updateComment($commentId, $data)
    {
        return Comment::where('id', $commentId)->update($data);
    }

    public function updateReply($replyId, $data)
    {
        return Reply::where('id', $replyId)->update($data);
    }

    public function changeCommentGood($commentId, $type)
    {
        if ($type == 'increment') {
            return Comment::where('id', $commentId)->increment('good');
        } else {
            return Comment::where('id', $commentId)->decrement('good');
        }
    }

    public function changeCommentBad($commentId, $type)
    {
        if ($type == 'increment') {
            return Comment::where('id', $commentId)->increment('bad');
        } else {
            return Comment::where('id', $commentId)->decrement('bad');

        }
    }

    public function changeReplyGood($replyId, $type)
    {
        if ($type == 'increment') {
            return Reply::where('id', $replyId)->increment('good');
        } else {
            return Reply::where('id', $replyId)->decrement('good');
        }
    }

    public function changeReplyBad($replyId, $type)
    {
        if ($type == 'increment') {
            return Reply::where('id', $replyId)->increment('good');
        } else {
            return Reply::where('id', $replyId)->decrement('good');
        }
    }

}


?>