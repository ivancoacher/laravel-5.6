@extends('admin.layouts.base')

@section('content')

    <a href="/admin/manager/add" class="layui-btn layui-btn-sm">
        add manager
    </a>

    <table class="layui-table">
        <thead>
        <tr>
            <th>name</th>
            <th>email</th>
            <th>user type</th>
            <th>last login time</th>
            <th>operation</th>
        </tr>
        </thead>
        <tbody>
        @if($result->isNotEmpty())
            @foreach($result as $k=>$v)
                <tr>
                    <td>{{$v->name}}</td>
                    <td>{{$v->email}}</td>
                    <td>{{$v->userRole->role->role_name??''}}</td>
                    <td>{{$v->last_login_time}}</td>
                    <td>
                        <a href="/admin/manager/modify/id/{{$v->id}}" class="layui-btn layui-btn-sm">
                            edit
                        </a>
                        <button  class="layui-btn layui-btn-sm" onclick="resetPassword({{$v->id}})">
                            reset password
                        </button>
                        <button  class="layui-btn layui-btn-sm layui-btn-danger" onclick="deleteAdmin({{$v->id}})">
                            delete
                        </button>
                    </td>
                </tr>
            @endforeach
        @else
            <tr>
                <td style="text-align: center" colspan="4">no data</td>
            </tr>
        @endif
        </tbody>
    </table>

@endsection

@section('post_script')
    <script>
        function resetPassword(id) {
            $.post(
                '/admin/manager/resetPassword',
                {
                    user_id:id
                },
                function (data) {
                    if (data.success == 1){
                        layer.open({
                            title: '重置密码成功'
                            ,content: data.content
                        });
                    }else{
                        layer.msg('重置密码失败')
                    }
                }
            )
        }

        function deleteAdmin(id) {
            $.post(
                '/admin/manager/delete',
                {
                    user_id:id
                },
                function (data) {
                    if (data.success == 1){
                        layer.msg('删除成功')
                    }else{
                        layer.msg('删除失败')
                    }
                }
            )
        }
    </script>
@endsection
