/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 12:12:41 by erobert           #+#    #+#             */
/*   Updated: 2014/03/15 18:38:30 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void	ft_getshading(t_data *d, t_vect *inter, int k, int save)
{
	t_color	tmp;
	t_color	c;

	tmp.c = ft_phong_shading(d, inter, &d->objs[k]);
	if (save)
	{
		c.c = save;
		tmp.rgba[0] = tmp.rgba[0] / 2 + c.rgba[0];
		tmp.rgba[1] = tmp.rgba[1] / 2 + c.rgba[1];
		tmp.rgba[2] = tmp.rgba[2] / 2 + c.rgba[2];
	}
	d->c.rgba[0] = (d->c.rgba[0] > tmp.rgba[0] ? d->c.rgba[0] : tmp.rgba[0]);
	d->c.rgba[1] = (d->c.rgba[1] > tmp.rgba[1] ? d->c.rgba[1] : tmp.rgba[1]);
	d->c.rgba[2] = (d->c.rgba[2] > tmp.rgba[2] ? d->c.rgba[2] : tmp.rgba[2]);
}

void		ft_getcolor(t_data *d, t_vect *inter, int k)
{
	int		save;
	int		shadow;
	int		l;

	save = d->c.c;
	d->objs[k].color = ft_tex_color(&d->objs[k], inter);
	l = 0;
	while (l < d->nb_lights)
	{
		d->light = d->lights[l++];
		ft_getshading(d, inter, k, save);
	}
	l = 0;
	while (l < d->nb_lights)
	{
		d->light = d->lights[l++];
		shadow = ft_shadow(d, inter, k, d->objs);
		if (shadow)
		{
			d->c.rgba[0] *= shadow / 100.0;
			d->c.rgba[1] *= shadow / 100.0;
			d->c.rgba[2] *= shadow / 100.0;
		}
	}
}
