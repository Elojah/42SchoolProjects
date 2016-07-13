/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 23:13:37 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/13 23:13:37 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# define IS_DIGIT(n) ((n) >= '0' && (n) <= '9')
# define BUFF_SIZE 1024
# define NB_BUILTIN 4

# include <stdlib.h>
# include "libft.h"

typedef struct	s_cmd
{
	char		*exe;
	char		**args;
	char		**env;
	char		*path;
	char		current_dir[BUFF_SIZE];
}				t_cmd;

/*
**PARSE
*/
void			parse(t_cmd *cmd, char *s);
char			*get_var_env(t_cmd *cmd, char *s);

/*
**BUILTIN
*/
int				exec_builtin(t_cmd *cmd);
void			sh_cd(t_cmd *cmd);
void			sh_setenv(t_cmd *cmd);
void			sh_unsetenv(t_cmd *cmd);
void			sh_env(t_cmd *cmd);
void			sh_exit(t_cmd *cmd);

/*
**CALCULUS
*/
void			exec_cmd(t_cmd *cmd);

#endif
