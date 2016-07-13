/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:16:04 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/27 16:58:48 by hdezier          ###   ########.fr       */
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

t_bool			send_data(int sock, char *s)
{
	int		size_data;

	size_data = ft_strlen(s);
	if (size_data > 1024)
	{
		ft_putstr((char *)"Message is too big\n");
		return (FALSE);
	}
	ft_putstr("\e[0;37msend:\t");
	ft_putnbr(size_data);
	ft_putstr(" bytes\e[0m\n");
	ft_putnbr_fd(size_data, sock);
	write(sock, (char *)".", 1);
	ft_putstr_fd(s, sock);
	if (need_file_sending(s))
		return (send_files(sock, s));
	else if (need_file_receiving(s))
		return (read_files(sock, s));
	return (TRUE);
}
