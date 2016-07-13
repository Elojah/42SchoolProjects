/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 19:03:49 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/08 19:03:49 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

static int	get_loop_key(int key_press, t_map *m)
{
	if (K(K_ESC))
	{
		mlx_destroy_window(m->mlx, m->win);
		ft_exit(1, "See ya !");
	}
	else if (K(K_Q))
		m->p.alpha += 0.1;
	else if (K(K_E))
		m->p.alpha -= 0.1;
	else if (K(K_A))
		m->p.pad[0]--;
	else if (K(K_D))
		m->p.pad[0]++;
	else if (K(K_W))
		m->p.pad[1]--;
	else if (K(K_S))
		m->p.pad[1]++;
	else if (K(K_R))
		m->p.h_coef++;
	else if (K(K_X))
		m->p.h_coef--;
	draw_window(m);
	return (0);
}

void		main_loop(t_map *m)
{
	mlx_do_key_autorepeaton(m->mlx);
	mlx_expose_hook(m->win, &draw_window, m);
	mlx_key_hook(m->win, &get_loop_key, m);
	mlx_loop(m->mlx);
}
