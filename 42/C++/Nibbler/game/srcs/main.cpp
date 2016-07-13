// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/03 16:38:39 by erobert           #+#    #+#             //
//   Updated: 2015/04/10 14:56:13 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <sstream>
#include "Game.hpp"
#include "Editor.hpp"

int			main(int ac, char **av)
{
	Game	g;
	Editor	e;

	if (ac == 1)
	{
		e.createMap();
		g.setMap(e.map());
		g.gameLoop();
	}
	else if (ac != 3)
		std::cerr << av[0] << " height width" << std::endl;
	else if (g.buildMap(av[1], av[2]))
		g.gameLoop();
	return (0);
}
