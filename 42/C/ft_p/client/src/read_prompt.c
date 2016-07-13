/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:52:30 by leeios            #+#    #+#             */
/*   Updated: 2016/04/27 17:11:04 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "client.h"
#include "libft.h"

static char		*read_user(void)
{
	char	*str;
	char	*tmp;
	char	buf[2];

	str = (char *)ft_memalloc(sizeof(*str));
	str[0] = '\0';
	buf[0] = ' ';
	buf[1] = '\0';
	while (*buf != '\n' && *buf != '\0')
	{
		read(0, buf, 1);
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
	}
	str[ft_strlen(str) - 1] = '\0';
	return (str);
}

void		read_prompt(int sock)
{
	char	*s;

	while (1)
	{
		ft_putstr("\e[1;34m$>\e[0m");
		s = read_user();
		send_data(sock, s);
		free(s);
		s = read_data(sock);
		if (s == NULL)
		{
			ft_putstr("Error occured server-side\n");
			continue ;
		}
		if (ft_strncmp(s, (char *)"QUIT", 4) == 0)
		{
			free(s);
			return ;
		}
		ft_putstr(s);
		free(s);
		write(1, "\n", 1);
	}
}
