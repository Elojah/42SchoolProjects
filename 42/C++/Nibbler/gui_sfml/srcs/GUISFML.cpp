// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GUINCurses.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/31 14:44:53 by erobert           #+#    #+#             //
//   Updated: 2015/04/10 14:32:56 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GUISFML.hpp"

GUISFML::GUISFML(void):
	_cellSize(10),
	_v(_cellSize, _cellSize),
	_w(_v),
	_a(_cellSize / 2),
	_h(_cellSize / 2 + 2, 4),
	_b(_v)
{
	_f.loadFromFile("data/open_sans_light");
	_t.setFont(_f);
	_t.setCharacterSize(12);
	_t.setColor(sf::Color::White);
	_t.setPosition(_cellSize, _cellSize);
	_input[Game::PAUSE] = 'e';
	_input[Game::RESTART] = 'r';
	_input[Game::EXIT] = 'q';
	_input[Game::UP] = 'w';
	_input[Game::LEFT] = 'a';
	_input[Game::DOWN] = 's';
	_input[Game::RIGHT] = 'd';
	_input[Game::F1] = '1';
	_input[Game::F2] = '2';
	_input[Game::F3] = '3';
}
GUISFML::~GUISFML(void)
{
	_window.close();
}

void							GUISFML::initMap(std::vector<int> const &map,
												 int height, int width)
{
	_tGrass.loadFromFile("data/metal");
	_tGrass.setRepeated(true);
	_map = map;
	_height = height;
	_width = width;
	if (!_window.isOpen())
		_window.create(sf::VideoMode(_width * _cellSize, _height * _cellSize),
					   "Nibbler");
	_a.setFillColor(sf::Color::Red);
	_a.setOutlineColor(sf::Color::Black);
	_a.setOutlineThickness(1);
	_w.setFillColor(sf::Color(50, 50, 50));
	_h.setFillColor(sf::Color(70, 70, 250));
	_h.setOutlineColor(sf::Color::Black);
	_h.setOutlineThickness(1);
	_b.setFillColor(sf::Color(100, 250, 100));
	_b.setOutlineColor(sf::Color::Black);
	_b.setOutlineThickness(1);
}
void							GUISFML::updateDisplay(tNibbler const &tN,
													   int apple, int score)
{
	tNibbler::const_iterator	it(tN.begin());
	tNibbler::const_iterator	ie(tN.end());
	int							i(0);
	std::ostringstream			ss;

	_sGrass.setTextureRect(sf::IntRect(0, 0, _width * _cellSize,
									   _height * _cellSize));
	_sGrass.setTexture(_tGrass);
	_window.draw(_sGrass);
	while (i < _height * _width)
	{
		if (_map[i] == Game::WALL)
		{
			_w.setPosition(i % _width * _cellSize, i / _width * _cellSize);
			_window.draw(_w);
		}
		i++;
	}	
	_a.setPosition(apple % _width * _cellSize, apple / _width * _cellSize);
	_window.draw(_a);
	if (it != ie)
	{
		_h.setPosition(it->x * _cellSize - 2, it->y * _cellSize - 2);
		it++;
	}
	while (it != ie)
	{
		_b.setPosition(it->x * _cellSize, it->y * _cellSize);
		_window.draw(_b);
		it++;
	}
	_window.draw(_h);
	if (tN.front().state == Game::DEAD)
	{
		ss << "Nibbler scoring: " << score;
		_t.setString(ss.str());
		_window.draw(_t);
	}
	_window.display();
}
Game::eEvent					GUISFML::getEvent(void)
{	
	int							i;

	while (_window.pollEvent(_event))
	{
		if (_event.type == sf::Event::Closed)
			return (Game::F1);
		else
		{
			i = 0;
			while (i < Game::E_EVENT)
			{
				if (_input[i] == _event.key.code)
					return (static_cast<Game::eEvent>(i));
				i++;
			}
		}
	}
	return (Game::E_EVENT);
}

GUISFML							*createGUI(void)
{
	return (new GUISFML);
}
void							deleteGUI(GUISFML *gN)
{
	delete gN;
}
