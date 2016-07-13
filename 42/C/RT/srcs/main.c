/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 14:36:23 by erobert           #+#    #+#             */
/*   Updated: 2014/03/19 14:24:01 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "raytracer.h"

static void	ft_draw(t_data *d)
{
	int		x;
	int		y;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (k < 4 && k < d->nb_cams)
	{
		x = d->size[0] / 2 * (k % 2);
		y = d->size[1] / 2 * (i % 2);
		d->cam = d->cams[k++];
		ft_draw_raytracer(d, x, y);
		mlx_put_image_to_window(d->mlx_ptr, d->mlx_win, d->img.ptr, 0, 0);
		if (k > 1)
			i = 1;
	}
}

static int	expose_hook(t_data *d)
{
	mlx_put_image_to_window(d->mlx_ptr, d->mlx_win, d->img.ptr, 0, 0);
	return (0);
}

static int	key_hook(int key, t_data *d)
{
	if (key == 65307)
		exit(mlx_destroy_image(d->mlx_ptr, d->img.ptr));
	return (0);
}

static int	ft_initimg(t_data *d, t_img *i)
{
	i->ptr = mlx_new_image(d->mlx_ptr, d->size[0], d->size[1]);
	if (i->ptr)
		i->data = mlx_get_data_addr(i->ptr, &i->bpp, &i->line, &i->endian);
	else
		return (-1);
	return (0);
}

int			main(int ac, char **av)
{
	t_data	d;

	if ((d.mlx_ptr = mlx_init()) == 0)
		return (-1);
	if (!ft_getscene(&d, ac, av))
		return (0);
	d.mlx_win = mlx_new_window(d.mlx_ptr, d.size[0], d.size[1], "Raytracer");
	if (d.mlx_win == 0)
		return (-1);
	if (ft_initimg(&d, &d.img))
		return (-1);
	ft_draw(&d);
	mlx_hook(d.mlx_win, 2, 3, key_hook, &d);
	mlx_expose_hook(d.mlx_win, expose_hook, &d);
	mlx_loop(d.mlx_ptr);
	return (0);
}
