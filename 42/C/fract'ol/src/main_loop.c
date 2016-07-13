/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 21:31:31 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/14 21:31:31 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "libft.h"

static void		set_param_koch(t_map *m)
{
	m->kd.depth = 2;
}

static void		set_param_julia(t_map *m)
{
	m->jd.c_x = 0.3;
	m->jd.c_y = 0.5;
	m->jd.depth = 50;
}

static void		set_param_dragon(t_map *m)
{
	m->dd.depth = 10;
	m->dd.x_rule = ft_strdup("X+YF+");
	m->dd.y_rule = ft_strdup("-FX-Y");
}

static void		set_param(t_map *m)
{
	m->zoom = 1.0;
	m->move[0] = 0;
	m->move[1] = 0;
	set_param_julia(m);
	set_param_dragon(m);
	set_param_koch(m);
}

int				main_loop(t_map *m)
{
	set_param(m);
	calculus(m);
	mlx_key_hook(m->win, &get_loop_key, m);
	mlx_mouse_hook(m->win, &get_loop_scroll, m);
	mlx_hook(m->win, 6, (1l << 6), &get_loop_mouse, m);
	mlx_loop(m->mlx);
	return (0);
}
