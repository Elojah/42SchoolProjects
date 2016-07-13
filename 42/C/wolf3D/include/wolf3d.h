/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 20:52:08 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/08 20:52:08 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIN_W 800
# define WIN_H 600
# define PROJ_W 800
# define PROJ_H 600
# define ERR_VAL 0

/*
**MATH
*/
# define ABS(n) ((n) > 0 ? (n) : -(n))
# define MIN(a, b) ((a) > (b) ? (b) : (a))
# define MAX(a, b) ((a) > (b) ? (a) : (b))
# define SQ(n) ((n) * (n))

/*
**SHORTCUT
*/
# define VEC_XU m->player.pos[0] + m->player.dir[0] * m->player.walk_speed
# define VEC_YU m->player.pos[1] + m->player.dir[1] * m->player.walk_speed
# define VEC_XD m->player.pos[0] - m->player.dir[0] * m->player.walk_speed
# define VEC_YD m->player.pos[1] - m->player.dir[1] * m->player.walk_speed
# define VEC_XR m->player.pos[0] + m->player.plane[0] * m->player.walk_speed
# define VEC_YR m->player.pos[1] + m->player.plane[1] * m->player.walk_speed

/*
**MAP_ATTR
*/
# define EMPTY 0
# define WALL 1
# define SKY 2
# define SKY_COLOR 0x0086B2F8
# define GROUND 3
# define GROUND_COLOR 0x0088421D

/*
**KEY_PRESS
*/
# define K_ESC 0xff1b
# define K_A 0x0061
# define K_Z 0x007A
# define K_E 0x0065
# define K_R 0x0072
# define K_Q 0x0071
# define K_S 0x0073
# define K_D 0x0064
# define K_W 0x0077
# define K_X 0x0078
# define K(n) key_press == n

/*
**COLOR
*/
# define C_BLACK 0x00000000
# define C_GREY_B 0x00454545
# define C_GREY 0x00868686
# define C_GREY_W 0x00A1A1A1
# define C_RED 0x00FF0000
# define C_GREEN 0x0000FF00
# define C_BLUE 0x000000FF

typedef struct				s_point
{
	int						x;
	int						y;
	int						z;
}							t_point;

typedef struct				s_player
{
	float					pos[2];
	float					dir[2];
	float					plane[2];
	float					walk_speed;
	float					rot_speed;
}							t_player;

typedef struct				s_map
{
	void					*mlx;
	void					*win;
	int						**map;
	int						*w;
	int						h;
	struct s_player			player;
}							t_map;

typedef struct				s_ray_data
{
	float					camera_x;
	int						hit;
	struct s_player			origin;
	int						map[2];
	float					side_dist[2];
	float					delta_dist[2];
	int						step[2];
	int						side;
	float					dist;
	int						color;
}							t_ray_data;

/*
**CALCULUS
*/
int							calculus(t_map *m);
void						set_row_screen(t_map *m, int n);

/*
**LOOP
*/
void						main_loop(t_map *m);
int							get_loop_key(int key_press, t_map *m);

/*
**DRAW LINE
*/
void						draw_line(t_map *m
	, t_point origin, t_point dest);

#endif
