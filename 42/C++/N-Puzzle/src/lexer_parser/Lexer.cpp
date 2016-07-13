// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lexer.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/05 17:13:57 by erobert           #+#    #+#             //
//   Updated: 2015/03/09 19:45:00 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Lexer.hpp"

Lexer::Lexer(void) {}
Lexer::~Lexer(void) {}

void						Lexer::getComment(std::ifstream &ifs)
{
	char					c;
	std::string				str;
	tToken					comment;

	while (1138)
	{
		ifs.get(c);
		if (ifs.eof() || c == '\n')
		{
			comment.first = COMMENT;
			comment.second = str;
			_tokens.push_back(comment);
			return ;
		}
		str.push_back(c);
	}
}
void						Lexer::getSize(std::ifstream &ifs, char c)
{
	std::string				str;
	tToken					size;

	while (1138)
	{
		if (ifs.eof() || c == '\n')
		{
			size.first = SIZE;
			size.second = str;
			_tokens.push_back(size);
			return ;
		}
		else if (c == '#')
			return (getComment(ifs));
		else if (c != ' ')
			str.push_back(c);
		ifs.get(c);
	}
}
void						Lexer::getValues(std::ifstream &ifs, char c)
{
	std::string				str;
	tToken					value;

	while (1138)
	{
		if (ifs.eof() || c == '\n')
		{
			value.first = VALUE;
			value.second = str;
			_tokens.push_back(value);
			return ;
		}
		else if (c == '#')
			return (getComment(ifs));
		else if (c == ' ')
		{
			while (c == ' ')
				ifs.get(c);
			value.first = VALUE;
			value.second = str;
			_tokens.push_back(value);
			str.clear();
		}
		else
		{
			str.push_back(c);
			ifs.get(c);
		}
	}
}

std::list<Lexer::tToken>	&Lexer::tokenize(std::ifstream &ifs)
{
	char					c;
	bool					first(true);
	tToken					end;

	while (ifs.get(c))
	{
		if (c != ' ')
		{
			if (c == '#')
				getComment(ifs);
			else if (first)
			{
				getSize(ifs, c);
				first = false;
			}
			else
				getValues(ifs, c);
			end.first = END;
			end.second = "*";
			_tokens.push_back(end);
		}
	}
	return (_tokens);
}
