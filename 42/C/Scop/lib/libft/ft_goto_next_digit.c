#include "libft.h"

char				*ft_goto_next_digit(const char *line)
{
	unsigned int		i;

	i = 0;
	while (line[i] && ft_isdigit(line[i]))
		++i;
	while (line[i] && !ft_isdigit(line[i]))
		++i;
	return ((char *)line + i);
}
