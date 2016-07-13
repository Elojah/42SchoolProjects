/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 01:13:44 by leeios            #+#    #+#             */
/*   Updated: 2016/06/01 01:58:47 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_READER_H
# define FILE_READER_H

# include "krpsim.h"
# include <stdint.h>

class FileReader
{
public:
	FileReader(void);
	~FileReader(void);

	e_err				open_file(const char *filename);
	inline const char	*get_file_data(void) const {return (m_file_data);};

private:
	char		*m_file_data;
	uint32_t	m_size_data;
};

#endif
