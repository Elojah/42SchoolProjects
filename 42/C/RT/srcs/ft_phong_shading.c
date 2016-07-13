/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phong_shading.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/30 14:43:58 by erobert           #+#    #+#             */
/*   Updated: 2014/03/21 15:21:27 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raytracer.h"

static float	ft_diffuse(t_data *d, t_vect *inter, t_obj *obj)
{
	t_vect		light;
	t_vect		normal;
	double		n2;

	ft_obj_trans(&light, &d->light.o, obj, '+');
	ft_addsub_vect(&light, &light, inter, '-');
	ft_normalobj(&normal, inter, obj);
	n2 = ft_dot_product(&normal, &normal) * ft_dot_product(&light, &light);
	return (ft_dot_product(&normal, &light) * 1 / sqrt(n2));
}

static float	ft_specular(t_data *d, t_vect *inter, t_obj *obj)
{
	t_vect		light;
	t_vect		normal;
	t_vect		ref;
	double		n2;

	ft_obj_trans(&light, &d->light.o, obj, '+');
	ft_addsub_vect(&light, &light, inter, '-');
	ft_normalobj(&normal, inter, obj);
	n2 = ft_dot_product(&normal, &normal);
	ref.x = light.x - 2 * ft_dot_product(&light, &normal) / n2 * normal.x;
	ref.y = light.y - 2 * ft_dot_product(&light, &normal) / n2 * normal.y;
	ref.z = light.z - 2 * ft_dot_product(&light, &normal) / n2 * normal.z;
	n2 = n2 * ft_dot_product(&ref, &ref);
	return (ft_dot_product(&normal, &ref) / sqrt(n2));
}

int				ft_phong_shading(t_data *d, t_vect *inter, t_obj *obj)
{
	t_color		c;
	double		diffuse;
	double		specular;
	double		k;
	int			i;

	c.c = obj->color;
	diffuse = ft_diffuse(d, inter, obj) * obj->ads[1];
	if (diffuse < 0)
		diffuse = 0;
	specular = pow(-ft_specular(d, inter, obj), 25) * obj->ads[2];
	if (specular < 0)
		specular = 0;
	i = 0;
	while (i < 3)
	{
		k = c.rgba[i] * obj->ads[0];
		k += c.rgba[i] * diffuse + d->light.c.rgba[i] * specular;
		k *= (double)d->light.c.rgba[i] / 255.0;
		if (k > 255)
			k = 255;
		c.rgba[i++] = k;
	}
	return (c.c);
}
