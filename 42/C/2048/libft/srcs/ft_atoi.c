/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:22:45 by erobert           #+#    #+#             */
/*   Updated: 2014/03/26 10:33:13 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_toint(const char *str)
{
	int			res;

	res = *str - '0';
	str++;
	while (*str <= '9' && *str >= '0')
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (res);
}

int				ft_atoi(const char *str)
{
	if (!str)
		return (0);
	if (*str == ' ' || *str == '\f' || *str == '\n')
		return (ft_atoi(str + 1));
	if (*str == '\r' || *str == '\t' || *str == '\v')
		return (ft_atoi(str + 1));
	if (*str == '+' && str[1] <= '9' && str[1] >= '0')
		return (ft_atoi(str + 1));
	if (*str == '-' && str[1] <= '9' && str[1] >= '0')
		return (ft_atoi(str + 1) * -1);
	if (*str <= '9' && *str >= '0')
		return (ft_toint(str));
	else
		return (0);
}
