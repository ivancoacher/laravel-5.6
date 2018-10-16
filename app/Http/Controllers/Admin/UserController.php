<?php

namespace App\Http\Controllers\Admin;

use App\Http\Controllers\Controller;

class UserController extends Controller
{
    //
    public function index()
    {
        $result = collect([]);
        return view('admin.ad')->with(
            ['result'=> $result]
        );
    }
}
