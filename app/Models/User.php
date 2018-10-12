<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class User extends Model
{
    //
    protected $table = 'wxC_user_t';

    const CREATED_AT = 'cdate';
    const UPDATED_AT = 'udate';
    protected $primaryKey = 'id';
    protected $keyType = 'string';

    public function comments()
    {
        return $this->hasMany(Comment::class, 'id', 'user_id');
    }

    public function replies()
    {
        return $this->hasMany(Reply::class, 'id', 'user_id');
    }

    public function bbs()
    {
        return $this->hasMany(Bbs::class, 'id', 'user_id');
    }

    public function store()
    {
        return $this->hasMany(Store::class, 'id', 'user_id');
    }

    public function agree()
    {
        return $this->hasMany(Agree::class, 'id', 'user_id');
    }


}
