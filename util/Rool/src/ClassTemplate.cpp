#include "ClassTemplate.hpp"
#include "TemplateBehavior.hpp"
#include "UsualInterface.hpp"
#include "UsualClass.hpp"
#include <fstream>

ClassTemplate::ClassTemplate(void) {
}

ClassTemplate::ClassTemplate(std::string const &path) : _path(path) {
}

ClassTemplate::~ClassTemplate(void) {
	for (tBehaviors::const_iterator it = _behav.begin(); it != _behav.end(); ++it) {
		delete (*it);
	}
}

std::string						ClassTemplate::create(const std::string &str) {
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

std::vector<TemplateBehavior *>		ClassTemplate::createBehavMap(void) {
	tBehaviors		result;

	result.push_back(new UsualInterface);
	result.push_back(new UsualClass);/*Keep UsualClass in last item*/
	return (result);
}

const std::vector<TemplateBehavior *>	ClassTemplate::_behav = ClassTemplate::createBehavMap();
