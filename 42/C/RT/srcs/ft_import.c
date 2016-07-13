/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 14:47:46 by erobert           #+#    #+#             */
/*   Updated: 2014/03/27 11:54:23 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "raytracer.h"

static void	ft_getvertex(t_data *d, t_vect *vertex, t_vect *normal, char *line)
{
	int		max;

	max = OBJS_MAX * 3;
	while (*line && *line == ' ')
		line++;
	d->objs[d->nb_objs].vertex[0] = vertex[(ft_atoi(line) - 1) % max];
	while (*line && *line != '/')
		line++;
	line++;
	while (*line && *line != '/')
		line++;
	line++;
	d->objs[d->nb_objs].vertex[3] = normal[(ft_atoi(line) - 1) % OBJS_MAX];
	while (*line && *line != ' ')
		line++;
	while (*line && *line == ' ')
		line++;
	d->objs[d->nb_objs].vertex[1] = vertex[(ft_atoi(line) - 1) % max];
	while (*line && *line != ' ')
		line++;
	d->objs[d->nb_objs++].vertex[2] = vertex[(ft_atoi(line) - 1) % max];
}

static void	ft_triangle(t_data *d, t_vect *vertex, t_vect *normal, char *line)
{
	d->objs[d->nb_objs].type = 60;
	d->objs[d->nb_objs].rot[0] = 0;
	d->objs[d->nb_objs].rot[1] = 0;
	d->objs[d->nb_objs].rot[2] = 0;
	d->objs[d->nb_objs].scale.x = 0;
	d->objs[d->nb_objs].scale.y = 0;
	d->objs[d->nb_objs].scale.z = 0;
	d->objs[d->nb_objs].trans.x = 0;
	d->objs[d->nb_objs].trans.y = 0;
	d->objs[d->nb_objs].trans.z = 0;
	d->objs[d->nb_objs].ads[0] = 0.1;
	d->objs[d->nb_objs].ads[1] = 1;
	d->objs[d->nb_objs].ads[2] = 0.1;
	d->objs[d->nb_objs].color = 0xFFFFFF;
	d->objs[d->nb_objs].tex.ptr = NULL;
	d->objs[d->nb_objs].bump.ptr = NULL;
	ft_getvertex(d, vertex, normal, line);
}

int			ft_import(t_data *d, int fd)
{
	char	*line;
	t_vect	vertex[OBJS_MAX * 3];
	int		nb_vertex;
	t_vect	normal[OBJS_MAX];
	int		nb_normal;

	line = NULL;
	nb_vertex = 0;
	nb_normal = 0;
	while (ft_getline(fd, &line))
	{
		if (!line)
			return (0);
		if (*line == 'v' && line[1] == ' ' && nb_vertex < OBJS_MAX * 3)
			ft_getvect(&vertex[nb_vertex++], line + 1);
		else if (*line == 'v' && line[1] == 'n' && nb_normal < OBJS_MAX)
			ft_getvect(&normal[nb_normal++], line + 2);
		else if (*line == 'f' && d->nb_objs < OBJS_MAX)
			ft_triangle(d, vertex, normal, line + 1);
		free(line);
	}
	return (1);
}
