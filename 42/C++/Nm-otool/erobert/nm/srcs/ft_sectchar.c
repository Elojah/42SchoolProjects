/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sectchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 17:57:14 by erobert           #+#    #+#             */
/*   Updated: 2014/04/27 20:06:02 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static char						ft_getchar(void *ptr, uint8_t n)
{
	struct segment_command_64	*seg_cmd;
	struct section_64			*sect;
	uint8_t						i;

	seg_cmd = (struct segment_command_64 *)ptr;
	i = 0;
	ptr += sizeof(*seg_cmd);
	while (++i <= seg_cmd->nsects)
	{
		sect = (struct section_64 *)ptr;
		if (i == n)
			return (sect->sectname[2]);
		ptr += sect->size;
	}
	return (' ');
}

char							ft_sectchar(void *ptr, uint8_t n)
{
	struct mach_header_64		*header;
	struct segment_command_64	*seg_cmd;
	char						tmp;
	int							i;

	header = (struct mach_header_64 *)ptr;
	ptr += sizeof(*header);
	i = header->ncmds;
	while (i-- > 0 && n > 0)
	{
		seg_cmd = (struct segment_command_64 *)ptr;
		if (seg_cmd->cmd != LC_SEGMENT_64)
			return ('s');
		tmp = ft_getchar(ptr, n);
		if (tmp != ' ')
			return (tmp);
		n -= seg_cmd->nsects;
		ptr += seg_cmd->cmdsize;
	}
	return ('s');
}
