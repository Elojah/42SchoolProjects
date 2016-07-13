/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:47:29 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/27 18:50:41 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

static void		write_file(int fd, int sock, int i)
{
	char	buf[1024];
	int		r;

	while (i > 0)
	{
		r = read(sock, buf, i > 1024 ? 1024 : i);
		write(fd, buf, r);
		i -= 1024;
	}
}

static t_bool	read_file(char *filename, int sock)
{
	char	size_data[10];
	int		i;
	int		r;
	int		fd;

	i = -1;
	r = 1;
	fd = open(filename, O_CREAT | O_WRONLY, S_IRWXU);
	while (++i < 9 && r > 0)
	{
		r = read(sock, &(size_data[i]), 1);
		if (size_data[i] == '.')
		{
			size_data[i] = '\0';
			i = ft_atoi(size_data);
			if (i == 0)
			{
				unlink(filename);
				return (FALSE);
			}
			write_file(fd, sock, i);
			write(sock, (char *)"OK", 2);
		}
		else if (size_data[i] < '0' || size_data[i] > '9')
			return (FALSE);
	}
	return (TRUE);
}

t_bool			read_files(int sock, char *msg)
{
	int		i;
	char	**params;

	ft_putstr("Receiving files...\n");
	i = 0;
	params = ft_strsplit(msg, ' ');
	while (params[++i] != NULL)
	{
		ft_putstr(params[i]);
		ft_putstr("\treceiving...\n");
		if (read_file(params[i], sock) == FALSE)
		{
			ft_putstr("Error receiving file \n");
			return (FALSE);
		}
		else
			ft_putstr("File received !\n");
	}
	return (TRUE);
}
