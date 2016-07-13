/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalobj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 12:20:19 by erobert           #+#    #+#             */
/*   Updated: 2014/03/19 17:35:39 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raytracer.h"

static void	ft_normal_type(t_vect *normal, t_vect *inter, int type)
{
	if (type == 0)
	{
		normal->x = 0;
		normal->y = 0;
		normal->z = 1;
	}
	else if (type == 2)
	{
		*normal = *inter;
		normal->z = 0;
	}
	else if (type == -1)
	{
		normal->x *= -1.0;
		normal->y *= -1.0;
		normal->z *= -1.0;
	}
}

static void	ft_normal_cone(t_vect *normal, t_vect *inter)
{
	double	tmp;

	*normal = *inter;
	normal->z = 0;
	tmp = sqrt(ft_dot_product(normal, normal));
	normal->x /= tmp;
	normal->y /= tmp;
	if (inter->z > 0)
		normal->z = -1;
	else
		normal->z = 1;
}

static void	ft_normal_torus(t_vect *normal, t_vect *inter, t_obj *t)
{
	double	tmp1;
	double	tmp2;
	double	r0;
	double	r1;

	r0 = t->scale.x;
	r1 = t->scale.y;
	tmp1 = r1 * r1 - r0 * r0;
	tmp2 = ft_dot_product(inter, inter);
	normal->x = 4 * inter->x * (tmp2 + tmp1) - 8 * r1 * r1 * inter->x;
	normal->y = 4 * inter->y * (tmp2 + tmp1) - 8 * r1 * r1 * inter->y;
	normal->z = 4 * inter->z * (tmp2 + tmp1);
}

static void	ft_bump_mapping(t_vect *normal, t_vect *inter, t_obj *obj)
{
	int		index[2];
	int		bpp;
	int		k;

	if (obj->bump.ptr)
	{
		ft_mapobj(obj, &obj->bump, inter, index);
		bpp = obj->bump.bpp / 8;
		k = index[1] * bpp * obj->bump.size[0];
		k += index[0] % obj->bump.size[0] * bpp;
		normal->x += obj->bump.data[k++];
		normal->y += obj->bump.data[k++];
		normal->z += obj->bump.data[k];
	}
}

void		ft_normalobj(t_vect *normal, t_vect *inter, t_obj *obj)
{
	if (obj->type / 10 == 0 || obj->type / 10 == 5)
		ft_normal_type(normal, inter, 0);
	else if (obj->type / 10 == 1)
		*normal = *inter;
	else if (obj->type / 10 == 2)
		ft_normal_type(normal, inter, 2);
	else if (obj->type / 10 == 3)
		ft_normal_cone(normal, inter);
	else if (obj->type / 10 == 4)
		ft_normal_torus(normal, inter, obj);
	else if (obj->type / 10 == 6)
		*normal = obj->vertex[3];
	if (obj->type % 10 == 1)
		ft_normal_type(normal, inter, -1);
	ft_bump_mapping(normal, inter, obj);
}
