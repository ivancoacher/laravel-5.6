<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class User extends Model
{
    //
    protected $table = 'wxC_user_t';

    const CREATED_AT = 'cdate';
    const UPDATED_AT = 'udate';
}
