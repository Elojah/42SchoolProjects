#include "LoopBegin.hpp"

LoopBegin::LoopBegin(void) {
}

LoopBegin::LoopBegin(LoopBegin const &src) {
	if (this != &src)
		*this = src;
}

LoopBegin::~LoopBegin(void) {
}

LoopBegin		&LoopBegin::operator=(LoopBegin const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

void		LoopBegin::exec(int *i) {
	(void)i;
}
