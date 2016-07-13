/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 17:03:25 by hdezier           #+#    #+#             */
/*   Updated: 2013/12/02 17:03:26 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static int	ft_rchr(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_add_line(const int fd, t_gnl *t, char **line)
{
	int		handle_error;

	t->to_free = *line;
	*line = ft_strjoin(*line, t->buf);
	free(t->to_free);
	handle_error = read(fd, t->buf, BUFF_SIZE);
	t->buf[handle_error] = '\0';
	return (handle_error >= 0 ? handle_error == BUFF_SIZE : -1);
}

static char	*ft_get_line(t_gnl *t)
{
	char	*l;

	t->ret = ft_rchr(t->buf, '\n');
	if (t->ret == -1)
	{
		l = ft_strdup(t->buf);
		ft_strclr(t->buf);
		t->ret = ft_rchr(t->buf, '\0') > 0 ? 1 : -1;
	}
	else
	{
		l = ft_strsub(t->buf, 0, t->ret + 1);
		l[t->ret] = '\0';
		ft_strncpy(t->buf, (t->to_free =
			ft_strsub(t->buf, t->ret + 1, BUFF_SIZE)), BUFF_SIZE - t->ret + 1);
		free(t->to_free);
	}
	return (l);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	t = {"\0", 1, -1, NULL};
	int				handle_error;

	if (t.cur_fd != fd)
	{
		t.cur_fd = fd;
		ft_strclr(t.buf);
	}
	if (!line || read(fd, NULL, 0) < 0)
		return (-1);
	(*line) = ft_strnew(1);
	while ((t.ret = ft_rchr(t.buf, '\n')) < 0
		&& (handle_error = ft_add_line(fd, &t, line) > 0))
		;
	if (handle_error == -1)
		return (-1);
	*line = ft_strjoin(*line, ft_get_line(&t));
	return (t.ret >= 0);
}
