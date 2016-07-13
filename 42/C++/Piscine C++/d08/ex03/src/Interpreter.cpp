#include "Interpreter.hpp"
#include "IInstruction.hpp"
#include "FInstruction.hpp"
#include <iostream>
#include <fstream>

Interpreter::Interpreter(void) {
	for (unsigned int i = 0; i < SIZE_MAX_MEMORY; ++i) {
		_buffer[i] = 0;
	}
	_i = &(_buffer[0]);
}

Interpreter::Interpreter(Interpreter const &src) {
	if (this != &src)
		*this = src;
}

Interpreter::~Interpreter(void) {
	while (!_q.empty()) {
		delete _q.front();
		_q.pop();
	}
}

void			Interpreter::exec(void) {
	while (!_q.empty()) {
		_q.front()->exec(_i);
		_q.pop();
	}
}

void			Interpreter::read(std::string const &filename) {
	std::ifstream		ifs(filename.c_str());
	FInstruction		f;
	IInstruction		*tmp;
	char				c;

	if (ifs.fail()) {
		return ;
	} else {
		while (ifs.get(c)) {
			tmp = f.makeInstruction(c);
			if (tmp != 0x0) {
				_q.push(tmp);
			}
		}
	}
}

Interpreter		&Interpreter::operator=(Interpreter const &rhs) {
	if (this != &rhs) {
		while (!_q.empty()) {
			delete _q.front();
			_q.pop();
		}
		_i = rhs._i;
		_q = rhs._q;
		for (unsigned int i = 0; i < SIZE_MAX_MEMORY; ++i) {
			_buffer[i] = rhs._buffer[i];
		}
	}
	return (*this);
}
