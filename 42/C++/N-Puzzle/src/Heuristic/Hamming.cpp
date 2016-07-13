#include "Hamming.hpp"
#include "State.hpp"

Hamming::Hamming(State const &s)
{
	_size = s.getSize();
	_finalMap = s.getMap();
}
Hamming::~Hamming(void) {}

int			Hamming::eval(State const &s) const
{
	size_t	i;
	int		result(0);
	tArray const	&map(s.getMap());

	for (i = 0; i < _size * _size; ++i)
	{
		if (map[i] != _finalMap[i])
			result++;
	}
	return (result);
}
