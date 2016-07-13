#include "Base.hpp"

Base::Base(void) {
}

Base::Base(Base const &src) {
	if (this != &src)
		*this = src;
}

Base::~Base(void) {
}

Base		&Base::operator=(Base const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, Base const &s) {
	(void)s;
	stream << "I am just some virtual Base..." << std::endl;
	return (stream);
}
