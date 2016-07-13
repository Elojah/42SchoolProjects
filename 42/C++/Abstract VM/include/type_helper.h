/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_helper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 14:17:11 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/24 15:29:59 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_HELPER_H
# define TYPE_HELPER_H

# include "Tokens.h"

# include <cmath>
# include <fenv.h>
# include <iostream>
# include <limits>
# include <sstream>
# include <stdexcept>

namespace	helper
{

	template<typename U>
	static inline std::string	_toStr(const U &value)
	{
		if (std::is_same<U, int8_t>::value
			|| std::is_same<U, int16_t>::value
			|| std::is_same<U, int32_t>::value)
			return (std::to_string(value));
		std::ostringstream	ss;
		ss << value;
		return (ss.str());
	};

	template<typename U>
	static inline U				_toType(const std::string &value)
	{
		U						result;

		try
		{
			if (std::is_same<U, int8_t>::value
				|| std::is_same<U, int16_t>::value
				|| std::is_same<U, int32_t>::value)
			{
				auto	convertedValue = std::stoi(value);
				if (convertedValue < std::numeric_limits<U>::min()
					|| convertedValue > std::numeric_limits<U>::max())
					throw (std::out_of_range(""));
				result = convertedValue;
			}
			else if (std::is_same<U, float>::value)
				result = std::stof(value);
			else if (std::is_same<U, double>::value)
				result = std::stod(value);
		}
		catch (const std::invalid_argument &e) {throw (eErr::INVALID_ARG);}
		catch (const std::out_of_range &e) {throw (eErr::OVERFLOW_INIT);}
		return (result);
	};

	struct			sAdd
	{
		template<typename U>
		static inline U			operate(const std::string &lhs, const std::string &rhs)
		{
			U					result;
			U					lhsValue;
			U					rhsValue;
			static const U		nullValue(0.0);
			U					lhsOverflowLimit(nullValue);

			lhsValue = _toType<U>(lhs);
			rhsValue = _toType<U>(rhs);

			result = lhsValue + rhsValue;

			if (lhsValue > nullValue)
				lhsOverflowLimit = std::numeric_limits<U>::max() - std::abs(rhsValue);
			else
				lhsOverflowLimit = std::abs(std::numeric_limits<U>::min() + std::abs(rhsValue));

			if ((lhsValue > nullValue) == (rhsValue > nullValue)
					&& std::abs(lhsValue) > lhsOverflowLimit)
				throw (eErr::OVERFLOW_CALC);
			return (result);
		}
	};
	struct			sSub
	{
		template<typename U>
		static inline U			operate(const std::string &lhs, const std::string &rhs)
		{
			U					result;
			U					lhsValue;
			U					rhsValue;
			static const U		nullValue(0.0);
			U					lhsOverflowLimit(nullValue);

			lhsValue = _toType<U>(lhs);
			rhsValue = _toType<U>(rhs);

			result = lhsValue - rhsValue;

			if (lhsValue > nullValue)
				lhsOverflowLimit = std::numeric_limits<U>::max() - std::abs(rhsValue);
			else
				lhsOverflowLimit = std::abs(std::numeric_limits<U>::min() + std::abs(rhsValue));

			if ((lhsValue > nullValue) != (rhsValue > nullValue)
					&& std::abs(lhsValue) > lhsOverflowLimit)
				throw (eErr::OVERFLOW_CALC);
			return (result);
		}
	};
	struct			sMul
	{
		template<typename U>
		static inline U			operate(const std::string &lhs, const std::string &rhs)
		{
			U					result;
			U					lhsValue;
			U					rhsValue;
			static const U		nullValue(0.0);
			U					lhsOverflowLimit(nullValue);

			feclearexcept(FE_UNDERFLOW);
			lhsValue = _toType<U>(lhs);
			rhsValue = _toType<U>(rhs);

			result = lhsValue * rhsValue;

			if ((lhsValue > nullValue) == (rhsValue > nullValue))
				lhsOverflowLimit = std::numeric_limits<U>::max() / std::abs(rhsValue);
			else
				lhsOverflowLimit = std::abs(std::numeric_limits<U>::min() / std::abs(rhsValue));

			if (fetestexcept(FE_UNDERFLOW))
				throw (eErr::UNDERFLOW_CALC);
			else if (lhsOverflowLimit != nullValue && std::abs(lhsValue) > lhsOverflowLimit)
				throw (eErr::OVERFLOW_CALC);
			return (result);
		}
	};
	struct			sDiv
	{
		template<typename U>
		static inline U			operate(const std::string &lhs, const std::string &rhs)
		{
			U					result;
			U					lhsValue;
			U					rhsValue;
			static const U		nullValue(0.0);
			static const U		identity(1.0);
			static const U		negIdentity(-1.0);
			U					lhsOverflowLimit(nullValue);

			feclearexcept(FE_UNDERFLOW);
			lhsValue = _toType<U>(lhs);
			rhsValue = _toType<U>(rhs);
			if (rhsValue == nullValue)
				throw (eErr::DIV_BY_ZERO);
			result = lhsValue / rhsValue ;

			if (rhsValue > negIdentity && rhsValue < identity)
			{
				if (rhsValue > nullValue == lhsValue > nullValue)
					lhsOverflowLimit = std::numeric_limits<U>::max() * std::abs(rhsValue);
				else
					lhsOverflowLimit = std::abs(std::numeric_limits<U>::min() * std::abs(rhsValue));
			}

			if (lhsOverflowLimit != nullValue && std::abs(lhsValue) > lhsOverflowLimit)
				throw (eErr::OVERFLOW_CALC);
			else if (fetestexcept(FE_UNDERFLOW))
				throw (eErr::UNDERFLOW_CALC);
			return (result);
		}
	};
	struct			sMod
	{
		template<typename U>
		static inline U			operate(const std::string &lhs, const std::string &rhs)
		{
			U					result;
			U					lhsValue;
			U					rhsValue;

			lhsValue = _toType<U>(lhs);
			rhsValue = _toType<U>(rhs);
			result = std::fmod(lhsValue, rhsValue);
			if (fetestexcept(FE_INVALID))
				throw (eErr::DIV_BY_ZERO);
			return (result);
		}
	};
};

#endif
