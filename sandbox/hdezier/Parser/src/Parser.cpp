#include "Parser.hpp"
#include "Entity.hpp"
#include "Gate.hpp"
#include "Equal.hpp"
#include "Comment.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>

Parser::Parser(void) {
}

Parser::~Parser(void) {
	for (tSetTokens::iterator iTok = _globalTokens.begin(); iTok != _globalTokens.end(); ++iTok) {
		delete (*iTok);
	}
}

Parser::Parser(const std::string &filename) {
	std::ifstream		ifs(filename.c_str());

	initGlobalTokens();
	if (ifs.fail()) {
		std::cout << "File is not valid" << std::endl;
		return ;
	}
	exec(ifs);
}

void			Parser::exec(std::ifstream &ifs) {
	std::string			line;
	int					n;
	int					nbToken;
	int					response;
	size_t				mask;
	size_t				numline(0);
	size_t				i;
	size_t				len;

	nbToken = _globalTokens.size();
	mask = (1L << _globalTokens.size()) - 1;
	while (std::getline(ifs, line)) {
		line.push_back('\n');
		len = line.size();
		for (i = 0; i < len; ++i) {
			for (n = 0; n < nbToken; ++n) {
				if (!((mask >> n) & 1)) {
					continue ;
				}
				response = _globalTokens[n]->detect(line[i]);
				if (response == FOUND) {
					continue ;
				} else if (response == COMPLETE) {
					_readTokens.push_back(_globalTokens[n]->getAsRead());
					resetGlobalTokens();
					mask = (1L << _globalTokens.size()) - 1;
					n = -1;
				} else if (response == MASTER) {
					mask = (1L << n);
				} else if (response == NONE) {
					mask &= ~(1L << n);
					if (mask == 0) {
						if (!isSeparator(line[i])) {
							std::cout << "\033[1;31mParsing error on\033[0m:\t" << line[i] << std::endl
										<< "Line:\t" << numline << std::endl
										<< line << std::endl << i << "th char" << std::endl
										<< "Unrecognized symbol." << std::endl;
						} else if (tokenizing()) {
							std::cout << "\033[1;31mParsing error on\033[0m:\t" << line[i] << std::endl
										<< line << std::endl << i << "th char" << std::endl
										<< "Unfinished expression." << std::endl;
						}
						resetGlobalTokens();
						mask = (1L << _globalTokens.size()) - 1;
					}
				}
			}
		}
		numline++;
	}
}

bool			Parser::isSeparator(char const &c) {
	return (c == ' ' || c == '\t' || c == '\n');
}

bool			Parser::tokenizing(void) const {
	for (tSetTokens::const_iterator iTok = _globalTokens.begin(); iTok != _globalTokens.end(); ++iTok) {
		if (!(*iTok)->isEmptyWord()) {
			return (true);
		}
	}
	return (false);
}

void			Parser::resetGlobalTokens(void) {
	for (tSetTokens::iterator iTok = _globalTokens.begin(); iTok != _globalTokens.end(); ++iTok) {
		(*iTok)->reset();
	}
}

void			Parser::initGlobalTokens(void) {
	_globalTokens.push_back(new Entity());
	_globalTokens.push_back(new Gate());
	_globalTokens.push_back(new Equal());
	_globalTokens.push_back(new Comment());
}

void			Parser::display(void) {
	for (tTokens::iterator iTok = _readTokens.begin(); iTok != _readTokens.end(); ++iTok) {
		std::cout << "READ:\t" << iTok->word << " of type " << iTok->type << std::endl;
	}
}
