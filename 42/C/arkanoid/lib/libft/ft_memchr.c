/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:36:53 by hdezier           #+#    #+#             */
/*   Updated: 2013/11/22 12:44:12 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (!s || !n)
		return ((unsigned char *)0);
	else if (*(unsigned char *)s == (unsigned char)c)
		return ((unsigned char *)s);
	else
		return (ft_memchr(s + 1, c, n - 1));
}
