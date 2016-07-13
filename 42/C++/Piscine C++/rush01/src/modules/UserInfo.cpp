#include "UserInfo.hpp"

UserInfo::UserInfo(void) {
	_data.title = "User info";
	_data.h = 5;
	_data.w = 50;
	_data.y = 2;
	_data.x = 2;
	_data.type = 1;
	_data.graph = false;
}

UserInfo::UserInfo(UserInfo const &src) {
	if (this != &src)
		*this = src;
}

UserInfo::~UserInfo(void) {
}

UserInfo		&UserInfo::operator=(UserInfo const &rhs) {
	if (this != &rhs) {
		_data = rhs._data;
	}
	return (*this);
}

void			UserInfo::start(void) {
	FILE		*pipe(popen("hostname", "r"));
	char		buffer[128];
	std::string	hostname("");
	std::string	username("");

	if (pipe) {
		while(!feof(pipe)) {
			if(fgets(buffer, 128, pipe))
				hostname += buffer;
		}
		pclose(pipe);
		_data.str_content += " Host: " + hostname;
		_data.str_content.pop_back();
		_data.str_content += "  /  ";
	}
	pipe = popen("id -u -n", "r");
	if (pipe) {
		while(!feof(pipe)) {
			if(fgets(buffer, 128, pipe))
				username += buffer;
		}
		pclose(pipe);
		_data.str_content += "User: " + username;
		_data.str_content.pop_back();
	}
}

void			UserInfo::refresh(void) {
	;
}

IMonitorModule::sData const		&UserInfo::getData(void) const {
	return (_data);
}
