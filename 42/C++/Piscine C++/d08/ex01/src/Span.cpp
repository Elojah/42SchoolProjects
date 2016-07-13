#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <complex>

Span::Span(unsigned int N) :
	_n(N),
	_i(0) {
	_container = new int[_n];
}

Span::Span(Span const &src) {
	if (this != &src)
		*this = src;
}

Span::~Span(void) {
}

Span		&Span::operator=(Span const &rhs) {
	if (this != &rhs) {
		_n = rhs._n;
		_i = rhs._i;
		delete [] _container;
		_container = new int[_n];
		for (unsigned int i = 0; i < _n; ++i) {
			_container[i] = rhs._container[i];
		}
	}
	return (*this);
}

void			Span::addRange(int a, int b) {
	while (a < b) {
		addNumber(a++);
	}
}

void			Span::addNumber(int a) {
	if (_i >= _n) {
		throw std::out_of_range("OutOfRange");
	} else {
		_container[_i++] = a;
	}
}

int				Span::longestSpan(void) {
	if (_i < 2) {
		throw std::logic_error("less than two number");
	} else {
		return (*std::max_element(_container, _container + _i) - *std::min_element(_container, _container + _i));
	}
}

int				Span::shortestSpan(void) {
	int			min;
	int			tmp;

	if (_i < 2) {
		throw std::logic_error("less than two number");
	} else {
		min = std::abs(_container[0] - _container[1]);
		for (unsigned int i = 0; i < _i; ++i) {
			for (unsigned int j = 0; j < _i; ++j) {
				if (i != j && (tmp = std::abs(_container[i] - _container[j])) < min) {
					min = tmp;
				}
			}
		}
	}
	return (min);
}
