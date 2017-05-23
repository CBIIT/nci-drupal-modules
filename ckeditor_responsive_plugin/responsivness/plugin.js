/**
 * @file
 * Plugin definition and settings.
 */

(function () {
  'use strict';
  CKEDITOR.plugins.add('responsivness', {
    icon: 'responsivness',
    init: function (editor) {

      // Register the toolbar buttons.
      editor.ui.addButton('responsivness', {
        label: Drupal.t('Insert a responsive area'),
        icon: this.path + 'images/responsivness.png',
        command: 'beResponsive'
      });

      var cssPath = this.path + 'responsivness.css';

      editor.on('instanceReady', function () {
        this.document.appendStyleSheet(cssPath);
      });
      editor.addCommand('beResponsive', new CKEDITOR.dialogCommand('beResponsive', {
        allowedContent: ' div(ckeditor-col-container,first-col,last-col,onecol,twocol,threecol,fourcol,fivecol,sixcol,sevencol,eightcol,ninecol,tencol,elevencol,twelvecol,grid-1,grid-2,grid-3,grid-4,grid-5,grid-6,grid-7,grid-8,grid-9,grid-10,grid-11,grid-12)'
      }));

      CKEDITOR.dialog.add('beResponsive', this.path + 'dialogs/beResponsive.js');
    }
  });
})();
