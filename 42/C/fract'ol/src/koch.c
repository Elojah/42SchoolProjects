/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 20:48:15 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/19 20:48:16 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <math.h>

void		koch_line(t_map *m, t_point origin, t_point dest, int depth)
{
	t_point	tier_1;
	t_point	tier_2;
	t_point	pic;

	if (depth <= 0)
		draw_line(m, origin, dest);
	else
	{
		tier_1 = (t_point){(2.0 * origin.x + dest.x) / 3.0
			, (2.0 * origin.y + dest.y) / 3.0, C_WHITE};
		tier_2 = (t_point){(origin.x + 2.0 * dest.x) / 3.0
			, (origin.y + 2.0 * dest.y) / 3.0, C_WHITE};
		pic = (t_point){(origin.x + dest.x) / 2.0 - sqrt(3.0)
			* (dest.y - origin.y) / 6.0
			, (origin.y + dest.y) / 2.0 + sqrt(3.0)
			* (dest.x - origin.x) / 6.0, C_WHITE};
		koch_line(m, origin, tier_1, depth - 1);
		koch_line(m, tier_1, pic, depth - 1);
		koch_line(m, pic, tier_2, depth - 1);
		koch_line(m, tier_2, dest, depth - 1);
	}
}

void		koch(t_map *m)
{
	t_point	a;
	t_point	b;
	t_point	c;

	a = (t_point){WIN_W / 3, WIN_H / 3, C_WHITE};
	b = (t_point){2 * WIN_W / 3, WIN_H / 3, C_WHITE};
	c = (t_point){WIN_W / 2, 2 * WIN_H / 3, C_WHITE};
	koch_line(m, b, a, m->kd.depth);
	koch_line(m, a, c, m->kd.depth);
	koch_line(m, c, b, m->kd.depth);
}
