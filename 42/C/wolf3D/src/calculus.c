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

#include "wolf3d.h"
#include "mlx.h"
#include "libft.h"

int		calculus(t_map *m)
{
	int	i;

	i = -1;
	ft_putendl("calculus");
	while (++i < WIN_W)
		set_row_screen(m, i);
	return (0);
}
