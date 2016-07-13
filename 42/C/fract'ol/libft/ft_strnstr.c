/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:19:52 by hdezier           #+#    #+#             */
/*   Updated: 2013/11/22 13:32:39 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int				length;
	unsigned int	i;

	if (!s2 || !s2 || !n)
		return (NULL);
	if (!*s2)
		return ((char*)s1);
	length = ft_strlen(s2);
	i = 0;
	if ((unsigned int)length > n)
		return (NULL);
	while (*s1 && i < n - (length - 1))
	{
		if (*s1 == *s2)
		{
			if (ft_strncmp(s1, s2, length) == 0)
				return ((char*)s1);
		}
		s1++;
		i++;
	}
	return (NULL);
}
