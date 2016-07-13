#include "Window.hpp"
#include <string.h>
#include <sys/ioctl.h>

Window::Window(void) {
	_setDefaultSize();
	win = newwin(h, w, y, x);
	user = newwin(1, w - 2, h - 1, 2);
	keypad(win, TRUE);
	wrefresh(win);
	refresh();
}

Window::Window(int hSet, int wSet, int ySet, int xSet) :
											h(hSet),
											w(wSet),
											y(ySet),
											x(xSet) {
	win = newwin(h, w, y, x);
	user = newwin(1, w - 2, h - 1, 2);
	keypad(win, TRUE);
	wrefresh(win);
	refresh();
}

Window::~Window(void) {
	if (win) {
		wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
		wrefresh(win);
		delwin(win);
	}
	if (user) {
		wborder(user, ' ', ' ', ' ',' ',' ',' ',' ',' ');
		wrefresh(user);
		delwin(user);
	}
}

std::string	Window::readUser(void) const {
	std::string	result;
	char		str[256];

	wclear(user);
	echo();
	curs_set(1);
	wgetstr(user, str);
	curs_set(0);
	noecho();
	result.assign(str);
	return (result);
}

void	Window::notifyUser(const std::string &str) const {
	wclear(user);
	waddstr(user, str.c_str());
	wrefresh(user);
	noecho();
	wgetch(user);
	/*Some asynchrnous stuff could be great*/
}

void			Window::setTitle(std::string const &titleSet) {
	title = std::string(titleSet);
	box(win, 0, 0);
	mvwaddstr(win, 0, (w - title.size()) / 2, title.c_str());
	wrefresh(win);
}

void	Window::_setDefaultSize(void) {
	struct winsize			ws;

	if (ioctl(0, TIOCGWINSZ, &ws) == -1) {
		return ;
	}
	h = ws.ws_row;
	w = ws.ws_col;
	y = 0;
	x = 0;
}

