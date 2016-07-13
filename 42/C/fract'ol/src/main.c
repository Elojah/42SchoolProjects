/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 22:06:59 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/06 22:07:00 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "libft.h"

int			main(int ac, char **av)
{
	t_map	m;

	ft_exit(ac != 2, "Usage: ./fractol fractal_name");
	ft_exit((m.mlx = mlx_init()) == (void *)0, "MLX can't init");
	ft_exit((m.win = mlx_new_window(m.mlx, WIN_W, WIN_H, "_W3D_"))
		== (void *)0, "MLX can't create new window");
	ft_exit((m.img = mlx_new_image(m.mlx, WIN_W, WIN_H))
		== (void *)0, "MLX can't create new image");
	m.fractal_name = av[1];
	main_loop(&m);
	return (0);
}
