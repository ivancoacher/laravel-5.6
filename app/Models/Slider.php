<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Slider extends Model
{
    //
    protected $table = 'wxC_slider_t';
    const CREATED_AT = 'cdate';
    const UPDATED_AT = 'udate';
    public $incrementing = false;
    protected $keyType = 'string';
}
