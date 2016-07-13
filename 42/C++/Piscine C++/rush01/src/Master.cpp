#include "Master.hpp"
#include "NCursesDisplay.hpp"
#include "FLDisplay.hpp"
#include "UserInfo.hpp"
#include "OSInfo.hpp"
#include "DateTime.hpp"
#include "CPUInfo.hpp"
#include "RAMInfo.hpp"
#include "Cat.hpp"
#include <cstdlib>
#include <iostream>
#include <unistd.h>

Master::Master(int nDisplay) {
	if (nDisplay == 0) {
		_dis = new NCursesDisplay();
	} else if (nDisplay == 1) {
		_dis = new FLDisplay();
	}
}

void			Master::createModules(int nModules) {
	if (nModules < 0 || nModules > MAX_MODULES - 1) {
		return ;
	}
	_mods.push_back(new UserInfo());
	_mods.push_back(new OSInfo());
	_mods.push_back(new DateTime());
	_mods.push_back(new CPUInfo());
	_mods.push_back(new RAMInfo());
	_mods.push_back(new Cat());
	for (std::vector<IMonitorModule *>::iterator i = _mods.begin(); i != _mods.end(); ++i) {
		(*i)->start();
		(*i)->refresh();
	}
	_dis->start(_mods);
}

Master::Master(Master const &src) {
	if (this != &src)
		*this = src;
}

void			Master::loop(void) {
	clock_t		t;
	clock_t		tmp;
	int			input;

	t = clock();
	_dis->render(_mods);
	while (true) {
		input = _dis->input();
		if (input == ESCFL || input == ESCNC) {
			break ;
		} else if (input == 'a' || input == 'd') {
			switchDisplay(input ==  'a' ? 1 : 0);
			_dis->start(_mods);
			_dis->render(_mods);
		}
		if ((tmp = clock() - t) > REFRESH_TIME) {
			for (std::vector<IMonitorModule *>::iterator i = _mods.begin(); i != _mods.end(); ++i) {
				(*i)->refresh();
			}
			_dis->render(_mods);
		}
	}
}

void		Master::switchDisplay(int nDis) {
	delete _dis;
	sleep(1);
	if (!nDis) {
		_dis = new FLDisplay();
		endwin();
	} else {
		_dis = new NCursesDisplay();
	}
	sleep(1);
}

Master::~Master(void) {
	delete _dis;
	for (std::vector<IMonitorModule *>::iterator i = _mods.begin(); i != _mods.end(); ++i) {
		delete *i;
	}
	endwin();
}

Master		&Master::operator=(Master const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}
