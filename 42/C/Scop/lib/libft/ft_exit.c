/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 22:28:20 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/06 22:28:21 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_exit(int test, char *error_msg)
{
	if (test)
	{
		ft_putstr_fd("ERROR:\t", 2);
		ft_putendl_fd(error_msg, 2);
		exit(0);
	}
}
