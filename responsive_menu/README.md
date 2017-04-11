## About

This module integrates the mmenu jquery plugin with Drupal's menu system with the aim of having an off-canvas mobile menu and a horizontal menu at wider widths. It integrates with your theme's breakpoints to allow you to trigger the display of the horizontal menu at your desired breakpoint. The mobile off-canvas menu is displayed through a toggle icon or with the optional integration of swipe gestures.

## Install

The only library required by this module is the [mmenu](http://mmenu.frebsite.nl) plugin. You need to download the jQuery version and place it in your `libraries` directory, usually this is located in `/sites/all/libraries` (create the directory if you need to). Rename your newly placed download to mmenu, so the resulting path is `/sites/all/libraries/mmenu`. This module will look in `/sites/all/libraries/mmenu/dist/js` for the javascript files so ensure you have the correct file structure.

The other two libraries which add functionality (if desired) are the [superfish](https://github.com/joeldbirch/superfish) plugin and the [hammerjs](http://hammerjs.github.io) library. Place those in `/sites/all/libraries` and rename them to superfish and hammerjs. For superfish you should have a structure like `/sites/all/libraries/superfish/dist/js`, while hammerjs should be `/sites/all/libraries/hammerjs`.

You also need to use a jQuery version from 1.7 onwards (use the required jquery_update module).

## Configuration

As an administrator visit /admin/structure/menu/settings

You can set the various options. Some of the options will require the libraries to be present before allowing configuration.

Set your jQuery version to at least 1.7 at /admin/config/development/jquery_update

## Theming and theme compatibility

This module should be compatible with most themes. One basic requirement is that the theme includes a wrapping 'page' div. This is so that mmenu knows which elements belong inside the wrapper when the off canvas menu is opened. Bartik is an example of a theme with a wrapping div. Bootstrap (3) is an example of a theme which doesn't have the wrapping
div (although you can easily add one to page.tpl.php, see [this issue](https://www.drupal.org/node/2727345)). More details on how to set up the divs are on an [mmenu documentation
page](http://mmenu.frebsite.nl/tutorials/off-canvas/the-page.html).

It should also be noted that the default css that comes with the module provides some _very basic_ styling and should be copied and pasted into your theme's css so that you can modify it to fit your theme's style. Once you've copied and pasted the css into your stylesheet you can disable the inclusion of the module's css on the settings page.

## Licenses

The licenses for the libraries used by this module are:

hammerjs: MIT
mmenu: Creative Commons Attribution-NonCommercial
superfish: MIT

The mmenu plugin used to have an MIT license but has changed to the CC NonCommercial license. So you'll need to pay the developer a fee to use it in a commercial web site. Alternatively you can download the earlier MIT licensed version which should be compatible. This module will track the latest stable version.
