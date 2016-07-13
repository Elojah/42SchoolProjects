#include "Master.hpp"
#include <iostream>

int		main(void) {


	// int		bg;

	// bg = 0;
	// std::cout << "Choose your graphic library : " << std::endl;
	// std::cout << "[0] Ncurses" << std::endl;
	// std::cout << "[1] FLTK " << std::endl;
	// std::cin >> bg;
	Master	m(0);
	m.createModules(1);
	m.loop();
	return (0);
}
