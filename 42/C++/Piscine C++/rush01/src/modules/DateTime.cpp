#include "DateTime.hpp"
#include <sstream>

DateTime::DateTime(void) {
	_data.title = "Date Time";
	_data.h = 5;
	_data.w = 50;
	_data.y = 7;
	_data.x = 2;
	_data.type = 1;
	_data.graph = false;
}

DateTime::DateTime(DateTime const &src) {
	if (this != &src)
		*this = src;
}

DateTime::~DateTime(void) {
}

DateTime		&DateTime::operator=(DateTime const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

void						DateTime::start(void) {
	;
}

void						DateTime::refresh(void) {
	time_t					t(std::time(0));
	struct tm				*now(localtime(&t));
	std::stringstream		date;
	std::stringstream		time;

	_data.str_content.clear();
	date << ' ' << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<<  now->tm_mday;
	_data.str_content = date.str();
	time <<  now->tm_hour << ":";
	if (now->tm_min < 10) {
		time << "0";
	}
	time << now->tm_min << ":";
	if (now->tm_sec < 10) {
		time << "0";
	}
	time << now->tm_sec;
	_data.str_content += "  /  ";
	_data.str_content += time.str();
}

IMonitorModule::sData const	&DateTime::getData(void) const {
	return (_data);
}

