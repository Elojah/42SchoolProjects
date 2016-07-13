#include "Cat.hpp"

Cat::Cat(void) {
	_data.title = "ZAZ ZAZ ZAZ";
	_data.h = 2;
	_data.w = 20;
	_data.y = 22;
	_data.x = 52;
	_data.str_content = "Zaz loves cat !";
	_data.type = 3;
	_data.graph = false;
}

Cat::Cat(Cat const &src) {
	if (this != &src)
		*this = src;
}

Cat::~Cat(void) {
}

Cat		&Cat::operator=(Cat const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

void						Cat::start(void) {
}

void						Cat::refresh(void) {
}

IMonitorModule::sData const	&Cat::getData(void) const {
	return (_data);
}

