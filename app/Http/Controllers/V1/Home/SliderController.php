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
        $response = [];
        if ($result->isNotEmpty()) {
            foreach ($result as $k => $v) {
                $response[] = array(
                    'order' => $v + 1,
                    'id' => $v->id,
                    'img_url' => $v->img_url,
                    'img_link' => $v->img_link,
                    'order_id' => $v->order_id,
                );
            }
            return ['code' => self::RETURN_SUCCESS, 'msg' => '数据申请成功', 'items' => $response];
        } else {
            return ['code' => self::RETURN_FAIL, 'msg' => '暂无数据'];
        }
    }
}
