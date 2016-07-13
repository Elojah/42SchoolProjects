/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 13:12:41 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/11 15:55:38 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"
#include <unistd.h>

static void	exec(char *s)
{
	int		port = ft_atoi(s);
	if (port == 0)
		write(2, "Port argument is not valid\n", 27);
	else
		listen_port(port);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		write(2, "Please specify one argument\n", 28);
	else
		exec(av[1]);
	return (0);
}
