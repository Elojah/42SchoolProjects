#include "PlasmaRifle.hpp"
#include <iostream>

PlasmaRifle::PlasmaRifle(void) :
	AWeapon("PlasmaRifle", 5, 21) {
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src) :
	AWeapon(src._name, src._cost, src._damages) {
	if (this != &src)
		*this = src;
}

PlasmaRifle::~PlasmaRifle(void) {
}

void		PlasmaRifle::attack(void) const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

PlasmaRifle		&PlasmaRifle::operator=(PlasmaRifle const &rhs) {
	if (this != &rhs) {
		_name = rhs._name;
		_cost = rhs._cost;
		_damages = rhs._damages;
	}
	return (*this);
}
