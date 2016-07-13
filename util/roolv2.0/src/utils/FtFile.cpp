/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FtFile.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 12:31:19 by leeios            #+#    #+#             */
/*   Updated: 2015/09/06 19:03:43 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <sstream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

namespace utils {

bool	makeFolder(const std::string &path) {
	if (mkdir(path.c_str(), S_IRWXU) < 0) {
		return (false);
	}
	return (true);
}

bool	makeFolderTree(std::string const &schema, std::string const &path) {
	std::ifstream	ifs(("./config/proj_tree/" + schema).c_str());

	if (ifs.fail()) {
		return (false);
	}
	std::string		line;

	if (mkdir(path.c_str(), S_IRWXU) < 0) {
		ifs.close();
		return (false);
	}
	while (std::getline(ifs, line)) {
		if (mkdir((path + "/" + line).c_str(), S_IRWXU) < 0) {
			ifs.close();
			return (false);
		}
	}
	ifs.close();
	return (true);
}

bool	makePath(const std::string &pathEnsure, const std::string &pathToMake) {
	std::string		finalPath(pathEnsure);
	char					*token;
	char					*toFree;

	if (pathToMake.empty()) {
		return (false);
	}
	toFree = strdup(pathToMake.c_str());
	token = strtok(toFree, "/");
	while (token != nullptr) {
		finalPath += "/";
		finalPath += token;
		mkdir(finalPath.c_str(), S_IRWXU);
		token = strtok(nullptr, "/");
	}
	free(toFree);
	return (true);
}

bool	touchFile(std::string const &origin, std::string const &dest) {

	std::ifstream	ifs(origin.c_str());
	std::ofstream	ofs(dest.c_str());
	std::string		line;

	if (ifs.fail() || ofs.fail()) {
		return (false);
	}
	while (std::getline(ifs, line)) {
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
	return (true);
}

bool	touchFileVariables(std::string const &origin, std::string const &dest
		, const std::map<std::string, std::string> &map) {
	std::ifstream		ifs(origin);
	std::ofstream		ofs(dest);
	std::string			line;

	if (ifs.fail() || ofs.fail()) {
		return (false);
	}
	while (std::getline(ifs,line)) {
		for (const auto i : map) {
			size_t found(0);

			while ((found = line.find(i.first, found)) != std::string::npos) {
				line.replace(found, i.first.length(), i.second);
				found++;
			}
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
	return (true);
}

const std::string			duplicateString(std::string const &filename
	, std::vector< std::map < std::string, std::string > > const &vecMap) {
	std::ifstream		ifs(filename);

	if (vecMap.empty() || ifs.fail()) {
		return ("");
	}
	std::string				result;
	std::stringstream	buffer;

	buffer << ifs.rdbuf();
	for (const auto i : vecMap) {
		std::string line(buffer.str());

		for (const auto s : i) {
			size_t found(0);

			while ((found = line.find(s.first, found)) != std::string::npos) {
				line.replace(found, s.first.length(), s.second);
				found++;
			}
		}
		result += line;
	}
	return (result);
}


void	addToFile(const std::string &oldName, const std::string &newName
	, const std::string &filePath, bool removeOld) {
	std::ifstream	ifs((filePath).c_str());
	std::ofstream	ofs;
	std::string		line;
	std::vector<std::string>			tmpFile;

	while (std::getline(ifs, line)) {
		tmpFile.push_back(line);
	}
	for (auto itRead = tmpFile.begin(); itRead != tmpFile.end(); ++itRead) {
		if ((*itRead).find(oldName) == std::string::npos) {
			continue ;
		}
		tmpFile.insert(itRead + 1, "\t\t" + newName + "\\");
		if (removeOld) {
			tmpFile.erase(itRead);
		}
		break ;
	}
	ifs.close();
	ofs.open((filePath).c_str());
	for (auto itWrite = tmpFile.begin(); itWrite != tmpFile.end(); ++itWrite) {
		ofs << *itWrite << std::endl;
	}
	ofs.close();
}

} //ns utils
