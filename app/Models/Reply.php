<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Reply extends Model
{
    //
    protected $table = 'wxC_reply_t';
    const CREATED_AT = 'cdate';
    const UPDATED_AT = 'udate';

    public function toReply()
    {
        return $this->hasOne(User::class, 'reply_to_id', 'id');
    }

    public function author()
    {
        return $this->hasOne(User::class, 'user_id', 'id');
    }
}
