/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getrgba.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 15:59:02 by erobert           #+#    #+#             */
/*   Updated: 2014/03/03 15:59:03 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int			ft_getrgba(char *line)
{
	t_color	c;

	c.rgba[3] = 0;
	c.rgba[2] = ft_atoi(++line);
	while (*line != ' ')
		line++;
	c.rgba[1] = ft_atoi(++line);
	while (*line != ' ')
		line++;
	c.rgba[0] = ft_atoi(++line);
	return (c.c);
}
