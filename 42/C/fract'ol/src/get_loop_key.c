/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_loop_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 18:50:23 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/14 18:50:23 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"

static void	get_key_julia(t_map *m, int key_press)
{
	if (K(K_Z))
		m->jd.c_x -= 0.1;
	else if (K(K_X))
		m->jd.c_x += 0.1;
	else if (K(K_V))
		m->jd.c_y -= 0.1;
	else if (K(K_C))
		m->jd.c_y += 0.1;
}

static void	get_key_dragon(t_map *m, int key_press)
{
	if (K(K_Z))
		m->dd.depth -= 1;
	else if (K(K_X))
		m->dd.depth += 1;
}

int			get_loop_key(int key_press, t_map *m)
{
	if (K(K_ESC))
	{
		mlx_destroy_image(m->mlx, m->img);
		mlx_destroy_window(m->mlx, m->win);
		ft_exit(1, "See ya !");
	}
	else if (K(K_A))
		m->move[0] += MOVE_SPEED;
	else if (K(K_D))
		m->move[0] -= MOVE_SPEED;
	else if (K(K_W))
		m->move[1] += MOVE_SPEED;
	else if (K(K_S))
		m->move[1] -= MOVE_SPEED;
	else if (K(K_Q))
		m->zoom -= ZOOM_SPEED;
	else if (K(K_E))
		m->zoom += ZOOM_SPEED;
	else
	{
		get_key_julia(m, key_press);
		get_key_dragon(m, key_press);
	}
	calculus(m);
	return (0);
}
