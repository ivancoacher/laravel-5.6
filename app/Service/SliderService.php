<?php

namespace App\Service;

use App\Models\Slider;

class SliderService
{

    public function getSliders()
    {
        return Slider::orderBy('order_id')->get();
    }
}


?>