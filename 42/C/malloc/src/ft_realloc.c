/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 16:49:05 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/29 17:20:39 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <sys/mman.h>
#include <sys/stat.h>

static void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	if (!s1 || !s2)
		return (s1);
	while (n-- > 0)
		((unsigned char *)s1)[n] = ((unsigned char *)s2)[n];
	return (s1);
}

void		*realloc(void *ptr, size_t size)
{
	void	*tmp;

	tmp = malloc(size);
	ft_memcpy(tmp, (unsigned char *)ptr + sizeof(t_mem)
		, ((t_mem *)(ptr))->size);
	free(ptr);
	return (tmp);
}
