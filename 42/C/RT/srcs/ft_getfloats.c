/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfloats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 16:45:44 by erobert           #+#    #+#             */
/*   Updated: 2014/03/17 17:47:47 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	ft_getfloats(float *tab, int accuracy, char *line)
{
	tab[0] = ft_atoi(++line);
	while (*line != ' ')
		line++;
	tab[1] = ft_atoi(++line);
	while (*line != ' ')
		line++;
	tab[2] = ft_atoi(++line);
	tab[0] /= accuracy;
	tab[1] /= accuracy;
	tab[2] /= accuracy;
}
