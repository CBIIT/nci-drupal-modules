/**
 * @file
 * Client-side filtering for GatherContent module.
 */

(function ($, Drupal, window) {
  'use strict';

  Drupal.behaviors.gathercontentImportSelectedCounter = {
    attach: function (context) {
      $('.gathercontent-checkboxcounter[data-gathercontent-counter-id]', context).once('gathercontent-checkboxcounter').each(function () {
        var $self = $(this);
        var count = 0;
        var counterId = $(this).data('gathercontent-counter-id');
        var counterSettings = Drupal.settings[counterId];
        var $checkboxes = $(this).closest('form').find('input[type="checkbox"]');
        var singular = '1 item selected';
        var plural = '@count items selected';

        if (typeof counterSettings === 'object') {
          if (typeof counterSettings.checkboxesSelector === 'string') {
            $checkboxes = $(counterSettings.checkboxesSelector);
          }

          if (typeof counterSettings.counterMessage === 'object') {
            singular = typeof counterSettings.counterMessage[0] === 'string' ?
              counterSettings.counterMessage[0] : singular;
            plural = typeof counterSettings.counterMessage[1] === 'string' ?
              counterSettings.counterMessage[1] : plural;
          }
        }

        count = $checkboxes.filter(':checked').length;
        $self.text(Drupal.formatPlural(count, singular, plural));

        $checkboxes.bind('change', function () {
          count = $checkboxes.filter(':checked').length;
          $self.text(Drupal.formatPlural(count, singular, plural));
        });
      });
    }
  };

})(jQuery, Drupal, window);
