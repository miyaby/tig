#define SIZEOF_REV	41	/* Holds a SHA-1 and an ending NUL */
	char id[SIZEOF_REV];	/* Commit SHA1 ID */
		if (!strcmp(opt, "log") ||
		    !strcmp(opt, "diff") ||
		    !strcmp(opt, "show")) {
			opt_request = opt[0] == 'l'
				    ? REQ_VIEW_LOG : REQ_VIEW_DIFF;
			break;
		}

		if (opt[0] && opt[0] != '-')
			break;

LINE(ACKED,	   "    Acked-by",	COLOR_YELLOW,	COLOR_DEFAULT,	0), \

	/* State flags */
	unsigned int selected:1;

	struct keybinding *keybinding = keybindings[keymap];
	if (!keybinding)
		keybinding = calloc(1, sizeof(*keybinding));
/* Reading from the prompt? */
static bool input_mode = FALSE;

	bool draw_ok;
	if (selected) {
		line->selected = TRUE;
	} else if (line->selected) {
		line->selected = FALSE;
		wmove(view->win, lineno, 0);
		wclrtoeol(view->win);
	}

	scrollok(view->win, FALSE);
	draw_ok = view->ops->draw(view, line, lineno, selected);
	scrollok(view->win, TRUE);
	return draw_ok;
	if (input_mode)
		wnoutrefresh(view->win);
	else
		wrefresh(view->win);
	char buf[SIZEOF_STR];
	char state[SIZEOF_STR];
	size_t bufpos = 0, statelen = 0;
	assert(view_is_displayed(view));
		string_format_from(state, &statelen, "- %s %d of %d (%d%%)",
				   view->ops->type,
				   view->lineno + 1,
				   view->lines,
				   lines);

		if (view->pipe) {
			time_t secs = time(NULL) - view->start_time;

			/* Three git seconds are a long time ... */
			if (secs > 2)
				string_format_from(state, &statelen, " %lds", secs);
		}
	string_format_from(buf, &bufpos, "[%s]", view->name);
	if (*view->ref && bufpos < view->width) {
		size_t refsize = strlen(view->ref);
		size_t minsize = bufpos + 1 + /* abbrev= */ 7 + 1 + statelen;
		if (minsize < view->width)
			refsize = view->width - minsize + 7;
		string_format_from(buf, &bufpos, " %.*s", refsize, view->ref);
	if (statelen && bufpos < view->width) {
		string_format_from(buf, &bufpos, " %s", state);
	}

	if (view == display[current_view])
		wbkgdset(view->title, get_line_attr(LINE_TITLE_FOCUS));
	else
		wbkgdset(view->title, get_line_attr(LINE_TITLE_BLUR));

	mvwaddnstr(view->title, 0, 0, buf, bufpos);
	wclrtoeol(view->title);

	if (input_mode)
		wnoutrefresh(view->title);
	else
		wrefresh(view->title);
update_display_cursor(struct view *view)
do_scroll_view(struct view *view, int lines)
	bool redraw_current_line = FALSE;
	/* Move current line into the view. */
	if (view->lineno < view->offset) {
		view->lineno = view->offset;
		redraw_current_line = TRUE;
	} else if (view->lineno >= view->offset + view->height) {
		view->lineno = view->offset + view->height - 1;
		redraw_current_line = TRUE;
	}

	assert(view->offset <= view->lineno && view->lineno < view->lines);

		if (redraw_current_line)
			draw_view_line(view, view->lineno - view->offset);
	assert(view_is_displayed(view));

	do_scroll_view(view, lines);
move_view(struct view *view, enum request request)
	int scroll_steps = 0;
		scroll_steps = steps;
			scroll_steps = -view->offset;
				scroll_steps = view->lines - view->offset - 1;
				if (scroll_steps >= view->height)
					scroll_steps -= view->height - 1;
	}
	if (!view_is_displayed(view)) {
		view->offset += steps;
		view->ops->select(view, &view->line[view->lineno]);
	/* Repaint the old "current" line if we be scrolling */
	if (ABS(steps) < view->height)
		draw_view_line(view, view->lineno - steps - view->offset);
	if (scroll_steps) {
		do_scroll_view(view, scroll_steps);
	}

	/* Draw the current line */
	draw_view_line(view, view->lineno - view->offset);
static void search_view(struct view *view, enum request request);
			search_view(view, request);
search_view(struct view *view, enum request request)
	regex_err = regcomp(view->regex, opt_search, REG_EXTENDED);
	string_copy(view->grep, opt_search);
		do_scroll_view(prev, lines);
		move_view(view, request);
			move_view(view, request);
			if (view_is_displayed(view))
			move_view(view, request);
		search_view(view, request);
/* Parse output from git-ls-tree(1):
	enum open_flags flags = display[0] == view ? OPEN_SPLIT : OPEN_DEFAULT;
			char *data = line->data;
	char *text = line->data;
	text += STRING_SIZE("100644 blob ");

	if (line->type == LINE_TREE_FILE) {
		string_ncopy(ref_blob, text, 40);
		/* Also update the blob view's ref, since all there must always
		 * be in sync. */
		string_copy(VIEW(REQ_VIEW_BLOB)->ref, ref_blob);

	} else if (line->type != LINE_TREE_DIR) {
		return;

	string_ncopy(view->ref, text, 40);
	char id[SIZEOF_REV];		/* SHA1 ID. */
static bool status_empty = TRUE;

	if (input_mode)
		return;

	if (!status_empty || *msg) {
			status_empty = FALSE;
			status_empty = TRUE;
		wclrtoeol(status_win);
	update_display_cursor(view);
		input_mode = TRUE;

		input_mode = FALSE;

		mvwprintw(status_win, 0, 0, "%s%.*s", prompt, pos, buf);
		wclrtoeol(status_win);

	/* Clear the status window */
	status_empty = FALSE;
	report("");

	if (status == CANCEL)