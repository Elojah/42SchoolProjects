/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:20:37 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/27 17:25:45 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	need_file_sending(char *s)
{
	char	*sub;

	sub = s;
	while (*sub == ' ')
		++sub;
	return (ft_strncmp(s, (char *)"put", 3) == 0 ? TRUE : FALSE);
}

static t_bool	need_file_receiving(char *s)
{
	char	*sub;

	sub = s;
	while (*sub == ' ')
		++sub;
	return (ft_strncmp(s, (char *)"get", 3) == 0 ? TRUE : FALSE);
}

char		*read_msg(int sock)
{
	char	*msg;
	char	size_data[10];
	int		i;
	int		r;

	i = -1;
	r = 1;
	while (++i < 9 && r > 0)
	{
		r = read(sock, &(size_data[i]), 1);
		if (size_data[i] == '.')
		{
			size_data[i] = '\0';
			i = ft_atoi(size_data);
			ft_putstr("\e[0;37mread:\t");
			ft_putnbr(i);
			ft_putstr(" bytes\e[0m\n");
			msg = (char *)ft_memalloc(i);
			r = read(sock, msg, i);
			msg[r] = '\0';
			return (msg);
		}
		else if (size_data[i] < '0' || size_data[i] > '9')
		{
			ft_putstr((char *)"Header is not valid:\t");
			size_data[i + 1] = '\0';
			ft_putstr(size_data);
			ft_putstr((char *)"\n");
			return (NULL);
		}
	}
	return (NULL);
}

char		*read_data(int sock)
{
	char	*msg;

	msg = read_msg(sock);
	if (msg == NULL)
		return (msg);
	if (need_file_sending(msg) && send_files(sock, msg) == FALSE)
	{
		msg = read_msg(sock);
		return (NULL);
	}
	else if (need_file_receiving(msg) && read_files(sock, msg) == FALSE)
	{
		msg = read_msg(sock);
		return (NULL);
	}
	return (msg);
}
