# Content types and fields

--vv--

# Content types
- Different types of content.
  - Example: Text page, News, Product, Calendar, …
- Difference in:
-   Permissions, styling, workflow, etc.
- **Major building block** in Drupal architecture. 
- Free to define your types.

--vv--

# Demo: Create content types
- Available content types
- Create content types
- Manage fields
- Manage display

--vv--

# Exercise
As visitor I can read about each performance, each with it’s own page on the site.

- Create a Content type Performance.
  - Enter Name and Description, machine name 'act'.
  - Do not publish a performance on the front page.
  - Do not show author and date information.
  - A performance will not be added to the menu.

--vv--

# Exercise
As visitor I want to see an image, time, location, a short description and social media links.

- Add fields for:
  - Image (image, 1x, with alt text)
  - Location (short tekst, 1x)
  - Time (date-time, 1x)
  - Description (long text, 1x, with wysiwyg)
  - Social media (links, unlimited, external links)

--vv--

# Demo: Adding fields
- Data type
- (text, file, etc.)
- Field configuration
- Order and display

--vv--

# Best practices
- Content (Entities) first, structure second. Drupal is strong in structuring data.
- Determine the content types early in the site building process. The have a major impact on the architecture.

--vv--

# Best practices
- Field machine names:
  - Field unique for one content type: field_act_social
  - Field (possibly) used in multiple content types: 
<br>field_start_time or field__start_time

--vv--

# Demo: Content types
- Manage form display
- Manage display
- View mode

--vv--

# Exercise
As editor, entering a performance is simple and intuitive.
_Don’t make me think_

- Give fields a logical order.
- Make those fields required that are required for the site to operation.
- Add a simple WYSIWYG editor to the Description field.
- Limit links to only external links.

--vv--

# Exercise
As organisation I want the acts to be displayed according to the design.

- Create an Act
- Check / modify the order of the fields. Consider responsive behaviour too.
- Use labels according to the design.

--vv--

# Demo: Fields
- Field form configuration
- Field display configuration

--vv--

# Tips
- Fields can be added to entities:
  - Comments
  - Taxonomy
  - Account (profile)
  - Blocks
  - Contact form
- More field types are available via contrib modules.
- More display and layout opties are available via contrib modules.