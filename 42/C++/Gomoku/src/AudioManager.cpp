// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AudioManager.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/01 14:18:45 by erobert           #+#    #+#             //
//   Updated: 2016/05/18 18:30:54 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AudioManager.hpp"

AudioManager::AudioManager(void)
{
	std::string	musicFiles[E_MUSIC];
	std::string	soundFiles[E_SOUND];
	int			i(-1);

	musicFiles[HYMNE_A_LA_KRO] = "data/hymne-a-la-kro.ogg";
	musicFiles[CRISPY_BACON] = "data/crispy-bacon.ogg";
	while (++i < E_MUSIC)
	{
		_music[i].openFromFile(musicFiles[i]);
		_music[i].setLoop(true);
	}
	soundFiles[CHEWBACCA] = "data/chewbacca.ogg";
	i = -1;
	while (++i < E_SOUND)
	{
		_buffer[i].loadFromFile(soundFiles[i]);
		_sound[i].setBuffer(_buffer[i]);
	}
}
AudioManager::~AudioManager(void) {}

void			AudioManager::playMusic(eMusic music)
{
	int			i(-1);

	while (++i < E_MUSIC)
		_music[i].stop();
	if (_music[music].getStatus() == sf::SoundSource::Stopped)
		_music[music].play();
}
void			AudioManager::nextMusic(void)
{
	int			i(-1);

	while (++i < E_MUSIC)
	{
		if (_music[i].getStatus() == sf::SoundSource::Playing)
		{
			_music[i].stop();
			_music[++i % E_MUSIC].play();
		}
	}
}
void			AudioManager::stopMusic(void)
{
	int			i(-1);

	while (++i < E_MUSIC)
	{
		if (_music[i].getStatus() == sf::SoundSource::Playing)
			_music[i].stop();
	}
}
void			AudioManager::playSound(eSound sound)
{
	_sound[sound].play();
}
