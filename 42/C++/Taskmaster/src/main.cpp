// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/10/29 14:09:39 by hdezier           #+#    #+#             //
//   Updated: 2015/10/29 14:26:20 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Master.hpp"
#include <iostream>
#include <fstream>

static void		exec(void)
{
	Master		m;

	m.readConfig("./config/programs.conf");
	m.start();//TO FIX
	// m.loop();
}

int				main(void)
{
	initscr();
	clear();
	noecho();
	cbreak();
	raw();
	keypad(stdscr, TRUE);
	curs_set(0);
	exec();
	endwin();
	return (0);
}
