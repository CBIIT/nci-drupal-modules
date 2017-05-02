(function ($) {

  'use strict';

  Drupal.behaviors.responsive_menu = {
    attach: function (context, settings) {

      $('body', context).once('responsive-menu', function() {

        if (typeof($.mmenu) != 'undefined') {

          // Get the position and theme options from Drupal settings.
          var position = Drupal.settings.responsive_menu.position;
          var theme = Drupal.settings.responsive_menu.theme;

          // Set up the off canvas menu.
          $('#off-canvas').mmenu({
            extensions: [theme, 'effect-slide-menu'],
            offCanvas: {
              zposition: 'next',
              position: position
            }
          }, {
            clone: false
          });
        }

        // Apply the superfish library to the menu.
        if ($.fn.superfish) {
          // Get the superfish settings.
          var superfishDelay = Drupal.settings.responsive_menu.superfish.delay,
            superfishSpeed = Drupal.settings.responsive_menu.superfish.speed,
            superfishSpeedOut = Drupal.settings.responsive_menu.superfish.speedOut;
          // Attach superfish to the responsive menu.
          $('#horizontal-menu').superfish({
            delay: parseInt(superfishDelay, 10),
            speed: parseInt(superfishSpeed, 10),
            speedOut: parseInt(superfishSpeedOut, 10)
          }).addClass('sf-menu');
        }

        // Add the Hammer config if needed.
        if (typeof(Hammer) != 'undefined') {

          var mc = new Hammer($('body').get(0), {
            cssProps: {
              userSelect: true
            },
            // Reset the touchAction to auto as this allows pinch zooming.
            // mmenu handles the scrolling once open.
            touchAction: 'auto'
          });
          mc.get('swipe').set({
            velocity: 0.3,
            threshold: 5
          });

          mc.on("swipeleft swiperight", function(e) {
            // Only do something if we're below our breakpoint. The simplest
            // method is to check whether the horizontal desktop sized
            // responsive menu is hidden.
            if ($('.responsive-menu-block-wrapper').is(':hidden')) {
              hammerswipe(mc, e);
            }
          });

        }

      });
    }
  };

  /**
   * Opens or closes the mmenu based on swipe direction.
   *
   * @param mc
   *   Hammer object instance.
   * @param e
   *   Swipe event.
   */
  function hammerswipe(mc, e) {
    var position = Drupal.settings.responsive_menu.position;
    var api = $('#off-canvas').data('mmenu'),
      $html = $('html');

    if (e.type == 'swiperight') {
      if (position == 'right' && $html.hasClass('mm-opened')) {
        // Close the menu.
        api.close();
      }
      if (position == 'left' && !$html.hasClass('mm-opened')) {
        // Open the menu.
        api.open();
      }
    }

    if (e.type == 'swipeleft') {
      if (position == 'right' && !$html.hasClass('mm-opened')) {
        // Open the menu.
        api.open();
      }
      if (position == 'left' && $html.hasClass('mm-opened')) {
        // Close the menu.
        api.close();
      }
    }
  }

})(jQuery);
