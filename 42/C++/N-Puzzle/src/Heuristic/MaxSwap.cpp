#include "MaxSwap.hpp"
#include "State.hpp"

MaxSwap::MaxSwap(State const &s)
{
	_size = s.getSize();
	_finalMap = s.getMap();
}
MaxSwap::~MaxSwap(void) {}

int			MaxSwap::eval(State const &s) const
{
	size_t	i;
	size_t	j;
	int		tmp;
	int		result(0);
	tArray	map(s.getMap());

	for (i = 0; i < _size * _size; ++i)
	{
		if (map[i] != _finalMap[i])
		{
			result++;
			j = 0;
			while (j < _size * _size)
			{
				if (map[j] == _finalMap[i])
				{
					tmp = map[i];
					map[i] = map[j];
					map[j] = tmp;
					break ;
				}
				j++;
			}
		}
	}
	return (result);
}
