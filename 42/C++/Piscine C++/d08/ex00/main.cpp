#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int								main(void) {
	int							tab0[] = {10, 20, 30, 40};
	std::vector<int>			vct0(tab0 , tab0 + 4);
	int							tab1[] = {10, 20, 30, 40, 10, 40, 50};
	std::list<int>				lst0(tab1 , tab1 + 7);

	std::cout << easyfind(vct0, 30) << std::endl;
	std::cout << easyfind(vct0, 53) << std::endl;
	std::cout << easyfind(lst0, 40) << std::endl;
	return (0);
}
