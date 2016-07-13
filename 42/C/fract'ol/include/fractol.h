/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 20:52:08 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/08 20:52:08 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_W 800.0
# define WIN_H 600.0
# define ERR_VAL 0

/*
**MATH
*/
# define ABS(n) ((n) > 0 ? (n) : -(n))
# define MIN(a, b) ((a) > (b) ? (b) : (a))
# define MAX(a, b) ((a) > (b) ? (a) : (b))
# define SQ(n) ((n) * (n))
# define D_TO_R(n) ((n) * M_PI / 180)

/*
**PARAM
*/
# define MOVE_SPEED 0.1
# define ZOOM_SPEED 0.1

/*
**KEY_PRESS
*/
# define K_ESC 0xff1b
# define K_A 0x0061
# define K_C 0x0063
# define K_Z 0x007A
# define K_E 0x0065
# define K_R 0x0072
# define K_Q 0x0071
# define K_S 0x0073
# define K_D 0x0064
# define K_V 0x0076
# define K_W 0x0077
# define K_X 0x0078
# define K(n) key_press == n

/*
**COLOR
*/
# define C_BLACK 0x00000000
# define C_WHITE 0x00FFFFFF
# define C_GREY_B 0x00454545
# define C_GREY 0x00868686
# define C_GREY_W 0x00A1A1A1
# define C_RED 0x00FF0000
# define C_GREEN 0x0000FF00
# define C_BLUE 0x000000FF
# define ADD_R(n) (((((int)(n)) % 256)) << 16)
# define ADD_G(n) (((((int)(n)) % 256)) << 8)
# define ADD_B(n) ((((int)(n)) % 256))

typedef struct				s_point
{
	int						x;
	int						y;
	int						z;
}							t_point;

typedef union				u_color
{
	int						c;
	char					rgba[4];
}							t_color;

typedef struct				s_koch_data
{
	int						depth;
}							t_koch_data;

typedef struct				s_julia_data
{
	int						depth;
	float					c_x;
	float					c_y;
}							t_julia_data;

typedef struct				s_dragon_data
{
	int						depth;
	char					*s;
	char					*x_rule;
	char					*y_rule;
}							t_dragon_data;

typedef struct				s_map
{
	void					*mlx;
	void					*win;
	void					*img;
	float					zoom;
	float					move[2];
	char					*fractal_name;
	struct s_julia_data		jd;
	struct s_dragon_data	dd;
	struct s_koch_data		kd;
}							t_map;

/*
**CALCULUS
*/
void						calculus(t_map *m);
int							get_loop_key(int key_press, t_map *m);
int							get_loop_mouse(int x, int y, t_map *m);
int							get_loop_scroll(int button
	, int x, int y, t_map *m);
int							main_loop(t_map *m);

/*
**Julia
*/
void						julia_set(t_map *m);

/*
**Dragon curve
*/
void						dragon_curve(t_map *m);

/*
**Koch
*/
void						koch(t_map *m);

/*
**DRAW LINE
*/
void						draw_line(t_map *m
	, t_point origin, t_point dest);
void						ft_put_pixel_to_image(t_map *m
	, int x, int y, int c);

#endif
