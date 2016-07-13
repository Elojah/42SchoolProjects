// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Exec.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/11 13:57:46 by erobert           #+#    #+#             //
//   Updated: 2015/03/13 20:16:21 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Exec.hpp"

Exec::Exec(void):
	_good(true),
	_name(""),
	_size(0),
	_heuristic(15)
{
	_arg[0] = "-f";
	_arg[1] = "-h";
	_arg[2] = "-s";
}
Exec::~Exec(void) {}

void					Exec::errorAv(void)
{
	std::cerr << _name
			  << ": [-f file_name | -s size] [-h heuristic]" << std::endl
			  << "heuristic (binary mask):" << std::endl
			  << "1 Manhatan" << std::endl
			  << "2 NTiles" << std::endl
			  << "4 Hamming" << std::endl
			  << "8 LinearConflict" << std::endl;
}
void					Exec::parsePuzzle(char *file)
{
	std::ifstream		ifs(file);
	Lexer				l;
	Parser				p;

	if (ifs.good())
	{
		p.parse(l.tokenize(ifs));
		if (p.good())
		{
			_vector = p.getVector();
			_size = p.getSize();
			ifs.close();
		}
		else
			_good = false;
	}
	else
	{
		std::cerr << _name << ": " << file << ": no such file" << std::endl;
		_good = false;
	}
}
void					Exec::parseHeuristic(char *heuristic)
{
	std::stringstream	ss;
	size_t				i(0);

	ss << heuristic;
	while (i < strlen(heuristic))
	{
		if (!isdigit(heuristic[i++]))
		{
			_good = false;
			return ;
		}
	}
	ss >> _heuristic;
	if (_heuristic < 1 || _heuristic > 15)
		_good = false;
}
void					Exec::parseSize(char *size)
{
	std::stringstream	ss;
	size_t				i(0);
	std::random_device	rd;
	std::mt19937		g(rd());

	ss << size;
	ss >> _size;
	if (_size < 3 || _size > MAX_SIZE)
	{
		_size = 0;
		_good = false;
		return ;
	}
	while (i < _size * _size)
		_vector.push_back(i++);
	std::shuffle(_vector.begin(), _vector.end(), g);
}

void					Exec::parseAv(int ac, char **av)
{
	int					i(1);

	_name = av[0];
	while (i < ac)
	{
		if (!_arg[0].compare(av[i]) && i + 1 < ac && !_size)
			parsePuzzle(av[++i]);
		else if (!_arg[1].compare(av[i]) && i + 1 < ac)
			parseHeuristic(av[++i]);
		else if (!_arg[2].compare(av[i]) && i + 1 < ac && !_size)
			parseSize(av[++i]);
		else
			_good = false;
		i++;
	}
	if (_size < 3)
		_good = false;
}

void					Exec::solvePuzzle(void)
{
	Puzzle				*p;

	if (!_good)
		return (errorAv());
	p = new Puzzle(_vector, _size, _heuristic);
	if (p->isSolvable())
	{
		if (p->solve())
			p->printResult();
	}
	else
		std::cout << "Puzzle is not solvable." << std::endl;
	delete p;
}
