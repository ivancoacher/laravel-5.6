<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Bbs extends Model
{
    //
    protected $table = 'wxC_bbs_t';
    const CREATED_AT = 'cdate';
    const UPDATED_AT = 'udate';

    public $incrementing = false;
    protected $keyType = 'string';

    //标签
    public function tags()
    {
        return $this->belongsToMany(Tag::class, 'wxC_bbs_tag_t', 'bbs_id', 'tag_id');
    }

    //作者
    public function author()
    {
        return $this->hasOne(User::class, 'author_id', 'id');
    }

    //内部图片
    public function images()
    {
        return $this->belongsToMany(Image::class, 'wxC_bbs_image_t', 'bbs_id', 'image)id');
    }

    //封面图
    public function surfaceImage()
    {
        return $this->hasOne(Image::class, 'surface_img', 'id');
    }

    public function comments()
    {
        return $this->belongsTo(Bbs::class, 'bbs_id', 'idx');
    }

    public function replies()
    {
        return $this->belongsTo(Bbs::class, 'bbs_id', 'idx');
    }

}
