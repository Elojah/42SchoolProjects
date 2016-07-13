#include "Boot.hpp"
#include "Project.hpp"
#include "SortItems.hpp"
#include "fileManip.hpp"
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>

Boot::Boot(void) : Menu() {
	simpleCreate("Projects List", "New project", "Return");
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

	if (ifs.fail()) {
		std::cout << "Error: File ./config/.proj doesn't exist." << std::endl;
		return ;
	}
	while (std::getline(ifs, line)) {
		if (line.empty() || line.at(0) == '#') {
			continue ;
		}
		tmp = strdup(line.c_str());
		items[new_item(basename(tmp), tmp)]
			= static_cast<Callback>(&Boot::openProject);
	}
	addItem("New project", static_cast<Callback>(&Boot::newProject));
	addItem("Return", static_cast<Callback>(&Boot::endMenu));
	ifs.close();
}

/*
**Callbacks
*/
void		Boot::newProject(ITEM *item) {
	std::string	path(readUser());

	if (!utils::makeFolderTree("classic.tree", path)) {
		notifyUser("Project " + path + " failed to build ...");
	}
	notifyUser("Project " + path + " created successfully !");
}

void		Boot::openProject(ITEM *item) {
	Project		p(std::string(item_description(item)));
}
