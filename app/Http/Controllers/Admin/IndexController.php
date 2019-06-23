<?php

namespace App\Http\Controllers\Admin;

use App\Http\Controllers\Controller;

class IndexController extends Controller
{
    //
    public function index()
    {
        echo 111;exit;
        return view('admin.index');
    }
}
