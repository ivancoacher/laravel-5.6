<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Forum extends Model
{
    //
    protected $table = 'wxC_forum_t';
    const CREATED_AT = 'cdate';
    const UPDATED_AT = 'udate';
}
