/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 14:58:56 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/29 17:44:55 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <unistd.h>

static void				ft_putnbr(unsigned long n, unsigned int base)
{
	static const char	tab[] = "0123456789ABCDEF";
	unsigned long		quo;
	unsigned long		mod;

	if (!n)
		return ;
	if (n > base - 1)
	{
		quo = n / base;
		ft_putnbr(quo, base);
		mod = n % base;
		write(1, &tab[mod], 1);
	}
	else
		write(1, &tab[n], 1);
}

static size_t			show_heap(t_heap *heap)
{
	t_mem				*current_mem;
	size_t				result;

	current_mem = heap->mem;
	result = 0;
	ft_putnbr((unsigned long)heap->mem, 16);
	write(1, "\n", 1);
	while (current_mem != NULL)
	{
		if (current_mem->size == 0 || current_mem->free == 1)
		{
			current_mem = current_mem->next;
			continue ;
		}
		write(1, "0x", 3);
		ft_putnbr((unsigned long)(current_mem + sizeof(t_mem)), 16);
		write(1, " - 0x", 5);
		ft_putnbr((unsigned long)(NORM_RESPECT(current_mem)), 16);
		write(1, " : ", 3);
		ft_putnbr((unsigned long)(current_mem->size), 10);
		result += current_mem->size;
		write(1, " octets\n", 8);
		current_mem = current_mem->next;
	}
	return (result);
}

t_data					*set_get_data(t_data *data)
{
	static t_data		*data_save = NULL;

	if (!data)
		return (data_save);
	data_save = data;
	return (NULL);
}

void					show_alloc_mem(void)
{
	t_data				*data;
	size_t				total;

	if (!(data = set_get_data(NULL)))
		return ;
	total = 0;
	if (data->tiny.mem && write(1, "TINY : 0x", 9))
		total += show_heap(&(data->tiny));
	if (data->small.mem && write(1, "SMALL : 0x", 11))
		total += show_heap(&(data->small));
	if (data->large.mem && write(1, "LARGE : 0x", 11))
		total += show_heap(&(data->large));
	write(1, "Total : ", 8);
	if (total)
		ft_putnbr((unsigned long)total, 10);
	else
		write(1, "0", 1);
	write(1, " octets\n", 8);
}
