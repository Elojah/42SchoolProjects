/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 16:55:39 by leeios            #+#    #+#             */
/*   Updated: 2016/05/25 15:49:16 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"
#include <unistd.h>

void		print_pieces(t_result *result)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < result->fit_size)
	{
		j = -1;
		while (++j < result->fit_size)
		{
			if (result->data[i][j] != EMPTY)
			{
				c = result->data[i][j] + 'A' - 1;
				write(1, &c, 1);
			}
			else
				write(1, ".", 1);
		}
		write(1, "\n", 1);
	}
}
