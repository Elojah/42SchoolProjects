#include "Serializer.hpp"
#include <cstdlib>
#include <climits>

Serializer::Serializer(void) {
}

Serializer::Serializer(Serializer const &src) {
	if (this != &src)
		*this = src;
}

Serializer::~Serializer(void) {
}

void				*Serializer::generate(void) {
	static Serializer::Data	data;
	static char const		alphanum[63] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	std::srand(clock());
	for (int i = 0; i < 8; ++i) {
		data.s1.push_back(alphanum[std::rand() % 62]);
		data.s2.push_back(alphanum[std::rand() % 62]);
	}
	data.n = std::rand();
	return (reinterpret_cast<void *>(&data));
}

Serializer::Data	*Serializer::discover(void *raw) {
	static Serializer::Data		*d;

	d = reinterpret_cast<Serializer::Data *>(raw);
	return (d);
}


Serializer		&Serializer::operator=(Serializer const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, Serializer const &s) {
	(void)s;
	return (stream);
}
