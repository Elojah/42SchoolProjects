/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_result_in_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 16:27:48 by leeios            #+#    #+#             */
/*   Updated: 2016/05/25 15:21:54 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

static void			write_piece_to_result(t_result *result, int x, int y)
{
	int		i;
	int		j;

	i = -1;
	while (++i < SIZE_PIECE)
	{
		j = -1;
		while (++j < SIZE_PIECE)
		{
			if (result->pieces.data[result->current_piece].data[i][j] == BLOC)
				result->data[x + i][y + j] = result->current_piece + 1;
		}
	}
}

static void			remove_piece_to_result(t_result *result, int x, int y)
{
	int		i;
	int		j;

	i = -1;
	while (++i < SIZE_PIECE)
	{
		j = -1;
		while (++j < SIZE_PIECE)
		{
			if (result->pieces.data[result->current_piece].data[i][j] == BLOC)
				result->data[x + i][y + j] = EMPTY;
		}
	}
}

static t_bool		is_next_to_other_piece(t_result *result, int x, int y)
{
	if ((x + 1 < MAX_PIECES * SIZE_PIECE && result->data[x + 1][y] != EMPTY)
		|| (x - 1 > 0 && result->data[x - 1][y] != EMPTY)
		|| (y + 1 < MAX_PIECES * SIZE_PIECE && result->data[x][y + 1] != EMPTY)
		|| (y - 1 > 0 && result->data[x][y - 1] != EMPTY))
		return (TRUE);
	return (FALSE);
}

static t_bool		is_valid_position(t_result *result, int x, int y)
{
	int		i;
	int		j;
	t_bool	next_to_other_piece;

	i = -1;
	next_to_other_piece = FALSE;
	while (++i < SIZE_PIECE)
	{
		j = -1;
		while (++j < SIZE_PIECE)
		{
			if ((result->pieces.data[result->current_piece].data[i][j] == BLOC
					&& (x + i >= result->fit_size || y + j >= result->fit_size
						|| x + i < 0 || y + j < 0
						|| result->data[x + i][y + j] != EMPTY)))
				return (FALSE);
			if (next_to_other_piece == FALSE)
				next_to_other_piece = is_next_to_other_piece(result
					, x + i, y + j);
		}
	}
	if (next_to_other_piece == TRUE || result->current_piece == 0)
		return (TRUE);
	return (FALSE);
}

t_error				fill_result_in_size(t_result *result)
{
	int		i;
	int		j;

	if (result->current_piece == result->pieces.size)
		return (NONE);
	i = -SIZE_PIECE;
	while (++i < MAX_PIECES * SIZE_PIECE)
	{
		j = -SIZE_PIECE;
		while (++j < MAX_PIECES * SIZE_PIECE)
		{
			if (is_valid_position(result, i, j) == FALSE)
				continue ;
			write_piece_to_result(result, i, j);
			++result->current_piece;
			if (calculus_dead_blocks(result) <= (result->fit_size
				* result->fit_size) - (result->pieces.size * SIZE_PIECE)
				&& fill_result_in_size(result) == NONE)
				return (NONE);
			--result->current_piece;
			remove_piece_to_result(result, i, j);
		}
	}
	return (NO_DISPOSITION_FOUND_AT_SIZE);
}
