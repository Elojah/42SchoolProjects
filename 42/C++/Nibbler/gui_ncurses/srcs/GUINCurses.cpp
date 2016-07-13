// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GUINCurses.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/31 14:44:53 by erobert           #+#    #+#             //
//   Updated: 2015/04/10 15:37:25 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GUINCurses.hpp"

GUINCurses::GUINCurses(void):
	_w(initscr())
{
	noecho();
	keypad(_w, 1);
	curs_set(0);
	start_color();
	init_pair(Game::APPLE, COLOR_RED, COLOR_BLACK);
	init_pair(Game::HEAD, COLOR_BLUE, COLOR_BLACK);
	init_pair(Game::BODY, COLOR_GREEN, COLOR_BLACK);
	_input[Game::F1] = '1';
	_input[Game::F2] = '2';
	_input[Game::F3] = '3';
	_input[Game::PAUSE] = 'e';
	_input[Game::RESTART] = 'r';
	_input[Game::EXIT] = 'q';
	_input[Game::UP] = 'w';
	_input[Game::LEFT] = 'a';
	_input[Game::DOWN] = 's';
	_input[Game::RIGHT] = 'd';
}
GUINCurses::~GUINCurses(void)
{
	endwin();
}

void							GUINCurses::initMap(std::vector<int> const &map,
													int height, int width)
{
	int							i(0);

	_map = map;
	_height = height;
	_width = width;
	while (i < _height * _width)
	{
		if (_map[i])
			mvaddch(i / _width + 2, i % _width, 'X');
		else
			mvaddch(i / _width + 2, i % _width, ' ');
		i++;
	}
	wrefresh(stdscr);
}
void							GUINCurses::updateDisplay(tNibbler const &tN,
														  int apple, int score)
{
	tNibbler::const_iterator	it(tN.begin());
	tNibbler::const_iterator	ie(tN.end());
	int							i(0);

	mvwprintw(stdscr, 0, 0, "Nibbler: wasd, e pause, r restart, q quit");
	mvwprintw(stdscr, 1, 0, "Fat bastard score: %d", score);
	while (i < _height * _width)
	{
		if (_map[i] == Game::BODY || _map[i] == Game::HEAD)
			mvaddch(i / _width + 2, i % _width, ' ');
		i++;
	}
	attron(COLOR_PAIR(Game::APPLE));
	mvaddch(apple / _width + 2, apple % _width, '*');
	attroff(COLOR_PAIR(Game::APPLE));
	attron(COLOR_PAIR(Game::HEAD));
	if (it != ie)
	{
		if (_map[it->x + it->y * _width] != Game::WALL)
		{
			_map[it->x + it->y * _width] = Game::HEAD;
			mvaddch(it->y + 2, it->x, 'O');
		}
	}
	it++;
	attroff(COLOR_PAIR(Game::HEAD));
	attron(COLOR_PAIR(Game::BODY));
	while (it != ie)
	{
		_map[it->x + it->y * _width] = Game::BODY;
		mvaddch(it->y + 2, it->x, 'o');
		it++;
	}
	attroff(COLOR_PAIR(Game::BODY));
	wrefresh(stdscr);
}
Game::eEvent					GUINCurses::getEvent(void)
{
	struct timeval				tv;
	fd_set						fds;
	int							input;
	int							i(0);

	tv.tv_sec = 0;
	tv.tv_usec = 0;
	FD_ZERO(&fds);
	FD_SET(STDIN_FILENO, &fds);
	select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
	if (FD_ISSET(STDIN_FILENO, &fds))
	{
		input = getch();
		while (i < Game::E_EVENT)
		{
			if (_input[i] == input)
				return (static_cast<Game::eEvent>(i));
			i++;
		}
	}
	return (Game::E_EVENT);
}

GUINCurses						*createGUI(void)
{
	return (new GUINCurses);
}
void							deleteGUI(GUINCurses *gN)
{
	delete gN;
}
