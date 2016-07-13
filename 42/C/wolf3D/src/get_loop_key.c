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

#include "wolf3d.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>

static void	move_vertical(t_map *m, float data[2], int dir)
{
	if (data[0] > 0 && data[0] < m->w[(int)m->player.pos[1]]
		&& m->map[(int)data[0]][(int)m->player.pos[1]] != WALL)
		m->player.pos[0] += (m->player.dir[0] * m->player.walk_speed) * dir;
	if (data[1] > 0 && data[1] < m->h
		&& m->map[(int)m->player.pos[0]][(int)data[1]] != WALL)
		m->player.pos[1] += (m->player.dir[1] * m->player.walk_speed) * dir;
}

static void	move_horizontal(t_map *m, float data[2], int dir)
{
	if (data[0] > 0 && data[0] < m->w[(int)m->player.pos[1]]
		&& m->map[(int)data[0]][(int)m->player.pos[1]] != WALL)
		m->player.pos[0] += (m->player.plane[0] * m->player.walk_speed) * dir;
	if (data[1] > 0 && data[1] < m->h
		&& m->map[(int)m->player.pos[0]][(int)data[1]] != WALL)
		m->player.pos[1] += (m->player.plane[1] * m->player.walk_speed) * dir;
}

static void	rotate(t_map *m, float data[2], int dir)
{
	m->player.dir[0] = m->player.dir[0] * cos(dir * m->player.rot_speed)
		- m->player.dir[1] * sin(dir * m->player.rot_speed);
	m->player.dir[1] = data[0] * sin(dir * m->player.rot_speed)
		+ m->player.dir[1] * cos(dir * m->player.rot_speed);
	m->player.plane[0] = m->player.plane[0] * cos(dir * m->player.rot_speed)
		- m->player.plane[1] * sin(dir * m->player.rot_speed);
	m->player.plane[1] = data[1] * sin(dir * m->player.rot_speed)
		+ m->player.plane[1] * cos(dir * m->player.rot_speed);
}

int			get_loop_key(int key_press, t_map *m)
{
	if (K(K_ESC))
	{
		mlx_destroy_window(m->mlx, m->win);
		ft_exit(1, "See ya !");
	}
	if (K(K_W))
		move_vertical(m, (float[2]){VEC_XU, VEC_YU}, 1);
	else if (K(K_S))
		move_vertical(m, (float[2]){VEC_XD, VEC_YD}, -1);
	else if (K(K_Q))
		rotate(m, (float[2]){m->player.dir[0], m->player.plane[0]}, 1);
	else if (K(K_E))
		rotate(m, (float[2]){m->player.dir[0], m->player.plane[0]}, -1);
	else if (K(K_D))
		move_horizontal(m, (float[2]){VEC_XR, VEC_YR}, 1);
	else if (K(K_A))
		move_horizontal(m, (float[2]){VEC_XR, VEC_YR}, -1);
	calculus(m);
	return (0);
}
