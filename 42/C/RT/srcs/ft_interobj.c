/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interobj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 12:17:45 by erobert           #+#    #+#             */
/*   Updated: 2014/03/26 11:11:16 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

double		ft_interobj(t_vect *dir, t_vect *o, t_obj *obj)
{
	t_inter	f[7];

	f[0] = &ft_intersection_plane;
	f[1] = &ft_intersection_sphere;
	f[2] = &ft_intersection_cylinder;
	f[3] = &ft_intersection_cone;
	f[4] = &ft_intersection_torus;
	f[5] = &ft_intersection_disk;
	f[6] = &ft_intersection_triangle;
	return (f[obj->type / 10 % 7](dir, o, obj));
}
