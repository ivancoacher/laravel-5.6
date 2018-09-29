<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Comment extends Model
{
    //
    protected $table = 'wxC_comment_t';
    protected $primaryKey = 'idx';
    const CREATED_AT = 'cdate';
    const UPDATED_AT = 'udate';
}
