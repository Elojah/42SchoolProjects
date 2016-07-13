/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 12:30:54 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/29 17:45:13 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# define N_ALLOC 100
# define TINY_PAGE 64
# define SMALL_PAGE 128
# define LARGE_PAGE 512

# define NORM_RESPECT(n) (n + sizeof(t_mem) + n->size)

# include <stdlib.h>

typedef struct		s_mem
{
	size_t			size;
	int				free;
	struct s_mem	*next;
}					t_mem;

/*
**head represents nb_bytes allocated on current page
*/
typedef struct		s_heap
{
	t_mem			*mem;
	size_t			head;
	size_t			stock;
}					t_heap;

typedef struct		s_data
{
	t_heap			tiny;
	t_heap			small;
	t_heap			large;
	struct rlimit	limit;
	size_t			total;
}					t_data;

/*
**Malloc
*/
extern void			*malloc(size_t len);

/*
**Show alloc mem
*/
extern void			show_alloc_mem(void);
t_data				*set_get_data(t_data *data);

/*
**Free
*/
extern void			free(void *ptr);

/*
**Realloc
*/
extern void			*ft_realloc(void *ptr, size_t size);

#endif
