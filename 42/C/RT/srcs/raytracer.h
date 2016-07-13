/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 16:02:51 by erobert           #+#    #+#             */
/*   Updated: 2014/03/26 13:00:34 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include <unistd.h>

# define VIEW_MAX 1000000
# define REFLECTION_MAX 10
# define LIGHTS_MAX 4
# define OBJS_MAX 69
# define EPSILON 0.000001
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define END "\033[0m"

typedef union		u_color
{
	int				c;
	unsigned char	rgba[4];
}					t_color;

typedef struct		s_vect
{
	double			x;
	double			y;
	double			z;
}					t_vect;

typedef struct		s_cam
{
	float			rot[3];
	t_vect			dir;
	t_vect			o;
}					t_cam;

typedef struct		s_light
{
	t_color			c;
	t_vect			o;
}					t_light;

typedef struct		s_img
{
	void			*ptr;
	int				size[2];
	char			*data;
	int				bpp;
	int				line;
	int				endian;
}					t_img;

typedef double		(*t_inter)();

typedef struct		s_obj
{
	int				type;
	float			rot[3];
	t_vect			scale;
	t_vect			trans;
	t_vect			vertex[4];
	int				color;
	float			ads[3];
	double			index;
	t_img			tex;
	t_img			bump;
}					t_obj;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	int				size[2];
	t_img			img;
	int				nb_cams;
	t_cam			cams[4];
	t_cam			cam;
	int				nb_lights;
	t_light			lights[LIGHTS_MAX];
	t_light			light;
	int				nb_objs;
	t_obj			objs[OBJS_MAX];
	t_color			c;
	double			index;
}					t_data;

void				*ft_memcpy(void *s1, const void *s2, size_t n);
int					ft_atoi(const char *str);
float				ft_atof(const char *str);
int					ft_getline(int const fd, char **line);
void				ft_getfloats(float *tab, int accuracy, char *line);
int					ft_getrgba(char *line);
void				ft_getvect(t_vect *u, char *line);
int					ft_getobj(t_data *d, t_obj *objs, char *line);
int					ft_getscene(t_data *d, int ac, char **av);
int					ft_isgood(t_data *d);
int					ft_import(t_data *d, int fd);
void				ft_rotate_vect(t_vect *u, float angle, char axis);
void				ft_addsub_vect(t_vect *r, t_vect *u, t_vect *v, char opp);
void				ft_cross_product(t_vect *result, t_vect *u, t_vect *v);
double				ft_dot_product(t_vect *u, t_vect *v);
void				ft_solve_polynomials(double *a, double *x);
void				ft_obj_trans(t_vect *d, t_vect *s, t_obj *obj, char opp);
void				ft_inter_vect(t_vect *inter, double t, t_cam *cam);
double				ft_intersection_plane(t_vect *dir, t_vect *o, t_obj *p);
double				ft_intersection_sphere(t_vect *dir, t_vect *o, t_obj *s);
double				ft_intersection_cylinder(t_vect *dir, t_vect *o, t_obj *c);
double				ft_intersection_cone(t_vect *dir, t_vect *o, t_obj *c);
double				ft_intersection_torus(t_vect *dir, t_vect *o, t_obj *t);
double				ft_intersection_disk(t_vect *dir, t_vect *o, t_obj *d);
double				ft_intersection_triangle(t_vect *dir, t_vect *o, t_obj *t);
double				ft_interobj(t_vect *dir, t_vect *o, t_obj *obj);
void				ft_mapobj(t_obj *obj, t_img *i, t_vect *inter, int *index);
void				ft_normalobj(t_vect *normal, t_vect *inter, t_obj *obj);
int					ft_nearest_object(t_data *d, t_vect *i, int k, t_cam *cam);
int					ft_reflection(t_data *d, t_vect *inter, t_vect *o, int k);
int					ft_transparency(t_data *d, t_vect *i, t_vect *dir, int k);
int					ft_refraction(t_data *d, t_vect *i, t_vect *dir, int k);
int					ft_subtract(t_data *d, t_vect *inter, t_vect *dir, int k);
int					ft_tex_color(t_obj *obj, t_vect *inter);
int					ft_phong_shading(t_data *d, t_vect *inter, t_obj *obj);
int					ft_shadow(t_data *d, t_vect *inter, int k, t_obj *objs);
void				ft_getcolor(t_data *d, t_vect *inter, int k);
void				ft_put_pixel_to_image(t_data *d, int x, int y, int c);
void				ft_draw_raytracer(t_data *d, int x, int y);

#endif
