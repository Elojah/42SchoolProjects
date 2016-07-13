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

#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>

static void	set_map_line(t_map *m, char *line, int nb_line)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_strsplit(line, ' ');
	while (tmp[++i])
		;
	m->w[nb_line] = i;
	m->map[nb_line] = (int *)malloc(m->w[nb_line] * sizeof(int));
	i = -1;
	while (++i < m->w[nb_line])
	{
		m->map[nb_line][i] = ft_atoi(tmp[i]);
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

static void	launch_mlx_win(t_map *m)
{
	ft_exit((m->win = mlx_new_window(m->mlx, WIN_W, WIN_H, "_FdF_"))
		== (void *)0, "MLX can't create new window");
	draw_window(m);
}

static void	set_param(t_map *m)
{
	int		i;
	int		max_w;

	i = -1;
	max_w = 0;
	while (++i < m->h)
	{
		if (m->w[i] > max_w)
			max_w = m->w[i];
	}
	m->p.pad[0] = WIN_H / 5;
	m->p.pad[1] = WIN_W / 15;
	m->p.sq_len = MIN((WIN_H * 0.8) / m->h, (WIN_W * 0.8) / max_w);
	m->p.alpha = 10 * M_PI / 180;
	m->p.h_coef = 1;
}

int			main(int ac, char **av)
{
	t_map	m;

	m.h = 0;
	ft_exit(ac != 2, "Usage: ./fdf path/to/file");
	set_map(&m, av[1]);
	ft_exit((m.mlx = mlx_init()) == (void *)0, "MLX can't init");
	set_param(&m);
	launch_mlx_win(&m);
	main_loop(&m);
	return (0);
}
