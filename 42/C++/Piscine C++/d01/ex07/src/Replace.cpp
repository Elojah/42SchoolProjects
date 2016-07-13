#include "Replace.hpp"
#include <iostream>
#include <fstream>

Replace::Replace(void) {
}

Replace::~Replace(void) {
}

void	Replace::exec(const std::string &filename, const std::string &s1, const std::string &s2) {
	std::ifstream	ifs(filename.c_str());
	std::ofstream	ofs((std::string(".replace").insert(0, filename)).c_str());
	std::string		line;
	std::size_t		found;
	std::size_t		len(s1.length());

	if (s1.empty() || s2.empty()) {
		std::cout << "ERROR:\tStrings are not correct." << std::endl;
	}
	if (ifs.fail()) {
		std::cout << "ERROR:\tFile " << filename << " doesn't exist." << std::endl;
		return ;
	}
	while (std::getline(ifs, line)) {
		found = 0;
		while ((found = line.find(s1, found)) != std::string::npos) {
			line.replace(found, len, s2);
			found += len + 1;
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
}
