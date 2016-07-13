#include "scop.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static void			load_vertex(t_object *obj, const char *line)
{
	if (obj->vertex_buffer_size >= MAX_VERTEX)
		return ;
	line = ft_goto_next(line, ' ');
	obj->vertex_buffer_data[obj->vertex_buffer_size].x = ft_atof(line);
	line = ft_goto_next(line, ' ');
	obj->vertex_buffer_data[obj->vertex_buffer_size].y = ft_atof(line);
	line = ft_goto_next(line, ' ');
	obj->vertex_buffer_data[obj->vertex_buffer_size].z = ft_atof(line);
	++obj->vertex_buffer_size;
}

static void			load_normal(t_object *obj, const char *line)
{
	if (obj->normal_buffer_size >= MAX_NORMAL)
		return ;
	line = ft_goto_next(line, ' ');
	obj->normal_buffer_data[obj->normal_buffer_size].x = ft_atof(line);
	line = ft_goto_next(line, ' ');
	obj->normal_buffer_data[obj->normal_buffer_size].y = ft_atof(line);
	line = ft_goto_next(line, ' ');
	obj->normal_buffer_data[obj->normal_buffer_size].z = ft_atof(line);
	++obj->normal_buffer_size;
}

static void			load_tex(t_object *obj, const char *line)
{
	if (obj->tex_buffer_size >= MAX_TEX)
		return ;
	line = ft_goto_next(line, ' ');
	obj->tex_buffer_data[obj->tex_buffer_size].u = ft_atof(line);
	line = ft_goto_next(line, ' ');
	obj->tex_buffer_data[obj->tex_buffer_size].v = ft_atof(line);
	++obj->tex_buffer_size;
}

static void			load_index(t_object *obj, const char *line)
{
	unsigned int	n;

	if (obj->index_buffer_size >= MAX_INDEX)
		return ;
	line = ft_goto_next(line, ' ');
	n = obj->index_buffer_size * 3;
	obj->ve_index_buffer_data[n] = ft_uatoi(line) - 1;
	line = ft_goto_next_digit(line + 1);
	obj->te_index_buffer_data[n] = ft_uatoi(line) - 1;
	line = ft_goto_next_digit(line + 1);
	obj->no_index_buffer_data[n] = ft_uatoi(line) - 1;
	line = ft_goto_next(line + 1, ' ');
	obj->ve_index_buffer_data[n + 1] = ft_uatoi(line) - 1;
	line = ft_goto_next_digit(line + 1);
	obj->te_index_buffer_data[n + 1] = ft_uatoi(line) - 1;
	line = ft_goto_next_digit(line + 1);
	obj->no_index_buffer_data[n + 1] = ft_uatoi(line) - 1;
	line = ft_goto_next(line + 1, ' ');
	obj->ve_index_buffer_data[n + 2] = ft_uatoi(line) - 1;
	line = ft_goto_next_digit(line + 1);
	obj->te_index_buffer_data[n + 2] = ft_uatoi(line) - 1;
	line = ft_goto_next_digit(line + 1);
	obj->no_index_buffer_data[n + 2] = ft_uatoi(line) - 1;
	++obj->index_buffer_size;
}

#include <stdio.h>
static void			print_obj(t_object *obj)
{
	// return ;
	for (unsigned int i = 0; i < obj->vertex_buffer_size; ++i)
	{
		printf("%f\t%f\t%f\n", obj->vertex_buffer_data[i].x
			, obj->vertex_buffer_data[i].y
			, obj->vertex_buffer_data[i].z);
	}
	for (unsigned int i = 0; i < obj->tex_buffer_size; ++i)
	{
		printf("%f\t%f\n", obj->tex_buffer_data[i].u
			, obj->tex_buffer_data[i].v);
	}
	for (unsigned int i = 0; i < obj->index_buffer_size * 3; ++i)
	{
		printf("%u\t%u\t%u\n"
			,obj->ve_index_buffer_data[i] + 1
			, obj->te_index_buffer_data[i] + 1
			, obj->no_index_buffer_data[i] + 1);
	}
}

void				load_obj(t_object *obj, char *filename)
{
	int				fd;
	char			*line;

	ft_exit((fd = open(filename, O_RDONLY)) < 0, "Can't read file");
	obj->vertex_buffer_size = obj->index_buffer_size = obj->normal_buffer_size
	= obj->tex_buffer_size = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) < 3 || line[0] == '#')
			;
		else if (line[0] == 'o')
			ft_strcpy((char *)obj->name, line + 2);
		else if (line[0] == 'v' && line[1] == ' ')
			load_vertex(obj, line + 1);
		else if (line[0] == 'v' && line[1] == 'n')
			load_normal(obj, line + 2);
		else if (line[0] == 'v' && line[1] == 't')
			load_tex(obj, line + 2);
		else if (line[0] == 'f' && line[1] == ' ')
			load_index(obj, line + 1);
		ft_memdel((void **)&line);
	}
	close(fd);
	print_obj(obj);
}
