/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 20:58:32 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/08 20:58:33 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "libft.h"

static void	clear_image(t_map *m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIN_W)
	{
		j = -1;
		while (++j < WIN_H)
			ft_put_pixel_to_image(m, i, j, C_BLACK);
	}
}

void		calculus(t_map *m)
{
	clear_image(m);
	ft_putstr("Start process ");
	ft_putendl(m->fractal_name);
	if (!ft_strcmp(m->fractal_name, "julia"))
		julia_set(m);
	else if (!ft_strcmp(m->fractal_name, "dragon"))
		dragon_curve(m);
	else if (!ft_strcmp(m->fractal_name, "koch"))
		koch(m);
	else
		ft_exit(1, "Fractal name not valid");
	ft_putstr("Done: process ");
	ft_putendl(m->fractal_name);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
}
