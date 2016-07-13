#include "Fixed.hpp"
#include <iostream>
#include <math.h>

int const	Fixed::_nbBits = 8;

Fixed::Fixed(void) :
	_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	_value = src.getRawBits();
}

Fixed::Fixed(int const value) {
	std::cout << "Int constructor called" << std::endl;
	_value = value << _nbBits;
}

Fixed::Fixed(float const value) {
	std::cout << "Float constructor called" << std::endl;
	_value = (int)(roundf(value * (1 << _nbBits)));
}


Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed		&Fixed::operator=(Fixed const &rhs) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		_value = rhs.getRawBits();
	return (*this);
}

int			Fixed::toInt(void) const {
	return ((_value) >> _nbBits);
}

float		Fixed::toFloat(void) const {
	return (((float)(_value)) / (1 << _nbBits));
}

void		Fixed::setRawBits(int const raw) {
	_value = raw;
}

int			Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

std::ostream&	operator<<(std::ostream& stream, const Fixed& f) {
	stream << f.toFloat();
	return (stream);
}
