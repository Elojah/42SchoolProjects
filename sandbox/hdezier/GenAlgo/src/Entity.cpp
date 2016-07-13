#include "Entity.hpp"

Entity::Entity(void) :
	_n(0) {
}

Entity::Entity(size_t n) :
	_n(n) {
}

Entity::Entity(void) {
	*this = rhs;
}

Entity::~Entity(void) {
}

Entity	&operator=(Entity const &rhs) {
	if (this != &rhs) {
		_a = rhs._a;
		_b = rhs._b;
		_c = rhs._c;
	}
}

void	Entity::reborn(Entity const &a, Entity const &b) {
	_a = (a._a + b._a) / 2;
	_b = a._b;
	_c = b._c;
}

int		Entity::evaluate(void) const {
	return (a *b / c);
}

std::ostream	&operator<<(std::ostream &s, Entity const &rhs) {
	std::cout << "Value:\t" << rhs.evaluate() << std::endl;
}
