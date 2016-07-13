/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 14:39:00 by hdezier           #+#    #+#             */
/*   Updated: 2014/03/26 10:35:47 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*trash;

	if (!alst)
		return ;
	lst = *alst;
	while (lst)
	{
		trash = lst;
		(*del)(lst->content, lst->content_size);
		lst = lst->next;
		free(trash);
	}
	*alst = NULL;
}
