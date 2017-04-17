/**
 * @file
 * Client-side form auto submission for GatherContent module.
 */

(function ($, Drupal, window) {
  'use strict';

  Drupal.behaviors.gathercontentAutoSubmit = {
    attach: function (context) {
      $('.gathercontent-autosubmit', context).once('gathercontent-autosubmit', function () {
        var $markup = $('<div/>', {
          class: 'ajax-progress ajax-progress-throbber'
        });
        $markup.append($('<div/>', {
          class: 'throbber',
          html: '&nbsp;'
        }));
        $markup.append($('<div/>', {
          class: 'message',
          text: Drupal.t('Please wait...')
        }));

        $(this).bind('change', function (event) {
          if ($(this).val() !== '0') {
            $(this).closest('form').submit();
            $(this).closest('form').find('input[type="submit"]').attr('disabled', 'disabled');
            $markup.insertAfter($(this));
          }
        });
      });
    }
  };

})(jQuery, Drupal, window);
