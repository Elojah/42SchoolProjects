/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:47:37 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/27 18:46:50 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <sys/stat.h>

static t_bool	write_file(char *filename, int sock)
{
	int					fd;
	int					r;
	char				buf[1024];
	struct stat			st;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("File required doesn't exist\n");
		write(sock, "0.", 2);
		return (FALSE);
	}
	stat(filename, &st);
	ft_putnbr_fd(st.st_size, sock);
	ft_putstr_fd(".", sock);
	while ((r = read(fd, buf, 1024)) > 0)
		write(sock, buf, r);
	ft_putstr("Wait response...\n");
	r = read(sock, buf, 2);
	buf[r] = '\0';
	if (ft_strcmp(buf, (char *)"OK") != 0)
	{
		ft_putstr("Response is not valid\n");
		return (FALSE);
	}
	ft_putstr("File sent !\n");
	return (TRUE);
}

t_bool		send_files(int sock, char *s)
{
	char	**params;
	int		i;

	write(1, "Sending files...\n", 17);
	params = ft_strsplit(s, ' ');
	i = 0;
	while (params[++i] != NULL)
	{
		ft_putstr(params[i]);
		ft_putstr("\tsending...\n");
		if (write_file(params[i], sock) == FALSE)
		{
			ft_putstr("Error sending file\n");
			return (FALSE);
		}
	}
	return (TRUE);
}
