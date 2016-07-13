/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 13:42:11 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/20 18:29:28 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

static int		init_server(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		write(2, "Binding error\n", 14);
		return (-1);
	}
	listen(sock, 42);
	ft_putstr("Server initialized\n");
	return (sock);
}

void			listen_port(int port)
{
	int					sock;
	int					cs;
	unsigned int		cslen;
	struct sockaddr_in	csin;
	pid_t				child;

	sock = init_server(port);
	if (sock == -1)
		return ;
	while (1)
	{
		cs = accept(sock, (struct sockaddr *)&csin, &cslen);
		ft_putstr("New client\n");
		child = fork();
		if (child == 0)
			new_client(cs);
	}
	close(sock);
}
