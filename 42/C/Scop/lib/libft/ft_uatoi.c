#include "libft.h"

unsigned int	ft_uatoi(const char *str)
{
	unsigned int	result;

	if (!str || !(*str))
		return (0);
	while (*str && *str < '0' && *str > '9')
		str++;
	result = *str - '0';
	str++;
	while (*str <= '9' && *str >= '0')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result);

}
