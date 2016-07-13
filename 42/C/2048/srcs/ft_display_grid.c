/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:46:13 by erobert           #+#    #+#             */
/*   Updated: 2015/03/01 17:20:35 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	ft_display_cell(t_data *d, int line, int column)
{
	int		i;
	int		j;
	int		size[2];

	size[0] = d->w_size[0] / d->size;
	size[1] = d->w_size[1] / d->size;
	line *= size[1];
	column *= size[0];
	i = -1;
	while (++i < size[1])
	{
		j = -1;
		while (++j < size[0])
			mvwprintw(stdscr, line + i, column + j, " ");
	}
}

static void	ft_display_number(t_data *d, int line, int column, int h)
{
	int		tmp;
	char	*str;
	int		size[2];

	size[0] = d->w_size[0] / d->size;
	size[1] = d->w_size[1] / d->size;
	str = d->tpls[d->grid[line][column]];
	line *= size[1];
	column *= size[0];
	tmp = h * (TPL_WIDTH + 1);
	str[tmp + TPL_WIDTH] = '\0';
	line += size[1] / 2;
	line -= TPL_HEIGHT / 2;
	column += size[0] / 2;
	column -= TPL_WIDTH / 2;
	mvwprintw(stdscr, line + h, column, str + tmp);
}

static void	ft_number_loop(t_data *d, int i)
{
	int		h;
	int		j;

	h = -1;
	while (++h < TPL_HEIGHT)
	{
		j = -1;
		while (++j < d->size)
		{
			attron(COLOR_PAIR(d->grid[i][j]));
			ft_display_number(d, i, j, h);
			attroff(COLOR_PAIR(d->grid[i][j]));
		}
	}
}

void		ft_display_grid(t_data *d)
{
	int		i;
	int		j;

	getmaxyx(d->w_ptr, d->w_size[1], d->w_size[0]);
	i = -1;
	while (++i < d->size)
	{
		j = -1;
		while (++j < d->size)
		{
			attron(COLOR_PAIR(d->grid[i][j]));
			ft_display_cell(d, i, j);
			attroff(COLOR_PAIR(d->grid[i][j]));
		}
		ft_number_loop(d, i);
	}
}
