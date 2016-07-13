#include "libft.h"

char			*ft_goto_next(const char *line, char c)
{
	unsigned int	i;

	i = 0;
	while (line[i] && line[i] != c)
		++i;
	while (line[i] == c)
		++i;
	return ((char *)line + i);
}
