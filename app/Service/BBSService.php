<?php

namespace App\Service;

use App\Models\Bbs;

class BBSService
{
    public function getBBSList()
    {

    }

    public function getBBSById($id)
    {
        return Bbs::find($id);
    }

}


?>