/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:56:53 by erobert           #+#    #+#             */
/*   Updated: 2013/11/22 12:44:00 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned int	i;

	if (!s1 || !s2)
		return (s1);
	i = 0;
	while (i < n)
	{
		((char *)s1)[i] = ((char *)s2)[i];
		if (((char *)s2)[i] == c)
			return (((char *)s1) + i + 1);
		i++;
	}
	return (NULL);
}
