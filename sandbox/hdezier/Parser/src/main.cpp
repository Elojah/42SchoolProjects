#include "Parser.hpp"
#include "Lexer.hpp"
#include <iostream>
#include <string>

void			exec(const std::string &s) {
	Parser	p(s);
	Lexer	l;

	p.display();
	l.exec(p);
}

int			main(int ac, char **av) {

	if (ac != 2) {
		std::cout << "Usage: [path file to parse]" << std::endl;
		return (0);
	}
	exec(av[1]);
	return (0);
}
