/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_torus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 13:54:54 by erobert           #+#    #+#             */
/*   Updated: 2014/03/26 12:52:25 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raytracer.h"

static double	ft_nearest_root(double *x)
{
	double		min;
	int			i;

	min = -1138.42;
	i = 0;
	while (i < 4)
	{
		if (x[i] > 0.0 && (min < 0.0 || x[i] < min))
			min = x[i];
		i++;
	}
	return (min);
}

double			ft_intersection_torus(t_vect *dir, t_vect *o, t_obj *t)
{
	double		a[5];
	double		tmp[7];
	double		r0;
	double		r1;
	double		x[4];

	x[0] = -1138.42;
	x[1] = -1138.42;
	x[2] = -1138.42;
	x[3] = -1138.42;
	r0 = t->scale.x;
	r1 = t->scale.y;
	tmp[0] = ft_dot_product(dir, dir);
	tmp[1] = 2.0 * ft_dot_product(o, dir);
	tmp[2] = ft_dot_product(o, o) - pow(r0, 2.0) - pow(r1, 2.0);
	a[4] = pow(tmp[0], 2.0);
	a[3] = 2.0 * tmp[0] * tmp[1];
	a[2] = pow(tmp[1], 2.0) + 2.0 * tmp[0] * tmp[2];
	a[2] += 4.0 * pow(r1, 2.0) * pow(dir->z, 2.0);
	a[1] = 2.0 * tmp[1] * tmp[2] + 8.0 * pow(r1, 2.0) * dir->z * o->z;
	a[0] = pow(tmp[2], 2.0) + 4.0 * pow(r1, 2) * pow(o->z, 2.0);
	a[0] -= 4.0 * pow(r1, 2.0) * pow(r0, 2.0);
	ft_solve_polynomials(a, x);
	return (ft_nearest_root(x));
}
