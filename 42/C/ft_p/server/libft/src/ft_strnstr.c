/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:19:52 by erobert           #+#    #+#             */
/*   Updated: 2013/11/22 13:32:39 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	k;

	if (!s1)
		return (NULL);
	if (!s2)
		return ((char *)s1);
	i = 0;
	k = 0;
	while (s1[i] && i <= n)
	{
		if (!s2[k])
			return ((char *)s1 + i - k);
		else if (s1[i] != s2[k])
		{
			i -= k;
			k = 0;
		}
		else if (s1[i] == s2[k])
			k++;
		i++;
	}
	if (s1[i] == s2[k] && !s1[i])
		return ((char *)s1 + i - k);
	return (NULL);
}
