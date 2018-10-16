<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">
    <title>虎妈牛娃</title>
    <link rel="stylesheet" href="/plugins/layui/css/layui.css">
    <!--[if lt IE 9]>
    <script src="https://cdn.staticfile.org/html5shiv/r29/html5.min.js"></script>
    <script src="https://cdn.staticfile.org/respond.js/1.4.2/respond.min.js"></script>
    @yield('pre_link')
    @yield('pre_script')
    <![endif]-->
</head>
<body class="layui-layout-body">
<div class="layui-layout layui-layout-admin">
    <div class="layui-header">
        <div class="layui-logo">虎妈牛娃后台管理</div>
        <!-- 头部区域（可配合layui已有的水平导航） -->
        {{--<ul class="layui-nav layui-layout-left">--}}
        {{--<li class="layui-nav-item"><a href="">控制台</a></li>--}}
        {{--<li class="layui-nav-item"><a href="">商品管理</a></li>--}}
        {{--<li class="layui-nav-item"><a href="">用户</a></li>--}}
        {{--<li class="layui-nav-item">--}}
        {{--<a href="javascript:;">其它系统</a>--}}
        {{--<dl class="layui-nav-child">--}}
        {{--<dd><a href="">邮件管理</a></dd>--}}
        {{--<dd><a href="">消息管理</a></dd>--}}
        {{--<dd><a href="">授权管理</a></dd>--}}
        {{--</dl>--}}
        {{--</li>--}}
        {{--</ul>--}}
        {{--<ul class="layui-nav layui-layout-right">--}}
        {{--<li class="layui-nav-item">--}}
        {{--<a href="javascript:;">--}}
        {{--<img src="http://t.cn/RCzsdCq" class="layui-nav-img">--}}
        {{--贤心--}}
        {{--</a>--}}
        {{--<dl class="layui-nav-child">--}}
        {{--<dd><a href="">基本资料</a></dd>--}}
        {{--<dd><a href="">安全设置</a></dd>--}}
        {{--</dl>--}}
        {{--</li>--}}
        {{--<li class="layui-nav-item"><a href="">退了</a></li>--}}
        {{--</ul>--}}
    </div>

    <div class="layui-side layui-bg-black">
        <div class="layui-side-scroll">
            <!-- 左侧导航区域（可配合layui已有的垂直导航） -->
            <ul class="layui-nav layui-nav-tree" lay-filter="test">
                <li class="layui-nav-item layui-nav-itemed">
                    <a class="" href="javascript:;">User Management</a>
                    <dl class="layui-nav-child">
                        <dd><a href="/admin/users">User List</a></dd>
                        {{--<dd><a href="javascript:;">列表二</a></dd>--}}
                        {{--<dd><a href="javascript:;">列表三</a></dd>--}}
                        {{--<dd><a href="">超链接</a></dd>--}}
                    </dl>
                </li>
                <li class="layui-nav-item">
                    <a href="javascript:;">School Management</a>
                    <dl class="layui-nav-child">
                        <dd><a href="/admin/schools">School List</a></dd>
                        {{--<dd><a href="javascript:;">列表二</a></dd>--}}
                        {{--<dd><a href="">超链接</a></dd>--}}
                    </dl>
                </li>
                <li class="layui-nav-item">
                    <a href="javascript:;">Article Management</a>
                    <dl class="layui-nav-child">
                        <dd><a href="/admin/articles">Article List</a></dd>
                        {{--<dd><a href="javascript:;">列表二</a></dd>--}}
                        {{--<dd><a href="">超链接</a></dd>--}}
                    </dl>
                </li>
                <li class="layui-nav-item">
                    <a href="javascript:;">Ad Management</a>
                    <dl class="layui-nav-child">
                        <dd><a href="/admin/ads">Ad List</a></dd>
                        {{--<dd><a href="javascript:;">列表二</a></dd>--}}
                        {{--<dd><a href="">超链接</a></dd>--}}
                    </dl>
                </li>
                {{--<li class="layui-nav-item"><a href="">云市场</a></li>--}}
                {{--<li class="layui-nav-item"><a href="">发布商品</a></li>--}}
            </ul>
        </div>
    </div>

    <div class="layui-body">
        <!-- 内容主体区域 -->
        <div style="padding: 15px;">
            @yield('content')
        </div>
    </div>

    {{--<div class="layui-footer">--}}
        {{--<!-- 底部固定区域 -->--}}
        {{--© layui.com - 底部固定区域--}}
    {{--</div>--}}
</div>
<script src="/plugins/layui/layui.js"></script>
<script>
    //JavaScript代码区域
    layui.use('element', function () {
        var element = layui.element;

    });
</script>
@yield('post_link')
@yield('post_script')
</body>
</html>