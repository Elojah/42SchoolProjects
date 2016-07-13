/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/12 13:51:22 by leeios            #+#    #+#             */
/*   Updated: 2015/09/06 17:21:00 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "Boot.hpp"

static void		initNCurses(void) {

	initscr();
	clear();
	noecho();
	cbreak();
	raw();
	cbreak();
	keypad(stdscr, TRUE);
}

static void		exec(void) {
	Boot	b;
}

int						main(int ac, char **av) {

	(void)ac;
	(void)av;

	initNCurses();
	exec();

	endwin();
	return (0);
}
