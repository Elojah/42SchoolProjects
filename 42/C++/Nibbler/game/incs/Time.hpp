// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Time.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/08 13:26:20 by erobert           #+#    #+#             //
//   Updated: 2015/04/11 17:10:46 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TIME_HPP
# define TIME_HPP

# include <sys/time.h>

class Time
{
public:
	Time(void);
	~Time(void);

	struct timeval	currentTime(void);

	int				msSinceLastTime(void);
	void			setCurrentTime(void);
	void			setLastTime(struct timeval value);
private:
	Time(const Time &t);

	Time			&operator=(const Time &t);

	struct timeval	_currentTime;
	struct timeval	_lastTime;
};

#endif
