#include "ReplaceClassName.hpp"
#include "parseStr.hpp"
#include "fileManip.hpp"

ReplaceClassName::ReplaceClassName(void) {
}

ReplaceClassName::~ReplaceClassName(void) {
}

bool			ReplaceClassName::isBehavior(std::string const &str) {
	if (str.find("${NEW_NAME=") != std::string::npos
		&& str.find("${OLD_NAME=") != std::string::npos) {
		return (true);
	}
	return (false);
}

std::string		ReplaceClassName::makeBehavior(void) {
	std::map<std::string, std::string>	oldMap;
	std::string							srcPath;

	srcPath = getStrLine(path + "/Makefile", genMapName["${OLD_NAME}"] + '\\');
	srcPath = getDirBaseName(srcPath)[0];
	oldMap = generateMapName(genMapName["${OLD_NAME}"]);
	genMapName = generateMapName(genMapName["${NEW_NAME}"]);
	replaceMapToMap(path + "/src/" + srcPath + oldMap["${CLASS_NAME}"] + ".cpp"
		, path + "/src/" + srcPath + genMapName["${CLASS_NAME}"] + ".cpp"
		,oldMap, genMapName);
	replaceMapToMap(path + "/include/" + oldMap["${CLASS_NAME}"] + ".hpp"
		, path + "/include/" + genMapName["${CLASS_NAME}"] + ".hpp"
		,oldMap, genMapName);
	addToFile(oldMap["${CLASS_NAME}"] + '\\', srcPath + genMapName["${CLASS_NAME}"], path + "/Makefile", true);
	return (oldMap["${CLASS_NAME}"] + " has successfully been replaced by " + genMapName["${CLASS_NAME}"]);
}

std::map<std::string, std::string(*)(const std::string&)>	ReplaceClassName::createMapName(void) {
	std::map<std::string, parseStr>	m;

	/*Add differents names here*/
	m["${CLASS_NAME}"] = &parseClassName;
	m["${INC_GUARD}"] = &parseIncGuard;
	m["${OLD_NAME}"] = &parseOldName;
	m["${NEW_NAME}"] = &parseNewName;
	return (m);
}
