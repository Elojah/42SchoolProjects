#include "Entity.hpp"

Entity::Entity(void) {
	_read.type = ENTITY;
}

Entity::~Entity(void) {
}

int		Entity::detect(const char &c) {
	bool		emptyWord(_read.word.empty());

	if (isalpha(c) || (!emptyWord && isdigit(c))) {
		_read.word.push_back(c);
		return (FOUND);
	}
	if (!emptyWord) {
		return (COMPLETE);
	}
	return (NONE);
}

int		Entity::getPriority(void) const {
	return (1);
}
