/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:31:25 by hdezier           #+#    #+#             */
/*   Updated: 2013/11/27 17:08:51 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	while (n-- > 0)
	{
		if (!*s1 && !*s2)
			return (1);
		if (!*s1 || !*s2)
			return (0);
		if (*s1++ != *s2++)
			return (0);
	}
	return (1);
}
