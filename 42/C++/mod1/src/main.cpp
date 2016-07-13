// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/21 17:01:21 by hdezier           #+#    #+#             //
//   Updated: 2015/05/23 18:17:14 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <iostream>
#include "CocoaWin.hpp"
#include "Map.hpp"
#include "Landscape.hpp"

void			exec(char *filename)
{
	CocoaWin	win(1920, 1280);
	Camera		cam;
	Map			m;
	Landscape	l(filename);

	win.init();
	l.init();
	if (l.fail())
		return ;
	m.addObject(&l);
	win.loop(m, cam);
}

int				main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "Enter a filename:\t" << std::endl;
	else
		exec(av[1]);
	return (0);
}
