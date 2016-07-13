/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgood.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 11:16:43 by erobert           #+#    #+#             */
/*   Updated: 2014/03/14 17:29:28 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int		ft_isgood(t_data *d)
{
	if (d->size[0] < d->img.size[0] || d->size[1] < d->img.size[1])
	{
		write(2, RED, 7);
		write(2, "Wrong format\n", 13);
		write(2, END, 4);
		return (0);
	}
	if (d->nb_cams > 2 && d->size[1] / 2 < d->img.size[1])
	{
		write(2, RED, 7);
		write(2, "Wrong format\n", 13);
		write(2, END, 4);
		return (0);
	}
	return (1);
}
