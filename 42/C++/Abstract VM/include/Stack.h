/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 15:30:16 by leeios            #+#    #+#             */
/*   Updated: 2016/05/19 19:07:41 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "Tokens.h"
# include <vector>

class Stack
{
public:

	Stack(void) = default;
	~Stack(void);

	eErr		doOperation(const lexOperations::sPush &param);
	eErr		doOperation(const lexOperations::sPop &param);

	eErr		doOperation(const lexOperations::sPrint &param) const;
	eErr		doOperation(const lexOperations::sAssert &param) const;
	eErr		doOperation(const lexOperations::sDump &param) const;

	eErr		doOperation(const lexOperations::sAdd &param);
	eErr		doOperation(const lexOperations::sSub &param);
	eErr		doOperation(const lexOperations::sMul &param);
	eErr		doOperation(const lexOperations::sDiv &param);
	eErr		doOperation(const lexOperations::sMod &param);

	inline void	popBackAndRemove(void)
	{
		auto	lastElem = m_container.back();
		delete (lastElem);
		m_container.pop_back();
	};

private:

	std::vector<const IOperand *>		m_container;
};

#endif
