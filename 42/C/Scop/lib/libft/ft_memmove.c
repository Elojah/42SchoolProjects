/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:07:22 by hdezier           #+#    #+#             */
/*   Updated: 2013/11/22 12:45:04 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void			*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*tmp;
	size_t		i;

	tmp = (char *)malloc(n * sizeof(char));
	if (!tmp || !s1 || !s2)
		return (NULL);
	i = 0;
	while (i < n)
	{
		tmp[i] = ((char *)s2)[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		((char *)s1)[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (s1);
}
