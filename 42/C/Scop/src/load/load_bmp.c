/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 18:19:16 by leeios            #+#    #+#             */
/*   Updated: 2015/07/09 18:29:15 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static void		read_bmp_file(t_object *obj, char *filename)
{
	int						fd;
	unsigned char	header[54];

	ft_exit((fd = open(filename, O_RDONLY)) < 0, "Can't read BMP file");
	ft_exit(read(fd, header, 54) < 0, "BMP file not valid");
	ft_exit(header[0] != 'B' || header[1] != 'M', "BMP file not valid");
	obj->bmp.data_pos = *(unsigned int *)&(header[0x0A]);
	obj->bmp.size = *(unsigned int *)&(header[0x22]);
	obj->bmp.width = *(unsigned int *)&(header[0x12]);
	obj->bmp.height = *(unsigned int *)&(header[0x16]);
	if (!obj->bmp.size)
		obj->bmp.size = obj->bmp.width * obj->bmp.height * 3;
	if (!obj->bmp.data_pos)
		obj->bmp.data_pos = 54;
	ft_exit(obj->bmp.size >= MAX_SIZE_BMP, "BMP file too fat");
	ft_exit(read(fd, obj->bmp.data, obj->bmp.size) < 0 , "BMP file not valid");
	close(fd);
}

void		load_bmp(t_object *obj, char *filename)
{
	read_bmp_file(obj, filename);
}
