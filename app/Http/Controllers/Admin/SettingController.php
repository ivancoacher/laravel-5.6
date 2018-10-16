<?php

namespace App\Http\Controllers\Admin;

use App\Http\Controllers\Controller;
use Illuminate\Http\Request;

class SettingController extends Controller
{
    //
    public function index()
    {
        $result = collect([]);
        return view('admin.setting')->with(['result' => $result]);
    }

    public function store(Request $request)
    {
        if ($request->method() == 'GET') {
            $result = collect([]);
            return view('admin.settingAdd')->with(['result' => $result]);
        } else {
            $data = $request->all();

        }
    }
    public function show($id){

    }
}
