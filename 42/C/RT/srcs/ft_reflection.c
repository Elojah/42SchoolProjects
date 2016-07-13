/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reflection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 14:42:40 by erobert           #+#    #+#             */
/*   Updated: 2014/03/25 15:05:36 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "raytracer.h"

static void		ft_dir_ref(t_vect *dest, t_vect *src, t_vect *inter, t_obj *obj)
{
	t_vect		normal;
	double		n2;
	double		tmp;

	ft_obj_trans(dest, src, obj, '+');
	ft_addsub_vect(dest, dest, inter, '-');
	ft_normalobj(&normal, inter, obj);
	n2 = sqrt(ft_dot_product(dest, dest));
	dest->x /= n2;
	dest->y /= n2;
	dest->z /= n2;
	n2 = ft_dot_product(&normal, &normal);
	tmp = 2.0 * ft_dot_product(dest, &normal) / n2;
	dest->x = tmp * normal.x - dest->x;
	dest->y = tmp * normal.y - dest->y;
	dest->z = tmp * normal.z - dest->z;
	ft_rotate_vect(dest, -obj->rot[2], 'z');
	ft_rotate_vect(dest, -obj->rot[1], 'y');
	ft_rotate_vect(dest, -obj->rot[0], 'x');
}

static void		ft_ref_color(t_data *d, t_vect *inter, int k)
{
	t_color		tmp;

	tmp.c = d->c.c;
	ft_getcolor(d, inter, k);
	d->c.rgba[0] = d->c.rgba[0] / 2 + tmp.rgba[0] / 2;
	d->c.rgba[1] = d->c.rgba[1] / 2 + tmp.rgba[1] / 2;
	d->c.rgba[2] = d->c.rgba[2] / 2 + tmp.rgba[2] / 2;
}

int				ft_reflection(t_data *d, t_vect *inter, t_vect *o, int k)
{
	static int	iter = 0;
	t_cam		cam;
	int			nb_obj;

	nb_obj = -1;
	if (iter < REFLECTION_MAX)
	{
		iter++;
		ft_ref_color(d, inter, k);
		ft_obj_trans(&cam.o, inter, &d->objs[k], '-');
		ft_dir_ref(&cam.dir, o, inter, &d->objs[k]);
		nb_obj = ft_nearest_object(d, inter, k, &cam);
		if (nb_obj > -1 && d->objs[nb_obj].type % 10 == 2)
			return (ft_reflection(d, inter, &cam.o, nb_obj));
		if (nb_obj > -1 && d->objs[nb_obj].type % 10 == 3)
			return (ft_transparency(d, inter, &cam.dir, nb_obj));
		if (nb_obj > -1 && d->objs[nb_obj].type % 10 == 4)
			return (ft_subtract(d, inter, &cam.dir, nb_obj));
		if (nb_obj > -1 && d->objs[nb_obj].type % 10 == 5)
			return (ft_refraction(d, inter, &cam.dir, nb_obj));
	}
	iter = 0;
	return (nb_obj);
}
