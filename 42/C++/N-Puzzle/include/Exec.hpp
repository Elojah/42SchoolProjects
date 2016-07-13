// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Exec.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/11 13:57:37 by erobert           #+#    #+#             //
//   Updated: 2015/03/20 11:36:36 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef EXEC_H
# define EXEC_H

# include <algorithm>
# include <fstream>
# include <iostream>
# include <random>
# include <string>
# include <string.h>
# include <vector>
# include "Lexer.hpp"
# include "Parser.hpp"
# include "Puzzle.hpp"

class Exec
{
public:
	Exec(void);
	~Exec(void);

	void				parseAv(int ac, char **av);
	void				solvePuzzle(void);
private:
	bool				_good;
	std::string			_name;
	std::string			_arg[3];
	std::vector<int>	_vector;
	size_t				_size;
	int					_heuristic;

	Exec(Exec const &e);

	Exec				&operator=(Exec const &e);

	void				errorAv(void);
	void				parsePuzzle(char *file);
	void				parseHeuristic(char *heuristic);
	void				parseSize(char *size);
};

#endif
