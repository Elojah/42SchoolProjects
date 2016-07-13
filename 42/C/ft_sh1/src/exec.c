/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 23:14:10 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/13 23:14:10 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void		exec_cmd(t_cmd *cmd)
{
	pid_t	f;
	int		status;

	if (!ft_strcmp("exit", cmd->exe))
		sh_exit(cmd);
	f = fork();
	if (f == 0)
	{
		if (!exec_builtin(cmd))
		{
			if (cmd->path && cmd->exe)
				execve(ft_strjoin(cmd->path, cmd->exe), cmd->args, cmd->env);
			else
				ft_exit(1, "Commande introuvable");
		}
	}
	else
	{
		if (waitpid(f, &status, 0) == -1)
			ft_putstr_fd("Error waiting command execution", 2);
		if (!WIFEXITED(status))
			ft_putstr_fd("Command execution terminated unnormally\n", 2);
		if (exec_builtin(cmd))
			exit(1);
	}
}
