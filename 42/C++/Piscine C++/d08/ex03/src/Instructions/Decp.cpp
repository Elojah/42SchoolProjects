#include "Decp.hpp"

Decp::Decp(void) {
}

Decp::Decp(Decp const &src) {
	if (this != &src)
		*this = src;
}

Decp::~Decp(void) {
}

Decp		&Decp::operator=(Decp const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

void		Decp::exec(int *i) {
	i--;
}
