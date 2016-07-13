#include "LoopEnd.hpp"

LoopEnd::LoopEnd(void) {
}

LoopEnd::LoopEnd(LoopEnd const &src) {
	if (this != &src)
		*this = src;
}

LoopEnd::~LoopEnd(void) {
}

LoopEnd		&LoopEnd::operator=(LoopEnd const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

void		LoopEnd::exec(int *i) {
	(void)i;
}
