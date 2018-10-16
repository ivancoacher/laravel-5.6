@extends('admin.layouts.base')

@section('content')

    <table class="layui-table">
        <colgroup>
            <col width="150">
            <col width="200">
            <col>
        </colgroup>
        <thead>
        <tr>
            <th>name</th>
            <th>email</th>
            <th>last login time</th>
        </tr>
        </thead>
        <tbody>
        @if($result->isNotEmpty())
            @foreach($result as $k=>$v)
                <tr>
                    <td>{{$v->name}}</td>
                    <td>{{$v->email}}</td>
                    <td>{{$v->last_login_time}}</td>
                </tr>
            @endforeach
        @else
            <tr>
                <td style="text-align: center" colspan="3">no data</td>
            </tr>
        @endif
        </tbody>
    </table>

@endsection
