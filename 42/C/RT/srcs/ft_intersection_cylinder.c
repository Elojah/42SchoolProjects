/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_cylinder.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 18:16:36 by erobert           #+#    #+#             */
/*   Updated: 2014/03/26 10:45:13 by erobert          ###   ########.fr       */
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
	}
	else
	{
		u->x *= scale->x;
		u->y *= scale->y;
	}
}

double		ft_intersection_cylinder(t_vect *dir, t_vect *o, t_obj *c)
{
	t_vect	abc;
	double	delta;
	double	x[2];

	ft_scale(dir, &c->scale, 1);
	ft_scale(o, &c->scale, 1);
	abc.x = pow(dir->x, 2) + pow(dir->y, 2);
	abc.y = 2 * (dir->x * o->x + dir->y * o->y);
	abc.z = pow(o->x, 2) + pow(o->y, 2) - 1;
	delta = abc.y * abc.y - 4 * abc.x * abc.z;
	if (delta >= 0)
	{
		x[0] = (-abc.y - sqrt(delta)) / (2 * abc.x);
		x[1] = (-abc.y + sqrt(delta)) / (2 * abc.x);
		ft_scale(dir, &c->scale, 0);
		ft_scale(o, &c->scale, 0);
		if ((x[0] < x[1] || x[1] < 0) && x[0] > 0)
		{
			if (fabs(dir->z * x[0] + o->z) < c->scale.z || c->scale.z == -1)
				return (x[0]);
		}
		if (fabs(dir->z * x[1] + o->z) < c->scale.z || c->scale.z == -1)
			return (x[1]);
	}
	return (-1);
}
