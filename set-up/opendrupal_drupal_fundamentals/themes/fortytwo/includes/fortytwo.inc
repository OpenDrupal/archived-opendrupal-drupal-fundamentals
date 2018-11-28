<?php

/**
 * @file
 * Contains functions needed for the theme.
 */

global $_fortytwo_path_to_core;
$_fortytwo_path_to_core = drupal_get_path('theme', 'fortytwo');

/**
 * Get theme functionalities.
 */
function fortytwo_get_theme(&$variables) {
  fortytwo_load_debuggers($variables);
  fortytwo_add_libraries($variables);
//  fortytwo_add_head_items();
}

/**
 * Get the path to the static files folder in the theme.
 */
function fortytwo_get_staticpath($addprefix = FALSE, $theme_key = 'fortytwo') {
  $ret = '';
  if ($addprefix) {
    $ret = '/';
  }
  $ret .= drupal_get_path('theme', $theme_key) . '/static/';
  return $ret;
}

/**
 * Add libraries to the theme.
 */
function fortytwo_add_libraries(&$variables) {
  $enquire = theme_get_setting('ft_enquire_js');
  if (!empty($enquire)) {
    $variables['page']['#attached']['library'][] = 'fortytwo/enquire';
  }

  $transit = theme_get_setting('ft_transit_js');
  if (!empty($transit)) {
    $variables['page']['#attached']['library'][] = 'fortytwo/transit';
  }

  $placeholder = theme_get_setting('ft_placeholder_js');
  if (!empty($placeholder)) {
    $variables['page']['#attached']['library'][] = 'fortytwo/placeholder';
  }

  $prettify = theme_get_setting('ft_prettify_js');
  if (!empty($prettify)) {
    $variables['page']['#attached']['drupalSettings']['fortytwo']['prettify_hide_upload'] = theme_get_setting('ft_prettify_js_hide_upload');
    $variables['page']['#attached']['drupalSettings']['fortytwo']['prettify_add_remove'] = theme_get_setting('ft_prettify_js_add_remove');
    $variables['page']['#attached']['library'][] = 'fortytwo/prettify';
  }
}

/**
 * Add meta tags to the html header.
 */
function fortytwo_add_head_items() {
  $viewport = theme_get_setting('ft_viewport');
  if (!empty($viewport)) {
    $user_scalable = theme_get_setting('ft_viewport_user_scaleable');
    $initial_scale = theme_get_setting('ft_viewport_initial_scale');
    $minimum_scale = theme_get_setting('ft_viewport_minimum_scale');
    $maximum_scale = theme_get_setting('ft_viewport_maximum_scale');
    $content = "width=device-width, initial-scale=" . $initial_scale . ", minimum-scale=" . $minimum_scale . ", maximum-scale=" . $maximum_scale . ", user-scalable=" . $user_scalable;
    $element = array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'viewport',
        'content' => $content,
      ),
    );
    drupal_add_html_head($element, 'ft-viewport');
  }

  $cleartype = theme_get_setting('ft_cleartype');
  if (!empty($cleartype)) {
    $meta = array(
      '#tag' => 'meta',
      '#attributes' => array('http-equiv' => 'cleartype', 'content' => 'on'),
    );

    drupal_add_html_head($meta, 'ft-cleartype');
  }
}

/**
 * Load debugging helper files.
 */
function fortytwo_load_debuggers(&$variables) {
  $debug = FALSE;
  // Load window size bookmarklet.
  if (theme_get_setting('ft_show_window_size') === 1) {
    $debug = TRUE;
    $variables['page']['#attached']['library'][] = 'fortytwo/windowsize';
  }
  if (theme_get_setting('ft_show_grid') === 1) {
    $debug = TRUE;
    $variables['page']['#attached']['library'][] = 'fortytwo/grid';
  }
  if ($debug) {
    drupal_set_message(t('Please turn off Forty Two debuggers on production websites.'), 'warning');
  }
}
