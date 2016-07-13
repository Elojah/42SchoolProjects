/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_loop_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 18:11:55 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/19 18:11:55 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"

int			get_loop_mouse(int x, int y, t_map *m)
{
	m->kd.depth = 10 * (x + y) / (WIN_W + WIN_H);
	if (m->jd.c_x == (float)x / WIN_W - 0.5
		&& m->jd.c_y == (float)y / WIN_H - 0.5)
		return (0);
	m->jd.c_x = (float)x / WIN_W - 0.5;
	m->jd.c_y = (float)y / WIN_H - 0.5;
	if (m->dd.depth == (int)(15 * (x + y) / (WIN_W + WIN_H)))
		return (0);
	m->dd.depth = 15 * (x + y) / (WIN_W + WIN_H);
	calculus(m);
	return (0);
}
