/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:32:34 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/27 18:17:49 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"
#include <dirent.h>

static void	exec_ls(char **params, t_client_data *client_data, t_ret_msg *msg)
{
	DIR					*dirp;
	struct dirent		*dp;

	(void)params;
	(void)client_data;
	dirp = opendir(".");
	if (!dirp)
	{
		msg->ret = ERROR;
		return ;
	}
	dp = readdir(dirp);
	while (dp)
	{
		if (dp->d_name[0] != '.')
		{
			append_msg(msg, dp->d_name);
			append_msg(msg, (char *)"\n");
		}
		dp = readdir(dirp);
	}
	msg->ret = SUCCESS;
}

static void	exec_get(char __attribute__((__unused__))**param
	, t_client_data __attribute__((__unused__))*client_data
	, t_ret_msg *msg)
{
	msg->ret = SUCCESS;
}

static void	exec_put(char __attribute__((__unused__))**param
	, t_client_data __attribute__((__unused__))*client_data
	, t_ret_msg *msg)
{
	msg->ret = SUCCESS;
}

static void	exec_pwd(char **param, t_client_data *client_data, t_ret_msg *msg)
{
	(void)param;
	ft_putstr("Asking: pwd_builtin");
	append_msg(msg, client_data->current_path);
	append_msg(msg, (char *)"\n");
	msg->ret = SUCCESS;
}

void			exec_cmd(t_cmd cmd, char **msg, t_client_data *client_data)
{
	static const t_cmd_ft	cmd_dispatcher[] =
	{
		&exec_ls, &exec_cd, &exec_get, &exec_put, &exec_pwd
	};
	static t_ret_msg		ret_msg =
	{
		"", 0, SUCCESS
	};

	ft_putstr("Exec command...");
	ret_msg.len = 0;
	if (cmd == NONE)
	{
		append_msg(&ret_msg, (char *)"Unrecognized command\n");
		ret_msg.ret = ERROR;
	}
	else if (cmd == QUIT)
	{
		append_msg(&ret_msg, (char *)"QUIT\n");
		ret_msg.ret = SUCCESS;
	}
	else
		cmd_dispatcher[(int)cmd](msg, client_data, &ret_msg);
	append_msg(&ret_msg, ret_msg.ret == SUCCESS ? (char *)"\e[1;32mSUCCESS\e[0m" : (char *)"\e[1;31mERROR\e[0m");
	ft_putstr((char *)"\nSend back\n");
	ft_putstr(ret_msg.msg);
	ft_putstr((char *)"\n");
	send_data(client_data->cs, ret_msg.msg);
}
