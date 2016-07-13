#include "OSInfo.hpp"

OSInfo::OSInfo(void) {
	_data.title = "OS info";
	_data.h = 5;
	_data.w = 50;
	_data.y = 2;
	_data.x = 52;
	_data.type = 1;
	_data.graph = false;
}

OSInfo::OSInfo(OSInfo const &src) {
	if (this != &src)
		*this = src;
}

OSInfo::~OSInfo(void) {
}

OSInfo		&OSInfo::operator=(OSInfo const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

void	OSInfo::start(void) {
	FILE		*pipe(popen("uname", "r"));
	char		buffer[128];
	std::string	os("");
	std::string	version("");

	if (pipe)
	{
		while(!feof(pipe))
		{
			if(fgets(buffer, 128, pipe))
				os += buffer;
		}
		pclose(pipe);
		_data.str_content += " OS: " + os;
		_data.str_content.pop_back();
		_data.str_content += "  /  ";
	}
	pipe = popen("uname -r", "r");
	if (pipe)
	{
		while(!feof(pipe))
		{
			if(fgets(buffer, 128, pipe))
				version += buffer;
		}
		pclose(pipe);
		_data.str_content += " Version: " + version;
		_data.str_content.pop_back();
	}
}

void						OSInfo::refresh(void) {
	;
}

IMonitorModule::sData const	&OSInfo::getData(void) const {
	return (_data);
}


