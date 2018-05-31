/**
 * @file
 * Implements Chosen widget.
 */
(function($) {
  Drupal.behaviors.chosen_ajax = {
    attach: function(context) {
      $('input.chosen-ajax', context).once('chosen', function() {
        var uri = this.value;
        var $input = $('#' + this.id.substr(0, this.id.length - 12));
        var options = {};
        if (Drupal.settings.chosen_ajax && Drupal.settings.chosen_ajax[this.id]) {
          options = Drupal.settings.chosen_ajax[this.id];
          if (options['typing_placeholder']) {
            options['keepTypingMsg'] = options['typing_placeholder'];
          }
          if (options['searching_placeholder']) {
            options['lookingForMsg'] = options['searching_placeholder'];
          }
        }
        var ajaxChosenOptions = chosenOptions = options;
        $.extend(ajaxChosenOptions, {
          method: 'GET',
          url: uri,
          dataType: 'json',
          jsonTermKey: ''
        });
        $input.ajaxChosen(ajaxChosenOptions, function(data) {return data;}, chosenOptions);
      });
    }
  }
})(jQuery);
