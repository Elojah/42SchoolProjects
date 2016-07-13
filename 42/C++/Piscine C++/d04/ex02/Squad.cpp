#include "Squad.hpp"
#include "ISpaceMarine.hpp"

Squad::Squad(void) :
	_count(0),
	_units(0) {
}

Squad::Squad(Squad const &src) {
	if (this != &src)
		*this = src;
}

Squad::~Squad(void) {
	for (int i = 0; i < _count; ++i)
		delete _units[i];
	delete []_units;
}

Squad		&Squad::operator=(Squad const &rhs) {
	if (this != &rhs) {
		for (int i = 0; i < _count; ++i)
			delete _units[i];
		_count = rhs.getCount();
		_units = new ISpaceMarine*[_count];
		for (int i = 0; i < _count; i++)
			_units[i] = rhs.getUnit(i);
	}
	return (*this);
}

int					Squad::getCount(void) const {
	return (_count);
}

ISpaceMarine		*Squad::getUnit(int n) const {
	if (n < 0 || n >= _count)
		return (0);
	return (_units[n]);
}

int					Squad::push(ISpaceMarine *sm) {
	ISpaceMarine	**tmp;

	tmp = new ISpaceMarine*[_count + 1];
	if (_count == 0) {
		tmp[0] = sm;
	} else {
		for (int i = 0; i < _count; ++i) {
			tmp[i] = _units[i];
		}
		tmp[_count] = sm;
		if (_units != 0)
			delete[] _units;
	}
	_units = tmp;
	return (++_count);
}
