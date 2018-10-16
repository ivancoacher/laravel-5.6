<?php

namespace App\Http\Controllers\Admin;

use Illuminate\Http\Request;
use App\Http\Controllers\Controller;

class AdController extends Controller
{
    //
    public function index()
    {
        $result = collect([]);
        return view('admin.ad')->with(['result' => $result]);
    }
}
