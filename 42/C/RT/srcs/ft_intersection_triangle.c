/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_triangle.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 11:57:12 by erobert           #+#    #+#             */
/*   Updated: 2014/03/16 16:31:13 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raytracer.h"

double		ft_intersection_triangle(t_vect *dir, t_vect *o, t_obj *t)
{
	t_vect	tmp[5];
	double	a[4];
	double	dis;

	ft_addsub_vect(&tmp[0], &t->vertex[1], &t->vertex[0], '-');
	ft_addsub_vect(&tmp[1], &t->vertex[2], &t->vertex[0], '-');
	ft_cross_product(&tmp[2], dir, &tmp[1]);
	a[0] = ft_dot_product(&tmp[0], &tmp[2]);
	if (fabs(a[0]) < EPSILON)
		return (-1);
	a[1] = 1.0 / a[0];
	ft_addsub_vect(&tmp[3], o, &t->vertex[0], '-');
	a[2] = a[1] * ft_dot_product(&tmp[3], &tmp[2]);
	if (a[2] < .0 || a[2] > 1.0)
		return (-1);
	ft_cross_product(&tmp[4], &tmp[3], &tmp[0]);
	a[3] = a[1] * ft_dot_product(dir, &tmp[4]);
	if (a[3] < .0 || a[2] + a[3] > 1.0)
		return (-1);
	dis = a[1] * ft_dot_product(&tmp[1], &tmp[4]);
	return (dis);
}
