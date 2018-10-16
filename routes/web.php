<?php

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/', 'IndexController@index');

Route::get('/shanghai/event', 'EventController@index');
Route::get('/shanghai-schools', 'EventController@index');
Route::get('/shanghai/article/guide-kindergartens-and-preschools-shanghai', 'EventController@index');
Route::get('/shanghai/article/guide-bilingual-schools-shanghai', 'EventController@index');
Route::get('/shanghai/article/guide-international-schools-shanghai', 'EventController@index');
Route::get('/food-drink', 'ArticleController@index');
Route::get('/things-to-do', 'ArticleController@index');
Route::get('/health-wellness', 'ArticleController@index');
Route::get('/education', 'ArticleController@index');
Route::get('/home-style', 'ArticleController@index');
Route::get('/shanghai/articles/win', 'ArticleController@index');
Route::get('/shanghai/articles/quick-reads', 'ArticleController@index');
Route::get('/node/add/listings', 'ArticleController@index');
Route::get('/node/add/events', 'ArticleController@index');
Route::get('/node/add/schools', 'ArticleController@index');


Route::namespace('Admin')->prefix('admin')->group(function () {

    Route::get('users', 'UserController@index');

    Route::get('articles', 'ArticleController@index');
    Route::get('articles/{id}', 'ArticleController@show');
    Route::get('articles/store', 'ArticleController@store');
    Route::any('articles/modify', 'ArticleController@modify');


    Route::get('schools', 'SchoolController@index');
    Route::any('schools/store', 'SchoolController@store');
    Route::get('schools/{id}', 'SchoolController@show');
    Route::any('schools/modify', 'SchoolController@modify');

    Route::get('ads', 'AdController@index');
    Route::any('ads/store', 'AdController@store');
    Route::get('ads/{id}', 'AdController@show');
    Route::any('ads/modify', 'AdController@modify');

    Route::get('settings', 'SettingController@index');

});


