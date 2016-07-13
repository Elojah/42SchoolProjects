#include "GUI.hpp"
#include <ncurses.h>

GUI::GUI(void) {
	initscr();
	clear();
	noecho();
	cbreak();
	raw();
	cbreak();
	keypad(stdscr, TRUE);
}

GUI::~GUI(void) {
	endwin();
}
