<?php

namespace App\Http\Controllers\Admin;

use Illuminate\Http\Request;
use App\Http\Controllers\Controller;

class SchoolController extends Controller
{
    //
    public function index(){
        $result = collect([]);
        return view('admin.school')->with(['result' => $result]);
    }
}
