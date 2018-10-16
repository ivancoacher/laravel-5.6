<?php $__env->startSection('content'); ?>

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
        <?php if($result->isNotEmpty()): ?>
            <?php $__currentLoopData = $result; $__env->addLoop($__currentLoopData); foreach($__currentLoopData as $k=>$v): $__env->incrementLoopIndices(); $loop = $__env->getLastLoop(); ?>
                <tr>
                    <td><?php echo e($v->name); ?></td>
                    <td><?php echo e($v->email); ?></td>
                    <td><?php echo e($v->last_login_time); ?></td>
                </tr>
            <?php endforeach; $__env->popLoop(); $loop = $__env->getLastLoop(); ?>
        <?php else: ?>
            <tr>
                <td style="text-align: center" colspan="3">no data</td>
            </tr>
        <?php endif; ?>
        </tbody>
    </table>

<?php $__env->stopSection(); ?>

<?php echo $__env->make('admin.layouts.base', array_except(get_defined_vars(), array('__data', '__path')))->render(); ?>