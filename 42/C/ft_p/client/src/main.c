/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 13:12:41 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/13 16:51:46 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "libft.h"
#include <unistd.h>

static void	exec(char *addr, char *port_s)
{
	int		port = ft_atoi(port_s);
	if (port == 0)
		ft_putstr_fd("Port argument is not valid\n", 2);
	else
		connect_ftp(addr, port);
}

int		main(int ac, char **av)
{
	if (ac != 3)
		ft_putstr_fd("Please specify two argument\n", 2);
	else
		exec(av[1], av[2]);
	return (0);
}
