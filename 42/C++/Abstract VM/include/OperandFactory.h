/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:38:03 by leeios            #+#    #+#             */
/*   Updated: 2016/05/23 02:51:17 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_FACTORY_H
# define OPERAND_FACTORY_H

# include "IOperand.h"

class OperandFactory
{
public:
	OperandFactory(void) = default;
	~OperandFactory(void) = default;

	static OperandFactory		*getInstance(void);
	static void					deleteInstance(void);
	IOperand const				*createOperand(IOperand::eOperandType type, std::string const & value) const;

private:
	typedef IOperand const*(OperandFactory::*creator)(std::string const&) const;

	static OperandFactory		*m_instance;

	IOperand const				*createInt8(std::string const & value) const;
	IOperand const				*createInt16(std::string const & value) const;
	IOperand const				*createInt32(std::string const & value) const;
	IOperand const				*createFloat(std::string const & value) const;
	IOperand const				*createDouble(std::string const & value) const;
};

#endif
