<?php

namespace App\Service;

use App\Models\Tag;

class TagService
{

    public function getTagList()
    {
        return Tag::whereNull('ddate')->get();
    }
}


?>