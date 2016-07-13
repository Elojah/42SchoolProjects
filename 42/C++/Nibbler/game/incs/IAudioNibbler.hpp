// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IAudioNibbler.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/08 16:17:09 by erobert           #+#    #+#             //
//   Updated: 2015/04/08 16:25:47 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef I_AUDIO_NIBBLER_HPP
# define I_AUDIO_NIBBLER_HPP

class IAudioNibbler
{
public:
	virtual ~IAudioNibbler(void) {};

	virtual void			playMusic(void) = 0;
	virtual void			playEatSound(void) = 0;
	virtual void			playDeathSound(void) = 0;
};

#endif
