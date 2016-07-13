/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:12:34 by leeios            #+#    #+#             */
/*   Updated: 2016/05/19 18:19:00 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_OPERAND_H
# define I_OPERAND_H

# include <string>

class IOperand
{
public:

	enum class eOperandType
	{
		Int8,// Representation of a signed integer coded on 8bits.
		Int16,// Representation of a signed integer coded on 16bits.
		Int32,// Representation of a signed integer coded on 32bits.
		Float,// Representation of a float.
		Double,// Representation of a double.
		E_TYPE
	};

	virtual ~IOperand(void) {};

	virtual int				getPrecision(void) const = 0;
	virtual eOperandType	getType(void) const = 0;

	virtual IOperand const		*operator+(IOperand const &rhs) const = 0;
	virtual IOperand const		*operator-(IOperand const &rhs) const = 0;
	virtual IOperand const		*operator*(IOperand const &rhs) const = 0;
	virtual IOperand const		*operator/(IOperand const &rhs) const = 0;
	virtual IOperand const		*operator%(IOperand const &rhs) const = 0;

	virtual std::string const	&toString(void) const = 0;

};
#endif
