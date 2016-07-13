// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Time.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/08 15:56:18 by erobert           #+#    #+#             //
//   Updated: 2015/04/11 17:11:03 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <sys/time.h>
#include "Time.hpp"

Time::Time(void)
{
	gettimeofday(&_currentTime, 0);
	gettimeofday(&_lastTime, 0);
}
Time::~Time(void) {}

struct timeval		Time::currentTime(void)
{
	return (_currentTime);
}

int					Time::msSinceLastTime(void)
{
	unsigned long	ms;
	int				ret;

	ms = static_cast<unsigned long>(_currentTime.tv_usec);
	if (_currentTime.tv_sec != _lastTime.tv_sec)
		ms += (_currentTime.tv_sec - _lastTime.tv_sec) * 1000000;
	ms -= _lastTime.tv_usec;
	ret = static_cast<int>(ms / 1000);
	return (ret);
}
void				Time::setCurrentTime(void)
{
	gettimeofday(&_currentTime, 0);
}
void				Time::setLastTime(struct timeval value)
{
	_lastTime.tv_usec = value.tv_usec;
	_lastTime.tv_sec = value.tv_sec;
}
