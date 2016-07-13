#include "AWindow.hpp"
#include <iostream>
#include <deque>
#include <string.h>
#include <sys/ioctl.h>

AWindow::AWindow(void) :
	_wwin(0x0),
	_wuser(0x0),
	_wtitle("Unnamed") {
	setDefaultSize();
}

AWindow::AWindow(int h, int w, int y, int x) :
											_wwin(0x0),
											_wuser(0x0),
											_wh(h),
											_ww(w),
											_wy(y),
											_wx(x),
											_wtitle("Unnamed") {
}

void		AWindow::init(void) {
	_wwin = newwin(_wh, _ww, _wy, _wx);
	_wuser = newwin(1, _ww - 2, _wh - 1, 2);
	keypad(_wwin, TRUE);
	wrefresh(_wwin);
}

AWindow::AWindow(AWindow const &src) {
	if (this != &src)
		*this = src;
}

AWindow		&AWindow::operator=(AWindow const &rhs) {
	if (this != &rhs) {
		_wwin = rhs._wwin;
		_wuser = rhs._wuser;
		_wh = rhs._wh;
		_ww = rhs._ww;
		_wy = rhs._wy;
		_wx = rhs._wx;
		_wtitle = rhs._wtitle;
	}
	return (*this);
}

WINDOW				*AWindow::getWin(void) const {return (_wwin);}
// const std::string	&AWindow::getTitle(void) const {return (_wtitle);}
// int					AWindow::getH(void) const {return (_wh);}
// int					AWindow::getW(void) const {return (_ww);}
// int					AWindow::getX(void) const {return (_wx);}
// int					AWindow::getY(void) const {return (_wy);}

void				AWindow::serialize(std::ostream& stream) const {
	stream << std::endl << "ID:\t\t" << _wwin << std::endl
			<< "Title:\t\t" << _wtitle << std::endl
			<< "Height:\t\t" << _wh << std::endl
			<< "Width:\t\t" << _ww << std::endl
			<< "XOrigin:\t" << _wx << std::endl
			<< "YOrigin:\t" << _wy;
}

std::ostream&	operator<<(std::ostream& stream, AWindow const &s) {
	s.serialize(stream);
	return (stream);
}

AWindow::~AWindow(void) {
	if (_wwin) {
		wborder(_wwin, ' ', ' ', ' ',' ',' ',' ',' ',' ');
		wrefresh(_wwin);
		delwin(_wwin);
	}
	if (_wuser) {
		wborder(_wuser, ' ', ' ', ' ',' ',' ',' ',' ',' ');
		wrefresh(_wuser);
		delwin(_wuser);
	}
}

std::string	AWindow::readUser(void) const {
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

void	AWindow::notifyUser(const std::string &str) const {
	wclear(_wuser);
	waddstr(_wuser, str.c_str());
	wrefresh(_wuser);
}

void	AWindow::printText(const std::string &str) const {
	mvwaddstr(_wwin, 2, 2, str.c_str());
	wrefresh(_wwin);
}

void	AWindow::showGraph(IMonitorModule::sData &d) const {
	std::string			s;
	unsigned int		pad(0);

	mvwaddstr(_wwin, _wh - 9, 2, "123456789");
	for (std::deque<unsigned int>::iterator i = d.buffer.begin(); i != d.buffer.end(); ++i) {
		for (unsigned int n = 0; n < *i; n += 10) {
			s.push_back('=');
		}
		s.push_back('|');
		mvwaddstr(_wwin, _wh - 8 + pad++, 2, s.c_str());
		s.clear();
	}
}

void			AWindow::setTitle(std::string const &titleSet) {
	_wtitle = std::string(titleSet);
	box(_wwin, 0, 0);
	mvwaddstr(_wwin, 0, (_ww - _wtitle.size()) / 2, _wtitle.c_str());
	wrefresh(_wwin);
}

void	AWindow::setDefaultSize(void) {
	struct winsize			ws;

	if (ioctl(0, TIOCGWINSZ, &ws) == -1) {
		return ;
	}
	_wh = ws.ws_row;
	_ww = ws.ws_col;
	_wy = 0;
	_wx = 0;
}

