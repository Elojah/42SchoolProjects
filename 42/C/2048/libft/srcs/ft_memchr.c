/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:36:53 by erobert           #+#    #+#             */
/*   Updated: 2013/11/22 12:44:12 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (!s || !n)
		return (NULL);
	else if (*(char *)s == c)
		return ((void *)s);
	else
		return (ft_memchr(s + 1, c, n - 1));
}
