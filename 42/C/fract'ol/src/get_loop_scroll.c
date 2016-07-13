/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_loop_scroll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 18:28:50 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/26 18:28:50 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"

#include <stdio.h>

int			get_loop_scroll(int button, int x, int y, t_map *m)
{
	if (button == 6)
		m->zoom -= ZOOM_SPEED;
	else if (button == 4)
		m->zoom += ZOOM_SPEED;
	x = y;
	y = x;
	calculus(m);
	return (0);
}
