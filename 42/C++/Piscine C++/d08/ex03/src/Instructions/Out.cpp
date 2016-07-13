#include "Out.hpp"
#include <iostream>

Out::Out(void) {
}

Out::Out(Out const &src) {
	if (this != &src)
		*this = src;
}

Out::~Out(void) {
}

Out		&Out::operator=(Out const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

void		Out::exec(int *i) {
	std::cout << static_cast<char>(*i);
}
