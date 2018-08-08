# System configuration

--vv--

# System configuration
- Front page, 403, 404
- Cron
- Performance
- Logging
- File system
- Maintenance mode

--vv--

# System configuration
- **403, 404**: Use a page for this.
- **Cron**: Server cron (crontab) has preference.
- **Performance**: Page cache dependent of the site dynamics. 1 day is a common default. Also: Various cache modules.
- **Logging**: Can often be disabled on production.

--vv--

# Tips
- Disable interface modules on production. E.g.: Views UI, Field UI.
- Disable development modules on production. E.g. Help, Admin Toolbar, Devel
> The Devel module can execute arbitrary PHP Don’t place this code on production