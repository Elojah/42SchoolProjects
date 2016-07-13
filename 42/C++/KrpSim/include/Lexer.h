/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 01:50:15 by leeios            #+#    #+#             */
/*   Updated: 2016/06/01 02:03:20 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "krpsim.h"

class Parser;
class Lexer
{
public:
	Lexer(const char *data);
	~Lexer(void) = default;
	e_err	send_tokens(Parser &pars) const;

private:
	const char	*m_data;

	Lexer(void);
};

#endif
