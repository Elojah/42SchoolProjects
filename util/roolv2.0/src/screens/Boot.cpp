/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boot.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 13:58:16 by leeios            #+#    #+#             */
/*   Updated: 2015/12/30 02:34:21 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Boot.hpp"
#include "utils.hpp"
#include "Project.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>

Boot::Boot(void) : Menu() {
	simpleCreate("Projects List");
}

Boot::~Boot(void) {
}

/*
**Class dependant item creation
*/
void		Boot::createItems(void)
{
	std::ifstream	ifs("./config/.proj");
	std::string		line;
	char					*tmp;

	addItem("New project", static_cast<Callback>(&Boot::newProject));
	addItem("Return", static_cast<Callback>(&Boot::endMenu));
	if (ifs.fail()) {
		notifyUser("Error: File ./config/.proj doesn't exist.");
		return ;
	}
	while (std::getline(ifs, line)) {
		if (line.empty() || line.at(0) == '#') {
			continue ;
		}
		tmp = strdup(line.c_str());
		_items[new_item(strdup(basename(tmp)), tmp)]
			= static_cast<Callback>(&Boot::openProject);
	}
	ifs.close();
}

void		Boot::sortItems(const int &length) {
	const static auto comp = [](const ITEM *lhs, const ITEM *rhs) -> bool {
		const char *lhsName = item_name(lhs);
		const char *rhsName = item_name(rhs);
		if(!strcmp(lhsName, "Return") || !strcmp(rhsName, "New project")) {
			return (false);
		} else if(!strcmp(lhsName, "New project") || !strcmp(rhsName, "Return")) {
			return (true);
		} else {
			return (strcmp(lhsName, rhsName) > 0);
		}
	};

	std::sort(_menuItems, _menuItems + length, comp);
}

/*
**Callbacks
*/
void		Boot::newProject(ITEM *item) {
	std::string	path(readUser());

	(void)item;
	if (!utils::makeFolderTree("classic.tree", path)) {
		notifyUser("Project " + path + " failed to build ...");
		return ;
	} else {
		std::string			name(utils::parseClassName(path));
		const std::map<std::string, std::string> map {
			{"${NAME}", path}
		};

		utils::touchFileVariables("./config/models/sublime-project.model"
			, path + '/' + name + ".sublime-project", map);
		utils::touchFile("./config/models/Makefile.model", path + "/Makefile");
		utils::touchFile("./config/models/main.model", path + "/src/main.cpp");
		notifyUser("Project " + path + " created successfully !");
		std::ofstream		proj("./config/.proj", std::fstream::app);

		if (proj.fail()) {
			notifyUser("Error opening proj list ...");
		} else {
			proj << path << std::endl;
		}
	}}

void		Boot::openProject(ITEM *item) {
	// Schema is HARDCODE here, customize like an option with default ?
	Project			proj(item_description(item), item_name(item));

	proj.run();
}
