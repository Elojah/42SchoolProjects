#include "Weapon.hpp"

Weapon::Weapon(void) : _type("No weapon") {
}
Weapon::Weapon(const std::string &s) : _type(std::string(s)) {
}

Weapon::~Weapon(void) {
}

void				Weapon::setType(const std::string &s) {
	_type = std::string(s);
}

const std::string	&Weapon::getType(void) {
	return (_type);
}
