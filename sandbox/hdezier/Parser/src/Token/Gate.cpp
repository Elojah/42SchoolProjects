#include "Gate.hpp"

Gate::Gate(void) {
	_read.type = GATE;
}

Gate::~Gate(void) {
}

int		Gate::detect(const char &c) {
	size_t		len(_read.word.size());

	if ((_read.word.empty() && (c == '&' || c == '|'))
		|| (len == 1 && c == _read.word[0])) {
		_read.word.push_back(c);
		return (FOUND);
	}
	if (len == 2) {
		return (COMPLETE);
	}
	return (NONE);
}

int		Gate::getPriority(void) const {
	return (1);
}
