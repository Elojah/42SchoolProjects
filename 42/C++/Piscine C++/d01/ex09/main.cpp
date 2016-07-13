#include "Logger.hpp"

int		main(void) {
	Logger		l("file.test");

	l.log("console", "My super message");
	l.log("file", "My super message");
	return (0);
}
