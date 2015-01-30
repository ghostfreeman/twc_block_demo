<?php

$plugin = array(
  'title' =>  t("Welcome"),
  'description' => t("This adds a friendly note in which the user can see when they last logged in."),
  'single' => TRUE,
  'category' => array(t("User"), -15),
  'edit form' => 'twc_block_demo_pane_edit_form',
  'admin info' => 'twc_block_demo_pane_admin_info',
  'default' => array(
    'text' => '',
  ),
  'render callback' => 'twc_block_demo_pane_ctype_render',
  'all contexts' => TRUE,
);

/**
 * This callback function should just load the existing content load inside
 * .module. That's why they call it modular code, no?
 */
function twc_block_demo_pane_ctype_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  $block->title = t("Welcome");
  $block->content = twc_block_demo_output();
  return $block;
}

/**
 * Apparantly I need to have an edit form in place for the pane.
 */
function twc_block_demo_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  return $form;
}
