/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refraction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:35:44 by erobert           #+#    #+#             */
/*   Updated: 2014/03/26 11:12:40 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raytracer.h"

static void		ft_dir_ref(t_vect *dir, t_vect *normal, t_obj *obj)
{
	double		tmp[2];
	double		n2;
	double		index;

	n2 = sqrt(ft_dot_product(dir, dir));
	dir->x /= n2;
	dir->y /= n2;
	dir->z /= n2;
	tmp[0] = -ft_dot_product(dir, normal);
	index = 1 / obj->index;
	tmp[1] = index * index * (1.0 - tmp[0] * tmp[0]);
	if (tmp[1] > 1.0)
		return ;
	tmp[1] = sqrt(1.0 - tmp[1]);
	dir->x = index * dir->x + (index * tmp[0] - tmp[1]) * normal->x;
	dir->y = index * dir->y + (index * tmp[0] - tmp[1]) * normal->y;
	dir->z = index * dir->z + (index * tmp[0] - tmp[1]) * normal->z;
}

static void		ft_dir_trans(t_vect *dir, t_vect *inter, t_obj *obj, int i)
{
	t_vect		normal;
	double		n2;

	ft_rotate_vect(dir, obj->rot[0], 'x');
	ft_rotate_vect(dir, obj->rot[1], 'y');
	ft_rotate_vect(dir, obj->rot[2], 'z');
	ft_normalobj(&normal, inter, obj);
	n2 = sqrt(ft_dot_product(&normal, &normal));
	if (i)
		n2 = -n2;
	normal.x /= n2;
	normal.y /= n2;
	normal.z /= n2;
	ft_dir_ref(dir, &normal, obj);
	ft_rotate_vect(dir, -obj->rot[2], 'z');
	ft_rotate_vect(dir, -obj->rot[1], 'y');
	ft_rotate_vect(dir, -obj->rot[0], 'x');
	n2 = sqrt(ft_dot_product(dir, dir));
	dir->x /= n2;
	dir->y /= n2;
	dir->z /= n2;
}

static t_cam	ft_cam_trans(t_cam *cam, t_obj *obj)
{
	t_cam		cam_trans;
	double		n2;

	cam_trans.dir = cam->dir;
	ft_rotate_vect(&cam_trans.dir, obj->rot[0], 'x');
	ft_rotate_vect(&cam_trans.dir, obj->rot[1], 'y');
	ft_rotate_vect(&cam_trans.dir, obj->rot[2], 'z');
	n2 = sqrt(ft_dot_product(&cam_trans.dir, &cam_trans.dir));
	cam_trans.dir.x /= n2;
	cam_trans.dir.y /= n2;
	cam_trans.dir.z /= n2;
	ft_obj_trans(&cam_trans.o, &cam->o, obj, '+');
	return (cam_trans);
}

static void		ft_out_obj(t_data *d, t_vect *inter, int k, t_cam *cam)
{
	t_cam		cam_trans;
	double		dist;

	cam_trans = ft_cam_trans(cam, &d->objs[k]);
	dist = ft_interobj(&cam_trans.dir, &cam_trans.o, &d->objs[k]);
	if (dist > 0.0)
	{
		ft_inter_vect(inter, dist, &cam_trans);
		ft_obj_trans(&cam->o, inter, &d->objs[k], '-');
		ft_dir_trans(&cam->dir, inter, &d->objs[k], 1);
		ft_inter_vect(&cam->o, EPSILON, cam);
	}
}

int				ft_refraction(t_data *d, t_vect *inter, t_vect *dir, int k)
{
	t_cam		cam;
	int			nb_obj;

	ft_getcolor(d, inter, k);
	ft_obj_trans(&cam.o, inter, &d->objs[k], '-');
	cam.dir = *dir;
	ft_dir_trans(&cam.dir, inter, &d->objs[k], 0);
	ft_inter_vect(&cam.o, EPSILON, &cam);
	ft_out_obj(d, inter, k, &cam);
	nb_obj = ft_nearest_object(d, inter, k, &cam);
	if (nb_obj > -1 && d->objs[nb_obj].type % 10 == 2)
		return (ft_reflection(d, inter, &cam.o, nb_obj));
	if (nb_obj > -1 && d->objs[nb_obj].type % 10 == 3)
		return (ft_transparency(d, inter, &cam.o, nb_obj));
	if (nb_obj > -1 && d->objs[nb_obj].type % 10 == 4)
		return (ft_subtract(d, inter, &cam.dir, nb_obj));
	if (nb_obj > -1 && d->objs[nb_obj].type % 10 == 5)
		return (ft_refraction(d, inter, &cam.dir, nb_obj));
	return (nb_obj);
}
