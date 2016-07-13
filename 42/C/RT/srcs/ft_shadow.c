/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 17:01:52 by erobert           #+#    #+#             */
/*   Updated: 2014/03/25 12:32:29 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raytracer.h"

static int		ft_type(t_data *d, t_obj *obj)
{
	t_color		c;

	if (obj->type % 10 == 3)
	{
		c.c = obj->color;
		d->c.rgba[0] = (1 - obj->ads[0] / 2) * 10 * d->c.rgba[0] / 10.0;
		d->c.rgba[0] += obj->ads[0] * c.rgba[0] / 10.0;
		d->c.rgba[1] = (1 - obj->ads[0] / 2) * 10 * d->c.rgba[1] / 10.0;
		d->c.rgba[1] += obj->ads[0] * c.rgba[1] / 10.0;
		d->c.rgba[2] = (1 - obj->ads[0] / 2) * 10 * d->c.rgba[2] / 10.0;
		d->c.rgba[2] += obj->ads[0] * c.rgba[2] / 10.0;
		if (150 - obj->ads[0] * 50 > 100)
			return (100);
		return (150 - obj->ads[0] * 50);
	}
	return (50);
}

int				ft_shadow(t_data *d, t_vect *inter, int k, t_obj *objs)
{
	t_vect		light;
	t_vect		save;
	t_vect		tmp;
	double		dist;
	int			l;

	ft_obj_trans(&save, inter, &objs[k], '-');
	l = 0;
	while (l < d->nb_objs)
	{
		if (l != k && d->objs[l].type % 10 != 4 && d->objs[l].type % 10 != 5)
		{
			ft_obj_trans(&tmp, &save, &objs[l], '+');
			ft_obj_trans(&light, &d->light.o, &objs[l], '+');
			ft_addsub_vect(&light, &light, &tmp, '-');
			dist = ft_interobj(&light, &tmp, &objs[l]);
			if (dist > 0.0 && dist < 1.0)
				return (ft_type(d, &d->objs[l]));
		}
		l++;
	}
	return (0);
}
