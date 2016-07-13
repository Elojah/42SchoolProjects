#include "Human.hpp"

Human::Human(void) {
}

Human::~Human(void) {
}

const Brain		&Human::getBrain(void) const {
	return (_b);
}

std::string		Human::identify(void) const {
	return (_b.identify());
}
