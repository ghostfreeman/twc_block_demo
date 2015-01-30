<?php
/**
 * Implements the form interface for users to define their own welcome
 * message as required by requirements. A function runs to load the field should
 * an entry already exist for the user is in the `login_messages` table with
 * their current User ID.
 */
function twc_block_demo_form($form, $form_state) {

}

/**
 * This is a validation function scaffold for the above form. Since its a
 * scaffold, nothing is used.
 */
function twc_block_demo_form_validate($form, &$form_state) {

}

/**
 * Save all changes to the database and then returns to the home page with a
 * message statign the changes have been saved
 */
function twc_block_demo_form_submit($form, &$form_state) {

}

/**
 * Look up the database for any existing field entries. If they exist, send them
 * back.
 */
function twc_block_demo_form_find_existing($user_id) {

}

/**
 * Write the new message to the database.
 */
function twc_block_demo_form_save_message($user_id, $message) {

}
