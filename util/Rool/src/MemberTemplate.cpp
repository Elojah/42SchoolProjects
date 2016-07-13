#include "MemberTemplate.hpp"
#include "ReplaceClassName.hpp"
#include <fstream>
#include <string.h>

MemberTemplate::MemberTemplate(void) {
}

MemberTemplate::MemberTemplate(std::string const &path) : _path(path) {
}

MemberTemplate::~MemberTemplate(void) {
	for (tBehaviors::const_iterator it = _behav.begin(); it != _behav.end(); ++it) {
		delete (*it);
	}
}

std::string								MemberTemplate::create(const std::string &str) {
	if (str.empty()) {
		return ("Nothing done");
	}
	for (tBehaviors::const_iterator it = _behav.begin(); it != _behav.end(); ++it) {
		if ((*it)->isBehavior(str)) {
			(*it)->init(str, _path);
			return ((*it)->makeBehavior());
		}
	}
	return ("No behavior matched with entry ...");
}

std::vector<TemplateBehavior *>		MemberTemplate::createBehavMap(void) {
	tBehaviors		result;

	result.push_back(new ReplaceClassName);
	return (result);
}

const std::vector<TemplateBehavior *>	MemberTemplate::_behav = MemberTemplate::createBehavMap();
