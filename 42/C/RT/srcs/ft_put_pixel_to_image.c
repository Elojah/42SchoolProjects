/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 15:30:17 by erobert           #+#    #+#             */
/*   Updated: 2014/03/19 14:18:26 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "raytracer.h"

static unsigned int	ft_swap_endian(unsigned int in)
{
	unsigned int	out;

	out = (in << 24);
	out |= ((in << 8) & 0x00ff0000);
	out |= ((in >> 8) & 0x0000ff00);
	out |= (in >> 24);
	return (out);
}

static unsigned int	ft_true_color(t_data *d, int rgb)
{
	unsigned int	color;

	color = mlx_get_color_value(d->mlx_ptr, rgb);
	if (d->img.endian == 1)
		color = ft_swap_endian(color);
	return (color);
}

void				ft_put_pixel_to_image(t_data *d, int x, int y, int c)
{
	unsigned int	color;
	int				i;
	int				bpp;

	color = ft_true_color(d, c);
	bpp = d->img.bpp / 8;
	i = y * d->img.line + x * bpp;
	ft_memcpy(d->img.data + i, &color, bpp);
}
