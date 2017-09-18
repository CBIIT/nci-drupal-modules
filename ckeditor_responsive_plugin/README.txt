CONTENTS OF THIS FILE
---------------------
   
 * Introduction
 * Requirements
 * Installation
 * Troubleshooting
 * FAQ
 * Maintainers


INTRODUCTION
------------

This module, used on top of CKEditor allows the use of responsive area within 
rich editing textarea. 

Instead of tables, the plugins insert divs with standard responsive css lasses.

 * For a full description of the module, visit the project page:
   https://www.drupal.org/project/ckeditor_responsive_plugin

 * To submit bug reports and feature suggestions, or to track changes:
   https://www.drupal.org/project/issues/2424721


REQUIREMENTS
------------
This module requires the following module:

 * CKEditor (https://drupal.org/project/ckeditor)


INSTALLATION
------------

This module requires CKEditor module to be installed
(https://www.drupal.org/project/ckeditor).

Copy the module folder to your module directory, enable it on the admin module
page.

Enable the module, and follow the line to your CKEditor profile for which you
want to enable the plugin. ie : /admin/config/content/ckeditor/edit/Advanced

 1. Under "Editor appearance", section "Plugins", please be sure that
"CKEditor Responsive Plugin : Allow to insert responsive areas" is checked
 2. Drag the button on your toolbar (the button is the one showed in
docs/button.jpg
 3. The text format you are using should allow div to be used within the 
 textarea. (If you are using the "Limit allowed HTML tags" you should add 
 div") in the allowed HTML tags list.
 4. The added css classes are "*col" (onecol, twocol...) and grid-* (grid-1 
 grid-2...) Make sure theses classes are working with your theme. If they 
 don't, have a look to the responsivness.css/responsivness.css file to copy 
 the appropriates classes. 


TROUBLESHOOTING
---------------

 * If the button does not display on the toolbar, check the following:

   - is the CKEditor option "CKEditor Responsive Plugin : Allow to insert 
   responsive areas" is checked ?

   - Is the button is present on CKEditor visual toolbar configuration ?


FAQ
---

Q: Does this module work with WYSIWYG bridge API ?

A: Nothing has been done for it, so I can't answer this question, feel free to 
try it out and report any issue you'll face.


MAINTAINERS
-----------

Current maintainers:
 * Kevin Gautreau (kgaut) - https://drupal.org/user/686336
