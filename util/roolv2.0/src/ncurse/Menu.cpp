/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 13:05:59 by leeios            #+#    #+#             */
/*   Updated: 2015/08/13 14:01:32 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Menu.hpp"
#include <stdlib.h>
#include <string.h>

Menu::Menu(void) : Window(),
					_menu(nullptr),
					_winMenu(nullptr) {
	_menuItems[0] = nullptr;
}

Menu::Menu(int h, int w, int y, int x) : Window(h, w, y, x),
										_menu(nullptr),
										_winMenu(nullptr) {
	_menuItems[0] = nullptr;
}

Menu::~Menu(void) {
	reset();
}

/*
**Util
*/
void				Menu::addItem(const std::string &str, void (Menu::*call)(ITEM *)) {
	ITEM			*tmp;

	if ((tmp = new_item(strdup(str.c_str()), nullptr))) {
		_items[tmp] = call;
	}
}

/*
**MAIN FUNCTIONS
*/
void		Menu::simpleCreate(const std::string &_title) {
	setTitle(_title);
	loop();
	userInput();
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
	while((key = wgetch(_win)) != ESC)
	{
		if (key == DOWN) {
			menu_driver(_menu, REQ_DOWN_ITEM);
		} else if (key == UP) {
			menu_driver(_menu, REQ_UP_ITEM);
		} else if (key == SELECT) {
			if ((it = _items.find(current_item(_menu))) != _items.end()) {
				(this->*(it->second))(current_item(_menu));
			} else {
				errorCallback(current_item(_menu));
			}
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
	_items.clear();
	if (_menu) {
		unpost_menu(_menu);
		free_menu(_menu);
		_menu = nullptr;
	}
	for (size_t i = 0; _menuItems[i]; ++i) {
		void	*tmp;
		tmp = (void *)item_description(_menuItems[i]);
		if (tmp) {
			free(tmp);
		}
		tmp = (void *)item_name(_menuItems[i]);
		if (tmp) {
			free(tmp);
		}
		free_item(_menuItems[i]);
	}
	if (_winMenu) {
		wrefresh(_winMenu);
		delwin(_winMenu);
		_winMenu = nullptr;
	}
}

void			Menu::setMenuItems(void) {
	size_t		i;

	i = 0;
	for (const auto &it : _items) {
		_menuItems[i] = it.first;
		i++;
	}
	_menuItems[i] = nullptr;
	sortItems(i);
}

void			Menu::createMenu(void) {
	_menu = new_menu((ITEM **)_menuItems);
	_winMenu = derwin(_win, _h - 4, _w - 4, 2, 2);
	set_menu_win(_menu, _win);
	set_menu_sub(_menu, _winMenu);
	set_menu_mark(_menu, "> ");
	set_menu_format(_menu, _h - 4, 1);
	post_menu(_menu);
	mvwaddstr(_win, 0, (_w - _title.size()) / 2, _title.c_str());
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
