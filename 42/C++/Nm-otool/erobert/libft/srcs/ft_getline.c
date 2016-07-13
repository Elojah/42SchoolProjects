/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 13:10:48 by erobert           #+#    #+#             */
/*   Updated: 2014/02/09 18:17:58 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t		ft_linelen(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

static int			ft_endline(char **str, char **line)
{
	char			*tmp;

	if (**str == '\0')
	{
		free(*str);
		*str = NULL;
		*line = NULL;
		return (0);
	}
	if (ft_linelen(*str) == ft_strlen(*str))
	{
		*line = ft_strdup(*str);
		tmp = *str;
		*str = ft_strdup(*str + ft_strlen(*str));
		free(tmp);
		return (1);
	}
	(*str)[ft_linelen(*str)] = '\0';
	*line = ft_strdup(*str);
	tmp = *str;
	*str = ft_strdup(*str + ft_linelen(*str) + 1);
	free(tmp);
	return (1);
}

int					ft_getline(int const fd, char **line)
{
	static char		*str = 0;
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	int				i;

	i = read(fd, buf, BUFF_SIZE);
	if (i == -1)
		return (-1);
	buf[i] = '\0';
	if (str)
	{
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
	}
	else
		str = ft_strjoin("", buf);
	if (i && ft_linelen(str) == ft_strlen(str))
		return (ft_getline(fd, line));
	else
		return (ft_endline(&str, line));
}
