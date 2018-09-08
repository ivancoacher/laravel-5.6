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
Route::get('/things-to-do','ArticleController@index');
Route::get('/health-wellness','ArticleController@index');
Route::get('/education','ArticleController@index');
Route::get('/home-style','ArticleController@index');
Route::get('/shanghai/articles/win','ArticleController@index');
Route::get('/shanghai/articles/quick-reads','ArticleController@index');
Route::get('/node/add/listings','ArticleController@index');
Route::get('/node/add/events','ArticleController@index');
Route::get('/node/add/schools','ArticleController@index');


