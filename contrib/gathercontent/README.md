# About

This module integrates Gather Content into Drupal.

## Installation

### Dependencies

* Image
* File
* [Entity API][entity]
* [Views][views]
* [Views Bulk Operations (VBO)][vbo]
* [Select (or other)][soo]
* [Composer Manager][composer manager]

### Optional dependecies

* [Libraries API 2.x][libraries] and [Tablesorter][tablesorter] for sortable tables.

### Tasks

1. Download and install dependent packages. You'll need [Composer][composer].
2. Install this module and update Composer managed packages.
3. If you want Gather Content admin forms have sortable table columns, enable
   [Libraries module][libraries], download the most recent release of [Tablesorter][tablesorter releases],
   and place it into `sites/all/libraries` Rename it's directory to
   `tablesorter-mottie`.

## Usage

[composer]: https://getcomposer.org/doc/00-intro.md#system-requirements
[composer manager]: https://www.drupal.org/project/composer_manager
[entity]: https://www.drupal.org/project/entity
[libraries]: https://drupal.org/project/libraries
[soo]: https://www.drupal.org/project/select_or_other
[tablesorter]: https://github.com/mottie/tablesorter
[tablesorter releases]: https://github.com/Mottie/tablesorter/releases
[vbo]: https://www.drupal.org/project/views_bulk_operations
[views]: https://www.drupal.org/project/views
