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
    });
    $api->group(['prefix' => 'comment', 'namespace' => 'App\Http\Controllers\V1\Home'], function ($api) {
        $api->get('list', 'BBSController@index');
        $api->get('store', 'BBSController@store');
        $api->get('show', 'BBSController@show');
    });

    $api->group(['prefix' => 'user', 'namespace' => 'App\Http\Controllers\V1\Home'], function ($api) {
        $api->get('list', 'BBSController@index');
        $api->get('store', 'BBSController@store');
        $api->get('show', 'BBSController@show');
    });

});