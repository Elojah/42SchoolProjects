#include "Logger.hpp"
#include <fstream>
#include <iostream>
#include <ctime>

Logger::Logger(std::string const &filename) : _filename(std::string(filename)) {
	_logDest[0].callback = &Logger::logToConsole;
	_logDest[0].s = "console";
	_logDest[1].callback = &Logger::logToFile;
	_logDest[1].s = "file";
}
Logger::~Logger(void) {
}

void			Logger::log(std::string const &dest, std::string const &message) const {
	std::string		formattedMessage(makeLogEntry(message));

	for (std::size_t i = 0; i < 2; ++i) {
		if (dest == _logDest[i].s)
			(this->*_logDest[i].callback)(formattedMessage);
	}
}


void			Logger::logToConsole(std::string const &log) const {
	std::cout << log << std::endl;
}
void	Logger::logToFile(std::string const &log) const {
	std::ofstream		ofs(_filename.c_str(), std::ofstream::app);

	if (ofs.fail())
		return ;
	ofs << log << std::endl;
	ofs.close();
}
std::string		Logger::makeLogEntry(std::string const &message) const {
	time_t		rawtime;
	struct tm	*timeinfo;
	char		buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
	return (std::string("[") + buffer + "]:" + message);
}
