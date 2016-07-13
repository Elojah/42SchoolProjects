/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:30:31 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/11 16:31:52 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_free_array_str(char **s)
{
	int		i;

	i = -1;
	if (s == NULL)
		return ;
	while (s[++i] != NULL)
		free(s[i]);
}
