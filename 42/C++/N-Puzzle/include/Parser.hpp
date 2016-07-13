// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Parser.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/05 19:20:26 by erobert           #+#    #+#             //
//   Updated: 2015/03/20 11:38:03 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PARSER_H
# define PARSER_H

# include <algorithm>
# include <iostream>
# include <list>
# include <sstream>
# include <vector>
# include "Lexer.hpp"

class Parser
{
public:
	typedef Lexer::tToken				tToken;
	typedef std::list<tToken>::iterator	tTI;

	Parser(void);
	~Parser(void);

	size_t						getSize(void);
	std::vector<int>			&getVector(void);

	void						parse(std::list<tToken> &tokens);
	bool						good(void) const;
private:
	bool						_good;
	std::vector<int>			_vector;
	size_t						_size;

	Parser(Parser const &p);

	Parser						&operator=(Parser const &p);

	void						error(size_t line);
	void						checkValue(std::string &value, size_t line);
	void						checkVector(void);
	void						size(tToken &token, size_t line);
	void						values(tTI &it, tTI ie, size_t line);
};

#endif
