#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) : _type("Untyped") {
	const static std::string		names[] = {
		"Igor", "Balor", "Tenor",
		"Arthrite", "Melior", "Kashiit",
		"Eros", "Matou", "Tremor", "Carios"
	};

	_name = names[rand() % 10];
	std::cout << "\tCreated: Zombie " << _type << '|' << _name << std::endl;
}

Zombie::Zombie(std::string name, std::string type) : _name(name),
													_type(type) {
	std::cout << "\tCreated: Zombie " << _type << '|' << _name << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "\tDeleted: Zombie " << _type << '|' << _name << std::endl;
}

void		Zombie::announce(void) const {
	std::cout << '<' << _name << " (" << _type << ")> Braiiiiiiinnnssss..." << std::endl;
}
