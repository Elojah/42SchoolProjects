// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AToken.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/30 15:58:48 by erobert           #+#    #+#             //
//   Updated: 2015/04/30 16:04:49 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AToken.hpp"

AToken::AToken(void) {}
AToken::~AToken(void) {}

void			AToken::reset(void)
{
	_buffer.clear();
}
sReadToken		AToken::getAsRead(void) const
{
	sReadToken	sRT;

	sRT.buffer = _buffer;
	sRT.type = getType();
	return (sRT);
}
bool			AToken::isEmptyWord(void) const
{
	return (_buffer.empty());
}
void			AToken::display(void) const
{
	std::cout << _buffer << std::endl;
}
