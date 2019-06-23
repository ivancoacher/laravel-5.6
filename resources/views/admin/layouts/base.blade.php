<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">
    <title>Management |Shanghai Family</title>
    <link rel="stylesheet" href="/plugins/layui/css/layui.css">
    <!--[if lt IE 9]>
    <script src="https://cdn.staticfile.org/html5shiv/r29/html5.min.js"></script>
    <script src="https://cdn.staticfile.org/respond.js/1.4.2/respond.min.js"></script>
    <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.8.0/jquery.min.js">

    <![endif]-->

    @yield('pre_link')
    @yield('pre_script')
</head>
<body class="layui-layout-body" layadmin-themealias="default">
<div class="layui-layout layui-layout-admin">
    <div class="layui-header">
        <div class="layui-logo">虎妈牛娃后台管理</div>
        <ul class="layui-nav layui-layout-right">
            <li class="layui-nav-item">
                <a href="javascript:;">
                    <img src="https://shfamily.com/images/logo_0.png" class="layui-nav-img"
                         style="background-color: #fff">
                    {{session('userInfo')->name}}
                </a>
                <dl class="layui-nav-child">
                    <dd><a href="/admin/users/profile">Profile</a></dd>
                    <dd><a href="/admin/users/changePassword">change Password</a></dd>
                </dl>
            </li>
            <li class="layui-nav-item"><a href="/admin/logout">退了</a></li>
        </ul>
    </div>

    <div class="layui-side layui-bg-black">
        <div class="layui-side-scroll">

            <!-- 左侧导航区域（可配合layui已有的垂直导航） -->
            <ul class="layui-nav layui-nav-tree" lay-filter="test">
                @if(in_array('admin.user',session('permission')))
                    <li class="layui-nav-item layui-nav-itemed">
                        <a class="" href="javascript:;">User Management</a>
                        <dl class="layui-nav-child">
                            {{--                            @if(session('userInfo')->user_type == 'super_admin')--}}
                            <dd><a href="/admin/manager">Manager List</a></dd>

                            {{--@endif--}}
                            <dd><a href="/admin/users">User List</a></dd>
                        </dl>
                    </li>
                @endif
                @if(in_array('admin.article',session('permission')))
                    <li class="layui-nav-item">
                        <a href="javascript:;">Article Management</a>
                        <dl class="layui-nav-child">
                            <dd><a href="/admin/articles">Article List</a></dd>
                            <dd><a href="/admin/articles/comments">Comments List</a></dd>
                        </dl>
                    </li>
                @endif
                @if(in_array('admin.ad',session('permission')))

                    <li class="layui-nav-item">
                        <a href="javascript:;">Ad Management</a>
                        <dl class="layui-nav-child">
                            <dd><a href="/admin/ads/list">Ads List</a></dd>
                            {{--<dd><a href="/admin/ads/list/expired">Ads Expired List</a></dd>--}}
                        </dl>
                    </li>
                @endif
                @if(in_array('admin.gallery',session('permission')))

                    <li class="layui-nav-item">
                        <a href="javascript:;">Gallery Management</a>
                        <dl class="layui-nav-child">
                            <dd><a href="/admin/galleries">Gallery List</a></dd>
                        </dl>
                    </li>
                @endif
                @if(in_array('admin.school',session('permission')))

                    <li class="layui-nav-item">
                        <a href="javascript:;">School Management</a>
                        <dl class="layui-nav-child">
                            @if(in_array('admin.school.list',session('permission')))
                                <dd><a href="/admin/schools">School List</a></dd>
                                <dd><a href="/admin/schools/cn">School CN List</a></dd>
                            @endif
                            @if(in_array('admin.school.account',session('permission')))
                                <dd><a href="/admin/schools/account/list">School Account List</a></dd>
                            @endif
                        </dl>
                    </li>
                @endif
                @if(in_array('admin.system',session('permission')))

                    <li class="layui-nav-item">
                        <a href="javascript:;">System Management</a>
                        <dl class="layui-nav-child">
                            <dd><a href="/admin/system/about-us">About us</a></dd>
                            <dd><a href="/admin/system/career">Career</a></dd>
                            <dd><a href="/admin/system/advertise">Why Advertise with Us</a></dd>
                            <dd><a href="/admin/system/wechat">Wechat</a></dd>
                            <dd><a href="/admin/system/email">Email</a></dd>
                            <dd><a href="/admin/system/telephone">Telephone</a></dd>
                            <dd><a href="/admin/system/facebook">Facebook</a></dd>
                        </dl>
                    </li>
                @endif
                @if(in_array('admin.download',session('permission')))

                    <li class="layui-nav-item">
                        <a href="javascript:;">Download Management</a>
                        <dl class="layui-nav-child">
                            <dd><a href="/admin/issues">Issues List</a></dd>
                            <dd><a href="/admin/guides">Guides List</a></dd>
                        </dl>
                    </li>
                @endif
                @if(in_array('admin.video',session('permission')))

                    <li class="layui-nav-item">
                        <a href="javascript:;">Video Management</a>
                        <dl class="layui-nav-child">
                            <dd><a href="/admin/video/list">Video List</a></dd>
                        </dl>
                    </li>
                @endif
                @if(in_array('admin.picture',session('permission')))

                    <li class="layui-nav-item">
                        <a href="javascript:;">Picture Management</a>
                        <dl class="layui-nav-child">
                            <dd><a href="/admin/picture">Picture List</a></dd>
                        </dl>
                    </li>
                @endif
                @if(in_array('admin.permissions',session('permission')))

                    <li class="layui-nav-item">
                        <a href="javascript:;">Permissions Management</a>
                        <dl class="layui-nav-child">
                            <dd><a href="/admin/roles">Role List</a></dd>
                        </dl>
                    </li>
                @endif
                @if(in_array('admin.city',session('permission')))
                    <li class="layui-nav-item">
                        <a href="javascript:;">City Management</a>
                        <dl class="layui-nav-child">
                            <dd><a href="/admin/cities">City List</a></dd>
                            <dd><a href="/admin/city/account/list">City Account List</a></dd>
                        </dl>
                    </li>
                @endif
                <li class="layui-nav-item">
                    <a href="javascript:;">Analysis</a>
                    <dl class="layui-nav-child">
                        <dd><a href="/admin/analysis">Analysis</a></dd>
                    </dl>
                </li>
                <li class="layui-nav-item">
                    <a href="javascript:;">Miniprogram Management</a>
                    <dl class="layui-nav-child">
                        <dd><a href="/admin/miniprogram/schools">School List</a></dd>
                    </dl>
                </li>
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
<script src="/js/jquery.min.js"></script>
<script>
    var layer;
    //JavaScript代码区域
    layui.use(['element', 'layer', 'form'], function () {
        var element = layui.element;
        layer = layui.layer
        form = layui.form;
        form.render()
    });
</script>
@yield('post_link')
@yield('post_script')
</body>
</html>