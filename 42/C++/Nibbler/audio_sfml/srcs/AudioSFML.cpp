// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AudioSFML.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/08 16:22:27 by erobert           #+#    #+#             //
//   Updated: 2015/04/10 14:25:10 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AudioSFML.hpp"

AudioSFML::AudioSFML(void)
{
	_music.openFromFile("data/hymne_a_la_kro");
	_music.setLoop(true);
	_eatBuffer.loadFromFile("data/chewbacca");
	_eatSound.setBuffer(_eatBuffer);
	_deathBuffer.loadFromFile("data/bladerunner_lesbian");
	_deathSound.setBuffer(_deathBuffer);
}
AudioSFML::~AudioSFML(void) {}

void				AudioSFML::playMusic(void)
{
	_music.play();
}
void				AudioSFML::playEatSound(void)
{
	_eatSound.play();
}

void				AudioSFML::playDeathSound(void)
{
	_deathSound.play();
}

AudioSFML			*createAudio(void)
{
	return (new AudioSFML);
}
void				deleteAudio(AudioSFML *gN)
{
	delete gN;
}
