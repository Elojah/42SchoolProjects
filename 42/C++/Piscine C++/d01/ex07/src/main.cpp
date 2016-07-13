#include "Replace.hpp"
#include <string>
#include <iostream>

static void		exec(char **av) {
	Replace		r;

	r.exec(std::string(av[1]), std::string(av[2]), std::string(av[3]));
}

int				main(int ac, char **av) {
	if (ac != 4)
		std::cout << "Usage:\t ./replace filename s1 s2" << std::endl;
	else
		exec(av);
	return (0);
}
