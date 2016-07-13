/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:43:56 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/23 02:33:45 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operand.h"

template<typename T>
Operand<T>::Operand(const std::string &value)
	: m_value(helper::_toType<T>(value))
	, m_strValue(helper::_toStr(m_value))
{
}

template<typename T>
template<typename OperationType>
IOperand const		*Operand<T>::_doOperation(IOperand const &rhs) const
{
	IOperand::eOperandType	resultType;
	auto					lhsType(getType());
	auto					rhsType(rhs.getType());
	if ((int)lhsType > (int)rhsType)
		resultType = getType();
	else
		resultType = rhs.getType();
	switch (resultType)
	{
		case (IOperand::eOperandType::Int8) :
			return
			(
				OperandFactory::getInstance()->createOperand(resultType, helper::_toStr(OperationType::template operate<int8_t>(toString(), rhs.toString())))
			);
		case (IOperand::eOperandType::Int16) :
			return
			(
				OperandFactory::getInstance()->createOperand(resultType, helper::_toStr(OperationType::template operate<int16_t>(toString(), rhs.toString())))
			);
		case (IOperand::eOperandType::Int32) :
			return
			(
				OperandFactory::getInstance()->createOperand(resultType, helper::_toStr(OperationType::template operate<int32_t>(toString(), rhs.toString())))
			);
		case (IOperand::eOperandType::Float) :
			return
			(
				OperandFactory::getInstance()->createOperand(resultType, helper::_toStr(OperationType::template operate<float>(toString(), rhs.toString())))
			);
		case (IOperand::eOperandType::Double) :
			return
			(
				OperandFactory::getInstance()->createOperand(resultType, helper::_toStr(OperationType::template operate<double>(toString(), rhs.toString())))
			);
		default : break ;
	};
	return (nullptr);
}

template class	Operand<int8_t>;
template class	Operand<int16_t>;
template class	Operand<int32_t>;
template class	Operand<float>;
template class	Operand<double>;
