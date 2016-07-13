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

#include "wolf3d.h"
#include "libft.h"
#include "mlx.h"

void		main_loop(t_map *m)
{
	mlx_expose_hook(m->win, &calculus, m);
	mlx_key_hook(m->win, &get_loop_key, m);
	mlx_do_key_autorepeaton(m->mlx);
	mlx_loop(m->mlx);
}
