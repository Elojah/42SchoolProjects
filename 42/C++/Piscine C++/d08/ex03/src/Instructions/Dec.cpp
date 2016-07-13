#include "Dec.hpp"

Dec::Dec(void) {
}

Dec::Dec(Dec const &src) {
	if (this != &src)
		*this = src;
}

Dec::~Dec(void) {
}

Dec		&Dec::operator=(Dec const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

void		Dec::exec(int *i) {
	(*i)--;
}
