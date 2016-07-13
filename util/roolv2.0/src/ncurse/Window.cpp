/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 13:05:48 by leeios            #+#    #+#             */
/*   Updated: 2015/08/13 14:01:39 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"
#include <string.h>
#include <sys/ioctl.h>

Window::Window(void) {
	setDefaultSize();
	_win = newwin(_h, _w, _y, _x);
	_user = newwin(1, _w - 2, _h - 1, 2);
	keypad(_win, TRUE);
	wrefresh(_win);
	refresh();
}

Window::Window(int h, int w, int y, int x) :
											_h(h),
											_w(w),
											_y(y),
											_x(x) {
	_win = newwin(_h, _w, _y, _x);
	_user = newwin(1, _w - 2, _h - 1, 2);
	keypad(_win, TRUE);
	wrefresh(_win);
	refresh();
}

Window::~Window(void) {
	if (_win) {
		wborder(_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
		wrefresh(_win);
		delwin(_win);
	}
	if (_user) {
		wborder(_user, ' ', ' ', ' ',' ',' ',' ',' ',' ');
		wrefresh(_user);
		delwin(_user);
	}
}

const std::string			Window::readUser(void) const {
	std::string	result;
	char		str[256];

	wclear(_user);
	echo();
	curs_set(1);
	wgetstr(_user, str);
	curs_set(0);
	noecho();
	result.assign(str);
	return (result);
}

void	Window::notifyUser(const std::string &str) const {
	wclear(_user);
	waddstr(_user, str.c_str());
	wrefresh(_user);
	noecho();
	wgetch(_user);
	/*Some asynchrnous stuff could be great*/
}

void			Window::setTitle(std::string const &title) {
	_title = std::string(title);
	box(_win, 0, 0);
	mvwaddstr(_win, 0, (_w - _title.size()) / 2, _title.c_str());
	wrefresh(_win);
}

void	Window::setDefaultSize(void) {
	struct winsize			ws;

	if (ioctl(0, TIOCGWINSZ, &ws) == -1) {
		return ;
	}
	_h = ws.ws_row;
	_w = ws.ws_col;
	_y = 0;
	_x = 0;
}

