// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lexer.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/05 17:09:39 by erobert           #+#    #+#             //
//   Updated: 2015/03/06 17:13:51 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef LEXER_H
# define LEXER_H

# include <fstream>
# include <list>
# include <string>

class Lexer
{
public:
	enum eToken
	{
		COMMENT,
		END,
		SIZE,
		VALUE
	};

	typedef std::pair<eToken, std::string>	tToken;

	Lexer(void);
	~Lexer(void);

	std::list<tToken>		&tokenize(std::ifstream &ifs);
private:
	std::list<tToken>		_tokens;

	Lexer(Lexer const &l);

	Lexer					&operator=(Lexer const &l);

	void					getComment(std::ifstream &ifs);
	void					getSize(std::ifstream &ifs, char c);
	void					getValues(std::ifstream &ifs, char c);
};

#endif
