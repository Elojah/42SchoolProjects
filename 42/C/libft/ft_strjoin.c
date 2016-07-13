/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:46:28 by hdezier           #+#    #+#             */
/*   Updated: 2013/11/22 12:48:39 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		l1;
	int		l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = ft_strnew(l1 + l2);
	if (!str)
		return (NULL);
	while (l2-- > 0)
		str[l1 + l2] = ((char *)s2)[l2];
	while (l1-- > 0)
		str[l1] = ((char *)s1)[l1];
	return (str);
}
