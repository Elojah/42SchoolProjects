/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getvect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 18:37:00 by erobert           #+#    #+#             */
/*   Updated: 2014/03/17 17:48:00 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	ft_getvect(t_vect *u, char *line)
{
	while (*line == ' ')
		line++;
	u->x = ft_atof(line);
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	u->y = ft_atof(line);
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	u->z = ft_atof(line);
}
