#include "Menu.hpp"
#include "SortItems.hpp"
#include <string.h>
#include <algorithm>

Menu::Menu(void) : Window(),
					menu(NULL),
					winMenu(NULL),
					sortObject(NULL) {
	menuItems[0] = NULL;
}

Menu::Menu(int h, int w, int y, int x) : Window(h, w, y, x),
										menu(NULL),
										winMenu(NULL) {
	menuItems[0] = NULL;
}

Menu::~Menu(void) {
	int		i;

	for (i = 0; menuItems[i]; ++i) {
		free_item(menuItems[i]);
	}
	if (menu) {
		unpost_menu(menu);
		free_menu(menu);
	}
	if (winMenu) {
		wrefresh(winMenu);
		delwin(winMenu);
	}
	if (sortObject) {
		delete sortObject;
	}
}

/*
**Util
*/
void				Menu::addItem(const std::string &str, void (Menu::*call)(ITEM *)) {
	ITEM			*tmp;

	if ((tmp = new_item(str.c_str(), ""))) {
		items[tmp] = call;
	}
}

/*
**MAIN FUNCTIONS
*/
void		Menu::simpleCreate(const std::string &title, const std::string &up, const std::string &down) {
	sortObject = new SortItems(up, down);
	setTitle(title);
	loop();
	userInput();
}

void		Menu::sortMenu(size_t length) {
	if (!sortObject) {
		return ;
	}
	std::sort(menuItems, menuItems + length, *sortObject);
}

void		Menu::loop(void) {
	reset();
	createItems();
	setMenuItems();
	createMenu();
}

void			Menu::userInput(void)
{
	char			key;
	Items::iterator	it;

	curs_set(0);
	while((key = wgetch(win)) != 27)
	{
		if (key == 's') {
			menu_driver(menu, REQ_DOWN_ITEM);
		} else if (key == 'w') {
			menu_driver(menu, REQ_UP_ITEM);
		} else if (key == 10) {
			if ((it = items.find(current_item(menu))) != items.end())
				(this->*(it->second))(current_item(menu));
			else
				errorCallback(current_item(menu));
			if (it->second == static_cast<Callback>(&Menu::endMenu)) {
				return ;
			}
			loop();
		}
	}
}

/*
**LOOP FUNCTIONS
*/
void		Menu::reset(void) {
	size_t	i;

	for (i = 0; menuItems[i]; i++) {
		free_item(menuItems[i]);
	}
	items.clear();
	if (menu) {
		unpost_menu(menu);
		free_menu(menu);
		menu = NULL;
	}
	if (winMenu) {
		wrefresh(winMenu);
		delwin(winMenu);
		winMenu = NULL;
	}
}

void			Menu::setMenuItems(void) {
	size_t		i;

	i = 0;
	for (Items::iterator it = items.begin(); it != items.end(); ++it) {
		menuItems[i] = it->first;
		i++;
	}
	menuItems[i] = NULL;
	sortMenu(i);
}

void			Menu::createMenu(void) {
	menu = new_menu((ITEM **)menuItems);
	winMenu = derwin(win, h - 4, w - 4, 2, 2);
	set_menu_win(menu, win);
	set_menu_sub(menu, winMenu);
	set_menu_mark(menu, "> ");
	set_menu_format(menu, h - 4, 1);
	post_menu(menu);
	mvwaddstr(win, 0, (w - title.size()) / 2, title.c_str());
}

/*
**Usual callbacks
*/
void			Menu::errorCallback(ITEM *item) {
	if (!item) {
		return ;
	}
	notifyUser(std::string(item_name(item)) + " callback is not define");
}

void		Menu::endMenu(ITEM *item) {
	(void)item;
}

