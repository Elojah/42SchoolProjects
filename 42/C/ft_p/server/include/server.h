/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:22:55 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/21 18:19:37 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define MAX_CLIENT 1024
# define DEFAULT_PATH "/data"

# include <unistd.h>
# include "libft.h"

typedef void	(*t_cmd_ft)(char **, t_client_data *, t_ret_msg *);

typedef enum		e_cmd
{
	LS = 0,
	CD,
	GET,
	PUT,
	PWD,
	QUIT,
	NONE
}					t_cmd;


void			listen_port(int port);
void			new_client(int cs);
void			exec_cmd(t_cmd cmd, char **msg, t_client_data *client_data);

/*
**BUILTINS
*/
void			exec_cd(char **param, t_client_data *client_data, t_ret_msg *msg);

/*
** LOG
*/
void			init_log(void);
void			write_log(char *s, const t_client_data *client_data);

#endif
