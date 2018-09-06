<?php
/**
 * See fs_user_editor_meet_editors section in fs_user_editor_block_view function.
 */
?>
<section id="editor_section">
    <div class="col-xs-12 title_editor">
         <h1>MEET THE EDITORS</h1>        
    </div>
    <div class="col-xs-12 container_editor">
        <div class="wrapper_editor">
          <?php foreach($items as $item): ?>
        <div class="item-editor">
            <a href=" <?php print $item['link']; ?>">
            <img src="<?php print $item['photo']; ?>">
            <div class="editor_overlay"></div>
            <div class="text_editor_name"><?php print $item['first_name']; ?></div>
            </a>
        </div>
        <?php endforeach ;?>
        </div>    
    </div>
</section>