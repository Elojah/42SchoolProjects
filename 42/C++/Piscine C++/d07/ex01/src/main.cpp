
#include <string>
#include <iostream>

template<typename T>
void			iter(T *array, unsigned int const len, void (*function)(T &t)) {
	size_t		i(0);

	while (i < len)
		function(array[i++]);
}

template<typename T>
void			stdcout(T &t) {
	std::cout << t;
}

int					main(void) {
	unsigned int	a[] = {1138, 42, 1138};
	std::string		b[] = {"Hello,", " I am", " Max, ", "Mad Max."};

	iter(a, 3, &stdcout);
	std::cout << std::endl;
	iter(b, 4, &stdcout);
	std::cout << std::endl;
}
