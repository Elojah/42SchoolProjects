/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subtract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 15:05:08 by erobert           #+#    #+#             */
/*   Updated: 2014/03/25 15:06:10 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raytracer.h"

int			ft_subtract(t_data *d, t_vect *inter, t_vect *dir, int k)
{
	t_cam	cam;
	int		nb_obj;

	cam.dir = *dir;
	ft_rotate_vect(&cam.dir, d->objs[k].rot[0], 'x');
	ft_rotate_vect(&cam.dir, d->objs[k].rot[1], 'y');
	ft_rotate_vect(&cam.dir, d->objs[k].rot[2], 'z');
	cam.o = *inter;
	ft_inter_vect(&cam.o, EPSILON, &cam);
	ft_inter_vect(&cam.o, ft_interobj(&cam.dir, &cam.o, &d->objs[k]), &cam);
	ft_obj_trans(&cam.o, &cam.o, &d->objs[k], '-');
	cam.dir = *dir;
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
