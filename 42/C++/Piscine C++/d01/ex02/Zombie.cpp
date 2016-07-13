#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) : _name("Unnamed"), _type("Untyped") {
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
