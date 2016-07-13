/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 19:23:34 by leeios            #+#    #+#             */
/*   Updated: 2016/05/25 15:49:00 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"
#include "unistd.h"
#include "stdlib.h"

void			exit_with_error(t_error err_value)
{
	(void)err_value;
	if (err_value == 0)
		return ;
	write(1, "error\n", 6);
	exit(2);
}
