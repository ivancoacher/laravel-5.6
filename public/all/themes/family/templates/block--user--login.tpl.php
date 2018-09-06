<span class="hidden">split-block</span>
                     <div class="form-group title-login-section">               
                             <span class="title-login">Log in</span>
                        </div>
            <?php
            $form = drupal_get_form('user_login_block');
            print drupal_render($form);
            ?>

