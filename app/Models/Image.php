<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Image extends Model
{
    //
    protected $table = 'wxC_image_t';
    const CREATED_AT = 'cdate';
    const UPDATED_AT = 'udate';
}
