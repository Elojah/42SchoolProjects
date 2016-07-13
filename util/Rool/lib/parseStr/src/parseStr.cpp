#include "parseStr.hpp"
#include <stdlib.h>
#include <strings.h>
#include <cstring>

/*
**Parse functions
*/
std::string		parseClassName(std::string const &str) {
	std::size_t	found;

	if ((found = str.find(':')) != std::string::npos) {
		return (str.substr(0, found));
	}
	return (std::string(str));
}
std::string		parseIncGuard(std::string const &str) {
	std::string				result;
	std::string				tmp;

	tmp = parseClassName(str);
	for (std::string::size_type i = 0; i < tmp.size(); ++i)
	{
		if (tmp[i] >= 'A' && tmp[i] <= 'Z' && i != 0)
			result.push_back('_');
		result.push_back(std::toupper(tmp[i]));
	}
	return (result);
}
std::string		parseParents(std::string const &str) {
	std::size_t	found;

	if ((found = str.find(':')) != std::string::npos) {
		return (str.substr(found + 1));
	}
	return (std::string());
}

std::string		parseOldName(std::string const &str) {
	std::size_t	found;

	if ((found = str.find("${OLD_NAME=")) != std::string::npos) {
		found += 11;/*HARDCODE*/
		return (str.substr(found, str.find('}', found) - found));
	}
	return ("");
}
std::string		parseNewName(std::string const &str) {
	std::size_t	found;

	if ((found = str.find("${NEW_NAME=")) != std::string::npos) {
		found += 11;/*HARDCODE*/
		return (str.substr(found, str.find('}', found) - found));
	}
	return ("");
}

std::vector<std::map<std::string, std::string> >					parseLoopParents(const std::string &str) {
	char											*pch;
	char											*toFree;
	std::vector<std::map<std::string, std::string> >	result;
	std::map<std::string, std::string>				tmp;
	std::string										wholeParent;
	std::size_t										found;
	std::size_t										foundEnd;

	if (str.empty()) {
		return (std::vector<std::map<std::string, std::string> >());
	}
	pch = std::strtok((toFree = strdup(str.c_str())),",");
	while (pch != NULL) {
		wholeParent = std::string(pch);
		found = wholeParent.find_first_not_of(' ');
		tmp["${ACCESS}"] = ", " + wholeParent.substr(found, (foundEnd = wholeParent.find(' ', found)) - found);
		found = wholeParent.find_first_not_of(' ', foundEnd);
		tmp["${CLASS_NAME}"] = wholeParent.substr(found, wholeParent.find(' ', found) - found);
		result.push_back(std::map<std::string, std::string>(tmp));
		pch = std::strtok(NULL,",");
	}
	free(toFree);

	/*HARDCODE*/
	(result.front())["${ACCESS}"].replace(0, 2, " : ");
	/*!HARDCODE*/
	return (result);
}
