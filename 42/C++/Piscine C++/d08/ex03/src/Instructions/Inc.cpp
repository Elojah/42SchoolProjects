#include "Inc.hpp"

Inc::Inc(void) {
}

Inc::Inc(Inc const &src) {
	if (this != &src)
		*this = src;
}

Inc::~Inc(void) {
}

Inc		&Inc::operator=(Inc const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

void		Inc::exec(int *i) {
	(*i)++;
}
