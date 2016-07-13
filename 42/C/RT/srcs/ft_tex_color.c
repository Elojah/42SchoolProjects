/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tex_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 15:51:15 by erobert           #+#    #+#             */
/*   Updated: 2014/03/19 14:18:54 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int			ft_tex_color(t_obj *obj, t_vect *inter)
{
	t_color	c;
	int		index[2];
	int		bpp;
	int		k;

	if (!obj->tex.ptr)
		return (obj->color);
	ft_mapobj(obj, &obj->tex, inter, index);
	bpp = obj->tex.bpp / 8;
	k = index[1] * bpp * obj->tex.size[0] + index[0] % obj->tex.size[0] * bpp;
	c.rgba[0] = obj->tex.data[k++];
	c.rgba[1] = obj->tex.data[k++];
	c.rgba[2] = obj->tex.data[k];
	c.rgba[3] = 0;
	return (c.c);
}
