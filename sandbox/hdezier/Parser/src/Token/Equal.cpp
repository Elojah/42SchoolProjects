#include "Equal.hpp"

Equal::Equal(void) {
	_read.type = EQUAL;
}

Equal::~Equal(void) {
}

int		Equal::detect(const char &c) {
	bool		emptyWord(_read.word.empty());
	char		last;

	if (emptyWord) {
		if (c == '<' || c == '=') {
			_read.word.push_back(c);
			return (FOUND);
		} else {
			return (NONE);
		}
	}
	if (c != '<' && c != '=' && c != '>') {
		if (_read.word.size() > 1) {
			return (COMPLETE);
		} else {
			return (NONE);
		}
	}
	last = *(_read.word.rbegin());
	if ((last == '=' && c == '>')
		|| (_read.word[0] == '<' && c == '=')) {
		_read.word.push_back(c);
		return (FOUND);
	}
	return (NONE);
}

int		Equal::getPriority(void) const {
	return (1);
}
