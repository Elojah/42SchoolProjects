#include "UsualClass.hpp"
#include "parseStr.hpp"
#include "fileManip.hpp"
#include <sys/stat.h>
#include <sys/types.h>

UsualClass::UsualClass(void) {
}

UsualClass::~UsualClass(void) {
}

bool																		UsualClass::isBehavior(std::string const &str) {
	(void)str;
	return (true);
}

void																		UsualClass::init(const std::string &str, const std::string &pathSet) {
	path = pathSet;
	genMapName["${FULL_ENTRY}"] = std::string(str);
	mapName = createMapName();
}

std::string																	UsualClass::makeBehavior(void) {
	std::vector<std::string>	names;

	names = getDirBaseName(genMapName["${FULL_ENTRY}"]);
	if (!names[0].empty()) {
		mkdir((path + "/src/" + names[0]).c_str(), S_IRWXU);
	} else {
		names[0].clear();
	}
	genMapName = generateMapName(names[1]);
	loopMapName = createLoopMapName();
	createNewFile("src", path + "/src/" + names[0] + genMapName["${CLASS_NAME}"] + ".cpp", genMapName, loopMapName);
	createNewFile("include", path + "/include/" + genMapName["${CLASS_NAME}"] + ".hpp", genMapName, loopMapName);
	addToFile("CLASS", names[0] + genMapName["${CLASS_NAME}"], path + "/Makefile", false);
	return ("Usual class " + genMapName["${CLASS_NAME}"] + " created successfully!");
}

std::map<std::string, std::string(*)(const std::string&)>					UsualClass::createMapName(void) {
	std::map<std::string, parseStr>	m;

	/*Add differents names here*/
	m["${CLASS_NAME}"] = &parseClassName;
	m["${INC_GUARD}"] = &parseIncGuard;
	m["${PARENTS}"] = &parseParents;
	return (m);
}

std::map<std::string, std::vector<std::map<std::string, std::string> > >	UsualClass::createLoopMapName(void) {
	loopMap			m;

	/*Add differents names here*/
	if (genMapName.find("${PARENTS}") != genMapName.end()
		&& !genMapName["${PARENTS}"].empty()) {/*Not mandatory ?*/
		m["${PARENTS}"] = parseLoopParents(genMapName["${PARENTS}"]);
	}
	return (m);
}
