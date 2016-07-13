/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:50:10 by leeios            #+#    #+#             */
/*   Updated: 2016/05/24 14:00:37 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.h"
#include "IOperand.h"
#include "Stack.h"

#include <iostream>
#include <map>

eErr		Lexer::read_line(const std::string &line, Stack &stack, const bool quickExit)
{
	std::string	cleanLine;
	auto		commentDelim = line.find_first_of(';');
	if (commentDelim != std::string::npos)
	{
		if (quickExit
			&& commentDelim != line.size() - 1
			&& line.at(commentDelim + 1) == ';')
			return (eErr::EXIT);
		cleanLine = line.substr(0, commentDelim);
	}
	else
		cleanLine = line;
	if (cleanLine.empty())
		return (eErr::NONE);
	auto	type = _analyzeType(cleanLine);
	if (type == eToken::PUSH)
	{
		lexOperations::sPush	typePush;
		if (_setElem(typePush, cleanLine) == false) return (eErr::SYNTAX_ERROR);
		return (stack.doOperation(typePush));
	}
	else if (type == eToken::POP)
	{
		lexOperations::sPop		typePop;
		return (stack.doOperation(typePop));
	}
	else if (type == eToken::PRINT)
	{
		lexOperations::sPrint	typePrint;
		return (stack.doOperation(typePrint));
	}
	else if (type == eToken::DUMP)
	{
		lexOperations::sDump	typeDump;
		return (stack.doOperation(typeDump));
	}
	else if (type == eToken::ASSERT)
	{
		lexOperations::sAssert	typeAssert;
		if (_setElem(typeAssert, cleanLine) == false) return (eErr::SYNTAX_ERROR);
		return (stack.doOperation(typeAssert));
	}
	else if (type == eToken::ADD)
	{
		lexOperations::sAdd		typeAdd;
		return (stack.doOperation(typeAdd));
	}
	else if (type == eToken::SUB)
	{
		lexOperations::sSub		typeSub;
		return (stack.doOperation(typeSub));
	}
	else if (type == eToken::MUL)
	{
		lexOperations::sMul		typeMul;
		return (stack.doOperation(typeMul));
	}
	else if (type == eToken::DIV)
	{
		lexOperations::sDiv		typeDiv;
		return (stack.doOperation(typeDiv));
	}
	else if (type == eToken::MOD)
	{
		lexOperations::sMod		typeMod;
		return (stack.doOperation(typeMod));
	}
	else if (type == eToken::EXIT)
		return (eErr::EXIT);
	return (eErr::UNKNOWN_INSTR);
}

eToken	Lexer::_analyzeType(const std::string &line)
{
	static const std::map<std::string, eToken>		analyzeMap =
	{
		{"push", eToken::PUSH},
		{"print", eToken::PRINT},
		{"assert", eToken::ASSERT},
		{"pop", eToken::POP},
		{"dump", eToken::DUMP},
		{"add", eToken::ADD},
		{"sub", eToken::SUB},
		{"mul", eToken::MUL},
		{"div", eToken::DIV},
		{"mod", eToken::MOD},
		{"exit", eToken::EXIT}
	};
	for (const auto &compareElem : analyzeMap)
	{
		const int		sizeTocompare(compareElem.first.size());
		if (compareElem.first.compare(0, sizeTocompare
			, line.c_str(), sizeTocompare) == 0)
			return (compareElem.second);
	}
	return (eToken::ERR);
}

bool	Lexer::_setElem(lexOperations::sElem &elem, const std::string &line)
{
	static const std::map<std::string, IOperand::eOperandType>		analyzeMap =
	{
		{"int8", IOperand::eOperandType::Int8},
		{"int16", IOperand::eOperandType::Int16},
		{"int32", IOperand::eOperandType::Int32},
		{"float", IOperand::eOperandType::Float},
		{"double", IOperand::eOperandType::Double}
	};

	const auto	firstDelim = line.find_first_of(' ');
	if (firstDelim == std::string::npos
		|| firstDelim == line.size() - 1)
		return (false);
	const auto	type = line.substr(firstDelim + 1);
	for (const auto &compareElem : analyzeMap)
	{
		const int		sizeTocompare(compareElem.first.size());
		if (compareElem.first.compare(0, sizeTocompare
			, type.c_str(), sizeTocompare) == 0)
		{
			elem.type = compareElem.second;
			const auto	openParenthesis = type.find_first_of('(');
			const auto	closeParenthesis = type.find_first_of(')');
			if (openParenthesis == std::string::npos
				|| openParenthesis == line.size() - 1
				|| closeParenthesis == std::string::npos
				|| closeParenthesis == 0
				|| closeParenthesis < openParenthesis)
				return (false);
			elem.elem = type.substr(openParenthesis + 1, closeParenthesis - openParenthesis - 1);
			return (true);
		}
	}
	return (false);
}
