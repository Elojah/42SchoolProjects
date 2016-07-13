/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 14:49:06 by erobert           #+#    #+#             */
/*   Updated: 2014/03/26 10:37:05 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ln;
	t_list	*lststart;

	ln = ft_lstnew(((*f)(lst))->content, ((*f)(lst))->content_size);
	if (!ln)
		return (NULL);
	lststart = ln;
	lst = lst->next;
	while (lst)
	{
		ln->next = ft_lstnew(((*f)(lst))->content, ((*f)(lst))->content_size);
		ln = ln->next;
		if (!ln)
			return (NULL);
		lst = lst->next;
	}
	return (lststart);
}
