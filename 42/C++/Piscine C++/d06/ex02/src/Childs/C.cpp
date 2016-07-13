#include "C.hpp"

C::C(void) {
}

C::C(C const &src) {
	if (this != &src)
		*this = src;
}

C::~C(void) {
}

C		&C::operator=(C const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, C const &s) {
	(void)s;
	stream << "I am C Class !" << std::endl;
	return (stream);
}
