/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus_dead_blocks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 17:50:59 by leeios            #+#    #+#             */
/*   Updated: 2016/05/25 15:52:02 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

static int	consecutive_dead_blocks(t_result *result, int i, int j)
{
	if (i < 0 || i >= result->fit_size
		|| j < 0 || j >= result->fit_size
		|| result->check_data[i][j] == DEAD)
		return (0);
	result->check_data[i][j] = DEAD;
	return (1
		+ consecutive_dead_blocks(result, i + 1, j)
		+ consecutive_dead_blocks(result, i, j + 1)
		+ consecutive_dead_blocks(result, i - 1, j)
		+ consecutive_dead_blocks(result, i, j - 1));
}

static void	init_check_data(t_result *result)
{
	int		i;
	int		j;

	i = -1;
	while (++i < result->fit_size)
	{
		j = -1;
		while (++j < result->fit_size)
		{
			if (result->data[i][j] == EMPTY)
				result->check_data[i][j] = ALIVE;
			else
				result->check_data[i][j] = DEAD;
		}
	}
}

int			calculus_dead_blocks(t_result *result)
{
	int		i;
	int		j;
	int		nb_dead_blocks;
	int		n;

	i = -1;
	nb_dead_blocks = 0;
	init_check_data(result);
	while (++i < result->fit_size)
	{
		j = -1;
		while (++j < result->fit_size)
		{
			n = consecutive_dead_blocks(result, i, j);
			if (n < SIZE_PIECE)
				nb_dead_blocks += n;
		}
	}
	return (nb_dead_blocks);
}
