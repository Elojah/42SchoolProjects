#include "libft.h"

static size_t	ft_nbrlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i] <= '9' && str[i] >= '0')
		i++;
	return (i);
}

static float	ft_dot_part(const char *str)
{
	float		dot_part;
	size_t		len;

	dot_part = ft_atoi(str + 1);
	len = ft_nbrlen(str + 1);
	while (len--)
		dot_part /= 10.0;
	return (dot_part);
}

float			ft_atof(const char *str)
{
	float		res;
	int			sign;

	if (!str)
		return (0);
	while (*str == ' ' || *str == '\f' || *str == '\n')
		str++;
	sign = 0;
	res = ft_atoi(str);
	if (*str == '-')
	{
		res = -res;
		sign = 1;
	}
	if (*str == '+' || *str == '-')
		str++;
	while (*str <= '9' && *str >= '0')
		str++;
	if (*str == '.' && str[1] <= '9' && str[1] >= '0')
		res += ft_dot_part(str);
	res = (sign ? -res : res);
	return (res);
}
