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
    <?php echo $__env->yieldContent('pre_link'); ?>
    <?php echo $__env->yieldContent('pre_script'); ?>
    <![endif]-->
</head>
<body class="layui-layout-body">
<div class="layui-layout layui-layout-admin">
    <div class="layui-header">
        <div class="layui-logo">虎妈牛娃后台管理</div>
        <!-- 头部区域（可配合layui已有的水平导航） -->
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    </div>

    <div class="layui-side layui-bg-black">
        <div class="layui-side-scroll">
            <!-- 左侧导航区域（可配合layui已有的垂直导航） -->
            <ul class="layui-nav layui-nav-tree" lay-filter="test">
                <li class="layui-nav-item layui-nav-itemed">
                    <a class="" href="javascript:;">User Management</a>
                    <dl class="layui-nav-child">
                        <dd><a href="/admin/users">User List</a></dd>
                        
                        
                        
                    </dl>
                </li>
                <li class="layui-nav-item">
                    <a href="javascript:;">School Management</a>
                    <dl class="layui-nav-child">
                        <dd><a href="/admin/schools">School List</a></dd>
                        
                        
                    </dl>
                </li>
                <li class="layui-nav-item">
                    <a href="javascript:;">Article Management</a>
                    <dl class="layui-nav-child">
                        <dd><a href="/admin/articles">Article List</a></dd>
                        
                        
                    </dl>
                </li>
                <li class="layui-nav-item">
                    <a href="javascript:;">Ad Management</a>
                    <dl class="layui-nav-child">
                        <dd><a href="/admin/ads">Ad List</a></dd>
                        
                        
                    </dl>
                </li>
                
                
            </ul>
        </div>
    </div>

    <div class="layui-body">
        <!-- 内容主体区域 -->
        <div style="padding: 15px;">
            <?php echo $__env->yieldContent('content'); ?>
        </div>
    </div>

    
        
        
    
</div>
<script src="/plugins/layui/layui.js"></script>
<script>
    //JavaScript代码区域
    layui.use('element', function () {
        var element = layui.element;

    });
</script>
<?php echo $__env->yieldContent('post_link'); ?>
<?php echo $__env->yieldContent('post_script'); ?>
</body>
</html>