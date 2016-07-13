#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base		*generate(void) {
	int		i;

	std::srand(clock());
	i = std::rand() % 3;
	if (i == 0) {
		std::cout << "A created" << std::endl;
		return (new A());
	} else if (i == 1) {
		std::cout << "B created" << std::endl;
		return (new B());
	} else {
		std::cout << "C created" << std::endl;
		return (new C());
	}
}

void		identify_from_pointer(Base *p) {
	if (dynamic_cast<A *>(p) != NULL) {
		std::cout << "I guess you're a class A !" << std::endl;
	} else if (dynamic_cast<B *>(p) != NULL) {
		std::cout << "I guess you're a class B !" << std::endl;
	} else if (dynamic_cast<C *>(p) != NULL) {
		std::cout << "I guess you're a class C !" << std::endl;
	}
	std::cout << *p << std::endl;
}

void		identify_from_reference(Base &p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "I guess you're a class A!" << std::endl;
	} catch (std::exception &e) {
		try {
			(void)dynamic_cast<B &>(p);
			std::cout << "I guess you're a class B!" << std::endl;
		} catch (std::exception &e) {
			try {
				(void)dynamic_cast<C &>(p);
				std::cout << "I guess you're a class C!" << std::endl;
			} catch (std::exception &e) {
				std::cout << "You're not what you look like..." << std::endl;
			}
		}
	}
	std::cout << p << std::endl;
}

int		main(void) {
	Base	*p;

	std::cout << "------------------" << std::endl;
	p = generate();
	std::cout << "From ptr: ";
	identify_from_pointer(p);
	std::cout << "From ref: ";
	identify_from_reference(*p);
	delete p;
	std::cout << "------------------" << std::endl;
	p = generate();
	std::cout << "From ptr: ";
	identify_from_pointer(p);
	std::cout << "From ref: ";
	identify_from_reference(*p);
	delete p;
	std::cout << "------------------" << std::endl;
	p = generate();
	std::cout << "From ptr: ";
	identify_from_pointer(p);
	std::cout << "From ref: ";
	identify_from_reference(*p);
	delete p;
	std::cout << "------------------" << std::endl;
	p = generate();
	std::cout << "From ptr: ";
	identify_from_pointer(p);
	std::cout << "From ref: ";
	identify_from_reference(*p);
	delete p;
	return (0);
}
