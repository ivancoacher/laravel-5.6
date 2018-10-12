<?php

namespace App\Service;

use App\Models\Bbs;
use App\Models\Comment;
use App\Models\Reply;
use App\Models\Store;
use App\Models\User;
use Illuminate\Support\Facades\DB;

class UserService
{

    public function getUserByOpenid($openid)
    {
        return User::where('openid', $openid)->first();
    }

    public function getUserById($id)
    {
        return User::find($id);
    }

    public function updateUserByOpenid($openid, $data)
    {
        return User::where('openid', $openid)->update($data);
    }

    public function storeUser($data)
    {
        $result = User::create($data);
        return $result->id;
    }

    public function updateUserThreshTime($openid)
    {
        return User::where('openid', $openid)->update(['thresh_time' => time()]);
    }

    public function getUserId($openid)
    {
        $result = User::where('openid', $openid)->first();
        return $result->id;
    }




}


?>