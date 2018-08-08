# Text editor

--vv--

# Text editor
- Text format: Configurable filter for safe display of text.
- WYSIWYG editor: Standaard CKEditor
- Quick edit: Edit content in-line via the 'frontend' of the website.

--vv--


# Demo: Editor
- WYSIWYG editor
- Quick edit
- Text format: Filter undesired HTML

--vv--

# Text format
- Text format: A set of filters and/or processors that will be applied to the text before display.
- Example. 'Restricted HTML'  allows a limited set of HTML (a.o. `<a>, <em>, <h1> .. <h6>`)
- To safeguard and clean-up of input.
- Optionally use a WYSIWYG editor.
- Assign to roles.

--vv--

# Text format (examples)
- Editor, admin
  - WYSIWYG: With WYSIWYG editor and many (or all) HTML allowed.
  - Raw: No editor, all HTML allowed. For example for legacy HTML with divs, spans and classes.
- Visitor
  - Restricted: No WYSIWYG editor, small set of HTML. For comments with links, bold, emoticons.
  - Plain text: No HTML, convert line breaks. For basic comments.

--vv--

# WYSIWYG editor
- Default editor: CKEditor.
- Other editors may be provided by contrib modules.
- Per text format: Enable/disable editor; Configurable set of buttons.
- Check that buttons and allowed HTML tags match.

--vv--

# Quick edit module
- Edit content without visiting the backend of the website.
- Intended for small adjustments. One field at the time.
- Only edit existing content. Empty fields can not be filled.

--vv--

# Exercise
As visitor I want to get an impression of an act by watching a video.

- Add a field that adds a YouTube embed code to the page. (The Video Embed Field module is recommended.)
- Create a text format 'iframe' that only allows an iframe and has no wysiwyg editor.
- Apply this to the video field.
- Add a help text with an example of an
- embed code and information about width and height.

--vv--

# Tips
- Use Media modules for a library of reusable images, video, etc.
- Use the Video Embed Field module for embedding videos.