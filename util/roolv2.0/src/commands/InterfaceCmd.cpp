/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InterfaceCmd.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 14:59:27 by leeios            #+#    #+#             */
/*   Updated: 2015/09/06 18:57:31 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InterfaceCmd.hpp"
#include "utils.hpp"
#include "config.hpp"

InterfaceCmd::InterfaceCmd(const std::string &path) :
	_path(path) {
}

InterfaceCmd::~InterfaceCmd(void) {
	;
}

bool								InterfaceCmd::adhere(const std::string &strCmd) const {
	std::string		name(utils::parseClassName(strCmd));

	return (name.at(0) == 'I' && name.at(1) >= 'A' && name.at(1) <= 'Z');
}

const std::string		InterfaceCmd::exec(const std::string &strCmd) const {
	std::string			name(utils::parseClassName(strCmd));
	auto						inheritParents(
		utils::duplicateString("./config/models/inherit_parents.model", utils::parseParents(strCmd))
	);

	if (!inheritParents.empty()) {
		inheritParents.at(0) = ':';
	}
	const std::map<std::string, std::string> map {
		{"${NAME}", name},
		{"${GUARD}", utils::parseGuard(strCmd)},
		{"${INC_PARENTS}", utils::duplicateString("./config/models/inc_parents.model", utils::parseParents(strCmd))},
		{"${INHERIT_PARENTS}", inheritParents}
	};

	utils::touchFileVariables("./config/models/interface.model"
		, _path + '/' + INCLUDE_DIRECTORY + '/' + name + ".hpp", map);
	return ("New class " + name + " created");
}

