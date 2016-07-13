/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Symbol.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 15:44:11 by leeios            #+#    #+#             */
/*   Updated: 2016/04/05 13:54:47 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOL_HPP
# define SYMBOL_HPP

#include <string>

enum class	eValue
{
	UNDEFINED = 0,
	TRUE,
	FALSE,
	ERROR
};

class Symbol
{
public:
	Symbol(const eValue val) : m_val(val) {};
	virtual ~Symbol(void) {};
	inline eValue		getVal(void) const {return (m_val);};
	inline eValue		getValNegative(bool neg) const
	{
		if (neg == false)
			return (m_val);
		switch (m_val)
		{
			case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
			case (eValue::TRUE) : return (eValue::FALSE);
			case (eValue::FALSE) : return (eValue::TRUE);
			case (eValue::ERROR) : return (eValue::ERROR);
		};
	};

	inline eValue		operator&&(const Symbol &rightOp) const
	{
		switch (m_val)
		{
			case (eValue::UNDEFINED) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::UNDEFINED);
					case (eValue::FALSE) : return (eValue::FALSE);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::TRUE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE);
					case (eValue::FALSE) : return (eValue::FALSE);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::FALSE) : return (eValue::FALSE);
			case (eValue::ERROR) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::ERROR);
					case (eValue::TRUE) : return (eValue::ERROR);
					case (eValue::FALSE) : return (eValue::ERROR);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
		}
	};

	inline eValue		operator||(const Symbol &rightOp) const
	{
		switch (m_val)
		{
			case (eValue::UNDEFINED) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE);
					case (eValue::FALSE) : return (eValue::UNDEFINED);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::TRUE) : return (eValue::TRUE);
			case (eValue::FALSE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE);
					case (eValue::FALSE) : return (eValue::FALSE);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::ERROR) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::ERROR);
					case (eValue::TRUE) : return (eValue::ERROR);
					case (eValue::FALSE) : return (eValue::ERROR);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
		}
	};

	inline eValue		operator^(const Symbol &rightOp) const
	{
		switch (m_val)
		{
			case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
			case (eValue::TRUE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::FALSE);
					case (eValue::FALSE) : return (eValue::TRUE);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::FALSE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE);
					case (eValue::FALSE) : return (eValue::FALSE);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::ERROR) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::ERROR);
					case (eValue::TRUE) : return (eValue::ERROR);
					case (eValue::FALSE) : return (eValue::ERROR);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
		}
	};


	inline bool		operator==(const Symbol &rightOp) const
	{
		switch (m_val)
		{
			case (eValue::UNDEFINED) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (false);
					case (eValue::TRUE) : return (false);
					case (eValue::FALSE) : return (false);
					case (eValue::ERROR) : return (false);
				}
			case (eValue::TRUE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (false);
					case (eValue::TRUE) : return (true);
					case (eValue::FALSE) : return (false);
					case (eValue::ERROR) : return (false);
				}
			case (eValue::FALSE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (false);
					case (eValue::TRUE) : return (false);
					case (eValue::FALSE) : return (true);
					case (eValue::ERROR) : return (false);
				}
			case (eValue::ERROR) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (false);
					case (eValue::TRUE) : return (false);
					case (eValue::FALSE) : return (false);
					case (eValue::ERROR) : return (false);
				}
		}
	};

	inline eValue		operator!=(const Symbol &rightOp) const
	{
		switch (m_val)
		{
			case (eValue::UNDEFINED) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::UNDEFINED);
					case (eValue::FALSE) : return (eValue::UNDEFINED);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::TRUE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::FALSE);
					case (eValue::FALSE) : return (eValue::TRUE);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::FALSE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE);
					case (eValue::FALSE) : return (eValue::FALSE);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::ERROR) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::ERROR);
					case (eValue::TRUE) : return (eValue::ERROR);
					case (eValue::FALSE) : return (eValue::ERROR);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
		}
	};

	inline bool		asBool(void) const
	{
		switch (m_val)
		{
			case (eValue::UNDEFINED) : return (false);
			case (eValue::TRUE) : return (true);
			case (eValue::FALSE) : return (false);
			case (eValue::ERROR) : return (false);
		}
	};

	inline static const std::string	getName(eValue val)
	{
		static const std::string	valueNames[(int)eValue::ERROR + 1] =
		{
			"UNDEFINED",
			"TRUE",
			"FALSE",
			"ERROR"
		};
		return (valueNames[(int)val]);
	};

private:
	const eValue				m_val;
};

#endif
