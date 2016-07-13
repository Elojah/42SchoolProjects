#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(void) : _name("Unnamed") {
}

HumanA::HumanA(const std::string &s) : _name(std::string(s)) {
}
HumanA::HumanA(const std::string &s, Weapon &w) : _name(std::string(s)),
													_w(&w) {
}

HumanA::~HumanA(void) {
}

void			HumanA::attack(void) const {
	if (_w)
		std::cout << _name << "\tATTACK WITH HIS AWESOME\t" << _w->getType() << std::endl;
	else
		std::cout << _name << "\tATTACK WITH HIS AWESOME\t" << "SLAPS ..." << std::endl;
}

void			HumanA::setWeapon(Weapon &w) {
	_w = &w;
}
