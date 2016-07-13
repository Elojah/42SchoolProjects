/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getobj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 18:25:17 by erobert           #+#    #+#             */
/*   Updated: 2014/03/25 12:20:56 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "raytracer.h"

static void		ft_getimg(t_data *d, t_img *i, char *line)
{
	char		tmp;
	int			j;

	while (*line && *line == ' ')
		line++;
	j = 0;
	while (line[j] && line[j] != ' ')
		j++;
	tmp = line[j];
	line[j] = '\0';
	i->ptr = mlx_xpm_file_to_image(d->mlx_ptr, line, &i->size[0], &i->size[1]);
	if (i->ptr)
		i->data = mlx_get_data_addr(i->ptr, &i->bpp, &i->line, &i->endian);
	line[j] = tmp;
}

static void		ft_gettex(t_data *d, t_obj *obj, char *line)
{
	obj->color = ft_getrgba(line);
	while (*line != '|')
		line++;
	ft_getfloats(obj->ads, 100, ++line);
	while (*line && *line != '|')
		line++;
	if (*line)
	{
		ft_getimg(d, &obj->tex, ++line);
		while (*line && *line != '|')
			line++;
		if (*line)
			ft_getimg(d, &obj->bump, ++line);
		else
			obj->bump.ptr = 0;
	}
	else
	{
		obj->tex.ptr = 0;
		obj->bump.ptr = 0;
	}
}

static void		ft_triangle(t_data *d, t_obj *obj, char *line)
{
	ft_getvect(&obj->vertex[0], line);
	while (*line != '|')
		line++;
	ft_getvect(&obj->vertex[1], ++line);
	while (*line != '|')
		line++;
	ft_getvect(&obj->vertex[2], ++line);
	while (*line != '|')
		line++;
	ft_getvect(&obj->vertex[3], ++line);
	while (*line != '|')
		line++;
	ft_gettex(d, obj, ++line);
}

int				ft_getobj(t_data *d, t_obj *objs, char *line)
{
	static int	k = 0;

	while (*line != ' ')
		line++;
	objs[k].type = ft_atoi(++line);
	if (objs[k].type % 10 == 5)
		objs[k].index = ft_atof(line + 2);
	while (*line != '|')
		line++;
	ft_getfloats(objs[k].rot, 1000, ++line);
	while (*line != '|')
		line++;
	ft_getvect(&objs[k].scale, ++line);
	while (*line != '|')
		line++;
	ft_getvect(&objs[k].trans, ++line);
	while (*line != '|')
		line++;
	if (objs[k].type / 10 == 6)
		ft_triangle(d, &objs[k], ++line);
	else
		ft_gettex(d, &objs[k], ++line);
	return (++k);
}
