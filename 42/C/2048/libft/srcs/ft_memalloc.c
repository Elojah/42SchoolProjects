/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:09:46 by erobert           #+#    #+#             */
/*   Updated: 2013/11/22 12:43:47 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = (void *)malloc(sizeof(*mem) * size);
	if (!mem)
		return (NULL);
	while (size-- > 0)
		((char *)mem)[size] = 0;
	return ((void *)mem);
}
