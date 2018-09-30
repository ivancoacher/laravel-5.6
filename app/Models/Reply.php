<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Reply extends Model
{
    //
    protected $table = 'wxC_reply_t';
    const CREATED_AT = 'cdate';
    const UPDATED_AT = 'udate';
}
