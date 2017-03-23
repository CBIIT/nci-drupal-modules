/**
 * @file
 * Customized tableselect for GatherContent module.
 *
 * Reference was Drupal core's tableselect.js.
 * Contains some ':visible' filters and control statements.
 *
 * Used by gathercontent_tableselect form type.
 */

(function ($, Drupal, window) {
  'use strict';

  Drupal.behaviors.gathercontentStickySizeFix = {
    attach: function () {
      $('table.sticky-enabled').once('gathercontent-sticky-table-resizer', function () {
        var timeout;
        var $originalTable = $(this);
        var $originalHeaderCells = $originalTable.children('thead').find('> tr > th');

        $(window).bind('resize.gathercontentUpdateSticky', function () {

          var $that = null;
          var $stickyCell = null;
          var cellWidth = null;
          var $stickyTable = $originalTable.prev('table.sticky-header');
          var $stickyHeaderCells = $stickyTable.find(' thead tr > th');

          window.clearTimeout(timeout);
          timeout = window.setTimeout(function () {
            // Resize header and its cell widths.
            // Only apply width to visible table cells. This prevents the header from
            // displaying incorrectly when the sticky header is no longer visible.
            for (var i = 0, il = $originalHeaderCells.length; i < il; i += 1) {
              $that = $($originalHeaderCells[i]);
              $stickyCell = $stickyHeaderCells.eq($that.index());
              cellWidth = $that.css('width');

              // Exception for IE7.
              if (cellWidth === 'auto') {
                cellWidth = $that[0].clientWidth + 'px';
              }
              $stickyCell.css('width', cellWidth);
            }

            $stickyTable.css('width', $originalTable.outerWidth());
          }, 200);
        });
      });
    }
  };

  Drupal.behaviors.gathercontentTableSelect = {
    attach: function (context) {
      // Select the inner-most table in case of nested tables.
      $('th.select-all', context).closest('table').once('gathercontent-table-select', Drupal.gathercontentTableSelect);
    }
  };

  Drupal.gathercontentTableSelect = function () {
    // Do not add a "Select all" checkbox if there are no rows with checkboxes
    // in the table.
    if ($('td input:checkbox', this).length === 0) {
      return;
    }

    // Keep track of the table, which checkbox is checked and alias the
    // settings.
    var table = this;
    var checkboxes;
    var lastChecked;
    var strings = {
      selectAll: Drupal.t('Select all rows in this table'),
      selectNone: Drupal.t('Deselect all rows in this table')
    };
    var updateSelectAll = function (state) {
      // Update table's select-all checkbox (and sticky header's if available).
      $(table).prev('table.sticky-header').andSelf().find('th.select-all input:checkbox').each(function () {
        $(this).attr('title', state ? strings.selectNone : strings.selectAll);
        this.checked = state;
      });
    };

    // Find all <th> with class select-all, and insert the check all checkbox.
    $('th.select-all', table).prepend($('<input type="checkbox" class="form-checkbox" />').attr('title', strings.selectAll)).click(function (event) {
      if ($(event.target).is('input:checkbox')) {
        // Loop through all checkboxes and set their state to the select all
        // checkbox' state if they are visible or false if not.
        checkboxes.each(function () {
          if ($(this).is(':visible')) {
            this.checked = event.target.checked;
            // Either add or remove the selected class based on the state of the
            // check all checkbox.
            $(this).closest('tr').toggleClass('selected', this.checked);
          }
          else {
            $(this).closest('tr').removeClass('selected');
          }
        });
        // Update the title and the state of the check all box.
        updateSelectAll(event.target.checked);
      }
    });

    // For each of the checkboxes within the table that are not disabled.
    checkboxes = $('td input.gathercontent-select-import-items:checkbox:enabled', table).click(function (e) {
      // Either add or remove the selected class based on the state of the check
      // all checkbox.
      $(this).closest('tr').toggleClass('selected', this.checked);

      // If this is a shift click, we need to highlight everything in the range.
      // Also make sure that we are actually checking checkboxes over a range
      // and that a checkbox has been checked or unchecked before.
      if (e.shiftKey && lastChecked && lastChecked !== e.target) {
        // We use the checkbox's parent TR to do our range searching.
        Drupal.gathercontentTableSelectRange($(e.target).closest('tr')[0], $(lastChecked).closest('tr')[0], e.target.checked);
      }

      // If all checkboxes are checked, make sure the select-all one is checked
      // too, otherwise keep unchecked.
      updateSelectAll((checkboxes.length === $(checkboxes).filter(':visible:checked').length));

      // Keep track of the last checked checkbox.
      lastChecked = e.target;
    });

    // If all checkboxes are checked on page load, make sure the select-all one
    // is checked too, otherwise keep unchecked.
    updateSelectAll((checkboxes.length === $(checkboxes).filter(':checked').length));
  };

  Drupal.gathercontentTableSelectRange = function (from, to, state) {
    // We determine the looping mode based on the order of from and to.
    var mode = from.rowIndex > to.rowIndex ? 'previousSibling' : 'nextSibling';

    // Traverse through the sibling nodes.
    for (var i = from[mode]; i; i = i[mode]) {
      // Make sure that we're only dealing with elements.
      if (i.nodeType !== 1) {
        continue;
      }

      // Either add or remove the selected class based on the state of the
      // target checkbox.
      $(i).toggleClass('selected', state);
      $('input:checkbox', i).each(function () { // eslint-disable-line no-loop-func
        this.checked = state;
      });

      if (to.nodeType) {
        // If we are at the end of the range, stop.
        if (i === to) {
          break;
        }
      }
      // A faster alternative to doing $(i).filter(to).length.
      else if ($.filter(to, [i]).r.length) {
        break;
      }
    }
  };

})(jQuery, Drupal, window);
