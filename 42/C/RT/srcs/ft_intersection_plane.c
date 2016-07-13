/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_plane.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 17:51:13 by erobert           #+#    #+#             */
/*   Updated: 2014/03/22 16:54:52 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raytracer.h"

double		ft_intersection_plane(t_vect *dir, t_vect *o, t_obj *p)
{
	double	x;
	double	tmp;

	if (dir->z)
	{
		x = -o->z / dir->z;
		if (p->scale.z < 0.0)
			return (x);
		tmp = dir->x * x + o->x;
		if (fabs(tmp) < p->scale.x && fabs(dir->y * x + o->y) < p->scale.y)
			return (x);
	}
	return (-1);
}
