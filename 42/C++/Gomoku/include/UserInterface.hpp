// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   UserInterface.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/28 12:07:12 by erobert           #+#    #+#             //
//   Updated: 2016/05/18 17:54:37 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef USER_INTERFACE_HPP
# define USER_INTERFACE_HPP

# define HEIGHT 1000
# define WIDTH 1000

# include <sstream>
# include "SFML/Graphics.hpp"
# include "Board.h"
# include "Player.h"

class UserInterface
{
public:
	enum eEvent
	{
		EXIT = 0,
		RESTART,
		MOUSE,
		PLAY,
		NEXT,
		STOP,
		P1_AI,
		P2_AI,
		HELP,
		E_EVENT
	};

	struct sEvent
	{
		eEvent			e;
		int				x;
		int				y;
	};

	UserInterface(void);
	~UserInterface(void);

	void				init(int size);
	void				render(IBoard const &b, Player const &p1,
							Player const &p2, common::eCell turn,
							uint8_t const *capturedStones, float time,
							common::vec2 help);
	void				renderWin(IBoard const &b, common::eCell win);
	sEvent const		&getEvent(void);
private:
	enum eStone
	{
		BLACK = 0,
		WHITE,
		P1_HELP,
		P2_HELP,
		E_STONE
	};

	float				_size;
	sf::RenderWindow	_window;
	sf::Texture			_tBoard;
	sf::Sprite			_sBoard;
	sf::CircleShape     _stone[E_STONE];
	sf::Font			_font;
	sf::Text			_text;
	sEvent				_event;

	UserInterface(UserInterface const &src);

	UserInterface		&operator=(UserInterface const &rhs);

	void				initWindow(void);
	void				initStone(void);
	void				renderBoard(IBoard const &b);
	void				renderCapturedStones(uint8_t const *capturedStones);
	void				renderTime(float time);
	void				renderPlayers(Player const &p1, Player const &p2,
							common::eCell turn);
	void				renderSwitch(Player const &p1, Player const &p2);
	void				drawStone(int x, int y, eStone stone);
};

#endif
