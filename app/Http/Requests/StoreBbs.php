<?php

namespace App\Http\Requests;

use Illuminate\Foundation\Http\FormRequest;

class StoreBbs extends FormRequest
{
    /**
     * Determine if the user is authorized to make this request.
     *
     * @return bool
     */
    public function authorize()
    {
        return true;
    }

    /**
     * Get the validation rules that apply to the request.
     *
     * @return array
     */
    public function rules()
    {
        return [
            //
            'openid' => 'required',
            'nick_name' => "required",
            'head_url' => 'required',
            'forum_id' => 'required',

            'title' => 'required',
            'content' => 'required',

            'expert' => 'required',
            'img_list' => 'required',
            'tag' => 'nullable',
            'tag_content' => 'nullable'
        ];
    }
}
