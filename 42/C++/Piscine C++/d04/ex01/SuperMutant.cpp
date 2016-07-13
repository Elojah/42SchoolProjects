#include "SuperMutant.hpp"
#include <iostream>

SuperMutant::SuperMutant(void) :
	Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &src) :
	Enemy(170, "Super Mutant") {
	if (this != &src)
		*this = src;
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant(void) {
	std::cout << "Aaargh ..." << std::endl;
}

void		SuperMutant::takeDamage(int amount) {
	if (!_hp || amount <= 3)
		return ;
	amount -= 3;
	if (amount > _hp) {
		_hp = 0;
	} else {
		_hp -= amount;
	}
}

SuperMutant		&SuperMutant::operator=(SuperMutant const &rhs) {
	if (this != &rhs) {
		_type = rhs._type;
		_hp = rhs._hp;
	}
	return (*this);
}
