#include "AssaultTerminator.hpp"
#include <iostream>

AssaultTerminator::AssaultTerminator(void) {
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &src) {
	if (this != &src)
		*this = src;
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator(void) {
	std::cout << "I’ll be back ..." << std::endl;
}

ISpaceMarine	*AssaultTerminator::clone(void) const {
	ISpaceMarine	*res;

	res = new AssaultTerminator(*this);
	return (res);
}

void			AssaultTerminator::battleCry(void) const {
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}

void			AssaultTerminator::rangedAttack(void) const {
	std::cout << "* does nothing *" << std::endl;
}

void			AssaultTerminator::meleeAttack(void) const {
	std::cout << "* attacks with chainfists *" << std::endl;
}

AssaultTerminator		&AssaultTerminator::operator=(AssaultTerminator const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}
