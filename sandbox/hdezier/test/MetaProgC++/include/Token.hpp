/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:26:33 by leeios            #+#    #+#             */
/*   Updated: 2016/03/13 22:35:00 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_HPP
# define TOKEN_HPP

# include "specialization.h"

# include <string>
# include <vector>
# include <iostream>

typedef const std::vector<std::string>	tLexicon;

enum class	eResponse
{
	NONE = 0,
	OK,
	COMPLETE
};

namespace	TokensDefinitions
{
	struct		sOperator
	{
		sOperator(void) = default;
		virtual ~sOperator(void) = default;
		static tLexicon	words;
	};
	struct		sOperand
	{
		sOperand(void) = default;
		virtual ~sOperand(void) = default;
		static tLexicon	words;
	};
	struct		sEntity
	{
		sEntity(void) = default;
		virtual ~sEntity(void) = default;
		static eResponse		detect(const std::string &str)
		{
			if (std::isalnum(str.back()))
				return (eResponse::OK);
			else if (std::isalnum(str.at(0)))
				return (eResponse::COMPLETE);
			else
				return (eResponse::NONE);
		}
	};
};

template<typename TokenDef>
class Token
{
public:
	Token(void) = default;
	virtual ~Token(void) = default;
protected:
private:

	DECL_INIT(0, spe_none, TokenDef)
	DECL_SPE(1, spe_detect, detect)
	DECL_SPE(2, spe_words, words)

	/*
	**
	** Detect implementations
	**
	*/

	/*
	** Words attribute
	*/
	template<typename T>
	static eResponse	_detect_impl(const std::string &readToken, spe_words)
	{
		std::cerr << "call to WORDS_ATT" << std::endl;
		size_t		readSize = readToken.size();
		for (const auto word : T::words)
		{
			size_t	sizeToCompare = std::min(readSize, word.size());
			if (word.compare(0, sizeToCompare, readToken.c_str(), sizeToCompare) == 0)
			{
				if (readSize > word.size())
					return (eResponse::COMPLETE);
				else
					return (eResponse::OK);
			}
		}
		return (eResponse::NONE);
	};

	/*
	** Detect method
	*/
	template<typename T>
	static eResponse	_detect_impl(const std::string &readToken, spe_detect)
	{
		std::cerr << "call to DETECT_METH" << std::endl;
		return (T::detect(readToken));
	};

	/*
	** Default fallback
	*/
	template<typename T>
	static eResponse	_detect_impl(const std::string &readToken, spe_none)
	{
		std::cerr << "call to NONE" << std::endl;
		(void)readToken;
		return (eResponse::NONE);
	};
	/*
	**
	**!Detect implementations
	**
	*/

public:
	static eResponse	detect(const std::string &readToken)
	{
		return (_detect_impl<TokenDef>(readToken, _specialization));
	};
};

#endif
