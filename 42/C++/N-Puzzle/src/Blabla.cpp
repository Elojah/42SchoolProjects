#include "Blabla.hpp"

Blabla::Blabla(void) {
}

Blabla::Blabla(Blabla const &src) {
	if (this != &src)
		*this = src;
}

Blabla::~Blabla(void) {
}

Blabla		&Blabla::operator=(Blabla const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, Blabla const &s) {
	stream << "" << std::endl;
	return (stream);
}
