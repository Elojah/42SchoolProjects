// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Editor.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 14:44:04 by erobert           #+#    #+#             //
//   Updated: 2015/04/10 15:49:10 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Editor.hpp"

Editor::Editor(void):
	_map(MAX_SIZE * MAX_SIZE)
{}
Editor::~Editor(void) {}

std::vector<int> const	&Editor::map(void) const
{
	return (_map);
}

void					Editor::createMap(void)
{
	WINDOW				*window;
	int					input;
	int					i(0);

	window = initscr();
	noecho();
	keypad(window, 1);
	curs_set(0);
	start_color();
	mvwprintw(stdscr, 0, 0, "Editor: wasd, e build wall, q quit");
	mvwprintw(stdscr, 1, 0, "                                  ");
	mvwprintw(stdscr, 1, 0, "        %d;%d", i % MAX_SIZE, i / MAX_SIZE);
	mvaddch(2, 0, '_');
	input = getch();
	i = 0;
	while (input != 'q')
	{
		if (input == 'w')
		{
			removeCursor(i);
			i = (i > MAX_SIZE - 1? i - MAX_SIZE : i + MAX_SIZE * (MAX_SIZE - 1));
			addCursor(i);
		}
		else if (input == 'd')
		{
			removeCursor(i);
			i = (i + 1) % (MAX_SIZE * MAX_SIZE);
			addCursor(i);
		}
		else if (input == 's')
		{
			removeCursor(i);
			i = (i / MAX_SIZE < MAX_SIZE - 1 ? i + MAX_SIZE : i % MAX_SIZE);
			addCursor(i);
		}
		else if (input == 'a')
		{
			removeCursor(i);
			i = (i > 0 ? i - 1 : MAX_SIZE - 1);
			addCursor(i);
		}
		else if (input == 'e')
		{
			mvaddch(i / MAX_SIZE + 2, i % MAX_SIZE, 'X');
			_map[i] = 1;
			i = (i + 1) % (MAX_SIZE * MAX_SIZE);
			addCursor(i);
		}
		mvwprintw(stdscr, 1, 0, "                                  ");
		mvwprintw(stdscr, 1, 0, "        %d;%d", i % MAX_SIZE, i / MAX_SIZE);
		input = getch();
	}
	endwin();
}

void					Editor::removeCursor(int i)
{
	if (_map[i])
		mvaddch(i / MAX_SIZE + 2, i % MAX_SIZE, 'X');
	else
		mvaddch(i / MAX_SIZE + 2, i % MAX_SIZE, ' ');
}
void					Editor::addCursor(int i)
{
	if (_map[i])
			mvaddch(i / MAX_SIZE + 2, i % MAX_SIZE, 'T');
	else
		mvaddch(i / MAX_SIZE + 2, i % MAX_SIZE, '_');
}
