/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_row_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 21:14:42 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/08 21:14:43 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "mlx.h"
#include "libft.h"
#include <stdlib.h>
#include <math.h>

static void	display_row(t_map *m, t_ray_data *rd, int n)
{
	int		calc_dist;

	calc_dist = fabs((int)(PROJ_H / rd->dist));
	draw_line(m, (t_point){n, 0, SKY_COLOR}, (t_point){n, -calc_dist / 2 + PROJ_H / 2, SKY_COLOR});
	draw_line(m, (t_point){n, -calc_dist / 2 + PROJ_H / 2, rd->color}, (t_point){n, calc_dist / 2 + PROJ_H / 2, rd->color});
	draw_line(m, (t_point){n, calc_dist / 2 + PROJ_H / 2, GROUND_COLOR}, (t_point){n, PROJ_H, GROUND_COLOR});
}

static void		init_ray_data(t_map *m, t_ray_data *rd)
{
	rd->origin.pos[0] = m->player.pos[0];
	rd->origin.pos[1] = m->player.pos[1];
	rd->origin.dir[0] = m->player.dir[0] + m->player.plane[0] * rd->camera_x;
	rd->origin.dir[1] = m->player.dir[1] + m->player.plane[1] * rd->camera_x;
	rd->map[0] = (int)rd->origin.pos[0];
	rd->map[1] = (int)rd->origin.pos[1];
	rd->hit = 0;
	rd->delta_dist[0] = sqrt(1 + SQ(rd->origin.dir[1]) / SQ(rd->origin.dir[0]));
	rd->delta_dist[1] = sqrt(1 + SQ(rd->origin.dir[0]) / SQ(rd->origin.dir[1]));
}

static void		init_ray_side(t_ray_data *rd)
{
	if (rd->origin.dir[0] < 0) {
		rd->step[0] = -1;
		rd->side_dist[0] = (rd->origin.pos[0] - (float)rd->map[0]) * rd->delta_dist[0];
	}
	else
	{
		rd->step[0] = 1;
		rd->side_dist[0] = ((float)rd->map[0] + 1.0 - rd->origin.pos[0]) * rd->delta_dist[0];
	}
	if (rd->origin.dir[1] < 0) {
		rd->step[1] = -1;
		rd->side_dist[1] = (rd->origin.pos[1] - (float)rd->map[1]) * rd->delta_dist[1];
	}
	else
	{
		rd->step[1] = 1;
		rd->side_dist[1] = ((float)rd->map[1] + 1.0 - rd->origin.pos[1]) * rd->delta_dist[1];
	}
}

static void		search_hit(t_map *m, t_ray_data *rd)
{
	while (rd->hit == 0) {
		if (rd->side_dist[0] < rd->side_dist[1])
		{
			rd->side_dist[0] += rd->delta_dist[0];
			rd->map[0] += rd->step[0];
			rd->side = 0;
		}
		else
		{
			rd->side_dist[1] += rd->delta_dist[1];
			rd->map[1] += rd->step[1];
			rd->side = 1;
		}
		if (rd->map[0] < 0 || rd->map[1] < 0 || rd->map[0] >= m->h || rd->map[1] >= m->w[rd->map[0]]
			|| m->map[rd->map[0]][rd->map[1]] == WALL)
			rd->hit = 1;
	}
}

void	set_row_screen(t_map *m, int n)
{
	t_ray_data	rd;

	rd.camera_x = ((2 * n) / (float)PROJ_W) - 1.0;
	init_ray_data(m, &rd);
	init_ray_side(&rd);
	search_hit(m, &rd);
	if (rd.side == 0)
		rd.dist = fabs(((float)rd.map[0]- rd.origin.pos[0] + (float)(1.0 - rd.step[0]) / 2.0) / rd.origin.dir[0]);
	else
		rd.dist = fabs(((float)rd.map[1] - rd.origin.pos[1] + (float)(1.0 - rd.step[1]) / 2.0) / rd.origin.dir[1]);
	if (rd.side == 0 && rd.step[0] < 0)
		rd.color = C_BLACK;
	else if (rd.side == 0 && rd.step[0] > 0)
		rd.color = C_GREY_W;
	if (rd.side == 1 && rd.step[1] < 0)
		rd.color = C_GREY;
	if (rd.side == 1 && rd.step[1] > 0)
		rd.color = C_GREY_B;
	display_row(m, &rd, n);
}
