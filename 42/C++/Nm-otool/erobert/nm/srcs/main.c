/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 17:07:39 by erobert           #+#    #+#             */
/*   Updated: 2014/04/27 18:40:16 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "ft_nm.h"

static void					*ft_getptr(char *file)
{
	struct stat				s;
	int						fd;
	void					*ptr;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("ft_nm: can't open file: ", 2);
		ft_putendl_fd(file, 2);
		return (NULL);
	}
	else
	{
		if (fstat(fd, &s) == -1)
			return (NULL);
		ptr = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
		if (ptr == MAP_FAILED || *(int *)ptr != (int)MH_MAGIC_64)
			return (NULL);
		return (ptr);
	}
}

static void					ft_nm(char *file)
{
	void					*ptr;
	struct mach_header_64	*header;
	struct load_command		*ld_cmd;
	int						i;

	ptr = ft_getptr(file);
	if (!ptr)
	{
		ft_putendl_fd("Error", 2);
		return ;
	}
	header = (struct mach_header_64 *)ptr;
	ptr += sizeof(*header);
	i = header->ncmds;
	while (i-- > 0)
	{
		ld_cmd = (struct load_command *)ptr;
		if (ld_cmd->cmd == LC_SYMTAB)
			ft_print_cmds(header, (struct symtab_command *)ptr);
		ptr += ld_cmd->cmdsize;
	}
}

int							main(int ac, char **av)
{
	int						i;

	i = 1;
	while (i < ac)
		ft_nm(av[i++]);
	if (ac == 1)
		ft_nm("a.out");
	return (0);
}
