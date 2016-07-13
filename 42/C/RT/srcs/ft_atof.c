/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 17:09:42 by erobert           #+#    #+#             */
/*   Updated: 2014/03/25 12:20:48 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static size_t	ft_nbrlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i] <= '9' && str[i] >= '0')
		i++;
	return (i);
}

float			ft_atof(const char *str)
{
	float		res;
	float		dot_part;
	size_t		len;

	if (!str)
		return (0);
	while (*str == ' ' || *str == '\f' || *str == '\n')
		str++;
	res = ft_atoi(str);
	if (*str == '+' || *str == '-')
		str++;
	while (*str <= '9' && *str >= '0')
		str++;
	if (*str == '.' && str[1] <= '9' && str[1] >= '0')
	{
		dot_part = ft_atoi(str + 1);
		len = ft_nbrlen(str + 1);
		while (len--)
			dot_part /= 10.0;
		res += dot_part;
	}
	return (res);
}
