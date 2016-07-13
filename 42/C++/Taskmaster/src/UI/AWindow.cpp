// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AWindow.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/10/29 14:33:31 by hdezier           #+#    #+#             //
//   Updated: 2015/10/29 14:38:26 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AWindow.hpp"
#include <iostream>
#include <string.h>
#include <sys/ioctl.h>

AWindow::AWindow(void):
	_wwin(0x0),
	_wuser(0x0),
	_wtitle("Unnamed")
{
	setDefaultSize();
}
AWindow::AWindow(int h, int w, int y, int x):
	_wwin(0x0),
	_wuser(0x0),
	_wh(h),
	_ww(w),
	_wy(y),
	_wx(x),
	_wtitle("Unnamed")
{}
AWindow::AWindow(AWindow const &src)
{
	if (this != &src)
		*this = src;
}
AWindow::~AWindow(void)
{
	if (_wwin)
	{
		wborder(_wwin, ' ', ' ', ' ',' ',' ',' ',' ',' ');
		wrefresh(_wwin);
		delwin(_wwin);
	}
	if (_wuser)
	{
		wborder(_wuser, ' ', ' ', ' ',' ',' ',' ',' ',' ');
		wrefresh(_wuser);
		delwin(_wuser);
	}
}

AWindow				&AWindow::operator=(AWindow const &rhs)
{
	if (this != &rhs)
		;
	return (*this);
}

void				AWindow::init(void)
{
	_wwin = newwin(_wh, _ww, _wy, _wx);
	_wuser = newwin(1, _ww - 2, _wh - 1, 2);
	keypad(_wwin, TRUE);
	wrefresh(_wwin);
	refresh();
}


WINDOW				*AWindow::getWin(void) const
{
	return (_wwin);
}
// const std::string	&AWindow::getTitle(void) const {return (_wtitle);}
// int					AWindow::getH(void) const {return (_wh);}
// int					AWindow::getW(void) const {return (_ww);}
// int					AWindow::getX(void) const {return (_wx);}
// int					AWindow::getY(void) const {return (_wy);}
void				AWindow::serialize(std::ostream& stream) const
{
	stream << std::endl << "ID:\t\t" << _wwin << std::endl
		   << "Title:\t\t" << _wtitle << std::endl
		   << "Height:\t\t" << _wh << std::endl
		   << "Width:\t\t" << _ww << std::endl
		   << "XOrigin:\t" << _wx << std::endl
		   << "YOrigin:\t" << _wy;
}

std::ostream		&operator<<(std::ostream& stream, AWindow const &s)
{
	s.serialize(stream);
	return (stream);
}


std::string			AWindow::readUser(void) const
{
	std::string	result;
	char		str[256];

	wclear(_wuser);
	echo();
	curs_set(1);
	wgetstr(_wuser, str);
	curs_set(0);
	noecho();
	result.assign(str);
	return (result);
}

void				AWindow::notifyUser(const std::string &str) const
{
	wclear(_wuser);
	waddstr(_wuser, str.c_str());
	wrefresh(_wuser);
	noecho();
	wgetch(_wuser);
	/*Some asynchrnous stuff could be great*/
}

void				AWindow::setTitle(std::string const &titleSet)
{
	_wtitle = std::string(titleSet);
	box(_wwin, 0, 0);
	mvwaddstr(_wwin, 0, (_ww - _wtitle.size()) / 2, _wtitle.c_str());
	wrefresh(_wwin);
}

void				AWindow::setDefaultSize(void)
{
	struct winsize	ws;

	if (ioctl(0, TIOCGWINSZ, &ws) == -1)
		return ;
	_wh = ws.ws_row;
	_ww = ws.ws_col;
	_wy = 0;
	_wx = 0;
}
