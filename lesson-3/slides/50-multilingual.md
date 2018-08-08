# Multilingual

--vv--

# Multilingual
- 3 types of translations:
  - Interface 
    <br>Translation of text set in PHP or JS code. 
    <br>Example: (error)message, administration interface.
  - Configuration 
    <br>Translation of text set in configuration. 
    <br>Example: Field label, URL of the front page.
  - Content 
    <br>Translation of content. 
    <br>Example: Node content, Image (alt text), taxonomy term.

--vv--

# Demo: Interface translation
- Modules: Language, Interface Translation
- Add a language
- Download and import interface translation files

--vv--

# Interface translation
- Language + Interface Translation module
- Community translations stored and managed at http://localize.drupal.org
- Override community translation via the build-in interface.
- Update translations during site building, but not at live site.

--vv--

# Configuration translation
- Multilingual website is more complex. Up to 50% extra time for two languages compared to one.
- Available ‘languages’: Language (EN, NL, …); Default de huidige pagina, Multiple languages, Unspecified, Not applicable (not translatable).
- Example 1: Image is not translated (is equal in every language), but the alt text differs per language.
- Voorbeeld 2: Entity reference not translated: In each language references to the same entity. (Should the entity be translated?) Translated: References a different entity in each language.

--vv--

# Translation of content
- Per entity, per field configurable what is (not) translatable.
- Source language can differ per entity.
- Translation by editors, depending on permissions.
- Use workflow modules for translation workflow.
- Modules available for external translation tools.
