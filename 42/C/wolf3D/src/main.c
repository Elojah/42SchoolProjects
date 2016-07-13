/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 22:06:59 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/06 22:07:00 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "mlx.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>

static void	set_map_line(t_map *m, char *line, int num_line)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_strsplit(line, ' ');
	while (tmp[++i])
		;
	m->w[num_line] = i;
	m->map[num_line] = (int *)malloc(m->w[num_line] * sizeof(int));
	i = -1;
	while (++i < m->w[num_line])
	{
		m->map[num_line][i] = ft_atoi(tmp[i]);
		free(tmp[i]);
	}
	free(tmp);
	free(line);
}

static void	set_map(t_map *m, char *filename)
{
	int		fd;
	char	*line;
	int		n;

	n = -1;
	ft_exit((fd = open(filename, O_RDONLY)) < 0, "Can't read file: 0");
	while (get_next_line(fd, &line) > 0)
		m->h++;
	close(fd);
	m->map = (int **)malloc(m->h * sizeof(int *));
	m->w = (int *)malloc(m->h * sizeof(int));
	ft_exit((fd = open(filename, O_RDONLY)) < 0, "Can't read file: 1");
	while (get_next_line(fd, &line) > 0)
		set_map_line(m, line, ++n);
	close(fd);
}

static void	set_param(t_map *m)
{
	m->player.plane[0] = 0;
	m->player.plane[1] = 1;
	m->player.dir[0] = -1;
	m->player.dir[1] = 0;
	m->player.pos[0] = 8.3;
	m->player.pos[1] = 7.25;
	m->player.rot_speed = 15.0 * M_PI / 180.0;
	m->player.walk_speed = 0.15;
}

int			main(int ac, char **av)
{
	t_map	m;

	m.h = 0;
	ft_exit(ac != 2, "Usage: ./wolf3d path/to/file");
	ft_exit((m.mlx = mlx_init()) == (void *)0, "MLX can't init");
	ft_exit((m.win = mlx_new_window(m.mlx, WIN_W, WIN_H, "_W3D_"))
		== (void *)0, "MLX can't create new window");
	set_map(&m, av[1]);
	set_param(&m);
	calculus(&m);
	main_loop(&m);
	return (0);
}
