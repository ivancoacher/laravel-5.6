<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Tag extends Model
{
    //
    protected $table = 'wxC_tag_t';
    const CREATED_AT = 'cdate';
    const UPDATED_AT = 'udate';
}