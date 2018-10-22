<?php

namespace App\Http\Controllers\Admin;

use App\Http\Controllers\Controller;
use App\Models\Article;
use Illuminate\Http\Request;

class ArticleController extends Controller
{
    //
    public function index()
    {
        $result = collect([]);
        return view('admin.article')->with(['result' => $result]);
    }

    public function store(Request $request)
    {
        if ($request->method() == 'GET') {
            $result = collect([]);
            return view('admin.articleAdd')->with(['result' => $result]);
        } else {
            $data = $request->all();
            $article = Article::create($data);
            $articleId = $article->id;
            $tags = $data['tags'];
            $article->tag->createMany($tags);
        }
    }

    public function modify(){
        echo 2222;
    }

    public function show($id)
    {
//        $result = Article::find($id);
    }
}
