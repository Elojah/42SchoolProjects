#include "FInstruction.hpp"
#include "IInstruction.hpp"
#include "Incp.hpp"
#include "Decp.hpp"
#include "Inc.hpp"
#include "Dec.hpp"
#include "Out.hpp"
#include "In.hpp"
#include "LoopBegin.hpp"
#include "LoopEnd.hpp"

FInstruction::FInstruction(void) {
}

FInstruction::FInstruction(FInstruction const &src) {
	if (this != &src)
		*this = src;
}

FInstruction::~FInstruction(void) {
}

FInstruction		&FInstruction::operator=(FInstruction const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

IInstruction													*FInstruction::makeIncp(void) const {
	return (new Incp());
}
IInstruction													*FInstruction::makeDecp(void) const {
	return (new Decp());
}
IInstruction													*FInstruction::makeInc(void) const {
	return (new Inc());
}
IInstruction													*FInstruction::makeDec(void) const {
	return (new Dec());
}
IInstruction													*FInstruction::makeOut(void) const {
	return (new Out());
}
IInstruction													*FInstruction::makeIn(void) const {
	return (new In());
}
IInstruction													*FInstruction::makeLoopBegin(void) const {
	return (new LoopBegin());
}
IInstruction													*FInstruction::makeLoopEnd(void) const {
	return (new LoopEnd());
}


IInstruction													*FInstruction::makeInstruction(char c) {
	std::map<char, maker>::const_iterator	it;

	it = _map.find(c);
	if (it == _map.end()) {
		return (0x0);
	} else {
		return ((this->*(it->second))());
	}
}

std::map<char, IInstruction*(FInstruction::*)(void) const>			FInstruction::createInstructionsMap(void) {
	std::map<char, maker>			result;

	result['>'] = &FInstruction::makeIncp;
	result['<'] = &FInstruction::makeDecp;
	result['+'] = &FInstruction::makeInc;
	result['-'] = &FInstruction::makeDec;
	result['.'] = &FInstruction::makeOut;
	result[','] = &FInstruction::makeIn;
	result['['] = &FInstruction::makeLoopBegin;
	result[']'] = &FInstruction::makeLoopEnd;
	return (result);
}
const std::map<char, IInstruction*(FInstruction::*)(void) const>		FInstruction::_map = createInstructionsMap();
