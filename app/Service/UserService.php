<?php

namespace App\Service;

use App\Models\User;

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

    }


}


?>