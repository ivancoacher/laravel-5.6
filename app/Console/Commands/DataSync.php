<?php

namespace App\Console\Commands;

use App\Models\Bbs;
use App\Models\Image;
use Illuminate\Console\Command;

class DataSync extends Command
{
    /**
     * The name and signature of the console command.
     *
     * @var string
     */
    protected $signature = 'command:bbs {param1}';

    /**
     * The console command description.
     *
     * @var string
     */
    protected $description = 'Command description';

    /**
     * Create a new command instance.
     *
     * @return void
     */
    public function __construct()
    {
        parent::__construct();
    }

    /**
     * Execute the console command.
     *
     * @return mixed
     */
    public function handle()
    {
        //
        $param1 = $this->argument('param1'); // 不指定参数名的情况下用argument
//        $param2 = $this->option('param2'); // 用--开头指定参数名

        if ($param1 == 'tag') {

            $bbsList = Bbs::all();

            foreach ($bbsList as $k => $v) {
                $tags = $v->tag;
                if (!$tags) {
                    continue;
                } else {
                    $bbsId = $v->id;
                    $tagId = explode(',', $tags);
                    $v->tags()->sync($tagId);
                }
            }
        }

        if ($param1 == 'images') {
            $bbsList = Bbs::all();
            foreach ($bbsList as $k => $v) {
                $images = $v->img_list;
                if (!$images) {
                    continue;
                } else {
                    $images = explode('|', $images);
                    $imageIds = [];
                    foreach ($images as $item => $value) {
                        $rst1 = Image::firstOrCreate(['url' => $value]);
                        $imageIds[] = $rst1->id;
                    }
                    $v->images()->sync($imageIds);
                }
            }
        }


    }
}
