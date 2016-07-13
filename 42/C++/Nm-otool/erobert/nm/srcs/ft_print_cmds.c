/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 15:55:43 by erobert           #+#    #+#             */
/*   Updated: 2014/04/27 19:37:12 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_nm.h"

static uint32_t	*ft_init_tab(uint32_t nsyms)
{
	uint32_t	*tab;
	uint32_t	i;

	tab = malloc(sizeof(*tab) * nsyms);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < nsyms)
	{
		tab[i] = i;
		i++;
	}
	return (tab);
}

static uint32_t	*ft_getsort(struct nlist_64 *nlst, uint32_t nsyms, char *str)
{
	uint32_t		*tab;
	uint32_t		tmp[3];
	char			*s[2];

	tab = ft_init_tab(nsyms);
	if (!tab)
		return (NULL);
	tmp[0] = -1;
	while (++tmp[0] + 1 < nsyms)
	{
		tmp[1] = -1;
		while (++tmp[1] + 1 < nsyms)
		{
			s[0] = str + nlst[tab[tmp[1]]].n_un.n_strx;
			s[1] = str + nlst[tab[tmp[1] + 1]].n_un.n_strx;
			if (ft_strcmp(s[0], s[1]) > 0)
			{
				tmp[2] = tab[tmp[1]];
				tab[tmp[1]] = tab[tmp[1] + 1];
				tab[tmp[1] + 1] = tmp[2];
			}
		}
	}
	return (tab);
}

static void		ft_print_type(void *ptr, struct nlist_64 *nlst)
{
	char			tmp;

	ft_print_uint32_t(nlst->n_value);
	if ((nlst->n_type & N_TYPE) == N_ABS)
		tmp = 'A';
	else if ((nlst->n_type & N_TYPE) == N_SECT)
	{
		tmp = ft_sectchar(ptr, nlst->n_sect);
		if (tmp <= 'Z' && tmp >= 'A')
			tmp += 32;
	}
	if ((nlst->n_type & N_EXT))
		tmp -= 32;
	write(1, &tmp, 1);
	write(1, " ", 1);
}

void			ft_print_cmds(void *ptr, struct symtab_command *sym_cmd)
{
	struct nlist_64	*nlst;
	char			*str;
	uint32_t		*tab;
	uint32_t		i;

	nlst = (struct nlist_64 *)(ptr + sym_cmd->symoff);
	str = (char *)(ptr + sym_cmd->stroff);
	tab = ft_getsort(nlst, sym_cmd->nsyms, str);
	if (!tab)
		return ;
	i = 0;
	while (i < sym_cmd->nsyms)
	{
		if ((nlst[tab[i]].n_type & N_TYPE) == N_UNDF)
			write(1, "                 U ", 19);
		else
			ft_print_type(ptr, &nlst[tab[i]]);
		ft_putendl_fd(str + nlst[tab[i++]].n_un.n_strx, 1);
	}
	free(tab);
}
