#include "Manhattan.hpp"
#include "State.hpp"
#include <iostream>

Manhattan::Manhattan(State const &s)
{
	_size = s.getSize();
	_finalMap = s.getMap();
}
Manhattan::~Manhattan(void) {}

int				Manhattan::eval(State const &s) const
{
	size_t		i;
	size_t		j;
	size_t		x;
	size_t		y;
	int			result(0);
	tArray const	&map(s.getMap());

	for (i = 0; i < _size * _size; ++i)
	{
		j = 0;
		while (j < _size * _size)
		{
			if (map[i] == _finalMap[j])
			{
				x = i % _size;
				y = j % _size;
				result += (i > j ? i / _size - j / _size + DIST(x, y)
						   : j / _size - i / _size + DIST(x, y));
				break ;
			}
			j++;
		}
	}
	return (result);
}
