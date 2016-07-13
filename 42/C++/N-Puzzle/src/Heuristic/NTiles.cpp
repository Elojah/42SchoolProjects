#include "NTiles.hpp"
#include "State.hpp"

NTiles::NTiles(State const &s)
{
	_size = s.getSize();
	_finalMap = s.getMap();
}
NTiles::~NTiles(void) {}

int			NTiles::eval(State const &s) const
{
	size_t	i;
	size_t	j;
	int		result(0);
	tArray const	&map(s.getMap());

	for (i = 0; i < _size * _size; ++i)
	{
		result += 2;
		j = 0;
		while (j < _size)
		{
			if (_finalMap[i / _size + j] == map[i])
			{
				result--;
				break ;
			}
			j++;
		}
		j = 0;
		while (j < _size)
		{
			if (_finalMap[j * _size + i % _size] == map[i])
			{
				result--;
				break ;
			}
			j++;
		}
	}
	return (result);
}
