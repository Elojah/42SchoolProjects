#include "ClassList.hpp"
#include "ClassTemplate.hpp"
#include "SortItems.hpp"
#include "MemberList.hpp"
#include "parseStr.hpp"
#include "fileManip.hpp"
#include <dirent.h>
#include <algorithm>
#include <fstream>

ClassList::ClassList(void) {
}

ClassList::ClassList(int h, int w, int y, int x) : Menu(h, w, y, x) {
}

ClassList::~ClassList(void) {
}

void		ClassList::sortMenu(size_t length) {
	SortItems	sortObject0("New class", "Return");
	SortItems	sortObject1("New lib", "")

	std::sort(menuItems, menuItems + length, sortObject0);
	std::sort(&(menuItems[1]), &(menuItems[1]) + length - 2, sortObject1);
}

void		ClassList::init(const std::string &path, const std::string &name) {
	_path = path
	_name = name;
	simpleCreate("Classes", "", "");
}

void		ClassList::createItems(void) {
	DIR				*dir;
	struct dirent	*ent;
	std::string		value;

	if ((dir = opendir((_path + "/include").c_str())) == NULL) {
		return ;
	}
	while ((ent = readdir(dir)) != NULL) {
		int				found;

		value = std::string(ent->d_name);
		found = value.find_last_of(".");
		if (value.compare(found + 1, value.size(), "hpp") == 0
			&& !value.substr(0, found).empty()) {
			addItem(value.substr(0, found), static_cast<Callback>(&ClassList::listAttributes));
		}
	}
	closedir(dir);
	addItem("New class", static_cast<Callback>(&ClassList::newClass));
	addItem("New lib", static_cast<Callback>(&ClassList::newLib));
	addItem("Return", static_cast<Callback>(&ClassList::endMenu));
}

/*
**Callbacks fcts
*/
void		ClassList::newClass(ITEM *item) {
	std::string		className;
	ClassTemplate	tpl(_path)

	(void)item;
	className = readUser();
	notifyUser(tpl.create(className));
}

void		ClassList::newLib(ITEM *item) {
	std::string							libName;
	std::string							libPath;
	std::map<std::string, std::string>	tmpMap;
	loopMap								tmpLoopMap;

	(void)item;
	libName = readUser();
	libPath = _path + "/lib/" + libName;
	tmpMap["${NAME}"] = libName;
	createArbo("lib", _path + "/lib", libName);
	createNewFile("MakeLib", libPath + "/Makefile", tmpMap, tmpLoopMap);
	tmpMap["${INC_GUARD}"] = parseIncGuard(libName);
	tmpMap["${CLASS_NAME}"] = libName;
	createNewFile("include", libPath + "/include/" + libName + ".hpp", tmpMap, tmpLoopMap);
	createNewFile("src", libPath + "/src/" + libName + ".cpp", tmpMap, tmpLoopMap);
	addToFile("LIB_LOCAL", "lib/" + libName, _path + "/Makefile", false);
	addToFile("LIB_GLOBAL", libName, _path + "/Makefile", false);
	notifyUser("Lib " + libName + " created successfully !");
}

void	ClassList::listAttributes(ITEM *item) {
	std::string		className(item_name(item));
	MemberList		member(h - 1, w / 2, 2, w / 2);

	member.init(_path, className);
}
