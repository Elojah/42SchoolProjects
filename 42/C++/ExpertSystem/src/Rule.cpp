/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rule.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 10:08:13 by leeios            #+#    #+#             */
/*   Updated: 2016/04/05 13:44:03 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rule.hpp"

#include <algorithm>

const char												Rule::m_opSymbols[] = "+|^";
const std::map<Rule::eLinkExpr, std::string>			Rule::m_linkSymbols =
{
	{Rule::eLinkExpr::IF_ONLY_IF, "<=>"},
	{Rule::eLinkExpr::IMPLIES, "=>"}
};

Rule::Rule(void)
	: m_link(eLinkExpr::NONE)
	, m_leftExpr(nullptr)
	, m_rightExpr(nullptr)
{
}

Rule::~Rule(void)
{
	// if (m_leftExpr != nullptr)
	// 	delete (m_leftExpr);
	// if (m_rightExpr != nullptr)
	// 	delete (m_rightExpr);
}

std::string	Rule::serialize(void)
{
	std::string		link;
	auto hasLink = Rule::m_linkSymbols.find(m_link);
	if (hasLink != Rule::m_linkSymbols.end())
		link = hasLink->second;
	else
		link = "XXX";
	return (m_leftExpr->serialize() + link + m_rightExpr->serialize());
}

std::string	Rule::serializeEval(const state_ctr &initStates)
{
	std::string	result;
	switch (m_leftExpr->eval(initStates))
	{
		case(eValue::UNDEFINED) :
			result += "UNDEFINED";
			break ;
		case(eValue::TRUE) :
			result += "TRUE";
			break ;
		case(eValue::FALSE) :
			result += "FALSE";
			break ;
		case(eValue::ERROR) :
			result += "ERROR";
			break ;
	}
	std::string		link;
	auto hasLink = Rule::m_linkSymbols.find(m_link);
	if (hasLink != Rule::m_linkSymbols.end())
		link = hasLink->second;
	else
		link = "XXX";
	result += link;
	switch (m_rightExpr->eval(initStates))
	{
		case(eValue::UNDEFINED) :
			result += "UNDEFINED";
			break ;
		case(eValue::TRUE) :
			result += "TRUE";
			break ;
		case(eValue::FALSE) :
			result += "FALSE";
			break ;
		case(eValue::ERROR) :
			result += "ERROR";
			break ;
	}
	return(result);
}

bool	Rule::_apply(state_ctr &initStates, eValue value, IExpr *expr)
{
	switch (value)
	{
		case (eValue::UNDEFINED) :
			return (false);
		case (eValue::TRUE) :
			return (expr->setAll(eValue::TRUE, initStates));
		case (eValue::FALSE) :
			return (expr->setAll(eValue::FALSE, initStates));
		case (eValue::ERROR) :
			return (false);
	}
}

bool	Rule::apply(state_ctr &initStates, const char c)
{
	if (m_presentSymbols.find(c) == std::string::npos)
		return (false) ;
	if (m_link == eLinkExpr::IMPLIES)
	{
		auto				separator = m_presentSymbols.find('=');
		auto				rightSide = m_presentSymbols.substr(separator);
		if (separator == std::string::npos || rightSide.find(c) == std::string::npos)
			return (false) ;
		return (_apply(initStates, _evalLeft(initStates), m_rightExpr));
	}
	else if (m_link == eLinkExpr::IF_ONLY_IF)
	{
		auto	leftVal = _evalLeft(initStates);
		auto	rightVal = _evalRight(initStates);
		if (leftVal != eValue::UNDEFINED)
		{
			if (rightVal == eValue::UNDEFINED)
				return (_apply(initStates, leftVal, m_rightExpr));
			if (leftVal != rightVal)
			{
				err::raise_error(eErr::FATAL, "Incoherent rule !!!\t" + serialize());
				return (false);
			}
		}
		// HERE we set at TRUE or FALSE evolved expressions ( A | B ^ C & D)
		if (rightVal != eValue::UNDEFINED)
			return (_apply(initStates, rightVal, m_leftExpr));
	}
	return (false);
}

/*
** Set expressions
*/
eErr	Rule::set(const std::string &line)
{
	size_t		separator;
	size_t		linkSize;
	for (const auto &link : Rule::m_linkSymbols)
	{
		separator = line.find(link.second);
		if (separator != std::string::npos)
		{
			if (link.second.compare("=>") == 0 && separator > 0 && line[separator - 1] == '<')
				continue ;
			m_link = link.first;
			linkSize = link.second.size();
			goto sep_found;
		}
	}
	err::raise_error(eErr::FATAL, "No implication found");
	return (eErr::FATAL);

	sep_found:
	m_leftExpr = _setExpr(line.substr(0, separator));
	// Add separator to better side detection
	m_presentSymbols += '=';
	m_rightExpr = _setExpr(line.substr(separator + linkSize));

	return (eErr::NONE);
}

IExpr	*Rule::_setExprAsChar(const std::string &s)
{
	auto result = new Expr<char>;
	for (const char &c : s)
	{
		if (c == ' ' || c == '\t' || c == '\r')
			continue ;
		else if (c == '!')
		{
			result->setLeftNegative(true);
			continue ;
		}
		else if (!isalpha(c))
		{
			delete result;
			err::raise_error(eErr::FATAL, "Character can't be identified as symbol");
			return (nullptr);
		}
		result->setLeftOperand(c);
		m_presentSymbols += c;
		return (result);
	}
	return (nullptr);
}

IExpr	*Rule::_setExprParenthesis(const std::string &s, Expr<IExpr *> *result, size_t parenthesis)
{
	size_t	parenthesisEnd = s.find(')');
	if (parenthesisEnd == std::string::npos)
	{
		delete result;
		err::raise_error(eErr::FATAL, "Parenthesis without end");
		return (nullptr);
	}
	result->setLeftOperand(_setExpr(s.substr(parenthesis + 1, parenthesisEnd)));
	if (parenthesisEnd < s.size())
	{
		auto	rightSide = s.substr(parenthesisEnd + 1);
		auto symbol = rightSide.find_first_of(Rule::m_opSymbols);
		if (symbol != std::string::npos)
		{
			result->setOperator(rightSide.at(symbol));
			result->setRightOperand(_setExpr(rightSide.substr(symbol + 1)));
		}
	}
	return (result);
}

IExpr	*Rule::_setExprAsExpr(const std::string &s, size_t symbol)
{
	auto result = new Expr<IExpr *>;

	size_t	parenthesis = s.find('(');
	if (parenthesis != std::string::npos)
	{
		for (const char &c : s)
		{
			if (c == ' ' || c == '\t' || c == '\r')
				continue ;
			else if (c == '!')
			{
				result->setLeftNegative(true);
				continue ;
			}
			else if (c == '(')
				return (_setExprParenthesis(s, result, parenthesis));
			else
				break ;
		}
	}
	result->setOperator(s.at(symbol));
	result->setLeftOperand(_setExpr(s.substr(0, symbol)));
	result->setRightOperand(_setExpr(s.substr(symbol + 1)));
	return (result);
}

IExpr	*Rule::_setExpr(const std::string &s)
{
	size_t	symbol = s.find_first_of(Rule::m_opSymbols);
	if (symbol == std::string::npos)
		return (_setExprAsChar(s));
	else
		return (_setExprAsExpr(s, symbol));
}
