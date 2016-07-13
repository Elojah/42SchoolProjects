#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>
# include <stdexcept>

template<typename T = void *>
class Array
{
private:
	T				*_a;
	unsigned int	_size;
public:
	Array<T>(void):
		_size(0) {
		_a = new T[0];
	}

	Array<T>(Array<T> const &a) {
		unsigned int	i(0);

		_size = a.size();
		_a = new T[_size];
		while (i < _size) {
			_a[i] = a[i];
			i++;
		}
	}

	Array<T>(unsigned int ui):
		_size(ui) {
		_a = new T[ui];
	}

	~Array<T>(void) {
		if (_a) {
			delete [] _a;
		}
	}

	Array<T>			&operator=(Array<T> const &a) {
		unsigned int	i(-1);

		_size = a.size();
		delete [] _a;
		_a = new T[_size];
		while (++i < _size) {
			_a[i] = a[i];
		}
		return (*this);
	}

	T					&operator[](unsigned int ui) const {
		if (ui >= _size) {
			throw std::out_of_range("out of range");
		}
		return (_a[ui]);
	}

	unsigned int		size(void) const {
		return (_size);
	}
};

#endif
