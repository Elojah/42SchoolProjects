/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_trans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 15:00:54 by erobert           #+#    #+#             */
/*   Updated: 2014/03/21 15:07:26 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void		ft_obj_trans(t_vect *dest, t_vect *src, t_obj *obj, char opp)
{
	*dest = *src;
	if (opp == '+')
	{
		ft_addsub_vect(dest, dest, &obj->trans, '-');
		ft_rotate_vect(dest, obj->rot[0], 'x');
		ft_rotate_vect(dest, obj->rot[1], 'y');
		ft_rotate_vect(dest, obj->rot[2], 'z');
	}
	else
	{
		ft_rotate_vect(dest, -obj->rot[2], 'z');
		ft_rotate_vect(dest, -obj->rot[1], 'y');
		ft_rotate_vect(dest, -obj->rot[0], 'x');
		ft_addsub_vect(dest, dest, &obj->trans, '+');
	}
}
