/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 15:30:21 by leeios            #+#    #+#             */
/*   Updated: 2016/05/19 17:59:08 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stack.h"
#include "OperandFactory.h"
#include <iostream>

Stack::~Stack(void)
{
	for (auto operand : m_container)
		delete (operand);
	OperandFactory::deleteInstance();
}


eErr		Stack::doOperation(const lexOperations::sPush &param)
{
	const IOperand	*elem;
	try {elem = OperandFactory::getInstance()->createOperand(param.type, param.elem);}
	catch (eErr err) {return (err);}
	m_container.push_back(elem);
	return (eErr::NONE);
}
eErr		Stack::doOperation(const lexOperations::sPop &param)
{
	(void)param;
	if (m_container.empty())
		return (eErr::POP_ON_EMPTY_STACK);
	popBackAndRemove();
	return (eErr::NONE);
}

eErr		Stack::doOperation(const lexOperations::sPrint &param) const
{
	(void)param;
	auto	lastElem = m_container.back();
	if (lastElem->getType() != IOperand::eOperandType::Int8)
		return (eErr::ASSERT_FALSE);
	char	c = std::stoi(lastElem->toString());
	std::cout << c << std::endl;
	return (eErr::NONE);
}
eErr		Stack::doOperation(const lexOperations::sAssert &param) const
{
	const auto lastElem = m_container.back();
	if (param.type != lastElem->getType()
		|| param.elem.compare(lastElem->toString()) != 0)
		return (eErr::ASSERT_FALSE);
	return (eErr::NONE);
}
eErr		Stack::doOperation(const lexOperations::sDump &param) const
{
	(void)param;
	for (auto i = m_container.rbegin(); i != m_container.rend(); ++i)
		std::cout << (*i)->toString() << std::endl;
	return (eErr::NONE);
}

eErr		Stack::doOperation(const lexOperations::sAdd &param)
{
	(void)param;
	if (m_container.size() < 2)
		return (eErr::MISSING_OPERANDS);
	const auto	lhs = m_container.back();
	const auto	rhs = m_container.at(m_container.size() - 2);
	const IOperand	*result;
	try {result = *lhs + *rhs;}
	catch (eErr err) {return (err);}
	popBackAndRemove();
	popBackAndRemove();
	m_container.push_back(result);
	return (eErr::NONE);
}
eErr		Stack::doOperation(const lexOperations::sSub &param)
{
	(void)param;
	if (m_container.size() < 2)
		return (eErr::MISSING_OPERANDS);
	const auto	lhs = m_container.back();
	const auto	rhs = m_container.at(m_container.size() - 2);
	const IOperand	*result;
	try {result = *lhs - *rhs;}
	catch (eErr err) {return (err);}
	popBackAndRemove();
	popBackAndRemove();
	m_container.push_back(result);
	return (eErr::NONE);
}
eErr		Stack::doOperation(const lexOperations::sMul &param)
{
	(void)param;
	if (m_container.size() < 2)
		return (eErr::MISSING_OPERANDS);
	const auto	lhs = m_container.back();
	const auto	rhs = m_container.at(m_container.size() - 2);
	const IOperand	*result;
	try {result = *lhs * *rhs;}
	catch (eErr err) {return (err);}
	popBackAndRemove();
	popBackAndRemove();
	m_container.push_back(result);
	return (eErr::NONE);
}
eErr		Stack::doOperation(const lexOperations::sDiv &param)
{
	(void)param;
	if (m_container.size() < 2)
		return (eErr::MISSING_OPERANDS);
	const auto	lhs = m_container.back();
	const auto	rhs = m_container.at(m_container.size() - 2);
	const IOperand	*result;
	try {result = *lhs / *rhs;}
	catch (eErr err) {return (err);}
	popBackAndRemove();
	popBackAndRemove();
	m_container.push_back(result);
	return (eErr::NONE);
}
eErr		Stack::doOperation(const lexOperations::sMod &param)
{
	(void)param;
	if (m_container.size() < 2)
		return (eErr::MISSING_OPERANDS);
	const auto	lhs = m_container.back();
	const auto	rhs = m_container.at(m_container.size() - 2);
	const IOperand	*result;
	try {result = *lhs % *rhs;}
	catch (eErr err) {return (err);}
	popBackAndRemove();
	popBackAndRemove();
	m_container.push_back(result);
	return (eErr::NONE);
}
