/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 17:46:10 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/07 17:46:10 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>

static int	color_deg(int h, int coef, int delta_h)
{
	return (C_CONVERT(h, h, h + coef * delta_h));
}

static void	draw_horizontal_line(t_map *m, t_point *origin
	, int delta[2], int inc[2])
{
	int		i;
	int		pad;

	i = -1;
	pad = delta[1];
	while (++i < delta[0])
	{
		origin->x += inc[0];
		pad += delta[1];
		if (pad >= delta[0])
		{
			pad -= delta[0];
			origin->y += inc[1];
		}
		mlx_pixel_put(m->mlx, m->win, origin->x, origin->y
			, color_deg(origin->z, i, delta[0]));
	}
}

static void	draw_vertical_line(t_map *m, t_point *origin
	, int delta[2], int inc[2])
{
	int		i;
	int		pad;

	i = -1;
	pad = delta[0];
	while (++i < delta[1])
	{
		origin->y += inc[1];
		pad += delta[0];
		if (pad >= delta[1])
		{
			pad -= delta[1];
			origin->x += inc[0];
		}
		mlx_pixel_put(m->mlx, m->win, origin->x, origin->y
			, color_deg(origin->z, i, delta[1]));
	}
}

void		draw_line(t_map *m, t_point origin, t_point dest)
{
	int		delta[2];
	int		inc[2];

	delta[0] = dest.x - origin.x;
	delta[1] = dest.y - origin.y;
	inc[0] = delta[0] > 0 ? 1 : -1;
	inc[1] = delta[1] > 0 ? 1 : -1;
	delta[0] = ABS(delta[0]);
	delta[1] = ABS(delta[1]);
	mlx_pixel_put(m->mlx, m->win, origin.x, origin.y
		, color_deg(origin.z, 1, 1));
	if (delta[0] > delta[1])
		draw_horizontal_line(m, &origin, delta, inc);
	else
		draw_vertical_line(m, &origin, delta, inc);
}
