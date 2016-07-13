#include "RAMInfo.hpp"
#include <sys/sysctl.h>
#include "/usr/include/mach/vm_statistics.h"
#include <iostream>
#include <mach/mach.h>
#include <unistd.h>
#include <sstream>
#include <iomanip>

RAMInfo::RAMInfo(void) {
	_data.title = "RAM info";
	_data.h = 15;
	_data.w = 50;
	_data.y = 12;
	_data.x = 2;
	_data.type = 1;
	_data.graph = true;
}

RAMInfo::RAMInfo(RAMInfo const &src) {
	if (this != &src)
		*this = src;
}

RAMInfo::~RAMInfo(void) {
}

RAMInfo		&RAMInfo::operator=(RAMInfo const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

void	RAMInfo::start(void) {
	;
}

void						RAMInfo::refresh(void) {
	int mib [] = { CTL_HW, HW_MEMSIZE };
	int64_t value = 0;
	size_t length = sizeof(value);

	if(-1 == sysctl(mib, 2, &value, &length, NULL, 0))
		std::cout << "sysctl fail." << std::endl;

	mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
	vm_statistics_data_t vmstat;
	if(KERN_SUCCESS != host_statistics(mach_host_self(), HOST_VM_INFO, (host_info_t)&vmstat, &count))
		std::cout << "host_statistics fail." << std::endl;

	double total = vmstat.wire_count + vmstat.active_count + vmstat.inactive_count + vmstat.free_count;
	double wired = vmstat.wire_count / total;
	double active = vmstat.active_count / total;
	double inactive = vmstat.inactive_count / total;
	double free_ram = vmstat.free_count / total;


	std::stringstream		info;

	info << std::fixed << std::setprecision (2);
	info << "   Active ram: " << active * 100 << "%\n"
		<< "    Inactive ram: " << inactive * 100 << "%\n"
		<< "    Wired ram: " << wired * 100 << "%\n"
		<< "    Freet ram: " << free_ram * 100 << "%\n";

	_data.str_content = info.str();
	addNewValueToGraph(static_cast<unsigned int>(active * 100));
}

void				RAMInfo::addNewValueToGraph(unsigned int percentage) {
	_data.buffer.insert(_data.buffer.begin(), percentage);
	if (_data.buffer.size() > MAX_SAVE) {
		_data.buffer.erase(_data.buffer.end() - 1);
	}
}


IMonitorModule::sData const	&RAMInfo::getData(void) const {
	return (_data);
}

