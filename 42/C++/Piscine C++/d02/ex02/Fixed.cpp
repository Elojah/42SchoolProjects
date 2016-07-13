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
	std::cout << "Assignation Fixed::operator called" << std::endl;
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

bool			Fixed::operator>(Fixed const &rhs) const {
	return (_value > rhs.getRawBits());
}

bool			Fixed::operator<(Fixed const &rhs) const {
	return (_value < rhs.getRawBits());
}

bool			Fixed::operator>=(Fixed const &rhs) const {
	return (_value >= rhs.getRawBits());
}

bool			Fixed::operator<=(Fixed const &rhs) const {
	return (_value <= rhs.getRawBits());
}

bool			Fixed::operator==(Fixed const &rhs) const {
	return (_value == rhs.getRawBits());
}

bool			Fixed::operator!=(Fixed const &rhs) const {
	return (_value != rhs.getRawBits());
}


Fixed			Fixed::operator+(Fixed const &rhs) const {
	Fixed		f;

	f.setRawBits(_value + rhs.getRawBits());
	return (f);
}

Fixed			Fixed::operator-(Fixed const &rhs) const {
	Fixed		f;

	f.setRawBits(_value - rhs.getRawBits());
	return (f);
}

Fixed			Fixed::operator*(Fixed const &rhs) const {
	int			tmp;
	Fixed		f;

	tmp = _value * rhs.getRawBits();
	f.setRawBits((tmp + ((tmp & 1 << (_nbBits - 1)) << 1)) >> _nbBits);
	return (f);
}

Fixed			Fixed::operator/(Fixed const &rhs) const {
	Fixed		f;
	if (rhs.getRawBits() == 0)
	{
		std::cerr << "Fixed point divide by 0" << std::endl;
		return (rhs);
	}
	f.setRawBits((_value << _nbBits) / rhs.getRawBits());
	return (f);
}


Fixed			Fixed::operator++(int) {
	Fixed		f;

	f.setRawBits(_value++);
	return (f);
}

Fixed			&Fixed::operator++(void) {
	_value++;
	return (*this);
}

Fixed			Fixed::operator--(int) {
	Fixed		f;

	f.setRawBits(_value--);
	return (f);
}

Fixed			&Fixed::operator--(void) {
	_value--;
	return (*this);
}

Fixed	&Fixed::min(Fixed const &a, Fixed const &b) {
	if (a > b)
		return ((Fixed &)(b));
	else
		return ((Fixed &)(a));
}
Fixed	&Fixed::max(Fixed const &a, Fixed const &b) {
	if (a > b)
		return ((Fixed &)(a));
	else
		return ((Fixed &)(b));
}


std::ostream&	operator<<(std::ostream& stream, const Fixed& f) {
	stream << f.toFloat();
	return (stream);
}
