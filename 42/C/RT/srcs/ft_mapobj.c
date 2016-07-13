/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapobj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 14:08:08 by erobert           #+#    #+#             */
/*   Updated: 2014/03/22 16:26:46 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raytracer.h"

static void	ft_mapping_plane(t_img *i, t_vect *inter, int *index)
{
	index[0] = (int)inter->x % i->size[0];
	index[1] = -(int)inter->y % i->size[1];
	if (index[0] < 0)
		index[0] += i->size[0];
	if (index[1] < 0)
		index[1] += i->size[1];
}

static void	ft_mapping_sphere(t_img *i, t_vect *inter, int *index)
{
	double	angle[2];
	double	a;
	double	r;

	r = sqrt(pow(inter->x, 2) + pow(inter->y, 2) + pow(inter->z, 2));
	angle[0] = asin(inter->z / r);
	if (cos(angle[0]) != 0.0)
	{
		a = inter->x / (r * cos(angle[0]));
		if (a < -1)
			a = -1;
		if (a > 1)
			a = 1;
		angle[1] = acos(a);
	}
	else
		angle[1] = 0;
	if (inter->y > 0.0)
		angle[1] = -angle[1];
	angle[1] += M_PI;
	a = angle[0] / M_PI + 0.5;
	index[1] = (int)(i->size[1] * (a - (int)a));
	a = 0.5 * angle[1] / M_PI;
	index[0] = (int)(i->size[0] * (a - (int)a));
}

static void	ft_mapping_cylinder(t_img *i, t_vect *inter, int *index)
{
	double	angle[2];
	double	a;
	double	r;

	r = sqrt(pow(inter->x, 2) + pow(inter->y, 2) + pow(inter->z, 2));
	angle[0] = asin(inter->z / r);
	if (cos(angle[0]) != 0.0)
	{
		a = inter->x / (r * cos(angle[0]));
		if (a < -1)
			a = -1;
		if (a > 1)
			a = 1;
		angle[1] = acos(a);
	}
	else
		angle[1] = 0;
	if (inter->y > 0.0)
		angle[1] = -angle[1];
	angle[1] += M_PI;
	a = 0.5 * angle[1] / M_PI;
	index[0] = (int)(i->size[0] * (a - (int)a));
	index[1] = -(int)inter->z % i->size[1];
	if (index[1] < 0)
		index[1] += i->size[1];
}

void		ft_mapobj(t_obj *obj, t_img *i, t_vect *inter, int *index)
{
	if (obj->type / 10 == 1)
		ft_mapping_sphere(i, inter, index);
	else if (obj->type / 10 == 2)
		ft_mapping_cylinder(i, inter, index);
	else
		ft_mapping_plane(i, inter, index);
}
