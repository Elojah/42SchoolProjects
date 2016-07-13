// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AudioSFML.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/08 16:20:01 by erobert           #+#    #+#             //
//   Updated: 2015/04/08 17:29:38 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AUDIO_SFML_HPP
# define AUDIO_SFML_HPP

# include "SFML/Audio.hpp"
# include "IAudioNibbler.hpp"

class AudioSFML: public IAudioNibbler
{
public:
	AudioSFML(void);
	~AudioSFML(void);

	virtual void			playMusic(void);
	virtual void			playEatSound(void);
	virtual void			playDeathSound(void);
private:
	sf::Music				_music;
	sf::SoundBuffer			_eatBuffer;
	sf::Sound				_eatSound;
	sf::SoundBuffer			_deathBuffer;
	sf::Sound				_deathSound;

	AudioSFML(AudioSFML const &gN);

	AudioSFML				&operator=(AudioSFML const &gN);
};

extern "C"
{
	AudioSFML				*createAudio(void);
	void					deleteAudio(AudioSFML *gN);
}

#endif
