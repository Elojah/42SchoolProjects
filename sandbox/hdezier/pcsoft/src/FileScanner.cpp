#include "FileScanner.hpp"
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

FileScanner::FileScanner(void) {
}

FileScanner::FileScanner(FileScanner const &src) {
	if (this != &src)
		*this = src;
}

FileScanner::~FileScanner(void) {
}

FileScanner		&FileScanner::operator=(FileScanner const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

bool			FileScanner::isScannableFile(char const *name) {
	static const char			extension[] = ".txt";
	static const unsigned int	lenExt = 4;
	unsigned int				len;

	if (!name || (len = strlen(name)) < lenExt) {
		return (false);
	}
	for (unsigned int i = 0; i < lenExt; ++i) {
		if (name[len - lenExt + i] != extension[i]) {
			return (false);
		}
	}
	return (true);
}

void			FileScanner::scanChildren(char *path) {
	DIR				*dir;
	struct dirent	*ent;

	std::cout << "Directory" << std::endl;
	if (access(path, R_OK | X_OK) == -1) {
		return ;
	}
	if ((dir = opendir(path)) != NULL) {
		while ((ent = readdir(dir)) != NULL) {
			if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, "..")) {
				continue ;
			}
			scan(&((std::string(path) + '/' + ent->d_name)[0]));/*LEAKS*/
		}
	}
	closedir(dir);
}

void			FileScanner::scanFile(char *filename) {
	static const char	separators[] = " \t";
	std::string			line;
	std::ifstream		ifs;
	char				*pch;

	std::cout << "Scannable File" << std::endl;
	ifs.open(filename);
	if (ifs.fail()) {
		return ;
	}
	while (std::getline(ifs, line)) {
		pch = strtok(&(line[0]), separators);
		while (pch != NULL) {
			_t.addValue(std::string(pch), filename);
			pch = strtok (NULL, separators);
		}
	}
	ifs.close();
}

void			FileScanner::scan(char *path) {
	struct stat		pathStat;

	if (!path) {
		return ;
	}
	std::cout << "Scanning:\t" << path << " ... ";
	lstat(path, &pathStat);
	if ((pathStat.st_mode & S_IRUSR) == 0) {
		std::cout << "Read access refused" << std::endl;
		return ;
	}
	if (S_ISDIR(pathStat.st_mode)) {
		scanChildren(path);
	} else if (S_ISREG(pathStat.st_mode) && isScannableFile(path)) {
		scanFile(path);
	} else {
		std::cout << "Not scannable file or dir" << std::endl;
	}
}

void			FileScanner::ask(void) {
	std::string	input;

	while (true) {
		std::cout << "Search(q for quit): ";
		std::cin >> input;
		if (std::cin.eof() == 1) {
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		if (strcmp(input.c_str(), "q") == 0) {
			break ;
		} else {
			_t.searchValue(input);
		}
	}
}
