<?php

namespace App\Service;

use App\Models\Comment;

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
}


?>