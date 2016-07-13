#include <string>
#include <iostream>

int		main(void) {
	std::string		s = "HI THIS IS BRAIN";
	std::string		*sPointer = &s;
	std::string		&sRef = s;

	std::cout << "Original string:\t" << s << std::endl;
	std::cout << "Pointer string:\t\t" << *sPointer << std::endl;
	std::cout << "Reference string:\t" << sRef << std::endl;
	return (0);
}
