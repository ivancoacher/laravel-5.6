<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Store extends Model
{
    //
    protected $table = 'wxC_store_t';
    const CREATED_AT = 'cdate';
    const UPDATED_AT = 'udate';
    public $incrementing = false;
    protected $keyType = 'string';
    public function bbs()
    {
        return $this->hasOne(Bbs::class, 'id', 'bbs_id');
    }

    public function author()
    {
        return $this->hasOne(User::class, 'id', 'user_id');
    }
}
