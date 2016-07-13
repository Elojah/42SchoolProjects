/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_vect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 16:59:37 by erobert           #+#    #+#             */
/*   Updated: 2014/02/18 18:22:45 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raytracer.h"

void		ft_rotate_vect(t_vect *u, float angle, char axis)
{
	t_vect	tmp;

	if (axis == 'x')
	{
		tmp.x = u->x;
		tmp.y = u->y * cos(angle) - u->z * sin(angle);
		tmp.z = u->y * sin(angle) + u->z * cos(angle);
	}
	else if (axis == 'y')
	{
		tmp.x = u->x * cos(angle) + u->z * sin(angle);
		tmp.y = u->y;
		tmp.z = u->z * cos(angle) - u->x * sin(angle);
	}
	else
	{
		tmp.x = u->x * cos(angle) - u->y * sin(angle);
		tmp.y = u->x * sin(angle) + u->y * cos(angle);
		tmp.z = u->z;
	}
	*u = tmp;
}
