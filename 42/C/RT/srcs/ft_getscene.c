/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getscene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 16:31:39 by erobert           #+#    #+#             */
/*   Updated: 2014/03/16 16:54:16 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "raytracer.h"

static int		ft_getlight(t_light *lights, char *line)
{
	static int	k = 0;

	if (k < LIGHTS_MAX)
	{
		while (*line != ' ')
			line++;
		ft_getvect(&lights[k].o, line);
		while (*line != '|')
			line++;
		lights[k++].c.c = ft_getrgba(++line);
	}
	return (k);
}

static int		ft_getcam(t_cam *cams, char *line)
{
	static int	k = 0;

	if (k < 4)
	{
		while (*line != ' ')
			line++;
		ft_getfloats(cams[k].rot, 1000, line);
		while (*line != '|')
			line++;
		ft_getvect(&cams[k].dir, ++line);
		while (*line != '|')
			line++;
		ft_getvect(&cams[k++].o, ++line);
	}
	return (k);
}

static void		ft_getsize(int *size, char *line)
{
	while (*line != ' ')
		line++;
	size[0] = ft_atoi(++line);
	while (*line != ' ')
		line++;
	size[1] = ft_atoi(++line);
}

static int		ft_read_scene(t_data *d, int fd)
{
	char		*line;

	line = NULL;
	d->nb_cams = 0;
	d->nb_lights = 0;
	d->nb_objs = 0;
	while (ft_getline(fd, &line))
	{
		if (!line)
			return (0);
		if (*line == 'w')
			ft_getsize(d->size, line);
		else if (*line == 'i')
			ft_getsize(d->img.size, line);
		else if (*line == 'c')
			d->nb_cams = ft_getcam(d->cams, line);
		else if (*line == 'l')
			d->nb_lights = ft_getlight(d->lights, line);
		else if (*line == 'o' && d->nb_objs < OBJS_MAX)
			d->nb_objs = ft_getobj(d, d->objs, line);
		free(line);
	}
	return (1);
}

int				ft_getscene(t_data *d, int ac, char **av)
{
	int			fd;

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (0);
		if (!ft_read_scene(d, fd) || close(fd) == -1)
			return (0);
		while (ac > 2)
		{
			fd = open(av[--ac], O_RDONLY);
			if (fd == -1)
				return (0);
			if (!ft_import(d, fd) || close(fd) == -1)
				return (0);
		}
		return (ft_isgood(d));
	}
	return (0);
}
