#include "UsualInterface.hpp"
#include "parseStr.hpp"
#include "fileManip.hpp"

UsualInterface::UsualInterface(void) {
}

UsualInterface::~UsualInterface(void) {
}

bool			UsualInterface::isBehavior(std::string const &str) {
	return ((str.c_str())[0] == 'I' && (str.c_str())[1] >= 'A' && (str.c_str())[1] <= 'Z');
}
std::string		UsualInterface::makeBehavior(void) {
	createNewFile("interface", path + "/include/" + genMapName["${CLASS_NAME}"] + ".hpp", genMapName, loopMapName);
	addToFile("INTERFACE", genMapName["${CLASS_NAME}"], path + "/Makefile", false);
	return ("Interface " + genMapName["${CLASS_NAME}"] + " created successfully!");
}

std::map<std::string, std::string(*)(const std::string&)>	UsualInterface::createMapName(void) {
	std::map<std::string, parseStr>	m;

	/*Add differents names here*/
	m["${CLASS_NAME}"] = &parseClassName;
	m["${INC_GUARD}"] = &parseIncGuard;
	m["${PARENTS}"] = &parseParents;
	return (m);
}

std::map<std::string, std::vector<std::map<std::string, std::string> > >	UsualInterface::createLoopMapName(void) {
	loopMap			m;

	/*Add differents names here*/
	if (genMapName.find("${PARENTS}") != genMapName.end()) {/*Not mandatory ?*/
		m["${PARENTS}"] = parseLoopParents(genMapName["${PARENTS}"]);
	}
	return (m);
}
