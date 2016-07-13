/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter_vect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 15:30:32 by erobert           #+#    #+#             */
/*   Updated: 2014/03/21 15:54:46 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raytracer.h"

void	ft_inter_vect(t_vect *inter, double t, t_cam *cam)
{
	inter->x = cam->dir.x * t + cam->o.x;
	inter->y = cam->dir.y * t + cam->o.y;
	inter->z = cam->dir.z * t + cam->o.z;
}
