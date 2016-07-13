// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   UINcurses.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/10/29 14:29:12 by hdezier           #+#    #+#             //
//   Updated: 2015/10/29 14:33:13 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "UINcurses.hpp"
#include <iostream>

UINcurses::UINcurses(void):	AWindow()
{}
UINcurses::UINcurses(int h, int w, int x, int y): AWindow(h, w, x, y)
{}

UINcurses::UINcurses(UINcurses const &src)
{
	if (this != &src)
		*this = src;
}

UINcurses::~UINcurses(void) {
}

UINcurses	&UINcurses::operator=(UINcurses const &rhs) {
	if (this != &rhs)
		;
	return (*this);
}

void		UINcurses::serialize(std::ostream &stream) const {
	stream << "UINcurses window:";
	AWindow::serialize(stream);
}
