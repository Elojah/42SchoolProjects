#include "NCursesDisplay.hpp"
# include "IMonitorModule.hpp"
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>

NCursesDisplay::NCursesDisplay(void) :
	AWindow() {

	initscr();
	clear();
	noecho();
	cbreak();
	raw();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);

	setDefaultSize();
	setTitle("Gkrellm");
}

NCursesDisplay::NCursesDisplay(int h, int w, int y, int x) :
	AWindow(h, w, y, x) {
}

NCursesDisplay::NCursesDisplay(NCursesDisplay const &src) {
	if (this != &src)
		*this = src;
}

NCursesDisplay		&NCursesDisplay::operator=(NCursesDisplay const &rhs) {
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

NCursesDisplay::~NCursesDisplay(void) {
	for (std::vector<AWindow *>::iterator i = _children.begin(); i != _children.end(); ++i) {
		delete *i;
	}
	curs_set(0);
}

void		NCursesDisplay::start(std::vector<IMonitorModule *> const &mods) {
	IMonitorModule::sData		d;

	init();
	_children.clear();
	setTitle("Gkrellm");
	for (std::vector<IMonitorModule *>::const_iterator i = mods.begin(); i != mods.end(); ++i) {
		d = (*i)->getData();
		_children.push_back(new AWindow(d.h, d.w, d.y, d.x));
		_children.back()->init();
		_children.back()->setTitle(d.title);
	}
}

void		NCursesDisplay::render(std::vector<IMonitorModule *> const &mods) {
	IMonitorModule::sData		d;
	unsigned int				nModules;

	nModules = mods.size();
	// wclear(_wwin);
	for (unsigned int i = 0; i < nModules; ++i) {
		wclear(_children[i]->getWin());
		d = mods[i]->getData();
		_children[i]->printText(d.str_content);
		if (d.graph) {
			_children[i]->showGraph(d);
		}
		if (d.type == 3) {
			// _children[i]->printText("Content not available on this UI");
			;
		}
		_children[i]->setTitle(d.title);
		wrefresh(_children[i]->getWin());
	}
	// wrefresh(_wwin);
	// setTitle("Gkrellm");
}

int		NCursesDisplay::input(void) {
	wtimeout(_wwin, REFRESH_TIME);
	return (wgetch(_wwin));
}
