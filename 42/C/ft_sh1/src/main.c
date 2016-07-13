/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 18:04:16 by hdezier           #+#    #+#             */
/*   Updated: 2015/02/23 18:04:16 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include <unistd.h>

static char		*read_user(void)
{
	char	*buf;
	int		r;

	buf = (char *)ft_memalloc((BUFF_SIZE + 1) * sizeof(char));
	r = read(0, buf, BUFF_SIZE);
	buf[r] = '\0';
	return (buf);
}

static void		import_path(t_cmd *cmd)
{
	extern char		**environ;
	int				i;

	i = -1;
	while (environ[++i])
		;
	cmd->env = (char **)ft_memalloc(i * sizeof(char *));
	while (--i >= 0)
	{
		cmd->env[i] = (char *)ft_memalloc(BUFF_SIZE * sizeof(char));
		ft_strncpy(cmd->env[i], environ[i], BUFF_SIZE);
	}
}

static void		main_loop(void)
{
	t_cmd			cmd;
	char			*s;

	import_path(&cmd);
	while (1)
	{
		ft_putstr("$>");
		s = read_user();
		parse(&cmd, s);
		if (!cmd.exe)
			continue ;
		exec_cmd(&cmd);
	}
}

int				main(void)
{
	main_loop();
	return (0);
}
