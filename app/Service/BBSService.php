<?php

namespace App\Service;

use App\Models\Bbs;
use App\Models\Comment;
use App\Models\Replay;

class BBSService
{
    public function getBBSList()
    {

    }

    public function getBBSById($id)
    {
        return Bbs::find($id);
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

    public function storeReplay($data)
    {
        $result = Replay::create($data);
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

}


?>