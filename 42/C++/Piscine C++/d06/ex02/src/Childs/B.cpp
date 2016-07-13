#include "B.hpp"

B::B(void) {
}

B::B(B const &src) {
	if (this != &src)
		*this = src;
}

B::~B(void) {
}

B		&B::operator=(B const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, B const &s) {
	(void)s;
	stream << "I am B Class !" << std::endl;
	return (stream);
}
