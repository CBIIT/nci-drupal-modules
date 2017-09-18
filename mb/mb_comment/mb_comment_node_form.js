
(function ($) {
  
Drupal.behaviors.mbCommentFieldsetSummaries = {
  attach: function (context) {
    // Provide the summary for the content type form.
    $('fieldset#edit-comment-buttons', context).drupalSetSummary(function(context) {
      var vals = [];

      // Cancel button.
      var cancel = $("select[name='mb_comment_cancel'] option:selected", context).text();
      cancel = Drupal.t('Cancel button') + ": " + cancel;
      vals.push(cancel);

      return Drupal.checkPlain(vals.join(', '));
    });
  }
};

})(jQuery);
