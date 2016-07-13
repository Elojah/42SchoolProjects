/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 19:42:31 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/05 19:42:46 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
**DEFINE
*/

# define BUFF_SIZE 3

typedef struct		s_gnl
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	int				cur_fd;
	char			*to_free;
}					t_gnl;

/*
**GNL
*/
int					get_next_line(const int fd, char **line);

#endif
