<?php

namespace App\Service;

use App\Models\Bbs;
use App\Models\Comment;
use App\Models\Reply;

class BBSService
{
    public function getBBSList()
    {

    }

    public function getBBSById($id)
    {
        return Bbs::with(['author','tags','images'])->where('id', $id)->first();
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
}


?>