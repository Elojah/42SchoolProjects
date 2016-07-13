/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cross_product.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 17:54:55 by erobert           #+#    #+#             */
/*   Updated: 2014/02/24 17:56:55 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	ft_cross_product(t_vect *result, t_vect *u, t_vect *v)
{
	result->x = u->y * v->z - u->z * v->y;
	result->y = u->z * v->x - u->x * v->z;
	result->z = u->x * v->y - u->y * v->x;
}
