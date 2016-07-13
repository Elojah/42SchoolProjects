#include "Converter.hpp"
#include <iostream>
#include <cstdlib>

Converter::Converter(char const *av) :
	_str(av) {
}

Converter::Converter(Converter const &src) {
	if (this != &src)
		*this = src;
}

Converter::~Converter(void) {
}

Converter		&Converter::operator=(Converter const &rhs) {
	if (this != &rhs) {
		_str = rhs._str;
	}
	return (*this);
}

void		Converter::toChar(std::ostream &stream) const {
	stream << static_cast<char>(static_cast<int>(std::strtol(_str.c_str(), NULL, 10))) << std::endl;
}
void		Converter::toInt(std::ostream &stream) const {
	stream << (static_cast<int>(std::strtol(_str.c_str(), NULL, 10))) << std::endl;
}
void		Converter::toFloat(std::ostream &stream) const {
	stream << (static_cast<float>(std::strtof(_str.c_str(), NULL))) << 'f' << std::endl;
}
void		Converter::toDouble(std::ostream &stream) const {
	stream << (static_cast<double>(std::strtod(_str.c_str(), NULL))) << std::endl;
}

std::ostream&	operator<<(std::ostream& stream, Converter const &s) {
	stream << "char: ";
	s.toChar(stream);
	stream << "int: ";
	s.toInt(stream);
	stream << "float: ";
	s.toFloat(stream);
	stream << "double: ";
	s.toDouble(stream);
	return (stream);
}
