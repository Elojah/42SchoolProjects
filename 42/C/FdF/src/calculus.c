/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 17:01:21 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/07 17:01:22 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static void	draw_grid(t_map *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m->h)
	{
		j = -1;
		while (++j < m->w[i])
		{
			if (j != m->w[i] - 1)
				draw_line(m, m->screen_p[i][j], m->screen_p[i][j + 1]);
			if (i != m->h - 1 && j < m->w[i + 1])
				draw_line(m, m->screen_p[i][j], m->screen_p[i + 1][j]);
		}
	}
}

int			draw_window(t_map *m)
{
	mlx_clear_window(m->mlx, m->win);
	calc_grid(m);
	draw_grid(m);
	return (1);
}
