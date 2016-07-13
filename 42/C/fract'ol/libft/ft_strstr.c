/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:34:32 by hdezier           #+#    #+#             */
/*   Updated: 2013/11/22 13:29:45 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	k;

	if (!s1 || !s2)
		return ((char *)s1);
	i = 0;
	k = 0;
	while (s1[i])
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
	if (s1[i] == s2[k])
		return ((char *)s1 + i - k);
	return (NULL);
}
