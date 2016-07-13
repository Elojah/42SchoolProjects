#include "Converter.hpp"
#include <iostream>

static void		exec(char *s) {
	Converter	c(s);

	std::cout << c;
}

int		main(int ac, char **av) {
	if (ac != 2 || !av[1] || !av[1][0]) {
		std::cout << "Usage:\t./runner STRING" << std::endl;
	} else {
		exec(av[1]);
	}
	return (0);
}
