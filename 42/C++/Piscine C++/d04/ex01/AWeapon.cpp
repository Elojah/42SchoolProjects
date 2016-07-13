#include "AWeapon.hpp"

AWeapon::AWeapon(void) {
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) :
	_name(std::string(name)),
	_damages(damage),
	_cost(apcost) {
}

AWeapon::AWeapon(AWeapon const &src) {
	if (this != &src)
		*this = src;
}

AWeapon::~AWeapon(void) {
}

std::string const	&AWeapon::getName(void) const {
	return (_name);
}

int					AWeapon::getAPCost(void) const {
	return (_cost);
}

int					AWeapon::getDamage(void) const {
	return (_damages);
}

AWeapon		&AWeapon::operator=(AWeapon const &rhs) {
	if (this != &rhs) {
		_name = rhs._name;
		_cost = rhs._cost;
		_damages = rhs._damages;
	}
	return (*this);
}
