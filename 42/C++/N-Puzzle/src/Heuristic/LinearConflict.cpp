#include "LinearConflict.hpp"
#include "State.hpp"

LinearConflict::LinearConflict(State const &s)
{
	_size = s.getSize();
	_finalMap = s.getMap();
}
LinearConflict::~LinearConflict(void) {}

int				LinearConflict::isInLine(int line, int n) const
{
	size_t		i;

	for (i = 0; i < _size; ++i)
	{
		if (n == _finalMap[line * _size + i])
			return (i);
	}
	return (-1);
}

int				LinearConflict::isInColumn(int col, int n) const
{
	size_t		i;

	for (i = 0; i < _size; ++i)
	{
		if (n == _finalMap[i * _size + col])
			return (i);
	}
	return (-1);
}

int				LinearConflict::eval(State const &s) const
{
	size_t		i;
	size_t		n;
	size_t		x;
	int			foundI;
	int			foundX;
	int			result(0);
	tArray const	&map(s.getMap());

	for (i = 0; i < _size * _size; ++i)
	{
		foundI = isInLine(i / _size, map[i]);
		if (foundI > -1)
		{
			for (n = 0; n < _size; ++n)
			{
				x = (i / _size) * _size + n;
				foundX = isInLine(x / _size, map[x]);
				if (foundX > -1 && ((i > x && foundI < foundX)
									|| (x > i && foundX < foundI)))
				{
						result += 2;
				}
			}
		}
		foundI = isInColumn(i % _size, map[i]);
		if (foundI > -1)
		{
			for (n = 0; n < _size; ++n)
			{
				x = n * _size + i % _size;
				foundX = isInColumn(x % _size, map[x]);
				if (foundX > -1	&& ((i > x && foundI < foundX)
									|| (x > i && foundX < foundI)))
				{
						result += 2;
				}
			}
		}
	}
	return (result);
}
