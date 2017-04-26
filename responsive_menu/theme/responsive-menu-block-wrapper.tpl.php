<?php
/**
 * @file
 * Default theme implementation to wrap the responsive menu block.
 *
 * Available variables:
 * - $content: The renderable array containing the menu.
 * - $classes: A string containing the CSS classes for the wrapper tag.
 *
 * The following variables are provided for contextual information.
 * - $delta: (string) The menu_block's block delta.
 *
 * @see template_preprocess_responsive_menu_block_wrapper()
 */
?>
<<?php print $element_type; ?> class="<?php print $classes; ?>">
  <?php print render($content); ?>
</<?php print $element_type; ?>>
