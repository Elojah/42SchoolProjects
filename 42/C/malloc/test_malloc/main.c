/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 13:55:00 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/29 17:36:00 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stdio.h"
#include "../include/ft_malloc.h"

#define START 1
#define SIZEMAX 40000

void		test_alloc(char *s, int size)
{
	printf("Test alloc for size:%d__________________\n", size);

	write(1, "_______Malloc:\n", 15);
	s = (char *)malloc(size * sizeof(char));

	show_alloc_mem();

	write(1, "_______Write:\n", 14);
	for (int i = 0; i < size; ++i)
		s[i] = 'a';
	s[size - 1] = '\0';

	write(1, "_______Free:\n", 13);
	free(s);
}

int		main(void)
{
	char			*s[SIZEMAX + 1];
	int				total = 0;

	for (int i = START; i < SIZEMAX; ++i)
	{
		total += i;
		test_alloc(s[i], i);
	}
	// for (int i = START; i < SIZEMAX; ++i)
	// 	free(s[i]);
	return (0);
}
