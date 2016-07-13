/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 18:08:03 by leeios            #+#    #+#             */
/*   Updated: 2016/04/27 16:22:37 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"

static t_bool		resolve_path_ex(char *path, int *i)
{
	int				prev;
	t_bool			resolved;

	prev = *i;
	resolved = FALSE;
	while (--prev >= 0)
	{
		if (path[prev] != '/')
			continue ;
		ft_strcpy(path + prev, path + *i + 3);
		*i = prev - 1;
		resolved = TRUE;
		break ;
	}
	return (resolved);
}

static t_bool		resolve_path(char *path)
{
	int				i;

	i = -1;
	while (path[++i] != '\0')
	{
		if (ft_strncmp(path + i, "/..", 3) == 0
			&& resolve_path_ex(path, &i) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

static t_bool		add_to_path(char *param, t_client_data *client_data
	, t_ret_msg *msg)
{
	if (ft_strlen(client_data->current_path) + ft_strlen(param)
		>= MAX_LEN_PATH)
	{
		append_msg(msg, (char *)"Path too long\n");
		return (FALSE);
	}
	ft_strcat(client_data->current_path, param);
	ft_strcat(client_data->current_path, "/");
	return (TRUE);
}

static t_bool		add_to_root(t_client_data *client_data, t_ret_msg *msg)
{
	char			full_path[MAX_LEN_PATH + MAX_LEN_ROOT_PATH];

	ft_strcpy(full_path, client_data->original_path);
	if (resolve_path(client_data->current_path) == FALSE)
	{
		ft_strcpy(client_data->current_path, (char *)"/");
		msg->ret = ERROR;
		append_msg(msg, (char *)"Don't fool me ! Go back to root.\n");
	}
	ft_strcat(full_path, client_data->current_path);
	if (chdir(full_path) == -1)
	{
		append_msg(msg, (char *)"Can't access this directory\n");
		append_msg(msg, full_path);
		append_msg(msg, (char *)"\n");
		return (FALSE);
	}
	return (TRUE);
}

void				exec_cd(char **param, t_client_data *client_data
	, t_ret_msg *msg)
{
	char			save_path[MAX_LEN_PATH];

	ft_strcpy(save_path, client_data->current_path);
	if (param == NULL || param[1] == NULL)
		ft_strcpy(client_data->current_path, (char *)"/");
	else if (add_to_path(param[1], client_data, msg) == FALSE)
	{
		msg->ret = ERROR;
		return ;
	}
	if (add_to_root(client_data, msg) == FALSE)
	{
		ft_strcpy(client_data->current_path, save_path);
		msg->ret = ERROR;
	}
	else
		msg->ret = SUCCESS;
}
