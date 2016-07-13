#include "Entities.hpp"

Entities::Entities(void) :
	_n(0),
	_melt(5) {
	_set = new Entity[_n];
}

Entities::Entities(size_t n) :
	_n(n),
	_melt(5) {
	_set = new Entity[_n];
}

Entities::Entities(void) {
	*this = rhs;
}

Entities::~Entities(void) {
}

Entities	&operator=(Entities const &rhs) {
	if (this != &rhs) {
		delete[] _set;
		_n = rhs._n;
		_n = rhs._melt;
		_set = new Entity[_n];
		for (size_t i = 0; i < _n; ++i) {
			_set[i] = rhs._set[i];
		}
	}
}

void	Entities::evolve(void) {
	size_t			a;
	size_t			b;
	size_t			tmp;
	int				aValue;
	int				bValue;
	int				tmpValue;

	for (size_t i = 0; i < _n; i += _melt) {
		a = i;
		b = i + 1;
		aValue = _set[a].evaluate();
		bValue = _set[b].evaluate();
		if (aValue < bValue) {
			tmp = a;
			a = b;
			b = tmp;
			tmpValue = aValue;
			aValue = tmpValue;
			bValue = tmpValue;
		}
		for (size_t j = i + 2; j < i + _melt; ++j) {
			if ((tmpValue = _set[j].evaluate()) > )
		}
	}
}
