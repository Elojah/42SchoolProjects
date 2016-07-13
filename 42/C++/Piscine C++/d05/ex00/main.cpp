#include "Bureaucrat.hpp"
#include <iostream>

int		main(void) {
	try {
		Bureaucrat	a("Blabla", 3);
		std::cout << a << std::endl;
		Bureaucrat	b("Blabla", -5);
		std::cout << b << std::endl;
		Bureaucrat	c("Blabla", 80);
		std::cout << c << std::endl;
		Bureaucrat	d("Blabla", 800);
		std::cout << d << std::endl;
		++a;
		++a;
		std::cout << a << std::endl;
		++a;
		++a;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
