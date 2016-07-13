/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:40:48 by leeios            #+#    #+#             */
/*   Updated: 2016/04/04 15:29:36 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Analyzer.hpp"
#include "Error.hpp"

static void		exec(const std::string &filename)
{
	Analyzer	a;

	a.analyze_file(filename);
	a.printRules();
}

int			main(int ac, char **av)
{
	if (ac != 2)
		err::raise_error(eErr::FATAL, "You must specify one filename");
	else
		exec(av[1]);
	return (0);
}
