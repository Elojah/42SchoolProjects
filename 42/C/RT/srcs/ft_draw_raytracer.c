/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_raytracer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 12:33:59 by erobert           #+#    #+#             */
/*   Updated: 2014/03/26 10:40:33 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raytracer.h"

static int		ft_ray_tracing(t_data *d, int *index, t_vect *inter)
{
	t_cam		cam;
	int			nb_obj;
	double		n2;

	cam.dir.x = d->cam.dir.x + index[0] - d->img.size[0] / 2;
	cam.dir.y = d->cam.dir.y + index[1] - d->img.size[1] / 2;
	cam.dir.z = d->cam.dir.z + d->img.size[0] / 2;
	n2 = sqrt(ft_dot_product(&cam.dir, &cam.dir));
	cam.dir.x /= n2;
	cam.dir.y /= n2;
	cam.dir.z /= n2;
	cam.o = d->cam.o;
	ft_rotate_vect(&cam.dir, d->cam.rot[0], 'x');
	ft_rotate_vect(&cam.dir, d->cam.rot[1], 'y');
	ft_rotate_vect(&cam.dir, d->cam.rot[2], 'z');
	nb_obj = ft_nearest_object(d, inter, -1, &cam);
	if (nb_obj > -1 && d->objs[nb_obj].type % 10 == 2)
		return (ft_reflection(d, inter, &cam.o, nb_obj));
	if (nb_obj > -1 && d->objs[nb_obj].type % 10 == 3)
		return (ft_transparency(d, inter, &cam.dir, nb_obj));
	if (nb_obj > -1 && d->objs[nb_obj].type % 10 == 4)
		return (ft_subtract(d, inter, &cam.dir, nb_obj));
	if (nb_obj > -1 && d->objs[nb_obj].type % 10 == 5)
		return (ft_refraction(d, inter, &cam.dir, nb_obj));
	return (nb_obj);
}

void			ft_draw_raytracer(t_data *d, int x, int y)
{
	t_vect		inter;
	int			nb_obj;
	int			index[2];

	index[0] = 0;
	while (index[0] < d->img.size[0])
	{
		index[1] = 0;
		while (index[1] < d->img.size[1])
		{
			d->c.c = 0;
			nb_obj = ft_ray_tracing(d, index, &inter);
			if (nb_obj > -1)
				ft_getcolor(d, &inter, nb_obj);
			ft_put_pixel_to_image(d, index[0] + x, index[1] + y, d->c.c);
			index[1]++;
		}
		index[0]++;
	}
	write(2, BLUE, 7);
	write(2, "Draw: done\n", 11);
	write(2, END, 4);
}
