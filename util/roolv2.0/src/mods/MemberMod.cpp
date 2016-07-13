/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MemberMod.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 15:24:43 by leeios            #+#    #+#             */
/*   Updated: 2015/08/14 19:40:28 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MemberMod.hpp"
#include "config.hpp"
#include <fstream>
#include <algorithm>
#include <string.h>

MemberMod::MemberMod(int h, int w, int x, int y) :
	Menu(h, w, x, y) {
	;
}

MemberMod::~MemberMod(void) {
	;
}

void		MemberMod::construct(const std::string &path, const std::string &name) {
	_path = path;
	_name = name;
	simpleCreate(_name);
}


void			MemberMod::sortItems(const int &length) {
	const static auto comp = [](const ITEM *lhs, const ITEM *rhs) -> bool {
		const char *lhsName = item_name(lhs);
		const char *rhsName = item_name(rhs);
		if(!strcmp(lhsName, "Return") || !strcmp(rhsName, "New member")) {
			return (false);
		} else if(!strcmp(lhsName, "New member") || !strcmp(rhsName, "Return")) {
			return (true);
		} else {
			return (strcmp(lhsName, rhsName) > 0);
		}
	};
	std::sort(_menuItems, _menuItems + length, comp);
}

void		MemberMod::createItems(void) {
	std::string		line;
	std::ifstream	ifs;
	std::string		access;
	size_t				count;

	line = _path + '/' + INCLUDE_DIRECTORY + '/' + _name + ".hpp";
	access = "";
	count = 0;
	ifs.open(line.c_str());
	if (!ifs) {
		return ;
	}
	while (std::getline(ifs, line))
	{
		if (line.find("class " + _name) != std::string::npos && std::getline(ifs, line))
		{
			while (std::getline(ifs, line) && line.compare("};") != 0)
			{
				parseLine(line, count);
				if (line.empty()) {
					;
				} else if (line.compare("public:") == 0) {
					access = "|  ";
				} else if (line.compare("protected:") == 0) {
					access = "/  ";
				} else if (line.compare("private:") == 0) {
					access = "-  ";
				} else {
					addItem(access + line, static_cast<Callback>(&MemberMod::errorCallback));
				}
				while (ifs.peek() == '\t' || ifs.peek() == ' ') {
					ifs.ignore();
				}
			}
			break ;
		}
	}
	ifs.close();
	addItem("New member", static_cast<Callback>(&MemberMod::errorCallback));
	addItem("Return", static_cast<Callback>(&MemberMod::endMenu));
}

void	MemberMod::parseLine(std::string &line, std::size_t &count) {
	std::size_t		found;
	std::size_t		bracket;

	if (line.empty()) {
		return ;
	}
	bracket = 0;
	while ((bracket = line.find('{', bracket)) != std::string::npos) {
		count++;
		bracket++;
	}
	bracket = 0;
	while ((bracket = line.find('}', bracket)) != std::string::npos) {
		count--;
		bracket++;
	}
	std::replace(line.begin(), line.end(), '\t', ' ');
	while (!line.empty() && line.at(0) == ' ') {
		line.erase(0, 1);
	}
	if ((count != 0 || line.find('}') != std::string::npos)
		&& (line.find('{') == std::string::npos || count > 1)) {
		line.clear();
	} else if ((found = line.find("//")) != std::string::npos
		|| (found = line.find("/*")) != std::string::npos
		|| (found = line.find("**")) != std::string::npos
		|| (found = line.find("*/")) != std::string::npos
		|| (found = line.find("{")) != std::string::npos) {
		line = line.substr(0, found);
	}
	if (line.find('(') != std::string::npos) {
		line.insert(0, "()  ");
	}
}
