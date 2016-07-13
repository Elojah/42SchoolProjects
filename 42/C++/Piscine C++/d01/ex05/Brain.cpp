#include "Brain.hpp"
#include <sstream>

Brain::Brain(void) {
	std::stringstream		ss;
	ss << this;
	_id = ss.str();
}

Brain::~Brain(void) {
}

std::string		Brain::identify(void) const {
	return (_id);
}
