#include "Project.hpp"
#include "IModule.hpp"
#include <string>
#include <fstream>
#include <libgen.h>
#include <string.h>
#include <stdlib.h>

Project::Project(void) {
}

Project::Project(std::string const &path) : Window() {
	char	*tmp;

	tmp = strdup(path.c_str());
	_path = std::string(path);
	_name = std::string(basename(tmp));
	free(tmp);
	setTitle(_name);
	setModules("./config/.modules");
	initModules();
}

Project::~Project(void) {
}

void		Project::setModules(std::string const &configFile) {
	std::ifstream		ifs(configFile.c_str());
	std::string			line;
	makeFn				tmp;

	while (std::getline(ifs, line)) {
		tmp = _modsFactory.makeModule(line);
		if (tmp) {
			_mods.push_back((_modsFactory.*tmp)(h / 2 - 2, w - 2, y + 1, x + 1));/*HARDCODE*/
		}
	}
}

void		Project::initModules(void) {
	for (std::vector<IModule *>::iterator it = _mods.begin(); it != _mods.end(); ++it) {
		(*it)->init(_path, _name);
	}
}
