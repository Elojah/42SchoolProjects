// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Parser.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/05 19:19:53 by erobert           #+#    #+#             //
//   Updated: 2015/03/11 14:43:23 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Parser.hpp"

Parser::Parser(void):
	_good(true),
	_size(0)
{}
Parser::~Parser(void) {}

size_t						Parser::getSize(void)
{
	return (_size);
}
std::vector<int>			&Parser::getVector(void)
{
	return (_vector);
}

void						Parser::error(size_t line)
{
	_good = false;
	std::cerr << "Parser: error line " << line;
}
void						Parser::checkValue(std::string &value, size_t line)
{
	std::string::iterator	it(value.begin());
	std::string::iterator	ie(value.end());

	while (it != ie)
	{
		if (*it < '0' || *it > '9')
		{
			error(line);
			std::cerr << ": bad value" << std::endl;
			return ;
		}
		it++;
	}
}
void						Parser::checkVector(void)
{
	std::vector<int>		tmp(_vector);
	size_t					i(-1);

	std::sort(tmp.begin(), tmp.end());
	while (++i < _vector.size())
	{
		if (static_cast<int>(i) != tmp[i])
		{
			_good = false;
			std::cerr << "Parser: wrong values" << std::endl;
			return ;
		}
	}
}
void						Parser::size(tToken &token, size_t line)
{
	std::stringstream		ss;

	checkValue(token.second, line);
	ss << token.second;
	ss >> _size;
	if (_size < 3)
	{
		error(line);
		std::cerr << ": size inferior to 3" << std::endl;
		_good = false;
	}
}
void						Parser::values(tTI &it, tTI ie, size_t line)
{
	std::stringstream		ss;
	int						tmp(0);
	size_t					count(0);

	while (it != ie)
	{
		if (it->first == Lexer::END || it->first == Lexer::COMMENT)
		{
			if (count != _size)
			{
				error(line);
				if (count < _size)
					std::cerr << ": not enough columns" << std::endl;
				else
					std::cerr << ": too much columns" << std::endl;
			}
			return ;
		}
		else if (it->first != Lexer::VALUE)
		{
			error(line);
			std::cerr << ": bad instruction" << std::endl;
		}
		checkValue(it->second, line);
		ss << it->second;
		ss >> tmp;
		ss.clear();
		_vector.push_back(tmp);
		count++;
		it++;
	}
}

void						Parser::parse(std::list<tToken> &tokens)
{
	tTI						it(tokens.begin());
	tTI						ie(tokens.end());
	size_t					line(0);
	size_t					count(0);

	while (it != ie && (it->first == Lexer::COMMENT || it->first == Lexer::END))
	{
		if (it->first == Lexer::END)
			line++;
		it++;
	}
	line++;
	size(*it, line);
	it++;
	while (it != ie)
	{
		if (it->first == Lexer::VALUE)
		{
			values(it, ie, ++line);
			count++;
		}
		else if (it->first != Lexer::COMMENT && it->first != Lexer::END)
			error(line);
		it++;
	}
	if (count != _size)
	{
		error(line);
		if (count < _size)
			std::cerr << ": not enough lines" << std::endl;
		else if (count > _size)
			std::cerr << ": too much lines" << std::endl;
	}
	checkVector();
}
bool						Parser::good(void) const
{
	return (_good);
}
