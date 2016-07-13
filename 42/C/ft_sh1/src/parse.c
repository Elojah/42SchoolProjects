/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 23:14:16 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/13 23:14:17 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

static char			*get_valid_path(char **paths, char *exe)
{
	int				i;
	DIR				*d;
	struct dirent	*dir;

	i = -1;
	while (paths[++i] != NULL)
	{
		if ((d = opendir(paths[i])))
		{
			while ((dir = readdir(d)))
			{
				if ((ft_strcmp(exe, dir->d_name)) == 0)
					return (paths[i]);
			}
			closedir(d);
		}
	}
	if (access(exe, F_OK) == 0)
		return ("");
	return (NULL);
}

static void			get_env(t_cmd *cmd)
{
	int				i;

	i = -1;
	cmd->path = NULL;
	while (cmd->env[++i])
	{
		if ((ft_strncmp(cmd->env[i], "PATH", 4)) == 0)
		{
			cmd->path = get_valid_path(ft_strsplit(cmd->env[i] + 5, ':')
				, cmd->exe);
			cmd->path = ft_strjoin(cmd->path, "/");
			break ;
		}
	}
}

char				*get_var_env(t_cmd *cmd, char *s)
{
	int		i;
	char	**s_env;

	i = -1;
	while (cmd->env[++i])
	{
		s_env = ft_strsplit(cmd->env[i], '=');
		if (!ft_strcmp(s_env[0], s))
			return (s_env[1]);
	}
	return (NULL);
}

void				parse(t_cmd *cmd, char *s)
{
	char		**split_cmd;
	int			i;

	i = 0;
	split_cmd = ft_strsplit(s, ' ');
	while (split_cmd[i])
	{
		if ((split_cmd[i] = ft_strtrim(split_cmd[i]))[0] == '\0')
			split_cmd[i] = split_cmd[i + 1];
		else
			i++;
	}
	split_cmd[i] = NULL;
	cmd->exe = split_cmd[0];
	if (split_cmd)
		cmd->args = split_cmd;
	else
		cmd->args = NULL;
	get_env(cmd);
}
