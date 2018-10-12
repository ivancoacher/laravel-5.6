<?php

namespace App\Service;

use App\Models\Comment;
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
}


?>