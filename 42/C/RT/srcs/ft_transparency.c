/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transparency.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 17:15:52 by erobert           #+#    #+#             */
/*   Updated: 2014/03/26 11:14:00 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void	ft_trans_color(t_data *d, t_vect *inter, int k)
{
	t_color	tmp;

	tmp.c = d->c.c;
	ft_getcolor(d, inter, k);
	d->c.rgba[0] = d->c.rgba[0] / 2 + tmp.rgba[0] / 2;
	d->c.rgba[1] = d->c.rgba[1] / 2 + tmp.rgba[1] / 2;
	d->c.rgba[2] = d->c.rgba[2] / 2 + tmp.rgba[2] / 2;
}

int			ft_transparency(t_data *d, t_vect *inter, t_vect *dir, int k)
{
	t_cam	cam;
	int		nb_obj;

	ft_trans_color(d, inter, k);
	cam.o = *inter;
	ft_rotate_vect(&cam.o, -d->objs[k].rot[2], 'z');
	ft_rotate_vect(&cam.o, -d->objs[k].rot[1], 'y');
	ft_rotate_vect(&cam.o, -d->objs[k].rot[0], 'x');
	ft_addsub_vect(&cam.o, &cam.o, &d->objs[k].trans, '+');
	cam.dir = *dir;
	ft_inter_vect(&cam.o, EPSILON, &cam);
	nb_obj = ft_nearest_object(d, inter, k, &cam);
	if (nb_obj > -1 && d->objs[nb_obj].type % 10 == 2)
		return (ft_reflection(d, inter, &cam.o, nb_obj));
	if (nb_obj > -1 && d->objs[nb_obj].type % 10 == 3)
		return (ft_transparency(d, inter, &cam.dir, nb_obj));
	if (nb_obj > -1 && d->objs[nb_obj].type % 10 == 4)
		return (ft_subtract(d, inter, &cam.dir, nb_obj));
	if (nb_obj > -1 && d->objs[nb_obj].type % 10 == 5)
		return (ft_refraction(d, inter, &cam.dir, nb_obj));
	return (nb_obj);
}
