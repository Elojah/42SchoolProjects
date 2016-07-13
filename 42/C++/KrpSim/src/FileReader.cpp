/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReader.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 01:13:39 by leeios            #+#    #+#             */
/*   Updated: 2016/06/01 01:58:49 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReader.h"

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

FileReader::FileReader(void)
	: m_file_data(nullptr)
	, m_size_data(0)
{
	;
}

FileReader::~FileReader(void)
{
	if (m_file_data == nullptr || m_size_data == 0)
		return ;
	munmap(m_file_data, m_size_data);
}

e_err		FileReader::open_file(const char *filename)
{
	int				fd;
	struct stat		buf;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (e_err::OPEN_FAILED);
	if (fstat(fd, &buf) < 0)
		return (e_err::FSTAT_FAILED);
	m_size_data = buf.st_size;
	m_file_data = (char *)mmap(0, m_size_data, PROT_READ, MAP_PRIVATE, fd, 0);
	if (m_file_data == MAP_FAILED)
		return (e_err::MMAP_FAILED);
	return (e_err::NONE);
}
