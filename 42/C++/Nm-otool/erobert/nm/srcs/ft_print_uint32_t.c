/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint32_t.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 17:16:59 by erobert           #+#    #+#             */
/*   Updated: 2016/03/28 11:06:58 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_nm.h"

static void		ft_putnbr(uint64_t n)
{
	const char	tab[] = "0123456789abcdef";
	uint64_t	quo;
	uint64_t	mod;

	if (!n)
		return ;
	if (n > 15)
	{
		quo = n / 16;
		ft_putnbr(quo);
		mod = n % 16;
		write(1, &tab[mod], 1);
	}
	else
		write(1, &tab[n], 1);
}

void			ft_print_uint32_t(uint64_t n)
{
	uint64_t	i;

	if (!n)
	{
		write(1, "0000000000000000 ", 17);
		return ;
	}
	i = ULLONG_MAX >> 4;
	while (i && n / i == 0)
	{
		write(1, "0", 1);
		i >>= 4;
	}
	ft_putnbr(n);
	write(1, " ", 1);
}
