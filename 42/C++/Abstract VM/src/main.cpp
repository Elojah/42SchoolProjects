/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:46:48 by leeios            #+#    #+#             */
/*   Updated: 2016/05/24 19:15:37 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.h"
#include "Stack.h"

#include <iostream>
#include <fstream>

static void		print_error(eErr err, unsigned int nLine)
{
	if (err != eErr::EXIT)
		std::cerr << "\033[31mERROR\033[30m[\033[0mLINE:\033[34m" << nLine << "\033[30m]\033[0m\t";
	switch(err)
	{
		case (eErr::NONE) :
			std::cerr << "You forgot to explicitly exit !" << std::endl;
		break ;
		case (eErr::EXIT) :
			std::cerr << "Thanks for using me, see ya !" << std::endl;
		break ;
		case (eErr::SYNTAX_ERROR) :
			std::cerr << "Syntax error" << std::endl;
		break ;
		case (eErr::UNKNOWN_INSTR) :
			std::cerr << "Unknown instruction" << std::endl;
		break ;
		case (eErr::INVALID_ARG) :
			std::cerr << "Argument invalid" << std::endl;
		break ;
		case (eErr::OVERFLOW_CALC) :
			std::cerr << "Overflow at calculus" << std::endl;
		break ;
		case (eErr::OVERFLOW_INIT) :
			std::cerr << "Overflow at variable initialization" << std::endl;
		break ;
		case (eErr::UNDERFLOW_CALC) :
			std::cerr << "Underflow at calculus" << std::endl;
		break ;
		case (eErr::POP_ON_EMPTY_STACK) :
			std::cerr << "Pop on empty stack" << std::endl;
		break ;
		case (eErr::DIV_BY_ZERO) :
			std::cerr << "Division by zero" << std::endl;
		break ;
		case (eErr::MISSING_OPERANDS) :
			std::cerr << "Not enough operands for operation" << std::endl;
		break ;
		case (eErr::NO_EXIT_INSTR) :
			std::cerr << "No exit instruction" << std::endl;
		break ;
		case (eErr::ASSERT_FALSE) :
			std::cerr << "Assert returned false" << std::endl;
		break ;
	}
}

static void		exec(void)
{
	Stack	stack;
	Lexer	lexer;
	unsigned int	nLine(1);
	eErr	error;

	while (1)
	{
		std::string		line;
		std::getline(std::cin, line);
		error = lexer.read_line(line, stack, true);
		if (error == eErr::EXIT)
			break ;
		if (error != eErr::NONE)
			print_error(error, nLine);
		++nLine;
	}
	print_error(error, nLine);
}

static void		exec(const char *filename)
{
	Stack	stack;
	Lexer	lexer;
	std::ifstream	ifs(filename);
	std::string		line;
	unsigned int	nLine(1);
	eErr	error;

	while (std::getline(ifs, line))
	{
		error = lexer.read_line(line, stack, false);
		if (error == eErr::EXIT)
			break ;
		if (error != eErr::NONE)
			print_error(error, nLine);
		++nLine;
	}
	print_error(error, nLine);
}

int		main(int ac, char **av)
{
	if (ac == 1)
		exec();
	else if (ac == 2)
		exec(av[1]);
	else
		std::cout << "Usage: ./runner [filename]" << std::endl;
	return (0);
}
