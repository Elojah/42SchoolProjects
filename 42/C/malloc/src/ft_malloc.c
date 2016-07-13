/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 12:31:02 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/29 17:48:02 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

static t_mem		*ft_alloc(size_t nb_pages)
{
	t_mem		*mem;

	mem = (t_mem *)mmap(0, (nb_pages + 1) * getpagesize()
			, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON
			, -1, 0);
	if (mem == MAP_FAILED)
		mem = NULL;
	else
		set_get_data(NULL)->total += (nb_pages + 1) * getpagesize();
	return (mem);
}

static void			new_local_mem(t_mem *p, size_t size)
{
	if (p == NULL)
		return ;
	p->size = size;
	p->free = 0;
	p->next = NULL;
}

static void			*assign_mem(t_heap *heap, size_t size)
{
	t_mem			*current_mem;

	if (!heap->mem)
	{
		heap->mem = ft_alloc(heap->stock);
		new_local_mem(heap->mem, size);
		heap->head += size + sizeof(t_mem);
		return ((void *)heap->mem + sizeof(t_mem));
	}
	current_mem = heap->mem;
	while (current_mem->next)
		current_mem = current_mem->next;
	heap->head += size + sizeof(t_mem);
	if (heap->head >= heap->stock * getpagesize())
	{
		current_mem->next = ft_alloc(heap->stock);
		heap->head = size + sizeof(t_mem);
	}
	else
		current_mem->next = (void *)current_mem
		+ sizeof(t_mem) + current_mem->size;
	new_local_mem(current_mem->next, size);
	return ((void *)current_mem->next + sizeof(t_mem));
}

void				*malloc(size_t size)
{
	void				*result;
	static t_data		data =
	{
		{NULL, 0, TINY_PAGE}
		, {NULL, 0, SMALL_PAGE}
		, {NULL, 0, LARGE_PAGE}
		, {0, 0}
		, 0
	};

	set_get_data(&data);
	getrlimit(RLIMIT_AS, &(data.limit));
	if (data.total > (size_t)data.limit.rlim_max || size == 0)
		return (NULL);
	if ((size + sizeof(t_mem)) * N_ALLOC < (size_t)TINY_PAGE * getpagesize())
		result = assign_mem(&(data.tiny), size);
	else if ((size + sizeof(t_mem)) * N_ALLOC
		< (size_t)SMALL_PAGE * getpagesize())
		result = assign_mem(&(data.small), size);
	else
		result = assign_mem(&(data.large), size);
	return (result);
}
