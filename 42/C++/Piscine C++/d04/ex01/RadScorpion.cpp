#include "RadScorpion.hpp"
#include <iostream>

RadScorpion::RadScorpion(void) :
	Enemy(80, "RadScorpion") {
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const &src) :
	Enemy(80, "RadScorpion") {
	if (this != &src)
		*this = src;
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion(void) {
	std::cout << "* SPROTCH *" << std::endl;
}

void		RadScorpion::takeDamage(int amount) {
	if (!_hp || amount <= 3)
		return ;
	amount -= 3;
	if (amount > _hp) {
		_hp = 0;
	} else {
		_hp -= amount;
	}
}

RadScorpion		&RadScorpion::operator=(RadScorpion const &rhs) {
	if (this != &rhs) {
		_type = rhs._type;
		_hp = rhs._hp;
	}
	return (*this);
}
