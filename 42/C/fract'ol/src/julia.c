/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 17:28:20 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/15 17:28:20 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static int		color_julia(int n)
{
	int			color;

	color = 0;
	color += ADD_B(n * n);
	color += ADD_G(log(n) * n);
	color += ADD_R(sqrt(n) * n);
	return (color);
}

static void		draw_point_julia(t_map *m, int i, int j)
{
	int			n;
	float		x;
	float		y;
	float		tmp;

	n = -1;
	x = 1.5 * ((float)i - WIN_W / 2) / (m->zoom * WIN_W / 2) + m->move[0];
	y = ((float)j - WIN_H / 2) / (m->zoom * WIN_H / 2) + m->move[1];
	while (++n < m->jd.depth)
	{
		tmp = x;
		x = SQ(x) - SQ(y) + m->jd.c_x;
		y = 2.0 * tmp * y + m->jd.c_y;
		if (SQ(x) + SQ(y) > 4)
			break ;
	}
	if (n && n < m->jd.depth)
		ft_put_pixel_to_image(m, i, j, color_julia(n));
}

void			julia_set(t_map *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < WIN_W)
	{
		j = -1;
		while (++j < WIN_H)
			draw_point_julia(m, i, j);
	}
}
