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
    public $incrementing = false;
    protected $keyType = 'string';
    public function author()
    {
        return $this->hasOne(User::class, 'user_id', 'id');
    }

    public function reply()
    {
        return $this->hasMany(Reply::class, 'comment_id', 'id');
    }

    public function toReply()
    {
        return $this->hasOne(User::class, 'reply_to_id', 'id');
    }

}
