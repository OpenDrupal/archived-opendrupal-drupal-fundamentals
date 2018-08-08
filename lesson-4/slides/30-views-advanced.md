# Advanced Views

--vv--

# Layout strategies
<!-- .slide: class="layout-image" -->

![Views layout strategies](lesson-4/slides/images/views-layout-strategies2.png)<!-- .element: style="width: 100%; heigth: 100%;" -->

--vv--

# Contextual filter
<!-- .slide: class="layout-title-page" -->

Filter content using information form the URL.

--vv--

# Contextual filter
- Views can filter data using information from it’s context:
  - URL, Current node, etc.
- Example:
  - news/politics, news/sport
  - List of content with the same taxonomy term(s) as the current node.

--vv--

# Demo: Contextual filter
- Add contextual filter
- Configuration

--vv--

# Exercise
As a visitor, on the act page, I want to find the other acts on the same stage.

- Create a Views block and place it in the region ‘Content’ below the primary content of an act.
- The View contains titles of acts with a link to their page.
- Add a contextual filter on taxonomy term ID. Use the ‘Provide default value’ with ‘Taxonomy term ID from URL’ and ‘Load default filter from node page, …’

--vv--

<!-- .slide: class="layout-image" -->

![Views contextual filter](lesson-4/slides/images/views-contextual-filter.png)<!-- .element: style="width: 65%; heigth: 65%;" -->

--vv--

# Tips
- Learn from the contextual filters in the default views. For example Taxonomy term 
- (URL: /taxonomy/term/%).
- Always check the filter behaviour when no or an unknown filter value is supplied.

--vv--

# Relationships
<!-- .slide: class="layout-title-page" -->
Combine data from different sources

--vv--

# Relationships
- Views can combine data from different sources (SQL: join of tables). 
- Example: Content + author; Content + file; Content + content. 
- Note: Complex relations may lead to bad performing views. Check the SQL query and/or use caching.

--vv--

# Demo: Relationships
- Create relationships
- Apply a field with relation

--vv--

# Exercise 1/3
As a visitor I want a program page per stage. That way I have all acts of my style together.

- Copy the program view.
- Use URL: program/%
- Add a contextual filter on taxonomy term ‘Stage’ to the view.
- Use ‘Provide default value’  and use the ‘Raw value from URL’
- Save the view and check the result: 
- The view now filters on taxonomy ID. 
- Example: /program/3

--vv--

# Exercise 2/3
As a visitor I want a program page per stage. That way I have all acts of my style together.

- Add a relation with the vocabulary Stage.
- Replace the contextual filter by a filter on Taxonomy term Name. This filter uses the ‘Stage’ relation. 
- Save the view and check the result. The view now filters on Taxonomy term name. 
- Example: /program/ballroom
- Adjust the filter so that the input gets validated as Stage term name, and the input value is used in the page title.

--vv--

<!-- .slide: class="layout-image" -->

![Views contextual filter](lesson-4/slides/images/views-relation-filter-1.png)<!-- .element: style="width: 70%; heigth: 70%;" -->

--vv--

<!-- .slide: class="layout-image" -->

![Views contextual filter](lesson-4/slides/images/views-relation-filter-2.png)<!-- .element: style="width: 70%; heigth: 70%;" -->


--vv--

# Exercise 3/3
As a visitor I want a program page per stage. That way I have all acts of my style together.

- Add links for navigation between the per stage programs pages.
- Option 1: Add navigation links in a text field on top of the program views.
- Options 2: Create a new menu with links to the various per stage program pages. Place the menu block on top of the program views.
