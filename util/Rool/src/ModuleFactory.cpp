#include "ModuleFactory.hpp"
#include "ClassList.hpp"
#include "IModule.hpp"
#include <fstream>

ModuleFactory::ModuleFactory(void) {
}

ModuleFactory::~ModuleFactory(void) {
}

IModule*(ModuleFactory::*ModuleFactory::makeModule(std::string const &key))(int, int, int, int) {
	std::map<std::string, makeFn>::const_iterator	it;

	it = ModuleFactory::allModules.find(key);
	if (it == ModuleFactory::allModules.end()) {
		return (NULL);
	}
	return (it->second);
}

std::map<std::string, IModule*(ModuleFactory::*)(int, int, int, int)>
		ModuleFactory::createAllModules(void) {
	std::map<std::string, makeFn>	result;

	result["classList"] = &ModuleFactory::makeClassList;
	return (result);
}

IModule		*ModuleFactory::makeClassList(int h, int w, int y, int x) {
	return (new ClassList(h, w, y, x));
}

const std::map<std::string, IModule*(ModuleFactory::*)(int h, int w, int y, int x)>
	ModuleFactory::allModules = ModuleFactory::createAllModules();
