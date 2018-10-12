<?php

/*
|--------------------------------------------------------------------------
| API Routes
|--------------------------------------------------------------------------
|
| Here is where you can register API routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| is assigned the "api" middleware group. Enjoy building your API!
|
*/

$api = app('Dingo\Api\Routing\Router');
$api->version('v1', function ($api) {
    $api->group(['prefix' => 'bbs', 'namespace' => 'App\Http\Controllers\V1\Home'], function ($api) {
        $api->get('list', 'BBSController@index');
        $api->get('store', 'BBSController@store');
        $api->get('show', 'BBSController@show');
        $api->get('changeStore', 'BBSController@changeStore');

    });
    $api->group(['prefix' => 'comment', 'namespace' => 'App\Http\Controllers\V1\Home'], function ($api) {
        $api->get('list', 'CommentController@index');
        $api->get('store', 'CommentController@store');
        $api->get('show', 'CommentController@show');
        $api->get('replyList', 'CommentController@replyList');
        $api->get('changeAgree', 'CommentController@changeAgree');
    });

    $api->group(['prefix' => 'user', 'namespace' => 'App\Http\Controllers\V1\Home'], function ($api) {
        $api->any('getOpenid', 'UserController@getOpenid'); //done
        $api->get('userStore', 'UserController@userStore');
        $api->get('userReply', 'UserController@store');
        $api->get('userPub', 'UserController@show');
        $api->get('userSuper', 'UserController@show');
    });

});