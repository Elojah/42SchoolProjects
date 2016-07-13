/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_disk.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 17:18:21 by erobert           #+#    #+#             */
/*   Updated: 2014/03/26 10:45:39 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

double		ft_intersection_disk(t_vect *dir, t_vect *o, t_obj *d)
{
	t_vect	inter;
	double	x;

	if (dir->z)
	{
		x = -o->z / dir->z;
		inter.x = (dir->x * x + o->x) * 1 / d->scale.x;
		inter.y = (dir->y * x + o->y) * 1 / d->scale.y;
		inter.z = (dir->z * x + o->z) * 1 / d->scale.z;
		if (ft_dot_product(&inter, &inter) < 1)
			return (x);
	}
	return (-1);
}
