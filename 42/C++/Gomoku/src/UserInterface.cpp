// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   UserInterface.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/28 12:13:37 by erobert           #+#    #+#             //
//   Updated: 2016/05/18 18:01:38 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "UserInterface.hpp"

UserInterface::UserInterface(void)
{
	_font.loadFromFile("./data/open_sans_light.ttf");
	_text.setFont(_font);
}
UserInterface::~UserInterface(void)
{
	if (_window.isOpen())
		_window.close();
}

void						UserInterface::init(int size)
{
	_size = size;
	if (_size == 19)
		_tBoard.loadFromFile("./data/goban-19.bmp");
	else if (_size == 13)
		_tBoard.loadFromFile("./data/goban-13.bmp");
	else
		_tBoard.loadFromFile("./data/goban-9.bmp");
	initWindow();
	initStone();
}
void						UserInterface::render(IBoard const &b,
								Player const &p1, Player const &p2,
								common::eCell turn,
								uint8_t const *capturedStones,
								float time, common::vec2 help)
{
	_window.clear(sf::Color(255, 212, 112));
	renderBoard(b);
	_text.setCharacterSize(32);
	_text.setStyle(sf::Text::Bold);
	renderCapturedStones(capturedStones);
	renderTime(time);
	renderPlayers(p1, p2, turn);
	renderSwitch(p1, p2);
	if (help.x != 255)
	{
		if (!p1.ai() && common::eCell::P1 == turn)
			drawStone(help.x, help.y, P1_HELP);
		if (!p2.ai() && common::eCell::P2 == turn)
			drawStone(help.x, help.y, P2_HELP);
	}
	_window.display();
}
void						UserInterface::renderWin(IBoard const &b,
								common::eCell win)
{
	_window.clear(sf::Color(255, 212, 112));
	renderBoard(b);
	_text.setPosition(64, 12);
	(void)win;
	if (win == common::eCell::P1)
	{
		_text.setColor(sf::Color::Black);
		_text.setString("BLACK WIN");
	}
	else if (win == common::eCell::P2)
	{
		_text.setColor(sf::Color::White);
		_text.setString("WHITE WIN");
	}
	_window.draw(_text);
	_window.display();
}


UserInterface::sEvent const	&UserInterface::getEvent(void)
{
	sf::Event				event;
	float					position[2];

	_event.e = E_EVENT;
	if (_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed
			|| (event.type == sf::Event::KeyPressed
				&& event.key.code == sf::Keyboard::Escape))
			_event.e = EXIT;
		else if (event.type == sf::Event::MouseButtonPressed)
		{
			position[0] = sf::Mouse::getPosition(_window).x;
			position[1] = sf::Mouse::getPosition(_window).y;
			if (position[1] < HEIGHT + 64 && position[1] > 64)
			{
				_event.e = MOUSE;
				_event.x = position[0] / ((10 + 52.05 * 19.) / _size);
				_event.y = (position[1] - 64) / ((10 + 52.05 * 19.) / _size);
			}
			else if (position[1] > HEIGHT + 64 && position[1] < HEIGHT + 116)
			{
				if (position[0] > 190 && position[0] < 290)
					_event.e = P1_AI;
				else if (position[0] < 810 && position[0] > 710)
					_event.e = P2_AI;
				else if (position[0] < 600 && position[0] > 430)
					_event.e = HELP;
			}
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::P)
				_event.e = PLAY;
			else if (event.key.code == sf::Keyboard::N)
				_event.e = NEXT;
			else if (event.key.code == sf::Keyboard::S)
				_event.e = STOP;
			else if (event.key.code == sf::Keyboard::R)
				_event.e = RESTART;
		}
		else
			getEvent();
	}
	return (_event);
}

void						UserInterface::initWindow(void)
{
	float					scale[0];

	if (!_window.isOpen())
		_window.create(sf::VideoMode(WIDTH, HEIGHT + 128), "Gomoku");
	_window.setFramerateLimit(60);
	scale[0] = WIDTH;
	scale[0] /= _tBoard.getSize().x;
	scale[1] = HEIGHT;
	scale[1] /= _tBoard.getSize().y;
	_sBoard.scale(scale[0], scale[1]);
	_sBoard.setTexture(_tBoard);
	_sBoard.setPosition(0, 64);
}
void						UserInterface::initStone(void)
{
	int						i(-1);

	while (++i < E_STONE)
	{
		_stone[i].setRadius(21 * 19. / _size);
		_stone[i].setOutlineThickness(2);
	}
	_stone[BLACK].setFillColor(sf::Color::Black);
	_stone[BLACK].setOutlineColor(sf::Color::Color(5, 5, 5, 100));
	_stone[WHITE].setFillColor(sf::Color::White);
	_stone[WHITE].setOutlineColor(sf::Color::Color(250, 250, 250, 100));
	_stone[P1_HELP].setFillColor(sf::Color::Color(5, 250, 5, 150));
	_stone[P1_HELP].setOutlineColor(sf::Color::Black);
	_stone[P2_HELP].setFillColor(sf::Color::Color(5, 250, 5, 150));
	_stone[P2_HELP].setOutlineColor(sf::Color::White);
}
void						UserInterface::drawStone(int x, int y,
													 eStone stone)
{
	_stone[stone].setPosition((10 + 52.05 * x) * 19. / _size,
							  (10 + 52.05 * y) * 19. / _size + 64);
	_window.draw(_stone[stone]);
}
void						UserInterface::renderBoard(IBoard const &b)
{
	common::vec2			coord;
	common::eCell			value;

	_window.draw(_sBoard);
	coord.x = 0;
	while (coord.x < _size)
	{
		coord.y = 0;
		while (coord.y < _size)
		{
			value = b.getCell(coord);
			if (value == common::eCell::P1)
				drawStone(coord.x, coord.y, BLACK);
			else if (value == common::eCell::P2)
				drawStone(coord.x, coord.y, WHITE);
			coord.y++;
		}
		coord.x++;
	}
}
void						UserInterface::renderCapturedStones(
								uint8_t const *capturedStones)
{
	std::stringstream		s1;
	std::stringstream		s2;

	s1 << static_cast<int>(capturedStones[0]);
	_stone[WHITE].setPosition(32, HEIGHT + 76);
	_window.draw(_stone[WHITE]);
	_text.setPosition(44, HEIGHT + 76);
	_text.setString(s1.str());
	_window.draw(_text);
	s2 << static_cast<int>(capturedStones[1]);
	_stone[BLACK].setPosition(WIDTH - 70, HEIGHT + 76);
	_window.draw(_stone[BLACK]);
	_text.setPosition(WIDTH - 58, HEIGHT + 76);
	_text.setString(s2.str());
	_window.draw(_text);
}
void						UserInterface::renderTime(float time)
{
	if (time)
	{
		std::stringstream		ss;
		ss << time << "ms";
		_text.setPosition(WIDTH - 256, 12);
		_text.setString(ss.str());
		_window.draw(_text);
	}
}
void						UserInterface::renderPlayers(Player const &p1,
								Player const &p2, common::eCell turn)
{
	_text.setColor(sf::Color::Black);
	_text.setPosition(64, 12);
	(void)p1;
	(void)p2;
	if (turn == common::eCell::P1)
	{
		_text.setString("BLACK TURN");
		_window.draw(_text);
	}
	_text.setPosition(80, HEIGHT + 76);
	_text.setString("BLACK");
	_window.draw(_text);
	_text.setColor(sf::Color::White);
	_text.setPosition(64, 12);
	if (turn == common::eCell::P2)
	{
		_text.setString("WHITE TURN");
		_window.draw(_text);
	}
	_text.setString("WHITE");
	_text.setPosition(WIDTH - 178, HEIGHT + 76);
	_window.draw(_text);
}
void						UserInterface::renderSwitch(Player const &p1,
								Player const &p2)
{
	_text.setColor(sf::Color::Color(205, 92, 92));
	_text.setPosition(190, HEIGHT + 76);
	if (p1.ai())
		_text.setString("AI ON");
	else
		_text.setString("AI OFF");
	_window.draw(_text);
	if (p2.ai())
		_text.setString("AI ON");
	else
		_text.setString("AI OFF");
	_text.setPosition(WIDTH - 291, HEIGHT + 76);
	_window.draw(_text);
	_text.setColor(sf::Color::Color(95, 200, 160));
	_text.setString("HELP");
	_text.setString("HELP");
	_text.setPosition(455, HEIGHT + 76);
	_window.draw(_text);
}
