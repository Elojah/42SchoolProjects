/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_sphere.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 16:28:26 by erobert           #+#    #+#             */
/*   Updated: 2014/03/22 17:09:32 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raytracer.h"

static void	ft_scale(t_vect *u, t_vect *scale, int yes)
{
	if (yes)
	{
		u->x *= 1 / scale->x;
		u->y *= 1 / scale->y;
		u->z *= 1 / scale->z;
	}
	else
	{
		u->x *= scale->x;
		u->y *= scale->y;
		u->z *= scale->z;
	}
}

double		ft_intersection_sphere(t_vect *dir, t_vect *o, t_obj *s)
{
	t_vect	abc;
	double	delta;
	double	x1;
	double	x2;

	ft_scale(dir, &s->scale, 1);
	ft_scale(o, &s->scale, 1);
	abc.x = pow(dir->x, 2) + pow(dir->y, 2) + pow(dir->z, 2);
	abc.y = 2 * (dir->x * o->x + dir->y * o->y + dir->z * o->z);
	abc.z = pow(o->x, 2) + pow(o->y, 2) + pow(o->z, 2) - 1;
	delta = abc.y * abc.y - 4 * abc.x * abc.z;
	if (delta >= 0.0)
	{
		x1 = (-abc.y - sqrt(delta)) / (2 * abc.x);
		x2 = (-abc.y + sqrt(delta)) / (2 * abc.x);
		ft_scale(dir, &s->scale, 0);
		ft_scale(o, &s->scale, 0);
		if ((x1 < x2 || x2 < 0) && x1 > 0.0)
			return (x1);
		return (x2);
	}
	return (-1);
}
