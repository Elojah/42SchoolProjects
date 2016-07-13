#include "Serializer.hpp"
#include <iostream>

void				*serialize(void) {
	Serializer		s;

	return (s.generate());
}

Serializer::Data	*unserialize(void *raw) {
	Serializer		s;

	return (static_cast<Serializer::Data *>(s.discover(raw)));
}

int		main(void) {
	void				*a;
	Serializer::Data	*b;
	Serializer::Data	*c;

	a = serialize();
	b = unserialize(a);
	c = unserialize(a);
	std::cout << "s1:\t" << b->s1
				<< std::endl
				<< "n:\t" << b->n
				<< std::endl
				<< "s2:\t" << b->s2
				<< std::endl;
	std::cout << "s1:\t" << c->s1
				<< std::endl
				<< "n:\t" << c->n
				<< std::endl
				<< "s2:\t" << c->s2
				<< std::endl;
	return (0);
}
