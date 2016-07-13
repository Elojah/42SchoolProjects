/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 23:14:48 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/07 23:14:48 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <math.h>

static void	transform_point(t_map *m, t_point *p)
{
	int		tmp;

	tmp = p->x;
	p->x = p->x * cos(m->p.alpha) - p->y * sin(m->p.alpha);
	p->y = tmp * sin(m->p.alpha) + p->y * cos(m->p.alpha);
	p->y -= p->z * m->p.h_coef;
}

void		calc_grid(t_map *m)
{
	int			i;
	int			j;
	t_point		p;

	i = -1;
	m->screen_p = (t_point **)malloc(m->h * sizeof(t_point *));
	while (++i < m->h)
	{
		j = -1;
		m->screen_p[i] = (t_point *)malloc(m->w[i] * sizeof(t_point));
		while (++j < m->w[i])
		{
			p = (t_point){m->p.pad[0] + m->p.sq_len * j
				, m->p.pad[1] + m->p.sq_len * i, m->map[i][j]};
			transform_point(m, &p);
			m->screen_p[i][j] = p;
		}
	}
}
