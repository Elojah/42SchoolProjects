/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassMod.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 20:13:46 by leeios            #+#    #+#             */
/*   Updated: 2015/08/14 19:40:21 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassMod.hpp"
#include "MemberMod.hpp"
#include "StandardCmd.hpp"
#include "InterfaceCmd.hpp"
#include "config.hpp"
#include <string.h>
#include <dirent.h>
#include <algorithm>

ClassMod::ClassMod(int h, int w, int x, int y) :
	Menu(h, w, x, y) {
	_cmds[0] = nullptr;
}

ClassMod::~ClassMod(void) {
	for (size_t i = 0; _cmds[i]; ++i) {
		delete _cmds[i];
	}
}

void		ClassMod::construct(const std::string &path, const std::string &name) {
	_path = path;
	_name = name;
	_cmds[0] = new InterfaceCmd(_path);
	_cmds[1] = new StandardCmd(_path);
	_cmds[2] = nullptr;
	simpleCreate(_name);
}

void			ClassMod::sortItems(const int &length) {
	const static auto comp = [](const ITEM *lhs, const ITEM *rhs) -> bool {
		const char *lhsName = item_name(lhs);
		const char *rhsName = item_name(rhs);
		if(!strcmp(lhsName, "Return") || !strcmp(rhsName, "New class")) {
			return (false);
		} else if(!strcmp(lhsName, "New class") || !strcmp(rhsName, "Return")) {
			return (true);
		} else {
			return (strcmp(lhsName, rhsName) > 0);
		}
	};
	std::sort(_menuItems, _menuItems + length, comp);
}

void			ClassMod::createItems(void) {
	DIR						*dir;
	struct dirent	*ent;
	std::string		value;

	addItem("New class", static_cast<Callback>(&ClassMod::newClass));
	addItem("Return", static_cast<Callback>(&ClassMod::endMenu));
	if ((dir = opendir((_path + '/' + INCLUDE_DIRECTORY).c_str())) == nullptr) {
		notifyUser("Error opening include directory");
		return ;
	}
	while ((ent = readdir(dir)) != nullptr) {
		int				found;

		value = std::string(ent->d_name);
		found = value.find_last_of(".");
		if (value.compare(found + 1, value.size(), "hpp") == 0
			&& !value.substr(0, found).empty()) {
			addItem(value.substr(0, found), static_cast<Callback>(&ClassMod::selectClass));
		}
	}
	closedir(dir);
}

void		ClassMod::newClass(ITEM *item) {
	std::string	input(readUser());

	(void)item;
	for (size_t i = 0; _cmds[i]; ++i) {
		if (_cmds[i]->adhere(input)) {
			notifyUser(_cmds[i]->exec(input));
			return ;
		}
	}
}

void	ClassMod::selectClass(ITEM *item) {
	MemberMod		member(20, 60, 1, 59);

	member.construct(_path, item_name(item));
}
