/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 22:34:05 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/06 22:34:11 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_W 1600
# define WIN_H 1200
# define PAD 50
# define FOCAL 60

/*
**MATH
*/

# define ABS(n) ((n) > 0 ? (n) : -(n))
# define MIN(a, b) ((a) > (b) ? (b) : (a))
# define MAX(a, b) ((a) > (b) ? (a) : (b))
# define SQ(n) ((n) * (n))
# define DIST(a, b) sqrt(SQ(a->x - b.x) + SQ(a->y - b.y));

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
# define C_BLACK 0x000000
# define C_RED 0xFF0000
# define C_CST 1
# define C_CONVERT(r, g, b) ((r << 16) + (g << 8) + b)

typedef struct				s_point
{
	int						x;
	int						y;
	int						z;
}							t_point;

typedef struct				s_param
{
	int						pad[2];
	int						sq_len;
	float					alpha;
	int						h_coef;
}							t_param;

typedef struct				s_map
{
	void					*mlx;
	void					*win;
	int						**map;
	int						*w;
	int						h;
	struct s_point			**screen_p;
	struct s_param			p;
}							t_map;

/*
**Draw win
*/
int							draw_window(t_map *m);

/*
**DRAW_LIB
*/
void						draw_line(t_map *m, t_point origin, t_point dest);

/*
**CALC GRID
*/
void						calc_grid(t_map *m);

/*
**LOOP
*/
void						main_loop(t_map *m);

#endif
