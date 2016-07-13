/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rule.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:45:24 by leeios            #+#    #+#             */
/*   Updated: 2016/04/05 13:22:41 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULE_HPP
# define RULE_HPP

#include <vector>

#include "Expr.hpp"

class Rule
{
public:

	enum class eLinkExpr
	{
		NONE = 0,
		IMPLIES,
		IF_ONLY_IF
	};

	Rule(void);
	virtual ~Rule(void);
	virtual eErr	set(const std::string &line);
	std::string		serialize(void);
	std::string		serializeEval(const state_ctr &initStates);

	inline const std::string	&getSymbols(void) const {return (m_presentSymbols);};

	bool						apply(state_ctr &initStates, const char c);
	inline bool					isValid(const state_ctr &initStates) const {return (Symbol(_evalLeft(initStates)) == Symbol(_evalRight(initStates)));};

protected:
private:
	eLinkExpr	m_link;
	IExpr*		m_leftExpr;
	IExpr*		m_rightExpr;


	std::string													m_presentSymbols;
	static const char											m_opSymbols[];
	static const std::map<Rule::eLinkExpr, std::string>			m_linkSymbols;

	IExpr			*_setExprAsExpr(const std::string &s, size_t symbol);
	IExpr			*_setExprParenthesis(const std::string &s, Expr<IExpr *> *result, size_t parenthesis);
	IExpr			*_setExprAsChar(const std::string &s);
	IExpr			*_setExpr(const std::string &s);

	inline eValue				_evalLeft(const state_ctr &initStates) const {return (m_leftExpr->eval(initStates));}
	inline eValue				_evalRight(const state_ctr &initStates) const {return (m_rightExpr->eval(initStates));}

	bool						_apply(state_ctr &initStates, eValue value, IExpr *expr);

};

#endif
