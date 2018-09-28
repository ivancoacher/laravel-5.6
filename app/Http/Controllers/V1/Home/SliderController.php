<?php

namespace App\Http\Controllers\V1\Home;

use App\Http\Controllers\Controller;
use App\Service\SliderService;

class SliderController extends Controller
{
    //
    public function index()
    {
        $service = new SliderService();

        $result = $service->getSliders();

        return [''];
    }
}
