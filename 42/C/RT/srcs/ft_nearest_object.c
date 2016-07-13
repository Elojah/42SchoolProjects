/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nearest_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:19:55 by erobert           #+#    #+#             */
/*   Updated: 2014/03/21 15:32:36 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raytracer.h"

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

int				ft_nearest_object(t_data *d, t_vect *inter, int k, t_cam *cam)
{
	t_cam		cam_trans;
	double		dis;
	double		tmp;
	int			nb_obj;
	int			l;

	dis = VIEW_MAX;
	nb_obj = -1;
	l = 0;
	while (l < d->nb_objs)
	{
		if (l != k)
		{
			cam_trans = ft_cam_trans(cam, &d->objs[l]);
			tmp = ft_interobj(&cam_trans.dir, &cam_trans.o, &d->objs[l]);
			if (tmp > 0.0 && tmp < dis)
			{
				dis = tmp;
				nb_obj = l;
				ft_inter_vect(inter, tmp, &cam_trans);
			}
		}
		l++;
	}
	return (nb_obj);
}
