#include "PowerFist.hpp"
#include <iostream>

PowerFist::PowerFist(void) :
	AWeapon("PowerFist", 8, 50) {
}

PowerFist::PowerFist(PowerFist const &src) :
	AWeapon(src._name, src._cost, src._damages) {
	if (this != &src)
		*this = src;
}

PowerFist::~PowerFist(void) {
}

void		PowerFist::attack(void) const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}

PowerFist		&PowerFist::operator=(PowerFist const &rhs) {
	if (this != &rhs) {
		_name = rhs._name;
		_cost = rhs._cost;
		_damages = rhs._damages;
	}
	return (*this);
}
