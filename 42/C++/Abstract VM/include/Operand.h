/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:18:40 by leeios            #+#    #+#             */
/*   Updated: 2016/05/23 02:22:57 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_H
# define OPERAND_H

# include "IOperand.h"
# include "OperandFactory.h"
# include "type_helper.h"

template<typename T>
class		Operand : public IOperand
{
public:
	Operand(void) = default;
	Operand(const std::string &value);
	virtual ~Operand(void) = default;

	inline virtual int			getPrecision(void) const override
	{
		return (sizeof(T));
	};

	inline virtual eOperandType	getType(void) const override
	{
		if (std::is_same<T, int8_t>::value)
			return (IOperand::eOperandType::Int8);
		if (std::is_same<T, int16_t>::value)
			return (IOperand::eOperandType::Int16);
		if (std::is_same<T, int32_t>::value)
			return (IOperand::eOperandType::Int32);
		if (std::is_same<T, float>::value)
			return (IOperand::eOperandType::Float);
		if (std::is_same<T, double>::value)
			return (IOperand::eOperandType::Double);
		return (IOperand::eOperandType::E_TYPE);
	};

	inline virtual IOperand const		*operator+(IOperand const &rhs) const override
	{
		return (_doOperation<helper::sAdd>(rhs));
	};
	inline virtual IOperand const		*operator-(IOperand const &rhs) const override
	{
		return (_doOperation<helper::sSub>(rhs));
	};
	inline virtual IOperand const		*operator*(IOperand const &rhs) const override
	{
		return (_doOperation<helper::sMul>(rhs));
	};
	inline virtual IOperand const		*operator/(IOperand const &rhs) const override
	{
		return (_doOperation<helper::sDiv>(rhs));
	};
	inline virtual IOperand const		*operator%(IOperand const &rhs) const override
	{
		return (_doOperation<helper::sMod>(rhs));
	};

	virtual std::string const	&toString(void) const override
	{
		return (m_strValue);
	}

private:
	const T							m_value;
	const std::string				m_strValue;

	template<typename OperationType>
	IOperand const		*_doOperation(IOperand const &rhs) const;
};

#endif
