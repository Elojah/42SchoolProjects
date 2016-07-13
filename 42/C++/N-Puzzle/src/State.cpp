// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   State.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/20 11:41:37 by erobert           #+#    #+#             //
//   Updated: 2015/03/20 13:34:19 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "State.hpp"

State::State(void)
{
	_id = id++;
}
State::State(State const &s)
{
	(*this) = s;
}
State::State(size_t size, std::array<int, MAX_CASE> const &map):
	_size(size),
	_value(NONE_SET),
	_previous(0)
{
	size_t						i;

	_id = id++;
	for (i = 0; i < _size * _size; ++i)
	{
		_map[i] = map[i];
		if (_map[i] == EMPTY_VALUE)
			_empty = i;
	}
	_depth = 0;
}
State::State(State const &s, char dir)
{
	_id = id++;
	_map = s.getMap();
	_value = NONE_SET;
	_size = s.getSize();
	_empty = s.getEmpty();
	_depth = s.getDepth() + 1;
	_previous = s.getId();
	if (dir >= 0)
		move(dir);
}
State::~State(void) {}

void							State::finalFillArray(void)
{
	size_t						i;
	size_t						j(0);
	size_t						n(2);

	for (i = 0; i < _size * _size; ++i)
		_map[i] = EMPTY_VALUE;
	i = 0;
	_map[0] = 1;
	while (n < _size * _size)
	{
		while (j < _size - 1 && _map[i * _size + j + 1] == EMPTY_VALUE)
			_map[i * _size + ++j] = n++;
		while (i < _size - 1 && _map[(i + 1) * _size + j] == EMPTY_VALUE)
			_map[++i * _size + j] = n++;
		while (j > 0 && _map[i * _size + j - 1] == EMPTY_VALUE)
			_map[i * _size + --j] = n++;
		while (i > 0 && _map[(i - 1) * _size + j] == EMPTY_VALUE)
			_map[--i * _size + j] = n++;
	}
	if (_size % 2 == 0)
		_map[_size / 2 * _size + _size / 2 - 1] = EMPTY_VALUE;
	i = 0;
	while (i < _size * _size)
	{
		if (_map[i] == EMPTY_VALUE)
		{
			_empty = i;
			return ;
		}
		i++;
	}
}

size_t							State::getId(void) const
{
	return(_id);
}
size_t							State::getDepth(void) const
{
	return(_depth);
}
void							State::setDepth(unsigned int depth)
{
	_depth = depth;
}
State::tArray const				&State::getMap(void) const
{
	return (_map);
}
size_t							State::getSize(void) const
{
	return (_size);
}
size_t							State::getPrevious(void) const
{
	return (_previous);
}
void							State::setPrevious(size_t s)
{
	_previous = s;
}
int								State::getValue(void) const
{
	return(_value);
}
void							State::setValue(int val)
{
	_value = val;
}
size_t							State::getEmpty(void) const
{
	return (_empty);
}

void							State::move(char const dir)
{
	int							tmp(0);
	int							inc(0);

	inc = dir < 2 ? 1 : _size;
	inc *= dir % 2 ? 1 : -1;
	tmp = _map[_empty];
	_map[_empty] = _map[_empty + inc];
	_map[_empty + inc] = tmp;
	_empty += inc;
}

State							&State::operator=(State const &s)
{
	if (this != &s)
	{
		_id = s.getId();
		_map = s.getMap();
		_value = s.getValue();
		_size = s.getSize();
		_empty = s.getEmpty();
		_depth = s.getDepth();
		_previous = s.getPrevious();
	}
	return (*this);
}
bool							State::operator==(State const &s) const
{
	size_t						i;
	size_t						sEmpty(s.getEmpty());
	int64_t const				*a;
	int64_t const				*b;

	if (sEmpty != _empty)
		return (false);
	a = reinterpret_cast<int64_t const *>(s.getMap().data());
	b = reinterpret_cast<int64_t const *>(_map.data());
	for (i = 0; i < _size * _size / 2; i++)
	{
		if (a[i] != b[i])
			return (false);
	}
	return (s.getMap()[_size * _size - 1] == _map[_size * _size - 1]);
}

void							State::display(void) const
{
	size_t						i;
	size_t						j;

	for (i = 0; i < _size; ++i)
		std::cout << "_________";
	std::cout << std::endl;
	for (i = 0; i < _size; ++i)
	{
		std::cout << '|';
		for (j = 0; j < _size; ++j)
		{
			if (_map[i * _size + j] != EMPTY_VALUE)
				std::cout << _map[i * _size + j] << '\t';
			else
				std::cout << " \t";
		}
		std::cout << '|' << std::endl;
	}
	for (i = 0; i < _size; ++i)
		std::cout << "_________";
	std::cout << std::endl;
}

size_t							State::id = 1;
