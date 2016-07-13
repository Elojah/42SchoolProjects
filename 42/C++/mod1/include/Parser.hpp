// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Parser.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/30 16:17:57 by hdezier           #+#    #+#             //
//   Updated: 2015/04/30 16:20:19 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PARSER_H
# define PARSER_H

# include <set>
# include <vector>
# include <string>

# include "AToken.hpp"

class AToken;

class Parser
{
public:
	Parser(const std::string &filename);
	~Parser(void);

	void								display(void);
	const std::vector<sReadToken>		getRead(void) const;
	bool								fail(void) const;
protected:
private:
	typedef std::vector<AToken *>		tSetTokens;
	typedef std::vector<sReadToken>		tTokens;

	Parser(void);
	Parser(Parser const &rhs);

	Parser								&operator=(Parser const &rhs);

	void								initGlobalTokens(void);
	void								resetGlobalTokens(void);
	void								exec(std::ifstream &ifs);
	bool								tokenizing(void) const;
	static bool							isSeparator(char const &c);


	tSetTokens							_globalTokens;
	tTokens								_readTokens;
	bool								_fail;
};

#endif
