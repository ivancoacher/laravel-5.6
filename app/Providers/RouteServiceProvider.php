<?php

namespace App\Providers;

use Illuminate\Foundation\Support\Providers\RouteServiceProvider as ServiceProvider;
use Illuminate\Support\Facades\Route;

class RouteServiceProvider extends ServiceProvider
{
    /**
     * This namespace is applied to your controller routes.
     *
     * In addition, it is set as the URL generator's root namespace.
     *
     * @var string
     */
    protected $namespace = 'App\Http\Controllers';

    /**
     * Define your route model bindings, pattern filters, etc.
     *
     * @return void
     */
    public function boot()
    {
        //

        parent::boot();
    }

    /**
     * Define the routes for the application.
     *
     * @return void
     */
    public function map()
    {
        $this->mapApiRoutes();
        $this->mapWebRoutes();
    }

    /**
     * Define the "web" routes for the application.
     *
     * These routes all receive session state, CSRF protection, etc.
     *
     * @return void
     */
    protected function mapWebRoutes()
    {


        $admin_prefix = config('admin.prefix');
        $admin_domain = config('admin.domain');

        if (!\App::runningInConsole() && empty($admin_prefix) && empty($admin_domain)) {
            throw new \Exception('ADMIN PREFIX OR DOMAIN MUST BE SET');
        }
        if (!empty($admin_prefix)) {
            $r = Route::prefix($admin_prefix);
        } else {
            $r = Route::domain($admin_domain);
        }
        $r->middleware(['web'])
            ->namespace($this->namespace . '\Admin')
            ->group(base_path('routes/admin.php'));


        $app_url = config('app.url');

        Route::domain($app_url)->middleware('web')
            ->namespace($this->namespace)
            ->group(base_path('routes/web.php'));

    }

    /**
     * Define the "api" routes for the application.
     *
     * These routes are typically stateless.
     *
     * @return void
     */
    protected function mapApiRoutes()
    {
        Route::prefix('api')
            ->namespace($this->namespace)
            ->group(base_path('routes/api.php'));
    }
}
