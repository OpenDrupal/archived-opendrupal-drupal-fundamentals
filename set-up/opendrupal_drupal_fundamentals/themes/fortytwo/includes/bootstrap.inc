<?php

/**
 * @file
 * bootstrap.inc
 *
 * Contains theme preprocessors to bootstrapize components.
 */

use Drupal\Component\Utility\SafeMarkup;
use Drupal\Core\Template\Attribute;

require_once dirname(__FILE__) . '/fortytwo.inc';

/**
 * Implements hook_preprocess_html().
 */
function fortytwo_preprocess_html(array &$variables) {
  // Setup the theme basics.
  fortytwo_get_theme($variables);

  // Set some custom body classes.
  $classes[] = theme_get_setting('ft_layout_style');
  $classes[] = theme_get_setting('ft_layout_responsive');

  // Set sidebar classes.
  if (isset($variables['page']['sidebar_first']) && isset($variables['page']['sidebar_second'])) {
    $classes[] = 'two-sidebars';
  }
  elseif (isset($variables['page']['sidebar_first']) || isset($variables['page']['sidebar_second'])) {
    $classes[] = 'one-sidebar';
    if (isset($variables['page']['sidebar_first'])) {
      $classes[] = 'sidebar-first';
    }
    if (isset($variables['page']['sidebar_second'])) {
      $classes[] = 'sidebar-second';
    }
  }
  else {
    $classes[] = 'no-sidebars';
  }

  // Set debug grid classes.
  $variables['grid'] = theme_get_setting('ft_show_grid');
  ($variables['grid']) ? $classes[] = 'show-grid' : FALSE;

  // Set debug identifier classes.
  $variables['responsive_identifier'] = theme_get_setting('ft_show_responsive_identifier');
  ($variables['responsive_identifier']) ? $classes[] = 'show-responsive-identifier' : FALSE;

  // Add the body classes to the attributes array.
  if (isset($variables['attributes']['class']) && is_array($variables['attributes']['class'])) {
    $variables['attributes']['class'] = array_merge($variables['attributes']['class'], $classes);
  }
  else {
    $variables['attributes']['class'] = $classes;
  }

  // Change the mime type of the favicon to make it work in all browsers.
  $favicon = theme_get_setting('favicon');
  $type = 'image/x-icon';
  $variables['#attached']['html_head_link'][] = array(
    array(
      'rel'  => 'shortcut icon',
      'href' => $favicon['url'],
      'type' => $type,
    ),
  );
}

/**
 * Implements hook_preprocess_block().
 *
 * Clean up the div classes for blocks
 */
function fortytwo_preprocess_block(array &$variables) {
  // Replace first occurance of block- to clean up the ID's.
  if (substr($variables['attributes']['id'], 0, 6) === 'block-') {
    $variables['attributes']['id'] = substr($variables['attributes']['id'], 6);
  }

  $theme = \Drupal::theme()->getActiveTheme()->getName();
  if (strstr($variables['attributes']['id'], $theme)) {
    $variables['attributes']['id'] = str_replace($theme . '-', '', $variables['attributes']['id']);
  }
}

/**
 * Override or insert variables into the node templates.
 *
 * @param array $variables
 *   An array of variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function fortytwo_preprocess_node(array &$variables, $hook) {
  /** @var \Drupal\node\Entity\Node $node */
  $node = $variables['node'];
  $function = __FUNCTION__ . '_' . $node->bundle();
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}

/**
 * Override or insert variables into the field templates.
 *
 * @param array $variables
 *   An array of variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function fortytwo_preprocess_field(array &$variables, $hook) {
  $element = $variables['element'];

  // There's some overhead in calling check_plain() so only call it if the label
  // variable is being displayed. Otherwise, set it to NULL to avoid PHP
  // warnings if a theme implementation accesses the variable even when it's
  // supposed to be hidden. If a theme implementation needs to print a hidden
  // label, it needs to supply a preprocess function that sets it to the
  // sanitized element title or whatever else is wanted in its place.
  $variables['label_hidden'] = ($element['#label_display'] == 'hidden');
  if (empty($variables['label'])) {
    $variables['label'] = $variables['label_hidden'] ? NULL : SafeMarkup::checkPlain($element['#title']);
  }
}

/**
 * Implements hook_preprocess_breadcrumb().
 */
function fortytwo_preprocess_breadcrumb(&$variables) {
  $breadcrumb = &$variables['breadcrumb'];

  // Retrieve the breadcrumb settings.
  $show_breadcrumb_home = theme_get_setting('ft_breadcrumb_home');
  $breadcrumb_separator = theme_get_setting('ft_breadcrumb_separator');
  $add_trailing = theme_get_setting('ft_breadcrumb_trailing');
  $add_title = theme_get_setting('ft_breadcrumb_title');

  $variables['seperator'] = $breadcrumb_separator;
  $variables['trailing'] = $add_trailing;

  // Optionally get rid of the homepage link.
  if (!$show_breadcrumb_home) {
    array_shift($breadcrumb);
  }

  if ($add_title && !empty($breadcrumb)) {
    $request = \Drupal::request();
    $route_match = \Drupal::routeMatch();
    $page_title = \Drupal::service('title_resolver')->getTitle($request, $route_match->getRouteObject());

    foreach ($breadcrumb as $key => &$crumb) {
      $crumb['icon'] = $breadcrumb_separator;
    }

    if (!empty($page_title)) {
      $breadcrumb[] = array(
        'text' => $page_title,
        'icon' => $breadcrumb_separator,
      );
    }

    end($breadcrumb);
    $lastkey = key($breadcrumb);

    if (empty($add_trailing) && $lastkey == $key) {
      unset($breadcrumb[$key]['icon']);
    }
  }
}
