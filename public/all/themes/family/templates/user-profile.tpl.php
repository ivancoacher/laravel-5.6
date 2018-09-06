<?php

/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $account->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $account->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 *
 * @ingroup themeable
 */

//dpm(current_path());
//var_dump(explode("/",current_path()));
$uid_current=explode("/",current_path())[1];
$user=user_load(intval($uid_current));

//global $user;
//$user_details = $user_profile['field_city']['#object'];
//$first_name = (count($user_details->field_first_name) && isset($user_details->field_first_name[LANGUAGE_NONE])) ? $user_details->field_first_name[LANGUAGE_NONE][0]['value'] : '';
//$last_name = (count($user_details->field_last_name) && isset($user_details->field_last_name[LANGUAGE_NONE])) ? $user_details->field_last_name[LANGUAGE_NONE][0]['value'] : '';
$user_picture = '';
$city = '';
$joined_date = '';
if (!empty($user_details->picture->uri)):
    $user_picture = file_create_url($user_details->picture->uri); //$user_picture = image_style_url("thumbnail", $user_details->picture->uri);
endif;

if (!empty($user_details->created)):
    $joined_date = format_date($user_details->created, 'custom', 'D, M j, Y');
endif;
?>


    <div class="container  user-menu-container square" <?php print $attributes; ?> >
        <div class="col-md-12 user-details">
            <div class="row coralbg white">
                <div class="col-md-6 no-pad">
                    <div class="user-pad">
                        <h3>Welcome back, <?php print ucwords($user->name) ?></h3>
                        <h4 class="white"><i class="fa fa-envelope" aria-hidden="true"></i> <?php print ucwords($user->mail); ?></h4>
                        <h4 class="white hidden"><i class="fa fa-building-o" aria-hidden="true"></i> Shanghai </h4>
                        <a type="button" class="btn btn-labeled btn-info" href="<?php print url('user/' . $user->uid . '/edit'); ?>">
                            <span class="btn-label"><i class="fa fa-pencil"></i></span>Update</a>
                    </div>
                </div>
                <div class="col-md-6 no-pad">
                    <div class="user-image">
                        <img src="<?php print variable_get("path_theme")."/images/my-profile-default.jpg";?>" class="img-responsive ">
                    </div>
                </div>
            </div>
<!--            <div class="row overview">
                <div class="col-md-4 user-pad text-center">
                    <h3>FOLLOWERS</h3>
                    <h4>2,784</h4>
                </div>
                <div class="col-md-4 user-pad text-center">
                    <h3>FOLLOWING</h3>
                    <h4>456</h4>
                </div>
                <div class="col-md-4 user-pad text-center">
                    <h3>APPRECIATIONS</h3>
                    <h4>4,901</h4>
                </div>
            </div>-->
        </div>      
    </div>

