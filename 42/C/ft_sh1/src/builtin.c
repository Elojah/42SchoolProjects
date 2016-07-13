/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 23:14:29 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/13 23:14:29 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include <unistd.h>

int		exec_builtin(t_cmd *cmd)
{
	int			i;
	static void	(*builtin_fcts[NB_BUILTIN])() = {sh_cd, sh_setenv
	, sh_unsetenv, sh_env};
	static char	builtin_name[NB_BUILTIN][20] = {"cd", "setenv", "unsetenv"
	, "env"};

	i = -1;
	while (++i < NB_BUILTIN)
	{
		if (!ft_strcmp(cmd->exe, builtin_name[i]))
		{
			(*builtin_fcts[i])(cmd);
			return (1);
		}
	}
	return (0);
}
