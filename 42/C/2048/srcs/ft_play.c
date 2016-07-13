/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:33:22 by hdezier           #+#    #+#             */
/*   Updated: 2015/02/28 18:28:03 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <stdlib.h>

static int		check_score(t_data *data)
{
	int			i;
	int			j;
	int			score;
	int			lost;

	score = 0;
	lost = -1;
	i = -1;
	while (++i < data->size)
	{
		j = -1;
		while (++j < data->size)
		{
			if (data->grid[i][j] > score)
				score = data->grid[i][j];
			if (lost < 0 && (data->grid[i][j] == N_0
				|| (i && data->grid[i - 1][j] == data->grid[i][j])
				|| (j && data->grid[i][j - 1] == data->grid[i][j])))
				lost = 1;
		}
	}
	return (score * lost);
}

static void		pop_new(t_data *data)
{
	int			i;
	int			j;
	int			n;
	int			random;
	int			tmp[25][2];

	n = -1;
	i = -1;
	while (++i < data->size)
	{
		j = -1;
		while (++j < data->size)
		{
			if (data->grid[i][j] == N_0)
			{
				tmp[++n][0] = i;
				tmp[n][1] = j;
			}
		}
	}
	if (n == -1)
		return ;
	random = rand() % (n + 1);
	data->grid[tmp[random][0]][tmp[random][1]] = (rand() % 10) < 8 ? N_2 : N_4;
}

static int		ft_move_case(t_data *data, int index[2]
	, int dir[2], int prev[3])
{
	int			nxi[2];

	nxi[0] = index[0] + dir[0];
	nxi[1] = index[1] + dir[1];
	if (data->grid[INDEX] != N_0 && nxi[0] >= 0 && nxi[0] < data->size
		&& nxi[1] >= 0 && nxi[1] < data->size)
	{
		if (data->grid[NEXT] == N_0)
		{
			data->grid[NEXT] = data->grid[INDEX];
			data->grid[INDEX] = N_0;
			prev[2] = 1;
			return (-1);
		}
		else if ((nxi[0] != prev[0] || nxi[1] != prev[1])
			&& data->grid[INDEX] == data->grid[NEXT])
		{
			data->grid[NEXT]++;
			data->grid[INDEX] = N_0;
			prev[0] = nxi[0];
			prev[1] = nxi[1];
			prev[2] = 1;
		}
	}
	return (1);
}

static int		ft_move(t_data *data, int dir[2])
{
	int					i;
	int					j;
	int					prev[3];
	int					save_inc;
	int					save_index;

	i = -1;
	prev[2] = 0;
	save_index = (dir[0] == 1 || dir[1] == 1) ? data->size - 1 : 0;
	save_inc = (!save_index) ? 1 : -1;
	while (++i < data->size)
	{
		j = save_index;
		prev[0] = -1;
		prev[1] = -1;
		while (j < data->size && j >= 0)
		{
			if (!dir[0])
				j += (save_inc * ft_move_case(data, (int[2]){i, j}, dir, prev));
			else
				j += (save_inc * ft_move_case(data, (int[2]){j, i}, dir, prev));
		}
	}
	return (prev[2]);
}

int				ft_play(t_data *data, char input)
{
	int			moved;

	if (input == 'w')
		moved = ft_move(data, (int[2]){-1, 0});
	else if (input == 'a')
		moved = ft_move(data, (int[2]){0, -1});
	else if (input == 's')
		moved = ft_move(data, (int[2]){1, 0});
	else if (input == 'd')
		moved = ft_move(data, (int[2]){0, 1});
	else
		return (0);
	if (moved)
		pop_new(data);
	else
		return (0);
	return (check_score(data));
}
