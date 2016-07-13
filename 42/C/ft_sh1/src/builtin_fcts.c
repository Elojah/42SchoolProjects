/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fcts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 23:14:40 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/13 23:14:40 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

void		sh_cd(t_cmd *cmd)
{
	char	*dir;

	if (!cmd->args[1])
		dir = get_var_env(cmd, "HOME");
	else
	{
		dir = ft_strjoin(get_var_env(cmd, "PWD"), "/");
		dir = ft_strjoin(dir, cmd->args[1]);
	}
	if (chdir(dir) < 0)
	{
		ft_putstr_fd("Can't access to this directory: ", 2);
		ft_putendl_fd(cmd->args[1], 2);
	}
	else
	{
		cmd->args[1] = ft_strjoin("PWD=", dir);
		sh_setenv(cmd);
	}
	free(dir);
}

void		sh_setenv(t_cmd *cmd)
{
	int		i;
	char	**s_env;
	char	**s_cmd;

	i = -1;
	while (cmd->env[++i])
	{
		s_env = ft_strsplit(cmd->env[i], '=');
		s_cmd = ft_strsplit(cmd->args[1], '=');
		if (!ft_strcmp(s_env[0], s_cmd[0]))
		{
			ft_strncpy(cmd->env[i], cmd->args[1], BUFF_SIZE);
			return ;
		}
	}
	s_env = (char **)ft_memalloc((i + 2) * sizeof(char *));
	cmd->env = (char **)ft_memcpy(s_env, cmd->env, i * sizeof(char *));
	cmd->env[i] = (char *)ft_memalloc(BUFF_SIZE * sizeof(char *));
	ft_strncpy(cmd->env[i], cmd->args[1], BUFF_SIZE);
	cmd->env[i + 1] = NULL;
}

void		sh_unsetenv(t_cmd *cmd)
{
	int		i;
	char	**s_env;

	i = -1;
	while (cmd->env[++i])
	{
		s_env = ft_strsplit(cmd->env[i], '=');
		if (!ft_strcmp(s_env[0], cmd->args[1]))
		{
			while (cmd->env[i])
			{
				cmd->env[i] = cmd->env[i + 1];
				i++;
			}
			return ;
		}
	}
}

void		sh_env(t_cmd *cmd)
{
	int		i;

	i = 0;
	while (cmd->env[i])
		ft_putendl(cmd->env[i++]);
}

void		sh_exit(t_cmd *cmd)
{
	(void)cmd;
	ft_exit(1, "See ya !\n");
}
