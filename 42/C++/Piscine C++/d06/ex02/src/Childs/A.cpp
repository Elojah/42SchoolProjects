#include "A.hpp"

A::A(void) {
}

A::A(A const &src) {
	if (this != &src)
		*this = src;
}

A::~A(void) {
}

A		&A::operator=(A const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, A const &s) {
	(void)s;
	stream << "I am A Class !" << std::endl;
	return (stream);
}
