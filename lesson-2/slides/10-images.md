# Images

--vv--

# Image styles
- Image style: A predefined set of operations on an image. Examples: resize, crop, rotate, black/white, etc.
- Processed image gets stored as file.
- Reusable and consistent display of the image.
- Responsive with Responsive Image and Breakpoint modules.

--vv--

# Demo:  Image styles
- Create a style
- Add an image effect
- Display settings for image fields

--vv--

# Exercise
As visitor I want to see a picture of the act.

- Add an image style 'Image act - Large'.
- Add an effect 'Scale and crop', size: 1200 x 600px.
- Apply this style when displaying the image.

--vv--

# Responsive images
- Different file is loaded depending on the width of the Viewport.
- Breakpoint: The with above which the display changes.
- Mobile first: Start with the smallest viewport width.

--vv--

# Demo: Responsive image
- Breakpoint definition
- bartik.breakpoints.yml
- Responsive image styles
- Display of responsive images
- HTML source

--vv--

# Responsive image
- Per breakpoint a different image (or none) gets loaded.
- Uses the `<picture>` tag.
- Fallback in older browsers with Picturefill.

```html
<picture>
  <!--[if IE 9]><video style="display: none;"><![endif]-->
  <source srcset="http://drupal8/.../example.png 1x" media="all and (min-width: 851px)" type="image/png">
  <source srcset="http://drupal8/.../styles/medium/.../example.png 1x" media="all and (min-width: 560px) and (max-width: 850px)" type="image/png">
  <!--[if IE 9]></video><![endif]-->
  <img property="schema:image" srcset="data:image/gif;base64,R0lGODlhAQ...">
</picture>
```

--vv--

# Breakpoint
- Breakpoints are be defined in the theme file: THEME.breakpoints.yml
- Any media query can be used.
- Multipliers supported (e.g. 1x, 1.5x, 2x).
- No relation with CSS media queries.
```yml
bartik.wide:
  label: wide
  mediaQuery: 'all and (min-width: 851px)'
  weight: 2
  multipliers:
    - 1x
```

--vv--

# Exercise
As visitor I want to receive a smaller image on my mobile device.

- TODO Breakpoints
- TODO Responsive image