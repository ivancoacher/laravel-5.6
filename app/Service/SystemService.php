<?php

namespace App\Service;

use App\Models\GlobalModel;

class SystemService
{

    public function getThreshTime()
    {
        $result = GlobalModel::select('threshold')->first();
        return $result->threshold;
    }
}


?>