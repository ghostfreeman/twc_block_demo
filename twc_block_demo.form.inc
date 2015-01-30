<?php
/**
 * Implements the form interface for users to define their own welcome
 * message as required by requirements. A function runs to load the field should
 * an entry already exist for the user is in the `login_messages` table with
 * their current User ID.
 */
function twc_block_demo_form($form, $form_state) {
  global $user;
  $form = array();
  $defaults = twc_block_demo_form_find_existing($user->uid);

  $form['message'] = array(
    '#type' => 'textfield',
    '#title' => t("Message"),
    '#default_value' => (isset($defaults) ? $defaults : ""),
    '#description' => "This message will be used, with the login date preceding it at the end. To reset to default, leave the field empty.",
  );

  $form['buttons'] = array();

  $form['buttons']['submit'] = array(
    "#type" => 'submit',
    "#value" => t('Save Changes'),
  );

  return $form;
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
  global $user;
  $save_status = twc_block_demo_form_save_message($user->uid, $form_state['values']['message']);
  drupal_set_message("The message has been saved.");
}

/**
 * Look up the database for any existing field entries. If they exist, send them
 * back.
 */
function twc_block_demo_form_find_existing($user_id) {
  $results = db_query("SELECT message FROM {login_messages} WHERE user_id = :n_user_id", array(":n_user_id" => $user_id));

  foreach ($results as $result) {
    $message = $result->message;
  }

  if(isset($message)) {
    return $message;
  } else {
    return null;
  }
}

/**
 * Write the new message to the database.
 */
function twc_block_demo_form_save_message($user_id, $message) {
  //Check if record exists

  $result = twc_block_demo_form_find_existing($user_id);

  if(sizeof($result) > 0) {
    //Record exists, we need to do an UPDATE call
    $result = db_update('login_messages')
      ->fields(array(
          'message' => $message,
        )
      )
      ->condition('user_id', $user_id, '=')
      ->execute();
  } else {
    //Record does not exist, create an INSERT call
    $result = db_insert('login_messages')
      ->fields(
        array(
          'user_id' => $user_id,
          'message' => $message,
        )
      )
      ->execute();
  }

  return $result;
}
