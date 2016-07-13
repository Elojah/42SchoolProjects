#include "Pony.hpp"
#include <iostream>

static void		ponyOnTheHeap(void)
{
	Pony	*p;

	std::cout << "Pony ready to go on the heap" << std::endl;
	p = new Pony();
	std::cout << "Created: Pony on the heap" << std::endl;
	std::cout << "Pony ready to be deleted from heap" << std::endl;
	delete p;
	std::cout << "Deleted: Pony on the heap" << std::endl;
}

static void		ponyOnTheStack(void)
{
	Pony	p;

	std::cout << "Created: Pony on the stack" << std::endl;
}

int				main(void)
{
	ponyOnTheStack();
	ponyOnTheHeap();
	return (0);
}
