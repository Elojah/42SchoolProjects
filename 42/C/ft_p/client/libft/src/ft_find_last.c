/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 18:15:06 by leeios            #+#    #+#             */
/*   Updated: 2016/04/19 18:16:59 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_last(const char *s, char c)
{
	int		len;

	len = ft_strlen(s);
	while (--len >= 0)
	{
		if (s[len] == c)
			return (len);
	}
	return (-1);
}
