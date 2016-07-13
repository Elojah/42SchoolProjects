/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:44:42 by leeios            #+#    #+#             */
/*   Updated: 2016/04/26 15:54:43 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "client.h"
#include "libft.h"

static int		create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;
	static const char	localhost[] = "127.0.0.1";

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	if (ft_strcmp(addr, "localhost") == 0)
		addr = (char *)localhost;
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
		sock = -1;
	return (sock);
}

void		connect_ftp(char *addr, int port)
{
	int						sock;

	sock = create_client(addr, port);
	if (sock == -1)
	{
		ft_putstr_fd("Connection error\n", 2);
		return ;
	}
	read_prompt(sock);
	close(sock);
}
