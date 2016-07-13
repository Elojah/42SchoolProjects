/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:50:17 by leeios            #+#    #+#             */
/*   Updated: 2016/05/24 14:00:35 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "Tokens.h"
# include <string>

class Stack;

class Lexer
{
public:

	Lexer(void) = default;
	virtual ~Lexer(void) = default;
	static eErr			read_line(const std::string &line, Stack &stack, const bool quickExit);
private:
	static eToken		_analyzeType(const std::string &line);
	static bool			_setElem(lexOperations::sElem &elem, const std::string &line);
};

#endif
