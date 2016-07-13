#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(void) : _name("Unnamed") {
}

HumanB::HumanB(const std::string &s) : _name(std::string(s)) {
}

HumanB::HumanB(const std::string &s, Weapon &w) : _name(std::string(s)),
													_w(&w) {
}

HumanB::~HumanB(void) {
}

void			HumanB::attack(void) const {
	if (_w)
		std::cout << _name << "\tATTACK WITH HIS AWESOME\t" << _w->getType() << std::endl;
	else
		std::cout << _name << "\tATTACK WITH HIS AWESOME\t" << "SLAPS ..." << std::endl;
}

void			HumanB::setWeapon(Weapon &w) {
	_w = &w;
}
