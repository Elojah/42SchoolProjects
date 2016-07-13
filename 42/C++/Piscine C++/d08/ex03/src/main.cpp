#include "Interpreter.hpp"
#include <string>

int			main(void) {
	Interpreter	i;

	i.read("./test/test.bf");
	i.exec();
	return (0);
}
