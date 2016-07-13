// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 13:22:57 by erobert           #+#    #+#             //
//   Updated: 2015/04/10 14:57:01 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_HPP
# define GAME_HPP

# include <dlfcn.h>
# include <iostream>
# include <list>
# include <sstream>
# include <unistd.h>
# include <vector>
# include "Time.hpp"

# define MIN_SIZE 10
# define MAX_SIZE 80
# define DEFAULT_SPEED 100
# define ACCELERATION 5
# define MAX_SPEED 10

class IGUINibbler;
class IAudioNibbler;

class Game
{
public:
	enum eEvent
	{
		F1 = 0,
		F2,
		F3,
		PAUSE,
		RESTART,
		EXIT,
		UP,
		LEFT,
		DOWN,
		RIGHT,
		E_EVENT
	};
	enum eState
	{
		ALIVE,
		DEAD
	};
	enum eObject
	{
		EMPTY,
		WALL,
		APPLE,
		HEAD,
		BODY
	};
	struct sNibbler
	{
		eState			state;
		int				dir;
		int				x;
		int				y;
	};

	Game(void);
	~Game(void);

	bool				buildMap(char *height, char *width);
	void				setMap(std::vector<int> const &map);
	void				gameLoop(void);
private:
	typedef std::list<sNibbler>	tNibbler;
	typedef IGUINibbler			*(*tGUICreator)(void);
	typedef void				(*tGUIDestructor)(IGUINibbler *gN);
	typedef IAudioNibbler		*(*tAudioCreator)(void);
	typedef void				(*tAudioDestructor)(IAudioNibbler *aN);

	int					_height;
	int					_width;
	std::vector<int>	_map;
	tNibbler			_nibbler;
	bool				_alive;
	bool				_pause;
	int					_speed;
	int					_score;
	void				*_dlHandle[4];
	IGUINibbler         *_gN[3];
	IAudioNibbler		*_aN;

	Game(Game const &g);

	Game				&operator=(Game const &g);

	void				initNibbler(void);
	int					initDL(void);
	void				closeDL(void);
	void				createGUI(int gui);
	void				destroyGUI(int gui);

	int					eventHandler(eEvent event, int gui);
	int					newApple(void);
	void				moveNibbler(eEvent event);
	bool				eatApple(int apple);
	bool				isDead(void);

	bool				printError(void) const;
	void				printMap(void) const;
};

#endif
