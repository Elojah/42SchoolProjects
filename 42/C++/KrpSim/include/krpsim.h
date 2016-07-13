/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   krpsim.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 00:48:24 by leeios            #+#    #+#             */
/*   Updated: 2016/06/01 01:13:25 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KRPSIM_H
# define KRPSIM_H

enum class e_err
{
	NONE = 0,
	BAD_ARG_NUMBER,
	OPEN_FAILED,
	FSTAT_FAILED,
	MMAP_FAILED,
	E_ERR
};

#endif
