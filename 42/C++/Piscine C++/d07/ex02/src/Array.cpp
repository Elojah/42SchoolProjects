#include <string>
#include <iostream>
#include "Array.hpp"

int						main(void)
{
	Array<int>			a(3);
	Array<std::string>	b(4);
	int					i(-1);

	std::cout << a.size() << std::endl;
	while (++i < 3)
		std::cout << a[i];
	std::cout << std::endl;
	std::cout << "---------------" << std::endl;
	a[0] = 1138;
	a[1] = 42;
	a[2] = 1138;
	i = -1;
	while (++i < 3)
		std::cout << a[i];
	std::cout << std::endl;
	std::cout << "---------------" << std::endl;
	i = -1;
	while (++i < 4)
		std::cout << b[i];
	std::cout << std::endl;
	std::cout << "---------------" << std::endl;
	b[0] = "Hello, ";
	b[1] = "I am ";
	b[2] = "Max, ";
	b[3] = "Mad Max.";
	i = -1;
	while (++i < 4)
		std::cout << b[i];
	std::cout << std::endl;
	std::cout << "---------------" << std::endl;
	Array<std::string>	c(b);

	i = -1;
	while (++i < 4)
		std::cout << c[i];
	std::cout << std::endl;
	std::cout << "---------------" << std::endl;
	Array<std::string>	e;

	e = b;
	i = -1;
	while (++i < 4)
		std::cout << e[i];
	std::cout << std::endl;
	std::cout << "---------------" << std::endl;
	try {b[5];}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	return (0);
}
