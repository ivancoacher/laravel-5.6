<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class GlobalModel extends Model
{
    //
    protected $table = 'wxC_global_t';

    const CREATED_AT = 'cdate';
    const UPDATED_AT = 'udate';
}
