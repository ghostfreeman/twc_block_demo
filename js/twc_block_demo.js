Drupal.behaviors.twc_block_demo_hide_last_login = {
  attach: function(context, settings) {
    if (jQuery('#block-twc-block-demo-user-last-login').length) {
      jQuery('#block-twc-block-demo-user-last-login').delay(10000).slideUp();
    }
  }
};
