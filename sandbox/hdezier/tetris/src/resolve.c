/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 15:39:02 by leeios            #+#    #+#             */
/*   Updated: 2016/05/25 15:24:12 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

/*
** @brief Minimum size square to test
** @param n Square
** @return Root
*/

static int	sqrt(int n)
{
	int		i;

	i = 0;
	while (++i < n)
	{
		if (i * i >= n)
			return (i);
	}
	return (0);
}

t_error		resolve(t_result *result)
{
	result->fit_size = sqrt(result->pieces.size * SIZE_PIECE);
	while (result->fit_size < MAX_PIECES * SIZE_PIECE)
	{
		result->current_piece = 0;
		if (fill_result_in_size(result) == NONE)
			return (NONE);
		++result->fit_size;
	}
	return (NO_DISPOSITION_FOUND);
}
