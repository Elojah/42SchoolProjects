/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 00:45:43 by leeios            #+#    #+#             */
/*   Updated: 2016/06/01 02:02:05 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "krpsim.h"

#include "FileReader.h"
#include "Lexer.h"
#include "Parser.h"

#include <iostream>
#include <stdlib.h>

/**
 * @brief Return main value
 * @details in: local err => out main err
 *
 * @param err local err
 * @return main err
 */
static int		ret_err(const e_err err)
{
	static const char * const	err_msg[] =
	{
		"NONE",
		"Usage: ./krpsim [filename]",
		"Unrecognized error"
	};

	if (err == e_err::NONE)
		return (EXIT_SUCCESS);
	std::cerr << err_msg[(int) err] << std::endl;
	return (EXIT_FAILURE);
}

/**
 * @brief main exec
 * @details read file => lex => parse => interpret => exec
 *
 * @param filename entry arg
 * @return local err
 */
static e_err		exec(const char *filename)
{
	FileReader		fr;

	auto err = fr.open_file(filename);
	if (err != e_err::NONE)
		return (err);

	Lexer			lex(fr.get_file_data());
	Parser			pars;

	err = lex.send_tokens(pars);
	if (err != e_err::NONE)
		return (err);
	return (e_err::NONE);
}

/**
 * @brief MAIN ENTRY
 * @details err: BAD_ARG_NUMBER
 *
 * @param ac n args
 * @param av args
 *
 * @return SUCCESS || FAILURE
 */
int		main(int ac, char **av)
{
	if (ac != 2)
		return (ret_err(e_err::BAD_ARG_NUMBER));
	return (ret_err(exec(av[1])));
}
