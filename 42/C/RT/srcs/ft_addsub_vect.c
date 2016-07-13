/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addsub_vect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 15:23:43 by erobert           #+#    #+#             */
/*   Updated: 2014/02/18 18:11:58 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	ft_addsub_vect(t_vect *result, t_vect *u, t_vect *v, char opp)
{
	if (opp == '+')
	{
		result->x = u->x + v->x;
		result->y = u->y + v->y;
		result->z = u->z + v->z;
	}
	else
	{
		result->x = u->x - v->x;
		result->y = u->y - v->y;
		result->z = u->z - v->z;
	}
}
