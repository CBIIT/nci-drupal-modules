/**
 * @file
 * Activates tablesorter plugin for GatherContent tables.
 */

(function ($, Drupal) {
  'use strict';

  //
  // Attaches tablesorter plugin.
  //
  Drupal.behaviors.gathercontentTableSorter = {
    attach: function (context) {
      // Adds custom data-date attr filter parser if tablesorter plugin is
      // available.
      if (typeof $.tablesorter !== 'undefined') {
        $.tablesorter.addParser({
          // Setting a unique id.
          id: 'datadate',
          is: function (s, table, cell, $cell) {
            if ($cell.attr('data-date')) {
              return true;
            }
            return false;
          },
          format: function (s, table, cell, cellIndex) {
            var $cell = $(cell);
            if ($cell.attr('data-date')) {
              return $cell.attr('data-date') || s;
            }
            return s;
          },
          parsed: false,
          type: 'text'
        });
      }

      //
      // Sets tablesorter plugin on tables with class tablesorter-enabled.
      //
      $('table.tablesorter-enabled', context).once('gathercontent-tablesorter', function () {
        var tablesorterOptions = {
          cssAsc: 'sort-down',
          cssDesc: 'sort-up',
          widgets: ['zebra']
        };
        if ((typeof Drupal.settings.gathercontent !== 'undefined') &&
          (typeof Drupal.settings.gathercontent.tablesorterOptionOverrides === 'object')) {
          var tsOverrides = Drupal.settings.gathercontent.tablesorterOptionOverrides;
          for (var attrname in tsOverrides) {
            tablesorterOptions[attrname] = tsOverrides[attrname];
          }
        }

        $(this).tablesorter(tablesorterOptions)
        // Keeps sticky table cell classes up-to-date.
        // Makes sticky header's tablesorter classes follow the main table's
        // ones.
        .bind('sortEnd', function (event) {
          if ($(this).is('table + table')) {
            var $baseTable = $('table + table');
            var $stickyTable = $baseTable.prev('table.sticky-header');

            if ($baseTable.length && $stickyTable.length) {
              var $baseTableHeaderCells = $baseTable.find('thead th');
              var $stickyTableHeaderCells = $stickyTable.find('thead th');
              var baseTableHeaderNum = $baseTableHeaderCells.length;

              for (var i = 0; i < baseTableHeaderNum; i += 1) {
                var baseTableHeaderCellClasses = $($baseTableHeaderCells[i]).attr('class');
                $($stickyTableHeaderCells[i]).attr('class', baseTableHeaderCellClasses);
              }
            }
          }
        });
      });
    }
  };
})(jQuery, Drupal);
