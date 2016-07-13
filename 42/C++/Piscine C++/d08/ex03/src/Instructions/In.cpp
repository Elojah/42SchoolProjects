#include "In.hpp"
#include <iostream>

In::In(void) {
}

In::In(In const &src) {
	if (this != &src)
		*this = src;
}

In::~In(void) {
}

In		&In::operator=(In const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

void		In::exec(int *i) {
	std::cin >> *i;
}
