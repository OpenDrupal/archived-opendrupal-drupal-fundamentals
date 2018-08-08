# Basic Views

--vv--

# Views
- Creates overviews with content from the CMS.
- In the form of a list, table, map, etc.
- Displayed as page, block, RSS-feed, etc.
- Three aspects:
  - Data selection
  - Display
  - User interaction

--vv--

#  Demo: Views
- Block with recent content
- Views interface
- Filter on content type

--vv--

#  Tips
- When investigating and building a Views, distinguish:
  - Selection
  - Display
  - Interaction

--vv--

#  Exercise
As developer I want to use Views to create different overviews within the website.

- Study the wireframes and analyse the required functionality.
- Make a list of properties of the required block and page type overviews. Distinguish: selection, display and user interaction.

--vv--

#  A page view

--vv--

#  User story
<!-- .slide: class="layout-image" -->

As visitor, I want an overview of the complete program.

![Festival program overview](lesson-1/slides/images/wireframes-festival-program.png)<!-- .element: style="width: 35%;" -->

--vv--

#  Demo: Page view
- Add a page view

--vv--

#  Page view
- Views has different display forms:
  - Block, Page, Feed, Attachment (View attached to a View)
- With contributed modules also as slideshow, file (download), Google map, REST endpoint, etc.

--vv--

#  Exercise 1/2
As visitor, I want an overview of the complete program.

- Create a View 'Program' that displays all performances as a page.
- Format the page as a list of teasers.
- The URL is /program
- Add the program page to the main menu.
- Do you recognise selection, display and interaction?
- Save the View and check the result.

--vv--

#  Exercise 2/2
As visitor, I want an overview of the complete program.

- Create an Image style for the act image on the program page.
- Apply this image style to the Teaser view mode of the act.
- Adjust the display of the other fields to match the design.
- Check the result.

--vv--

#  Layout strategies
<!-- .slide: class="layout-image" -->

![Views layout strategies](lesson-4/slides/images/views-layout-strategies1.png)<!-- .element: style="width: 100%; heigth: 100%;" -->

--vv--

#  Front page

--vv--

#  Front page
<!-- .slide: class="layout-image" -->

![Festival Frontpage](lesson-1/slides/images/wireframes-festival-front.png)<!-- .element: style="width: 45%; heigth: 45%;" -->

--vv--

#  Demo: Front page
- System settings ‘Default front page’
- Node or View as basis
- Front page
- A page with a special URL: ‘/’
- Configuration ‘Default front page’: system URL of the page.
- Use: Node, View. 
- Also: special content type for front page only.
- Or modules: Panels

--vv--

#  Exercise 1/3
As developer I want to use the Page View of the main acts as basis for the frontpage.

- Create a Page View.
- The View displays two main acts.
- Use a descriptive URL.
- Save the View.
- Check the result.
- Adjust the ‘Default front page’ configuration to use the main act View as front page.

--vv--

#  Exercise 2/3
As developer I want to use the Page View of the main acts as basis for the frontpage.

- Add a field to the Act content type that allows the editors to flag an act as main act
- Only show this field in the Act node form. Don’t display it publicly.
- Modify the View to only show the selected acts.

--vv--

#  Exercise 3/3
As developer I want to use the Page View of the main acts as basis for the frontpage.

- Create a special View mode to display the main act on the front page.
- Adjust the main act View to use this view mode. 
- Adjust the configuration of the view mode to display the right main act information.

--vv--

#  User Story
<!-- .slide: class="layout-image" -->

As visitor I expect links on the front to quickly find the Program or Tickets section of the website.

![Festival Frontpage](lesson-1/slides/images/wireframes-festival-front.png)<!-- .element: style="width: 35%;" -->

--vv--

#  Exercise
As visitor I expect links on the front to quickly find the Program or Tickets section of the website.

- Create a block with HTML for a button that links to the program page.
- Place this block on the front page in the left column.
- Create a second block with a Tickets button.
- Place this block on the front page in the right column.

--vv--

#  User Story
<!-- .slide: class="layout-image" -->

As a visitor I expect links on the front page to go to frequently visited pages.

![Festival Frontpage](lesson-1/slides/images/wireframes-festival-front.png)<!-- .element: style="width: 35%;" -->

--vv--

#  Exercise
As a visitor I expect links on the front page to go to frequently visited pages.

- Create a block with a few links to frequently visited pages.
- Place this block on the front page in the right column.

--vv--

#  A Block View

--vv--

#  User story
<!-- .slide: class="layout-image" -->

As a visitor I expect a short version of the program on the front page.

![Festival Frontpage](lesson-1/slides/images/wireframes-festival-front.png)<!-- .element: style="width: 35%;" -->

--vv--

#  Demo: Block View
- The News block
- Add a Block View

--vv--

#  Exercise
As a visitor I expect a short version of the program on the front page.

- Create a Block View of titles (with link) to all acts, sorted on start time.
- Save the block
- Place the block in the left column on the front page.
- The block does not need a title.

Note: We will finish this View later.

--vv--

#  User story
<!-- .slide: class="layout-image" -->

As a visitor I expect recent news on the front page.

![Festival Frontpage](lesson-1/slides/images/wireframes-festival-front.png)<!-- .element: style="width: 35%;" -->

--vv--

#  Exercise
As a visitor I expect recent news on the front page.

- Create a Block View of titles (with link) of the 3 most recent news articles.
- Add an image of size ‘Thumbnail’.
- Place this block on the front page in the right column.
- Disable the View that was responsible for the original front page.

--vv--

#  Content v.s. Fields
<!-- .slide: class="layout-title-page" -->

A View made out of individual fields.

--vv--

#  View of individual fields
- Views can combine individual pieces of data from the CMS.
- The need to use separate data in a View or a View mode is a strong argument to store this data in a separate field.

--vv--

#  Demo: Fields in a View
- Content display v.s. Fields
- Adding fields to a View

--vv--

#  Exercise
As a visitor I expect a short version of the program on the front page.

- Adjust the Program View so that it contains all relevant data. (You will combine this data in the next step.)

--vv--

#  Tips
- Use the preview at the bottom of the Views admin page to check the result before saving the View.

--vv--

#  Rewrite results

--vv--

#  Demo: Rewrite results
- Replacement patterns
- Exclude from display

--vv--

#  Exercise
As a visitor I expect a short version of the program on the front page.

- Use ‘Rewrite results' and replacement patterns to combine time and stage to: “15.00 - Ballroom”
- Display of the original field can be suppressed with 'Exclude from display’.

--vv--

#  Best practices
- Place excluded fields always on top of the list. Replacement patterns are only available from fields preceding the one that is being rewritten.
