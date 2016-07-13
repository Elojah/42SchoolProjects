/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:14:30 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/20 17:57:12 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				append_msg(t_ret_msg *msg, char *s)
{
	int				i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (msg->len >= MAX_SIZE_MSG - 1)
			break ;
		msg->msg[msg->len++] = s[i];
	}
	msg->msg[msg->len] = '\0';
}
