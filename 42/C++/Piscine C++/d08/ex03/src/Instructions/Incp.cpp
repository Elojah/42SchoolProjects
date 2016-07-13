#include "Incp.hpp"

Incp::Incp(void) {
}

Incp::Incp(Incp const &src) {
	if (this != &src)
		*this = src;
}

Incp::~Incp(void) {
}

Incp		&Incp::operator=(Incp const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

void		Incp::exec(int *i) {
	i++;
}
